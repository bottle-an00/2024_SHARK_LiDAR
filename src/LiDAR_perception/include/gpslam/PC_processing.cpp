#include "perception/data_struction.h"

#include <thread>

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::PointCloud2,sensor_msgs::PointCloud2, geometry_msgs::PoseStamped> MySyncPolicy;
typedef message_filters::Synchronizer<MySyncPolicy> Sync;

class gpslam{
private:
    ros::NodeHandle nh;
    message_filters::Subscriber<sensor_msgs::PointCloud2> subNonGroundCloud;
    message_filters::Subscriber<sensor_msgs::PointCloud2> subGroundCloud;
    message_filters::Subscriber<geometry_msgs::PoseStamped> subLocal;
    boost::shared_ptr<Sync> sync;
    
    ros::Publisher pubNonGroundMap;
    ros::Publisher pubLaneMap;
    ros::Publisher pubGroundMap;

    pcl::PointCloud<PointType>::Ptr groundCloudIn;// patchwork++에 의해 들어온 ground cloud를 저장
    pcl::PointCloud<PointType>::Ptr nongroundCloudIn;// patchwork++에 의해 들어온  non ground cloud를 저장

    pcl::PointCloud<PointType>::Ptr laneCloud;
    pcl::PointCloud<PointType>::Ptr NonLaneCloud;
    pcl::PointCloud<PointType>::Ptr GroundCloud;

    pcl::PointCloud<PointType>::Ptr NonGroundMapCloud;
    pcl::PointCloud<PointType>::Ptr laneMapCloud;
    pcl::PointCloud<PointType>::Ptr GroundMapCloud;

    pcl::VoxelGrid<PointType> downSizeFilterNonGround;
    pcl::VoxelGrid<PointType> downSizeFilterLane;
    pcl::VoxelGrid<PointType> downSizeFilterGround;

    std_msgs::Header cloudHeader;

    Ego_status ego_info;
    
public:

    gpslam():
        nh("~"){

        subNonGroundCloud.subscribe(nh, "/ground_segmentation/nonground", 1);
        subGroundCloud.subscribe(nh, "/ground_segmentation/ground", 1);
        subLocal.subscribe(nh, "/local_msgs_for_vision2", 10);
         
        sync.reset(new Sync(MySyncPolicy(10), subNonGroundCloud, subGroundCloud, subLocal));
        sync->registerCallback(boost::bind(&gpslam::cloudHandler, this, _1, _2, _3));

        pubNonGroundMap = nh.advertise<sensor_msgs::PointCloud2> ("/NongroundMap", 1);
        pubLaneMap = nh.advertise<sensor_msgs::PointCloud2> ("/LaneMap", 1); 
        pubGroundMap = nh.advertise<sensor_msgs::PointCloud2> ("/GroundMap", 1); 

        downSizeFilterLane.setLeafSize(0.2, 0.2, 0.2);
        downSizeFilterNonGround.setLeafSize(1.2, 1.2, 1.2);
        downSizeFilterGround.setLeafSize(1.2, 1.2, 1.2);

        allocateMemory();
        resetParameters();
    }

    void allocateMemory(){

        groundCloudIn.reset(new pcl::PointCloud<PointType>());

        nongroundCloudIn.reset(new pcl::PointCloud<PointType>());

        laneCloud.reset(new pcl::PointCloud<PointType>());

        NonLaneCloud.reset(new pcl::PointCloud<PointType>());

        GroundCloud.reset(new pcl::PointCloud<PointType>());

        NonGroundMapCloud.reset(new pcl::PointCloud<PointType>());

        laneMapCloud.reset(new pcl::PointCloud<PointType>());

        GroundMapCloud.reset(new pcl::PointCloud<PointType>());
    }

    void resetParameters(){

        groundCloudIn->clear();

        nongroundCloudIn->clear();
        
        laneCloud->clear();
        
        NonLaneCloud->clear();

        GroundCloud->clear();
    }

