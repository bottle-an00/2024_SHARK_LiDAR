#include "local/local.h"

using namespace std;

int main(int argc, char** argv){

    ros::init(argc, argv, "Local");
    
    Local local;

    ros::spin();
    return 0;
}