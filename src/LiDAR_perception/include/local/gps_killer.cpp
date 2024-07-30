#include "morai_msgs/GPSMessage.h"
#include <ros/ros.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include <sys/mman.h> // For shared memory

using namespace std;

class gps_killer
{
private:
    ros::NodeHandle nh;
    ros::Publisher pub_gps;
    ros::Subscriber sub_gps;

    morai_msgs::GPSMessage data;
    
    bool GPS_kill_sign =false;

public:
    gps_killer():
        nh("~"){
            sub_gps = nh.subscribe<morai_msgs::GPSMessage>("/gps",10, &gps_killer::GPSHandler,this);
            pub_gps = nh.advertise<morai_msgs::GPSMessage>("/gps_test", 1000);
    }

    ~gps_killer(){};

    void GPSHandler(morai_msgs::GPSMessage gps_msg){
        data = gps_msg;

        if(GPS_kill_sign){
            data.latitude =0.0;
            data.longitude =0.0;
        }

    }

    void pubInfo(){
        pub_gps.publish(data);
    }

    void setFlag(bool sign){
        if(sign){
            this->GPS_kill_sign = true;
            cout << "kill_gps" << endl;
        }else{
            this->GPS_kill_sign = false;
            cout << "GPS working" << endl;
        }
    }

};


int main(int argc, char** argv){


    pid_t pid;
    string input;
    bool* sign_ptr; 
    sign_ptr = (bool*)mmap(NULL, sizeof(bool), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    *sign_ptr = false;
    
    if (sign_ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    if( (pid = fork()) < 0 ){
        fprintf(stderr, "fork error\n");
        exit(1);
    }


    if(pid != 0){

        while(1){
            cin >> input;
            if(input == "1"){
                if (*sign_ptr) {
                    *sign_ptr = false;
                }
                else {
                    *sign_ptr = true;
                    cout << "GPS killer activated " <<  endl;
                }
            }
        } 
    }

    else{
        ros::init(argc, argv, "GPS_KILLER");

        gps_killer GK;
        ros::Rate rate(30);

        while (ros::ok())
        {
            GK.setFlag(*sign_ptr);
                        
            ros::spinOnce();

            GK.pubInfo();

            rate.sleep();
        }
        
    }
    
    

    return 0; 
}