    ~gpslam(){}
    
    void groundcloudHandler(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){
        
        pcl::fromROSMsg(*laserCloudMsg, *groundCloudIn);

    }

    void localMsgHandler(const geometry_msgs::PoseStamped::ConstPtr& localMsg){

        ego_info.curr.x = localMsg->pose.position.x;

        ego_info.curr.y = localMsg->pose.position.y;

        ego_info.roll = localMsg->pose.orientation.x;

        ego_info.pitch = localMsg->pose.orientation.y;

        ego_info.yaw = localMsg->pose.orientation.z;
    }

    void copyPointCloud(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){

        cloudHeader = laserCloudMsg->header;

        cloudHeader.frame_id = "/base_link";

        cloudHeader.stamp = ros::Time::now();

        pcl::fromROSMsg(*laserCloudMsg, *nongroundCloudIn);

    }

    void cloudHandler(const boost::shared_ptr<const sensor_msgs::PointCloud2>& laserCloudMsg,
                    const boost::shared_ptr<const sensor_msgs::PointCloud2>& GroundlaserCloudMsg,
                    const boost::shared_ptr<const geometry_msgs::PoseStamped>& LocalMsg ){

        groundcloudHandler(GroundlaserCloudMsg);

        localMsgHandler(LocalMsg);

        copyPointCloud(laserCloudMsg);
        
    }

    void run(){
        cout << "roll : " << ego_info.roll*180/PI << " pitch : " << ego_info.pitch*180/PI << endl;

        if(ego_info.roll*180/PI < 0.2 && ego_info.pitch*180/PI < 0.2 ){

            process_LiDAR_data();

            save_PCD_source();

            publishCloud();

            resetParameters();
        }
    }

    void process_LiDAR_data(){
        
        size_t cloud_size = groundCloudIn->points.size();

        for(int i = 0; i < cloud_size; i++ ){
            PointType thisPoint = groundCloudIn->points[i];
            
            if(thisPoint.intensity == 255 || thisPoint.intensity == 170){

                if(cal_range(thisPoint) < 15 && thisPoint.z >-1.65 && thisPoint.z <-1.45){ 

                    thisPoint.x -= 0.4;
                    
                    laneCloud->push_back(thisPoint);
                }
            }

            if(cal_range(thisPoint) < 15 && thisPoint.z >-1.65 && thisPoint.z <-1.45){
                thisPoint.x -= 0.4;
                GroundCloud->push_back(thisPoint);
            }
        }

        cloud_size = nongroundCloudIn->points.size();

        for(int i = 0; i < cloud_size; i++ ){
            PointType thisPoint = nongroundCloudIn->points[i];
            
            if(thisPoint.z >= -1.4 && cal_range(thisPoint)<90 && cal_range(thisPoint)>2 ){
                
                thisPoint.x -= 0.4;
                NonLaneCloud->push_back(thisPoint);
            }
        }

    }
    
    double cal_range(PointType p){
       return sqrt(p.x*p.x + p.y*p.y + p.z*p.z); 
    }

    pcl::PointCloud<PointType>::Ptr transformPointCloud(pcl::PointCloud<PointType>::Ptr cloudIn){

        pcl::PointCloud<PointType>::Ptr cloudOut(new pcl::PointCloud<PointType>());

        PointType *pointFrom;
        PointType pointTo;

        int cloudSize = cloudIn->points.size();
        cloudOut->resize(cloudSize);
        
        for (int i = 0; i < cloudSize; ++i){

            pointFrom = &cloudIn->points[i];
            float x1 = cos(ego_info.yaw) * pointFrom->x - sin(ego_info.yaw) * pointFrom->y;
            float y1 = sin(ego_info.yaw) * pointFrom->x + cos(ego_info.yaw)* pointFrom->y;
            float z1 = pointFrom->z;

            float x2 = x1;
            float y2 = cos(ego_info.roll) * y1 - sin(ego_info.roll) * z1;
            float z2 = sin(ego_info.roll) * y1 + cos(ego_info.roll)* z1;

            pointTo.x = cos(ego_info.pitch) * x2 + sin(ego_info.pitch) * z2 + ego_info.curr.x;
            pointTo.y = y2 + ego_info.curr.y;
            pointTo.z = -sin(ego_info.pitch) * x2 + cos(ego_info.pitch) * z2 + ego_info.curr.z;

            pointTo.intensity = pointFrom->intensity;

            cloudOut->points[i] = pointTo;
        }
        return cloudOut;
    }

