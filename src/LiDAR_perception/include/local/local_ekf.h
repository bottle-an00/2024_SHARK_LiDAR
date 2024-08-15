#ifndef _LOCAL_
#define _LOCAL_

#include "geodetic_utils.h"
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "morai_msgs/GPSMessage.h"
#include "EKF/gnssEKF.h"
#include <sensor_msgs/PointCloud2.h>

#include <ros/ros.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <tf/transform_datatypes.h>

#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

#define PI 3.14159265
#define PI2 2*3.141592

class Local{
private:

    ros::NodeHandle nh;
    ros::Subscriber sub_imu;
    ros::Subscriber sub_gps;
    
    ros::Subscriber sub_ndt_local;

    ros::Publisher pub_local;
    ros::Publisher pub_local2;
    geodetic_converter::GeodeticConverter GC;
    
    double roll, pitch, yaw;
    double angular_vel_z;

    double e_,n_,u_;

    geometry_msgs::PoseWithCovarianceStamped data2;

    tf::StampedTransform MappedTrans;
    tf::TransformBroadcaster tfBroadcaster;

    tf::StampedTransform map_2_camera_init_Trans;
    tf::TransformBroadcaster tfBroadcasterMap2CameraInit;

    tf::StampedTransform camera_2_base_link_Trans;
    tf::TransformBroadcaster tfBroadcasterCamera2Baselink;

    bool Non_GPS_Flag;
    bool ndt_working;

    geometry_msgs::PoseStamped ndt_msgs;

    GNSSEKF gnssEKF;
    MeasurementPackage measurement_pack_GNSS;

    string gps_topic;
    
public:
    sensor_msgs::Imu prev_imu_msg;
    bool gps_init;
    bool imu_init;


    Local():
        nh("~"){
        nh.getParam("/gps_topic", gps_topic);

        sub_imu = nh.subscribe<sensor_msgs::Imu>("/imu",100, &Local::imucallback,this);
        sub_gps = nh.subscribe<morai_msgs::GPSMessage>(gps_topic ,10, &Local::gpscallback,this);
        
        pub_local =  nh.advertise<geometry_msgs::PoseStamped>("/local_msgs_for_vision2", 1000);
        pub_local2 =  nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/local_msgs_for_vision_for_initialization", 1000);
        sub_ndt_local = nh.subscribe<geometry_msgs::PoseStamped>("/ndt_pose",10, &Local::ndtLocalHandler,this);

        MappedTrans.frame_id_ = "/camera_init";
        MappedTrans.child_frame_id_ = "/camera";

        map_2_camera_init_Trans.frame_id_ = "/map";
        map_2_camera_init_Trans.child_frame_id_ = "/camera_init";

        camera_2_base_link_Trans.frame_id_ = "/camera";
        camera_2_base_link_Trans.child_frame_id_ = "/base_link";
        allocateMemory();
    }
    
    void allocateMemory(){
        Non_GPS_Flag = false;
        gps_init = false;
        ndt_working = false;

        measurement_pack_GNSS.raw_measurements_ = VectorXd(2);
    }

    void gpscallback(const morai_msgs::GPSMessage Gps_msg){                              
        
        double lat_, lon_, alt_;

        lat_ = Gps_msg.latitude;
        lon_ = Gps_msg.longitude;
        alt_ = Gps_msg.altitude;

        if(lat_ != 0 && lon_ != 0){
            
            GC.initialiseReference(37.4193122129, 127.125659528, 1.56630456448);
            GC.geodetic2Enu(lat_,lon_,alt_,&e_,&n_,&u_);

            measurement_pack_GNSS.raw_measurements_<< e_, n_;

            measurement_pack_GNSS.timestamp_ = Gps_msg.header.stamp.toNSec();

            gnssEKF.initialization(measurement_pack_GNSS);            

            gnssEKF.ekf_predict(measurement_pack_GNSS.timestamp_,angular_vel_z);

            gnssEKF.ekf_update(measurement_pack_GNSS);

            Non_GPS_Flag = true;
            ndt_working = false;
            
        }else{

            if(Non_GPS_Flag == true){//init location 보내기
                data2.header.stamp = ros::Time::now();
                data2.header.frame_id = "world";
                data2.pose.pose.position.x = e_;
                data2.pose.pose.position.y = n_;

                geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromRollPitchYaw
                                          (roll, pitch, yaw);

                data2.pose.pose.orientation = odom_quat;
                pub_local2.publish(data2);

                Non_GPS_Flag = false;
            }

            //publishTF(Gps_msg->header.stamp, ndt_msgs.pose.position.x, ndt_msgs.pose.position.y);

        }
        
        gps_init = true;
    }

