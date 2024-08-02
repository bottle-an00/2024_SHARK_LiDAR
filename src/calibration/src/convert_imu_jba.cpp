#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>
#include <iostream>
#include <math.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include "novatel_oem7_msgs/INSPVA.h"

using namespace std;

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Imu,novatel_oem7_msgs::INSPVA> MySyncPolicy;
typedef message_filters::Synchronizer<MySyncPolicy> Sync;

class Imu_Convertor{
public:
    ros::NodeHandle nh;
    ros::Publisher imu_pub;
    
    boost::shared_ptr<Sync> sync;
    message_filters::Subscriber<sensor_msgs::Imu> imu_sub1;
    message_filters::Subscriber<novatel_oem7_msgs::INSPVA> imu_sub2;


    Imu_Convertor(){
        imu_pub = nh.advertise<sensor_msgs::Imu>("/imu/quaternion", 1);
        
        imu_sub1.subscribe(nh, "/imu/data_raw", 10);
        imu_sub2.subscribe(nh, "/novatel/oem7/inspva", 10);

        sync.reset(new Sync(MySyncPolicy(100),imu_sub1,imu_sub2 ));
        sync->registerCallback(boost::bind(&Imu_Convertor::imuCallback, this, _1, _2));
    }

    void imuCallback(const boost::shared_ptr<const sensor_msgs::Imu>& _imu_msg1,
    const boost::shared_ptr<const novatel_oem7_msgs::INSPVA>& _imu_msg2){

        
        double yaw = _imu_msg2->azimuth;
        double roll = 0.0;//msg->orientation.x* M_PI / 180;
        double pitch = 0.0;//fmod(msg->orientation.y + 180, 360) *M_PI/180;
            
        // double yaw = M_PI/2;
        double cr1 = cos(roll*0.5);
        double sr1 = sin(roll*0.5);
        double cp1 = cos(pitch*0.5);
        double sp1 = sin(pitch*0.5);
        double cy1 = cos(yaw*0.5);
        double sy1 = sin(yaw*0.5);
        
        double ori_w = cr1 * cp1 * cy1 + sr1 * sp1 * sy1;
        double ori_x = sr1 * cp1 * cy1 - cr1 * sp1 * sy1;
        double ori_y = cr1 * sp1 * cy1 + sr1 * cp1 * sy1;
        double ori_z = cr1 * cp1 * sy1 - sr1 * sp1 * cy1;   

        sensor_msgs::Imu imu_msg;
        imu_msg =*_imu_msg1;
        imu_msg.orientation.x = ori_x;
        imu_msg.orientation.y = ori_y;
        imu_msg.orientation.z = ori_z;
        imu_msg.orientation.w = ori_w;

        imu_msg.linear_acceleration.x = _imu_msg1->linear_acceleration.x;
        imu_msg.linear_acceleration.y = _imu_msg1->linear_acceleration.y;
        imu_msg.linear_acceleration.z = _imu_msg1->linear_acceleration.z;
        imu_msg.angular_velocity.x = _imu_msg1->angular_velocity.x*0.01;//M_PI/180.0;
        imu_msg.angular_velocity.y = _imu_msg1->angular_velocity.y*0.01;//M_PI/180.0;
        imu_msg.angular_velocity.z = _imu_msg1->angular_velocity.z*0.01;//M_PI/180.0;

        imu_msg.orientation_covariance = _imu_msg1->orientation_covariance;
        

        imu_msg.angular_velocity_covariance = _imu_msg1->angular_velocity_covariance;

        imu_msg.linear_acceleration_covariance = _imu_msg1->linear_acceleration_covariance;                                         

        imu_pub.publish(imu_msg);
    }
    
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "imu_conversion_node");

    Imu_Convertor imu_con;

    ROS_INFO("\033[1;32m---->\033[0m imu_converting Started.");
    ros::spin();

    return 0;
}