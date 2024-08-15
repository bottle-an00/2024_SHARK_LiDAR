#include "local/local.h"

using namespace std;

int main(int argc, char** argv){

    ros::init(argc, argv, "Local");
    
    Local local;

    // ros::Rate rate(30);
    // while (ros::ok())
    // {
    //     ros::spinOnce();
        
    //     if(local.gps_init && local.imu_init) {
    //         local.publish_EKF_local(local.prev_imu_msg);
    //     }

    //     rate.sleep();
    // }
    ros::spin();
    return 0;
}