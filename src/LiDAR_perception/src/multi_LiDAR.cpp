#include "calibration/multiLidarCalibration.h"

using namespace std;

int main(int argc, char** argv){

    ros::init(argc, argv, "LiDAR_Calibration");
    
    MultiLiDARCalibration MC;

    ROS_INFO("\033[1;32m---->\033[0m LiDAR Clibration Node Started.");

    ros::spin();
    return 0;
}