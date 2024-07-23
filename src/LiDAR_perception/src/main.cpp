#include "perception/object_detection.h"

using namespace std;

int main(int argc, char** argv){

    ros::init(argc, argv, "LiDAR");
    
    Object_Detection OD;

    ROS_INFO("\033[1;32m---->\033[0m LiDAR Node Started.");

    ros::spin();
    return 0;
}