    pcl::PointCloud<PointType>::Ptr downsampled_cloud(pcl::PointCloud<PointType>::Ptr input_cloud){

        pcl::PointCloud<PointType>::Ptr downsampled_cloud(new pcl::PointCloud<PointType>);

        pcl::VoxelGrid<PointType> sor;
        sor.setInputCloud(input_cloud);  
        sor.setLeafSize(0.20f, 0.2f, 0.20f);  
        sor.filter(*downsampled_cloud);

        return downsampled_cloud;
    }

    void save_PCD_source(){
        *NonGroundMapCloud = *downsampled_cloud(NonGroundMapCloud);
        *NonGroundMapCloud  += *transformPointCloud(NonLaneCloud);

        *laneMapCloud = *downsampled_cloud(laneMapCloud);
    	*laneMapCloud += *transformPointCloud(laneCloud);

        *GroundMapCloud = *downsampled_cloud(GroundMapCloud);
    	*GroundMapCloud += *transformPointCloud(GroundCloud);
        
    }

    void save_PCD_Map(){
        ros::Rate rate(0.2);

        while (ros::ok()){
            rate.sleep();
        }

        pcl::PointCloud<PointType>::Ptr NonGroundMapCloudDS(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr laneMapCloud_DS(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr GroundMapCloud_DS(new pcl::PointCloud<PointType>());

        downSizeFilterNonGround.setInputCloud(NonGroundMapCloud);
        downSizeFilterNonGround.filter(*NonGroundMapCloudDS);

        downSizeFilterLane.setInputCloud(laneMapCloud);
        downSizeFilterLane.filter(*laneMapCloud_DS);

        downSizeFilterGround.setInputCloud(GroundMapCloud);
        downSizeFilterGround.filter(*GroundMapCloud_DS);

        pcl::io::savePCDFileASCII(fileDirectory+"/NongroundMap.pcd", *NonGroundMapCloudDS);
        pcl::io::savePCDFileASCII(fileDirectory+"/Lane.pcd", *laneMapCloud_DS);
        pcl::io::savePCDFileASCII(fileDirectory+"/Ground.pcd", *GroundMapCloud_DS);

    }

    void publishCloud(){
        // 2. Publish clouds
        sensor_msgs::PointCloud2 laserCloudTemp;

        if (pubNonGroundMap.getNumSubscribers() != 0){
            pcl::toROSMsg(*NonGroundMapCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "map";
            pubNonGroundMap.publish(laserCloudTemp);
        }

        if (pubLaneMap.getNumSubscribers() != 0){
            pcl::toROSMsg(*laneMapCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "map";
            pubLaneMap.publish(laserCloudTemp);
        }

        if (pubGroundMap.getNumSubscribers() != 0){
            pcl::toROSMsg(*GroundMapCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "map";
            pubGroundMap.publish(laserCloudTemp);
        }
    }

    
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "gpslam");

    ROS_INFO("\033[1;32m---->\033[0m Map Optimization Started.");

    gpslam GS;

    std::thread saveMap(&gpslam::save_PCD_Map, &GS);
    
    ros::Rate rate(50);
    
    while (ros::ok())
    {
        ros::spinOnce();

        GS.run();

        rate.sleep();
    }
    
    saveMap.join();

    return 0;
}