    void imucallback(const sensor_msgs::Imu::ConstPtr& Imu_msg) {
        // Extract quaternion from IMU message
        geometry_msgs::Quaternion quaternion = Imu_msg->orientation;

        // Convert geometry_msgs::Quaternion to tf::Quaternion
        tf::Quaternion tf_quaternion;
        tf::quaternionMsgToTF(quaternion, tf_quaternion);

        // Compute the roll, pitch, and yaw angles from tf::Quaternion
        tf::Matrix3x3(tf_quaternion).getRPY(roll, pitch, yaw);
        
        // angular_vel_z = Imu_msg->angular_velocity.z;
        prev_imu_msg = *Imu_msg;
        imu_init = true;
        //if(gps_init) publish_EKF_local(Imu_msg);
    }

    void ndtLocalHandler(const geometry_msgs::PoseStamped::ConstPtr& ndt_local_msgs){
        //gps와 같은 역할
        ndt_msgs = *ndt_local_msgs;
        
        ndt_working = true;

        measurement_pack_GNSS.raw_measurements_<< ndt_msgs.pose.position.x, ndt_msgs.pose.position.y;

        measurement_pack_GNSS.timestamp_ = static_cast<long long>(ndt_local_msgs->header.stamp.toNSec());

        gnssEKF.initialization(measurement_pack_GNSS);

        gnssEKF.ekf_predict(measurement_pack_GNSS.timestamp_,angular_vel_z);

        gnssEKF.ekf_update(measurement_pack_GNSS);

    }

    void publish_EKF_local(sensor_msgs::Imu& Imu_msg){
        
        long long current_time = static_cast<long long>(Imu_msg.header.stamp.toNSec());
        
        angular_vel_z = Imu_msg.angular_velocity.z;

        gnssEKF.ekf_predict(current_time ,angular_vel_z);

        double ego_x = gnssEKF.ekf_.x_[0]; 
        double ego_y = gnssEKF.ekf_.x_[1]; 

        geometry_msgs::PoseStamped data;

        data.header.stamp = ros::Time::now();
        data.pose.position.x = ego_x;
        data.pose.position.y = ego_y;
        data.pose.position.z = 0;
        data.pose.orientation.x = roll;
        data.pose.orientation.y = pitch;
        data.pose.orientation.z = yaw;
        data.pose.orientation.w = 0.0; // 0은 센서 정상작동시 1은 비정상 작동시(gps 음영)
        
        if(ndt_working) data.pose.orientation.w = 1.0;

        nh.setParam("/local_working", true);
        nh.setParam("/ego_location_x",e_);
        nh.setParam("/ego_location_y" , n_);

        pub_local.publish(data);
        publishTF(Imu_msg.header.stamp, ego_x, ego_y);
        
    }

    void publishTF(ros::Time stamp_, double ego_x, double ego_y){

        geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromRollPitchYaw
                                  (roll, pitch, yaw);

        MappedTrans.stamp_ = stamp_;
        MappedTrans.setRotation(tf::Quaternion(odom_quat.x, odom_quat.y, odom_quat.z, odom_quat.w));
        MappedTrans.setOrigin(tf::Vector3(ego_x,ego_y, 0.0));
        
        tfBroadcaster.sendTransform(MappedTrans);
    }
    ~Local(){}
};


#endif