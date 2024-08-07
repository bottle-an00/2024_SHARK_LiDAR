#include <ros/ros.h>
#include <iostream>

using namespace std;

class status_manager
{
private:
    ros::NodeHandle nh;

    /*ndt_localization 관련*/
    bool ndt_working = false;
    double ndt_process_time = 0.0;

    /*patchwork++ 관련*/
    bool patchworkpp_working = false;
    double patchworkpp_process_time = 0.0;

    /*multi LiDAR Calbration 관련*/
    bool multi_LiDAR_Calibration_working = false;

    /*local 관련*/
    bool local_working = false;

    double ego_location_x =0.0; 
    double ego_location_y =0.0; 
    int currnet_index=0;

    /*Lidar perception 관련*/
    bool OD_working =false;
    double OD_process_time = 0.0;

public:
    status_manager():
        nh("~"){
        
    };

    void check_status(){

        nh.getParam("/ndt_working", ndt_working);
        nh.getParam("/ndt_process_time", ndt_process_time);

        nh.getParam("/patchworkpp_working", patchworkpp_working);
        nh.getParam("/patchworkpp_process_time", patchworkpp_process_time);

        nh.getParam("/multi_LiDAR_Calibration_working", multi_LiDAR_Calibration_working);

        nh.getParam("/local_working", local_working);
        nh.getParam("/ego_location_x", ego_location_x);
        nh.getParam("/ego_location_y", ego_location_y);
        nh.getParam("/currnet_index", currnet_index);

        nh.getParam("/OD_working", OD_working);
        nh.getParam("/OD_process_time", OD_process_time);

    }

    void print_status(){

        ROS_INFO_STREAM("\033[1;32m"<< endl 
        << "NDT_Localization :: " << (ndt_working ? "ON" : "OFF") <<endl
        << "NDT Process Time :: " << ndt_process_time << endl<<endl
        
        << "Patchworkpp :: " << (patchworkpp_working ? "ON" : "OFF") << endl
        << "Patworkpp Process Time :: " << patchworkpp_process_time << endl 
        
        << "Multi LiDAR Process :: " << (multi_LiDAR_Calibration_working ? "ON" : "OFF") << endl<<endl
        
        << "Local Process :: " << (local_working ? "ON":"OFF") << endl
        << "Ego Position :: { " << ego_location_x << " , " << ego_location_y << " } " << endl
        << "Ego Current :: " << currnet_index << endl<<endl

        << "Object Detection working :: " << (OD_working ? "ON" : "OFF" )<<endl
        << "Object Process Time :: " << OD_process_time << endl 
        << "\033[0m");
    }

    ~status_manager(){};
};



int main(int argc, char** argv){

    ros::init(argc, argv, "Status_Manager");
    
    status_manager SM;

    ros::Rate rate(10);

    while(ros::ok()){
        
        SM.check_status();

        SM.print_status();

        ros::spinOnce();
        
        rate.sleep();
    }

    return 0;
}
