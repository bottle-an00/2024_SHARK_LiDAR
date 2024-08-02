#define WIDTH 1280
#define HEIGHT 720

#include "utility.h"

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::PointCloud2,sensor_msgs::CompressedImage> MySyncPolicy;
typedef message_filters::Synchronizer<MySyncPolicy> Sync;

class Calibrator{
private:

    ros::NodeHandle nh;
    boost::shared_ptr<Sync> sync;
    message_filters::Subscriber<sensor_msgs::PointCloud2> subLaserCloud;
    message_filters::Subscriber<sensor_msgs::CompressedImage> subImage;
    
    // ros::Subscriber subLaserCloud;
    // ros::Subscriber subImage;
    
    ros::Publisher pubFullCloud;
   

    pcl::PointCloud<PointType>::Ptr laserCloudIn;
    pcl::PointCloud<PointXYZIR>::Ptr laserCloudInRing;

    pcl::PointCloud<PointType>::Ptr fullCloud; 
    PointType nanPoint; // fill in fullCloud at each iteration

    cv::Mat rangeMat; // range matrix for range image
    cv::Mat labelMat; // label matrix for segmentaiton marking
    cv::Mat groundMat; // ground matrix for ground cloud marking
    cv::Mat intensityMat; 

    std_msgs::Header cloudHeader;

    cv::Mat image;
    cv::Mat P_rect;
    cv::Mat RT;
    cv::Mat X_,Y_;
    float* toggle;
    
    string selected_element = " ";
    
    float extrinsic_info[6] = {1.5, 0.94, -89.43, 0.23, -0.43, -0.25};// roll, pitch, yaw, x,y,z
    float intrinsic_info[2] = {1192.78, 1192.51};// x_focal, y_focal
    
    float ini_extrinsic_info[6];
    float ini_intrinsic_info[2];

public:
    Calibrator():
        nh("~"){
        
        subLaserCloud.subscribe(nh, "/hesai/pandar", 5);
        subImage.subscribe(nh, "/gmsl_camera/dev/video0/compressed", 20);
        
        // subLaserCloud = nh.subscribe<sensor_msgs::PointCloud2>("/new_hesai_pointcloud", 5, &Calibrator::cloudHandler, this);
        // subImage = nh.subscribe("/gmsl_camera/dev/video0/compressed", 10,  &Calibrator::ImageHandler, this);

        sync.reset(new Sync(MySyncPolicy(100),subLaserCloud,subImage ));
        sync->registerCallback(boost::bind(&Calibrator::cloudHandler, this, _1, _2));

        pubFullCloud = nh.advertise<sensor_msgs::PointCloud2> ("/jba_cloud", 1);

        nanPoint.x = std::numeric_limits<float>::quiet_NaN();
        nanPoint.y = std::numeric_limits<float>::quiet_NaN();
        nanPoint.z = std::numeric_limits<float>::quiet_NaN();
        nanPoint.intensity = -1;

        allocateMemory();
        resetParameters();
    }

    void allocateMemory(){

        laserCloudIn.reset(new pcl::PointCloud<PointType>());
        laserCloudInRing.reset(new pcl::PointCloud<PointXYZIR>());

        fullCloud.reset(new pcl::PointCloud<PointType>());
        fullCloud->points.resize(N_SCAN*Horizon_SCAN);
        image = cv::Mat(WIDTH, HEIGHT, CV_8UC3, cv::Scalar::all(0));
        for (int i=0; i< 6; i++){
            
            if(i<=1) ini_intrinsic_info[i] = intrinsic_info[i];

            ini_extrinsic_info[i] = extrinsic_info[i];
        }
        CameraSetting();
    }

    void resetParameters(){

        CameraSetting();

        std::fill(fullCloud->points.begin(), fullCloud->points.end(), nanPoint);
    }

    ~Calibrator(){}

