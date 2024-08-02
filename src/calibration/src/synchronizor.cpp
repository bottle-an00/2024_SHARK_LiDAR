#define WIDTH 1280
#define HEIGHT 720

#include "utility.h"

class Calibrator{
private:

    ros::NodeHandle nh;

    ros::Subscriber subLaserCloud;
    ros::Subscriber subimu;
    ros::Subscriber subImage;
    
    ros::Publisher pubFullCloud;
   

    pcl::PointCloud<PointType>::Ptr laserCloudIn;
    pcl::PointCloud<PointXYZIR>::Ptr laserCloudInRing;

    pcl::PointCloud<PointType>::Ptr fullCloud; 
    PointType nanPoint; // fill in fullCloud at each iteration

    std_msgs::Header cloudHeader;
    double lidar_time;

public:
    Calibrator():
        nh("~"){

        subLaserCloud = nh.subscribe<sensor_msgs::PointCloud2>(pointCloudTopic, 5, &Calibrator::cloudHandler, this);
        subimu = nh.subscribe<sensor_msgs::Imu>("/imu/data_raw", 5, &Calibrator::imuHandler, this);
        // subImage = nh.subscribe("/gmsl_camera/dev/video0/compressed", 10,  &Calibrator::ImageHandler, this);

        pubFullCloud = nh.advertise<sensor_msgs::PointCloud2> ("/new_hesai_pointcloud", 1);

        nanPoint.x = std::numeric_limits<float>::quiet_NaN();
        nanPoint.y = std::numeric_limits<float>::quiet_NaN();
        nanPoint.z = std::numeric_limits<float>::quiet_NaN();
        nanPoint.intensity = -1;

        allocateMemory();
    }

    void allocateMemory(){

        laserCloudIn.reset(new pcl::PointCloud<PointType>());
        laserCloudInRing.reset(new pcl::PointCloud<PointXYZIR>());

        fullCloud.reset(new pcl::PointCloud<PointType>());
        fullCloud->points.resize(N_SCAN*Horizon_SCAN);
    }


    ~Calibrator(){}

    void copyPointCloud(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){

        cloudHeader = laserCloudMsg->header;
        lidar_time = (laserCloudMsg->header.stamp.toSec())+7.59493e+08-184.185;
        ros::Time lidar_stamp = ros::Time(lidar_time);
        cloudHeader.stamp = lidar_stamp; // Ouster lidar users may need to uncomment this line
        
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
            auto cam_offset =(msg->header.stamp.toSec());
            cout << "offset :: " << cam_offset - lidar_time << endl;
        }
        catch (cv_bridge::Exception& e)
        {
          ROS_ERROR("Could not convert to image!");
        }
    }

    void imuHandler(const sensor_msgs::Imu::ConstPtr& msg){
        auto imu_offset = (msg->header.stamp.toSec());
        cout << "imu offset :: " << imu_offset - lidar_time << endl;

    }

    void cloudHandler(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){
        copyPointCloud(laserCloudMsg);
        
        publishTopic();
    }


    void publishTopic(){
        sensor_msgs::PointCloud2 laserCloudTemp;

        // projected full cloud
        if (pubFullCloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*laserCloudInRing, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "Pandar64";
            pubFullCloud.publish(laserCloudTemp);
        }
    
    }
    
};


int main(int argc, char** argv){

    ros::init(argc, argv, "calibration");
    
    Calibrator cb;

    ROS_INFO("\033[1;32m---->\033[0m calibration Started.");

    ros::spin();
    return 0;
}
