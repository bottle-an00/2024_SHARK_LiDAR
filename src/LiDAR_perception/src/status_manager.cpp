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

    int contest_status = 0;

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

        nh.getParam("/status", contest_status);


    }

    void print_status(){

        ROS_INFO_STREAM("\033[1;37m"<< endl 
        <<"///////////////////////////////////////////////////" << endl << endl << endl
        
        << "Contest Status :: " << "\033[1;3;33m"<< contest_status << " ms" << endl << "\033[0;1;37m"<<endl << endl

        << "NDT_Localization :: " << "\033[1;3;33m" <<  (ndt_working ? "ON" : "OFF") << "\033[0;1;37m" <<endl
        << "NDT Process Time :: " << "\033[1;3;33m" << ndt_process_time <<" ms" << "\033[0;1;37m" << endl<<endl
        
        << "Patchworkpp :: " << "\033[1;3;33m"<< (patchworkpp_working ? "ON" : "OFF") << "\033[0;1;37m"<< endl
        << "Patchworkpp Process Time :: " << "\033[1;3;33m"<< patchworkpp_process_time <<" ms" << "\033[0;1;37m"<< endl <<endl
        
        << "Multi LiDAR Process :: " << "\033[1;3;33m"<< (multi_LiDAR_Calibration_working ? "ON" : "OFF") << "\033[0;1;37m"<< endl <<endl
        
        << "Local Process :: " << "\033[1;3;33m" << (local_working ? "ON":"OFF") << "\033[0;1;37m"<< endl
        << "Ego Position :: "  << "\033[1;3;33m" << "{ " << ego_location_x << " , " << ego_location_y << " } " << "\033[0;1;37m"<< endl
        << "Ego Current :: "   << "\033[1;3;33m" << currnet_index << "\033[0;1;37m"<< endl<<endl

        << "Object Detection working :: " << "\033[1;3;33m"<< (OD_working ? "ON" : "OFF" )<< "\033[0;1;37m"<<endl
        << "Object Process Time :: " << "\033[1;3;33m"<< OD_process_time << " ms" << endl << "\033[0;1;37m"<<endl << endl

        <<"///////////////////////////////////////////////////" << endl << endl << endl
        << "\033[0m");
    }

    void run(){
        
        check_status();

        print_status();

    }
    
    ~status_manager(){};
};



int main(int argc, char** argv){

    ros::init(argc, argv, "Status_Manager");
    
    status_manager SM;

    ros::Rate rate(10);

    while(ros::ok()){
        
        SM.run();

        ros::spinOnce();
        
        rate.sleep();
    }

    return 0;
}