    void copyPointCloud(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){

        cloudHeader = laserCloudMsg->header;
        cloudHeader.stamp = ros::Time::now(); // Ouster lidar users may need to uncomment this line
        pcl::fromROSMsg(*laserCloudMsg, *laserCloudIn);
        // Remove Nan points
        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*laserCloudIn, *laserCloudIn, indices);
        // have "ring" channel in the cloud
        if (useCloudRing == true){
            pcl::fromROSMsg(*laserCloudMsg, *laserCloudInRing);
            if (laserCloudInRing->is_dense == false) {
                ROS_ERROR("Point cloud is not in dense format, please remove NaN points first!");
                ros::shutdown();
            }  
        }
    }

    void ImageHandler(const sensor_msgs::CompressedImageConstPtr msg){
        try
        {
            if(get_ldata){
                image = cv::imdecode(cv::Mat(msg->data),1);//convert compressed image data to cv::Mat
                cv::resize(image,image,cv::Size(WIDTH,HEIGHT));
                cv::imshow("ref_img", image);
                get_ldata =false;
            }
        }
        catch (cv_bridge::Exception& e)
        {
          ROS_ERROR("Could not convert to image!");
        }
    }

    void cloudHandler(const boost::shared_ptr<const sensor_msgs::PointCloud2>& laserCloudMsg,
                    const boost::shared_ptr<const sensor_msgs::CompressedImage>& imgMsg){
        get_ldata = true;
        ImageHandler(imgMsg);
        auto start_time = std::chrono::high_resolution_clock::now();
        copyPointCloud(laserCloudMsg);
        projectPointCloud();
        
        publishCloud();
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        auto process_time = duration.count();
        LC_Fusion();
        cout << "process time :: " << process_time  << " ms"<<endl; 
        //imge 시각화 하는 부분
        textmaker();
        cv::imshow("view", image);
        int key = cv::waitKey(1);
        
        KeyboardHandler(key);

        resetParameters();
    }

    void projectPointCloud(){
        // range image projection
        float verticalAngle, horizonAngle, range, intensity;
        size_t rowIdn, columnIdn, index, cloudSize; 
        PointType thisPoint;

        cloudSize = laserCloudIn->points.size();

    
        for (size_t i = 0; i < cloudSize; ++i){

            thisPoint.x = laserCloudIn->points[i].x;
            thisPoint.y = laserCloudIn->points[i].y;
            thisPoint.z = laserCloudIn->points[i].z;

            double dist = ((thisPoint.x*thisPoint.x) +(thisPoint.y*thisPoint.y));

            if( dist <40*40 && thisPoint.z > - 1.58 && thisPoint.y < extrinsic_info[4]){
                //채널의 수직 각을 계산
                verticalAngle = atan2(thisPoint.z, sqrt(thisPoint.x * thisPoint.x + thisPoint.y * thisPoint.y)) * 180 / M_PI;

                float y_res;

                //channel의 간격이 다른 부분 (channel 1 ~ 5)
                if (verticalAngle >= -6 - 0.1 && verticalAngle < 2 + 0.1) 
                    rowIdn = (verticalAngle + 6)/0.167+10;

                else if (verticalAngle >= 2 + 0.1 && verticalAngle < 3 + 0.1) 
                    rowIdn = (verticalAngle + -2)/1.0+59;

                else if (verticalAngle >= -14.1 && verticalAngle < -6.1) 
                    rowIdn = (verticalAngle + 14)/1.0+2;

                else{
                    if (verticalAngle >= 11 + 0.1 && verticalAngle <= 15 + 0.1) 
                        y_res = 4.0;

                    else if (verticalAngle >= 5 + 0.1 && verticalAngle < 11+ 0.1) 
                        y_res = 3.0;

                    else if (verticalAngle >= 3 + 0.1 && verticalAngle < 5 + 0.1) 
                        y_res = 2.0;

                    else if (verticalAngle >= -19.1 && verticalAngle < - 14.1)
                        y_res = 5.0;

                    else if (verticalAngle >= -25 - 0.1 && verticalAngle < -19.1)
                        y_res = 6.0;

                    rowIdn = (verticalAngle + ang_bottom) / y_res;

                }
                if (rowIdn < 0 || rowIdn >= N_SCAN)
                    continue;

                horizonAngle = atan2(thisPoint.x, thisPoint.y) * 180 / M_PI;

                columnIdn = -round((horizonAngle-180.0)/ang_res_x) + Horizon_SCAN/2;

                if (columnIdn >= Horizon_SCAN)
                    columnIdn -= Horizon_SCAN;

                if (columnIdn < 0 || columnIdn >= Horizon_SCAN)
                    continue;
                index = columnIdn  + rowIdn * Horizon_SCAN;
                fullCloud->points[index] = thisPoint;
            }

        }
    }

    void textmaker(){
        
        int font = cv::FONT_HERSHEY_SIMPLEX;
        
        string tmp_str;
        string extrinsic_info_str[6];
        string intrinsic_info_str[2];

        for(int i =0; i< 6; i++){
            std::ostringstream oss;
    
            float tmp_value = extrinsic_info[i];
            oss << std::fixed << std::setprecision(2) << tmp_value;
            tmp_str = oss.str();

            extrinsic_info_str[i] = tmp_str;
        }

        for(int i =0; i< 2; i++){
            std::ostringstream oss;

            float tmp_value = intrinsic_info[i];
            oss << std::fixed << std::setprecision(2) << tmp_value;
            tmp_str = oss.str();
            
            intrinsic_info_str[i] = tmp_str;
        }

        string value_extrinsic = "roll:: " + extrinsic_info_str[0]
                               +" pitch :: " +  extrinsic_info_str[1]
                               +" yaw :: " +  extrinsic_info_str[2]
                               +" x :: " +  extrinsic_info_str[3]
                               +" y :: " +  extrinsic_info_str[4]
                               +" z :: " +  extrinsic_info_str[5];

        string valuse_intrinsic = "focal_length_x :: " + intrinsic_info_str[0]
                                + " focal_length_y :: " + intrinsic_info_str[1];

        cv::putText(image,"Change ::" + selected_element, cv::Point(0,50),font,0.7,(0,0,255),2);
        cv::putText(image,value_extrinsic, cv::Point(0,100),font,0.7,(0,0,255),2);
        cv::putText(image,valuse_intrinsic, cv::Point(0,150),font,0.7,(0,0,255),2);
    }
    
    void clear_argument(){
        for (int i=0; i<6; i++){
            float* ptr = &extrinsic_info[i];
            *ptr = ini_extrinsic_info[i];
        }

        for (int i=0; i<2; i++){
            float* ptr = &intrinsic_info[i];
            *ptr = ini_intrinsic_info[i];   
        }
    }
    
    void KeyboardHandler(int key){
        key %= 256;
        
        if (key == 'q'){
            exit(1);
        }

        if (key == 's'){
            save_calibration_result();
        }

        if (key == 'c'){
            clear_argument();
        }

        switch(key){
            case '1'://roll
                toggle = &extrinsic_info[0];
                selected_element = " roll ";
                break;
            case '2'://pitch
                toggle = &extrinsic_info[1];
                selected_element = " pitch ";

                break;
            case '3'://yaw
                toggle = &extrinsic_info[2];
                selected_element = " yaw ";
                break;
            case '4':// x 
                toggle = &extrinsic_info[3];
                selected_element = " x ";
                break;
            case '5':// y
                toggle = &extrinsic_info[4];
                selected_element = " y ";
                break;
            case '6':// z
                toggle = &extrinsic_info[5];
                selected_element = " z ";
                break;
            case '7'://focal_length(x)
                toggle = &intrinsic_info[0];
                selected_element = " focal_length_x ";
                break;
            case '8'://focal_length(y)
                toggle = &intrinsic_info[1];
                selected_element = " focal_length_y ";
                break;

            case 'u': //+0.01
                *toggle +=0.01;
                break;
            case 'i': //+0.1
                *toggle +=0.1;
                break;
            case 'o': //+1
                *toggle += 1;
                break;
            case 'p': //+10
                *toggle += 10;
                break;
            case '[': //+50
                *toggle += 50;
                break;

            case 'h': //-0.01
                *toggle -=0.01;
                break;
            case 'j': //-0.1
                *toggle -=0.1;
                break;
            case 'k': //-1
                *toggle -= 1;
                break;
            case 'l': //-10
                *toggle -= 10;
                break;        
            case ';': //-50
                *toggle -= 50;
                break;    
        }

    }

    cv::Mat getRotMat(){
        cv::Mat R = cv::Mat(3,3,CV_32F, cv::Scalar::all(0));
        cv::Mat P = cv::Mat(3,3,CV_32F, cv::Scalar::all(0));
        cv::Mat Y = cv::Mat(3,3,CV_32F, cv::Scalar::all(0));
        cv::Mat rot_mat = cv::Mat(3,3,CV_32F, cv::Scalar::all(0));

        double roll = (extrinsic_info[0]-90)*M_PI/180; //0
        double pitch = extrinsic_info[1]*M_PI/180;//0
        double yaw = (extrinsic_info[2]-90)*M_PI/180; //-90
    
        R.at<float>(0,0) = 1.0;
        R.at<float>(1,1) = cos(roll);
        R.at<float>(1,2) = -sin(roll);
        R.at<float>(2,1) = sin(roll);
        R.at<float>(2,2) = cos(roll);

        P.at<float>(0,0) = cos(pitch);
        P.at<float>(0,2) = sin(pitch);
        P.at<float>(1,1) = 1.0;
        P.at<float>(2,0) = -sin(pitch);
        P.at<float>(2,2) = cos(pitch);

        Y.at<float>(0,0) = cos(yaw);
        Y.at<float>(0,1) = -sin(yaw);
        Y.at<float>(1,0) = sin(yaw);
        Y.at<float>(1,1) = cos(yaw);
        Y.at<float>(2,2) = 1.0;

        rot_mat = Y*P*R;// 순서를 잘 지켜야 한다. 

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){//소수점 6자리에서 반올림 
                rot_mat.at<float>(i,j) = round(rot_mat.at<float>(i,j)*1000000.0)/1000000.0;
            }
        }

        return rot_mat;
    }

    void CameraSetting(){
        // Homogeneous coordinates 
        //intrinsic matrix ------------------------------------------
        P_rect = cv::Mat(3, 4, CV_32F, cv::Scalar::all(0));

        P_rect.at<float>(0,0) = intrinsic_info[0];
        P_rect.at<float>(0,2) = WIDTH/2;
        P_rect.at<float>(1,1) = intrinsic_info[1];
        P_rect.at<float>(1,2) = HEIGHT/2;
        P_rect.at<float>(2,2) = 1.0;
        
        //cout << P_rect << endl;
        //------------------------------------------------------------
        //extrinsic matrix -------------------------------------------
        RT = cv::Mat(4, 4, CV_32F, cv::Scalar::all(0));
        cv::Mat R_temp = cv::Mat(3, 3, CV_32F, cv::Scalar::all(0));
        R_temp = getRotMat();
        for(int i =0; i<3; i++){
            for(int j =0; j<3; j++){
                RT.at<float>(i,j) = R_temp.at<float>(i,j);
            }
        }

        for(int i=0;i < 3; i++){
            RT.at<float>(i,3) = extrinsic_info[i+3];
        }

        RT.at<float>(3,3) =1.0;
        RT=RT.inv();
        //cout << RT << endl;

        //------------------------------------------------------------

    }

    void LC_Fusion(){
        size_t cloudSize; 
        PointType thisPoint;

        cloudSize = fullCloud->points.size();

        for (size_t i = 0; i < cloudSize; ++i){
            thisPoint.x = fullCloud->points[i].x;
            thisPoint.y = fullCloud->points[i].y;
            thisPoint.z = fullCloud->points[i].z;

            X_ = cv::Mat(4,1, CV_32F, cv::Scalar::all(0));
            Y_ = cv::Mat(3,1, CV_32F, cv::Scalar::all(0));

            X_.at<float>(0,0) = thisPoint.x;
            X_.at<float>(1,0) = thisPoint.y;
            X_.at<float>(2,0) = thisPoint.z;
            X_.at<float>(3,0) = 1.0;

            Y_ = P_rect*RT*X_;                            
            int u = static_cast<int>(Y_.at<float>(0,0)/Y_.at<float>(2,0));
            int v = static_cast<int>(Y_.at<float>(1,0)/Y_.at<float>(2,0));

            if (u > 0 && u < WIDTH && v > 0 && v < HEIGHT){
                cv::circle(image,cv::Point(u,v),1,cv::Scalar(0,255,255),1,0);
            }
        }
    }

    void publishCloud(){
        sensor_msgs::PointCloud2 laserCloudTemp;

        // projected full cloud
        if (pubFullCloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*fullCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "world";
            pubFullCloud.publish(laserCloudTemp);
        }
    
    }
    
    string getCurrentDate(){
        auto now = chrono::system_clock::now();
        auto time_t_now = chrono::system_clock::to_time_t(now);

        stringstream ss;

        ss << put_time(localtime(&time_t_now), "%Y-%m-%d");
        return ss.str();
        
    }

    string getCurrentHMS(){
        auto now = chrono::system_clock::now();
        auto time_t_now = chrono::system_clock::to_time_t(now);

        stringstream ss;

        ss << put_time(localtime(&time_t_now), "%H-%M-%S");
        return ss.str();
    }

    bool folder_exist(string folder_path){

        DIR* dir = opendir(folder_path.c_str());
        if(dir != nullptr){
            closedir(dir);
            return true;
        }
        else return false;
    }

    void make_folder(string folder_name , string path){

        string folder_path = path + folder_name + "/"; 

        if(!folder_exist(folder_path)){
            if(mkdir(folder_path.c_str(),0777) ==0 ){
                cout << "Folder " << folder_name << " created! \n";
            }
            else{
                cerr << "Error: Unable to create folder\n";
                return;
            }
        }
        else cout << "Folder already existed" <<endl;
    }

    void save_calibration_result(){
        string currnet_path = "/home/jba/project/src/calibration/calibration_result/";

        string folder_name = getCurrentDate();

        make_folder(folder_name,currnet_path);

        string file_name = getCurrentHMS(); 
        string file_path = "/home/jba/project/src/calibration/calibration_result/" + folder_name+"/"+file_name + ".txt";
        
        ofstream outputFile(file_path);
        
        if(!outputFile.is_open()){
                cerr << "Error: Unable to open file\n";
                return;
        }

        outputFile << "roll :: " << extrinsic_info[0] << " | pitch :: " << extrinsic_info[1] << " | yaw :: " << extrinsic_info[2]
        << " | x :: " << extrinsic_info[3] << " | y :: " << extrinsic_info[4] << " | z :: " << extrinsic_info[5] << endl << endl;

        outputFile << "focal_length_x :: " << intrinsic_info[0] << " | focal_length_y :: " << intrinsic_info[1] << endl << endl;
 
        outputFile << "[RT]" << endl<<endl;
        for(int i = 0; i<4; i++){
            for(int j=0; j<4; j++){
                outputFile << setw(10) <<RT.at<float>(i,j);
            }
            outputFile << endl<<endl;
        }

        outputFile << "[intrinsic matrix]" << endl<<endl;
        for(int i = 0; i<4; i++){
            for(int j=0; j<4; j++){
                outputFile << setw(10) <<round(P_rect.at<float>(i,j)* 100000) /100000;
            }
            outputFile << endl;
        }

        outputFile.close();
        cout << "File " << file_name << ".txt has been created and written successfully!!" << endl; 
    }

};


int main(int argc, char** argv){

    ros::init(argc, argv, "calibration");
    
    Calibrator cb;

    ROS_INFO("\033[1;32m---->\033[0m calibration Started.");

    ros::spin();
    return 0;
}
