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
#include <cstdlib> //getenv()용도
#include <boost/filesystem.hpp>

#define PI 3.14159265


using Eigen::MatrixXf;
using Eigen::JacobiSVD;
using Eigen::VectorXf;

using namespace std;

typedef pcl::PointXYZI  PointType;

const extern int sensor_channel = 32;

const extern double LiDAR_to_GPS = -0.40; //라이다 위치 기준 gnss센서위치

std::string getHomeDirectory()
 {
     const char* homeDir = getenv("HOME");
     if (homeDir == nullptr) {
         std::cerr << "HOME environment variable is not set." << std::endl;
         return "";
     }

     return std::string(homeDir);
}

extern const string homeDirectory = getHomeDirectory();

extern const string fileDirectory = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/maps";

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

pcl::PointCloud<PointType>::Ptr transformPointCloud(pcl::PointCloud<PointType>::Ptr cloudIn, Ego_status& ego_info ){

    pcl::PointCloud<PointType>::Ptr cloudOut(new pcl::PointCloud<PointType>());

    PointType *pointFrom;
    PointType pointTo;

    int cloudSize = cloudIn->points.size();
    cloudOut->resize(cloudSize);
        
    for (int i = 0; i < cloudSize; ++i){

        pointFrom = &cloudIn->points[i];
        float x1 = cos(ego_info.yaw) * pointFrom->x - sin(ego_info.yaw) * pointFrom->y;
        float y1 = sin(ego_info.yaw) * pointFrom->x + cos(ego_info.yaw)* pointFrom->y;
        float z1 = pointFrom->z;

        float x2 = x1;
        float y2 = cos(ego_info.roll) * y1 - sin(ego_info.roll) * z1;
        float z2 = sin(ego_info.roll) * y1 + cos(ego_info.roll)* z1;

        pointTo.x = cos(ego_info.pitch) * x2 + sin(ego_info.pitch) * z2 + ego_info.curr.x;
        pointTo.y = y2 + ego_info.curr.y;
        pointTo.z = -sin(ego_info.pitch) * x2 + cos(ego_info.pitch) * z2 + ego_info.curr.z;

        pointTo.intensity = pointFrom->intensity;

        cloudOut->points[i] = pointTo;
    }
    return cloudOut;
}

double cal_range(PointType point){
    return sqrt(point.x*point.x + point.y*point.y + point.z*point.z);
}

double cal_diff(PointType point){
    return sqrt(point.x*point.x + point.y*point.y);
}

double cal_diff(PointType saved_Cone , PointType detected_Cone){
    double dx = saved_Cone.x - detected_Cone.x;
    double dy = saved_Cone.y - detected_Cone.y; 
    double dz = saved_Cone.z - detected_Cone.z;
        
    return sqrt(dx*dx + dy*dy + dz*dz);
}

double magnitude(const VectorXf& v) {
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

PointType vector2point(const VectorXf& v, PointType start_point){
    PointType tmp_point;
    tmp_point.x = v[0]+start_point.x;
    tmp_point.y = v[1]+start_point.y;
    tmp_point.z = v[2]+start_point.z;

    return tmp_point;
} 
     
VectorXf conduct_PCA (pcl::PointCloud<PointType>::Ptr input_cloud, int num){
    //num = 0이면 주축(분산도가 가장 큰 방향의 벡터를 의미함) , num=2이면 분산도가 가장 작은 방향의 벡터를 의미함

    //covariance matrix 생성
    Eigen::Matrix3f cov_;
    Eigen::Vector4f pc_mean_;
    VectorXf normal_;
    VectorXf singular_values_;
        
    pcl::computeMeanAndCovarianceMatrix(*input_cloud, cov_, pc_mean_);
        
    Eigen::JacobiSVD<Eigen::MatrixXf> svd(cov_, Eigen::DecompositionOptions::ComputeFullU);
    singular_values_ = svd.singularValues();
        
    // use the least singular vector as normal::PCA 수행
    normal_ = (svd.matrixU().col(num));
    if (normal_(2) < 0) { for(int i=0; i<3; i++) normal_(i) *= -1; }
        
    return normal_;// 법선 벡터를 추출
}

#endif
