#ifndef _LOCAL_
#define _LOCAL_

#include "geodetic_utils.h"
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include "morai_msgs/GPSMessage.h"
#include "EKF/FusionEKF.h"
#include <sensor_msgs/PointCloud2.h>

#include <ros/ros.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <tf/transform_datatypes.h>

#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Imu, morai_msgs::GPSMessage> Local_Policy;
typedef message_filters::Synchronizer<Local_Policy> local_sync;
#define PI 3.14159265

class Local{
private:

    ros::NodeHandle nh;
    message_filters::Subscriber<sensor_msgs::Imu> sub_imu;
    message_filters::Subscriber<morai_msgs::GPSMessage> sub_gps;
    boost::shared_ptr<local_sync> sync;
    
    ros::Subscriber sub_ndt_local;

    ros::Publisher pub_local;
    ros::Publisher pub_local2;
    geodetic_converter::GeodeticConverter GC;
    
    double roll  = 0.0;
    double pitch = 0.0;
    double yaw   = 0.0;
    double e_,n_,u_;

    geometry_msgs::PoseWithCovarianceStamped data2;

    tf::StampedTransform MappedTrans;
    tf::TransformBroadcaster tfBroadcaster;

    tf::StampedTransform map_2_camera_init_Trans;
    tf::TransformBroadcaster tfBroadcasterMap2CameraInit;

    tf::StampedTransform camera_2_base_link_Trans;
    tf::TransformBroadcaster tfBroadcasterCamera2Baselink;

    bool Non_GPS_Flag = false;

    geometry_msgs::PoseStamped ndt_msgs;

    FusionEKF EKF;
    VectorXd pred_local;
    MeasurementPackage measurement_pack;

    string gps_topic;

public:

    Local():
        nh("~"){
        nh.getParam("/gps_topic", gps_topic);

        sub_imu.subscribe(nh, "/imu", 100);
        sub_gps.subscribe(nh, gps_topic, 40);

        sync.reset(new local_sync(Local_Policy(40), sub_imu, sub_gps));
        sync->registerCallback(boost::bind(&Local::gpscallback, this, _1, _2));

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
        measurement_pack.raw_measurements_ = VectorXd(2);
        pred_local = Eigen::VectorXd::Zero(4);
    }

    void gpscallback(const boost::shared_ptr<const sensor_msgs::Imu>& Imu_msg,
                     const boost::shared_ptr<const morai_msgs::GPSMessage>& Gps_msg){
                                
        imucallback(Imu_msg);
        
        double lat_, lon_, alt_;

        lat_ = Gps_msg->latitude;
        lon_ = Gps_msg->longitude;
        alt_ = Gps_msg->altitude;

        if(lat_ != 0 && lon_ != 0){
            
            GC.initialiseReference(37.4193122129, 127.125659528, 1.56630456448);
            GC.geodetic2Enu(lat_,lon_,alt_,&e_,&n_,&u_);

            geometry_msgs::PoseStamped data;
            data.header.stamp = ros::Time::now();
            data.pose.position.x = e_;
            data.pose.position.y = n_;
            data.pose.position.z = 0;
            data.pose.orientation.x = roll;
            data.pose.orientation.y = pitch;
            data.pose.orientation.z = yaw;
            data.pose.orientation.w = 0.0; // 0은 센서 정상작동시 1은 비정상 작동시(gps 음영)

            measurement_pack.raw_measurements_<< e_, n_;

            pub_local.publish(data);
            Non_GPS_Flag = true;

            nh.setParam("/local_working", true);
            nh.setParam("/ego_location_x",e_);
            nh.setParam("/ego_location_y" , n_);

            publishTF(Gps_msg->header.stamp, e_, n_);
            
        }else{

            if(Non_GPS_Flag == true){
                data2.header.stamp = ros::Time::now();
                data2.header.frame_id = "map";
                data2.pose.pose.position.x = e_;
                data2.pose.pose.position.y = n_;

                geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromRollPitchYaw
                                          (roll, pitch, yaw);

                data2.pose.pose.orientation = odom_quat;
                pub_local2.publish(data2);

                Non_GPS_Flag = false;
            }

            publish_EKF_local(Imu_msg);
            
            nh.setParam("/local_working", true);
            nh.setParam("/ego_location_x",ndt_msgs.pose.position.x);
            nh.setParam("/ego_location_y" , ndt_msgs.pose.position.y);

            //publishTF(Gps_msg->header.stamp, ndt_msgs.pose.position.x, ndt_msgs.pose.position.y);

        }

    }

    void imucallback(const sensor_msgs::Imu::ConstPtr& Imu_msg) {
        // Extract quaternion from IMU message
        geometry_msgs::Quaternion quaternion = Imu_msg->orientation;

        // Convert geometry_msgs::Quaternion to tf::Quaternion
        tf::Quaternion tf_quaternion;
        tf::quaternionMsgToTF(quaternion, tf_quaternion);

        // Compute the roll, pitch, and yaw angles from tf::Quaternion
        tf::Matrix3x3(tf_quaternion).getRPY(roll, pitch, yaw);

    }

    void ndtLocalHandler(const geometry_msgs::PoseStamped::ConstPtr& ndt_local_msgs){
        ndt_msgs = *ndt_local_msgs;

        measurement_pack.raw_measurements_<< ndt_msgs.pose.position.x, ndt_msgs.pose.position.y;

        geometry_msgs::Quaternion quaternion = ndt_msgs.pose.orientation;

        // Convert geometry_msgs::Quaternion to tf::Quaternion
        tf::Quaternion tf_quaternion;
        tf::quaternionMsgToTF(quaternion, tf_quaternion);

        // Compute the roll, pitch, and yaw angles from tf::Quaternion
        tf::Matrix3x3(tf_quaternion).getRPY(roll, pitch, yaw);

        ndt_msgs.pose.orientation.x = roll;
        ndt_msgs.pose.orientation.y = pitch;
        ndt_msgs.pose.orientation.z = yaw;
        ndt_msgs.pose.orientation.w = 1.0;

        // pub_local.publish(ndt_msgs);
    }
    
    void publish_EKF_local(const sensor_msgs::Imu::ConstPtr& Imu_msg){

        measurement_pack.timestamp_ = static_cast<long long>(Imu_msg->header.stamp.toNSec());
        
        EKF.ProcessMeasurement(measurement_pack);

        pred_local = EKF.ekf_.x_;

        ndt_msgs.header.stamp = Imu_msg->header.stamp;
        
        ndt_msgs.pose.orientation.w =1.0;

        ndt_msgs.pose.position.x = pred_local[0];
        ndt_msgs.pose.position.y = pred_local[1];
        
        pub_local.publish(ndt_msgs);
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