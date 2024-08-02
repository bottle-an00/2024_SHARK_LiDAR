#ifndef _MULTI_LIDAR_CALIBRATION_
#define _MULTI_LIDAR_CALIBRATION_

#include <ros/ros.h>

#include "perception/data_struction.h"

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "perception/process_info.h"

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::PointCloud2, sensor_msgs::PointCloud2, sensor_msgs::PointCloud2> multi_Lidar_policy;
typedef message_filters::Synchronizer<multi_Lidar_policy> LiDAR_sync;

#define PI 3.14159265

class MultiLiDARCalibration{
private:

    ros::NodeHandle nh;

    message_filters::Subscriber<sensor_msgs::PointCloud2> sub_32e;
    message_filters::Subscriber<sensor_msgs::PointCloud2> sub_16r;
    message_filters::Subscriber<sensor_msgs::PointCloud2> sub_16l;

    boost::shared_ptr<LiDAR_sync> sync;
    
    ros::Publisher pub_carlibrated_pc2;

    pcl::PointCloud<PointType>::Ptr Lidar_Data;

    std_msgs::Header cloudHeader;

    Ego_status vlp16_r_info;
    Ego_status vlp16_l_info;

public:

    MultiLiDARCalibration():
        nh("~"){

        sub_32e.subscribe(nh, "/ns1/velodyne_points", 2);
        sub_16r.subscribe(nh, "/ns2/velodyne_points", 2);
        sub_16l.subscribe(nh, "/ns3/velodyne_points", 2);

        sync.reset(new LiDAR_sync(multi_Lidar_policy(50), sub_32e, sub_16r, sub_16l));
        sync->registerCallback(boost::bind(&MultiLiDARCalibration::LiDAR_callback, this, _1, _2,_3));

        pub_carlibrated_pc2 =  nh.advertise<sensor_msgs::PointCloud2>("/velodyne_points", 2);
        
        allocateMemory();
    }
    
    void allocateMemory(){
        Lidar_Data.reset(new pcl::PointCloud<PointType>());

        vlp16_r_info.curr.x =  0.0;
        vlp16_r_info.curr.y =  0.6;
        vlp16_r_info.curr.z =  0.05;

        vlp16_r_info.roll = -0.349066;

        vlp16_l_info.curr.x =  0.0;
        vlp16_l_info.curr.y = -0.6;
        vlp16_l_info.curr.z =  0.05;

        vlp16_l_info.roll = 0.349066;
    }

    void LiDAR_callback(const boost::shared_ptr<const sensor_msgs::PointCloud2>& hdl_32e_msg,
                     const boost::shared_ptr<const sensor_msgs::PointCloud2>& vlp16_r_msg,
                     const boost::shared_ptr<const sensor_msgs::PointCloud2>& vlp16_l_msg){
                        
        ROS_INFO_STREAM("\033[1;32m" << "MultiLiDARCalibration Working..."<< "\033[0m");
        
        cloudHeader = hdl_32e_msg->header;
        cloudHeader.frame_id = hdl_32e_msg->header.frame_id;
        cloudHeader.stamp = ros::Time::now(); 
        pcl::fromROSMsg(*hdl_32e_msg, *Lidar_Data);
        
        pcl::PointCloud<PointType>::Ptr vlp16_r(new pcl::PointCloud<PointType>());
        pcl::fromROSMsg(*vlp16_r_msg, *vlp16_r);
        pcl::VoxelGrid<PointType> sor;
        sor.setInputCloud(vlp16_r);  
        sor.setLeafSize(0.10f, 0.10f, 0.10f);  
        
        sor.filter(*vlp16_r);

        *Lidar_Data += *transformPointCloud(vlp16_r,vlp16_r_info);

        pcl::PointCloud<PointType>::Ptr vlp16_l(new pcl::PointCloud<PointType>());
        pcl::fromROSMsg(*vlp16_l_msg, *vlp16_l);
        sor.setInputCloud(vlp16_l);  
        sor.setLeafSize(0.10f, 0.10f, 0.10f);  
        
        sor.filter(*vlp16_l);
        *Lidar_Data += *transformPointCloud(vlp16_l,vlp16_l_info);

        multi_LiDAR_Calibration_working = true;

        publishPC2();
    }

    void publishPC2(){

        sensor_msgs::PointCloud2 laserCloudTemp;

        pcl::toROSMsg(*Lidar_Data, laserCloudTemp);
        
        laserCloudTemp.header.stamp = cloudHeader.stamp;
        
        laserCloudTemp.header.frame_id = cloudHeader.frame_id;
        
        pub_carlibrated_pc2.publish(laserCloudTemp);
    }
    

};


#endif