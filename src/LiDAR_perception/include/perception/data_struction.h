#ifndef _UTILITY_LIDAR_ODOMETRY_H_
#define _UTILITY_LIDAR_ODOMETRY_H_


#include <ros/ros.h>

#include <sensor_msgs/PointCloud2.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/range_image/range_image.h>
#include <pcl/filters/filter.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/common/common.h>
#include <pcl/registration/icp.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/segmentation/extract_clusters.h>
#include <sensor_msgs/point_cloud2_iterator.h>
#include <pcl/registration/icp.h>

#include <visualization_msgs/MarkerArray.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <vision_msgs/Detection2DArray.h>
#include <nav_msgs/Path.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <iterator>
#include <unordered_set>
#include <ctime>
#include <chrono>

#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

#include <tf2_msgs/TFMessage.h>
#include <Eigen/Geometry>

#define PI 3.14159265


using Eigen::MatrixXf;
using Eigen::JacobiSVD;
using Eigen::VectorXf;
using namespace std;

typedef pcl::PointXYZI  PointType;

const extern int sensor_channel = 32;

extern const string fileDirectory = "/home/jba/shark_ws/maps";

struct Ego_status{
    bool is_initialize = false;
    /*x,y는 동일, z는 yaw를 의미*/
    PointType prev;
    PointType curr;
    
    double roll;
    double pitch;
    double yaw;
};

struct Object_info{
    int id;
    PointType min_point;    
    PointType max_point;
    PointType mid_point;    
};


#endif
