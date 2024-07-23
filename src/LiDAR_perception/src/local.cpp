#include "local/local.h"

using namespace std;

int main(int argc, char** argv){

    ros::init(argc, argv, "Local");
    
    Local local;

    ROS_INFO("\033[1;32m---->\033[0m Local Node Started.");

    ros::spin();
    return 0;
}