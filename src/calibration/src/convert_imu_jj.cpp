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

using namespace std;

typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::Imu,sensor_msgs::Imu> MySyncPolicy;
typedef message_filters::Synchronizer<MySyncPolicy> Sync;

class Imu_Convertor{
public:
    ros::NodeHandle nh;
    ros::Publisher imu_pub;
    
    boost::shared_ptr<Sync> sync;
    message_filters::Subscriber<sensor_msgs::Imu> imu_sub1;
    message_filters::Subscriber<sensor_msgs::Imu> imu_sub2;


    Imu_Convertor(){
        imu_pub = nh.advertise<sensor_msgs::Imu>("/imu/quaternion", 1);
        
        imu_sub1.subscribe(nh, "/imu/data_raw", 10);
        imu_sub2.subscribe(nh, "/gps/imu", 10);

        sync.reset(new Sync(MySyncPolicy(100),imu_sub1,imu_sub2 ));
        sync->registerCallback(boost::bind(&Imu_Convertor::imuCallback, this, _1, _2));
    }

    void imuCallback(const boost::shared_ptr<const sensor_msgs::Imu>& _imu_msg1,
    const boost::shared_ptr<const sensor_msgs::Imu>& _imu_msg2){

        
        double ori_w = _imu_msg2->orientation.w;
        double ori_x = _imu_msg2->orientation.x;
        double ori_y = _imu_msg2->orientation.y;
        double ori_z = _imu_msg2->orientation.z;   

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