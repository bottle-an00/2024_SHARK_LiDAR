#include "local/local.h"
#include "local/local_gt.h"

using namespace std;

int main(int argc, char** argv){

    ros::init(argc, argv, "Local_Test");
    
    Local_gt local_gt;
    Local local;

    ros::spin();
    return 0;
}