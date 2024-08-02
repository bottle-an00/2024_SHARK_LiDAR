#define WIDTH 1280
#define HEIGHT 720

#include "utility.h"

class Rotator{
private:

    ros::NodeHandle nh;

    ros::Subscriber subLaserCloud;
    
    ros::Publisher pubFullCloud;
   

    pcl::PointCloud<PointType>::Ptr laserCloudIn;
    pcl::PointCloud<PointXYZIR>::Ptr laserCloudInRing;

    pcl::PointCloud<PointType>::Ptr fullCloud; 
    PointType nanPoint; // fill in fullCloud at each iteration

    std_msgs::Header cloudHeader;
    double lidar_time;

public:
    Rotator():
        nh("~"){

        subLaserCloud = nh.subscribe<sensor_msgs::PointCloud2>(pointCloudTopic, 5, &Rotator::cloudHandler, this);

        pubFullCloud = nh.advertise<sensor_msgs::PointCloud2> ("/new_hesai/pandar", 1);

        allocateMemory();
    }

    void allocateMemory(){

        laserCloudIn.reset(new pcl::PointCloud<PointType>());
        laserCloudInRing.reset(new pcl::PointCloud<PointXYZIR>());

        fullCloud.reset(new pcl::PointCloud<PointType>());
        fullCloud->points.resize(N_SCAN*Horizon_SCAN);
    }


    ~Rotator(){}

    void copyPointCloud(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){

        cloudHeader = laserCloudMsg->header;
        lidar_time = (laserCloudMsg->header.stamp.toSec());
        ros::Time lidar_stamp = ros::Time(lidar_time);
        cloudHeader.stamp = lidar_stamp; // Ouster lidar users may need to uncomment this line
        pcl::fromROSMsg(*laserCloudMsg, *laserCloudIn);
        // Remove Nan points
        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*laserCloudIn, *laserCloudIn, indices);
        double yaw_angle = M_PI / 2.0;

        Eigen::Affine3f transform = Eigen::Affine3f::Identity();
        transform.rotate(Eigen::AngleAxisf(yaw_angle, Eigen::Vector3f::UnitZ()));

        pcl::transformPointCloud(*laserCloudIn, *laserCloudIn, transform);
    }

    void cloudHandler(const sensor_msgs::PointCloud2ConstPtr& laserCloudMsg){
        copyPointCloud(laserCloudMsg);
        
        publishTopic();
    }


    void publishTopic(){
        sensor_msgs::PointCloud2 laserCloudTemp;

        // projected full cloud
        if (pubFullCloud.getNumSubscribers() != 0){
            pcl::toROSMsg(*laserCloudIn, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "world";
            pubFullCloud.publish(laserCloudTemp);
        }
    
    }
    
};


int main(int argc, char** argv){

    ros::init(argc, argv, "rotator");
    
    Rotator R;

    ROS_INFO("\033[1;32m---->\033[0m calibration Started.");

    ros::spin();
    return 0;
}
