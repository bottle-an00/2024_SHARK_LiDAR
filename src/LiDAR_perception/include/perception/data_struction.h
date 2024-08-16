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
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/sample_consensus_prerejective.h>

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

#include <nlohmann/json.hpp>

#define PI 3.14159265


using Eigen::MatrixXf;
using Eigen::JacobiSVD;
using Eigen::VectorXf;

using json = nlohmann::json;
using namespace std;

typedef pcl::PointXYZI  PointType;

const extern int sensor_channel = 32;

const extern double LiDAR_to_GPS = -0.40; //라이다 위치 기준 gnss센서위치
const extern double LiDAR_Height = 1.25;
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

extern const string map_file_path = homeDirectory + "/2024_SHARK_LiDAR/src/LiDAR_perception/path/seongnam_final_global_path.json";

struct Ego_status{
    bool is_initialize = false;
    /*x,y는 동일, z는 yaw를 의미*/
    PointType curr;
    
    double roll;
    double pitch;
    double yaw;
};

struct Object_info{
    int id;

    double heading;

    pcl::PointCloud<PointType>::Ptr obj_cloud; // 물체 기준 좌표계에서 물체에 해당하는 pointcloud

    PointType min_point;    
    PointType max_point;
    PointType mid_point;    
};

struct path_info{
    vector<VectorXf> position;
};

void read_path(path_info& path_info) {

    std::ifstream file(map_file_path);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    json root;
    file >> root;

    file.close();

    if (!root.is_object()) {
        std::cerr << "Invalid JSON format. Root must be an object." << std::endl;
        return;
    }

    path_info.position.resize(root.size());
    
    size_t index = 0;
    
    for (auto it = root.begin(); it != root.end(); ++it) {
        if (!it.value().is_array() || it.value().size() < 3) {
            std::cerr << "Invalid JSON format. Each element must be an array of at least 3 elements." << std::endl;
            return;
        }
        index = std::stoi(it.key());
        path_info.position[index] = VectorXf(3);
        path_info.position[index][0] = it.value()[0].get<double>();
        path_info.position[index][1] = it.value()[1].get<double>();
        path_info.position[index][2] = index;
    }

    std::cout << "Coordinates saved successfully. Size :: " << path_info.position.size() << std::endl;
}

int index_finder(path_info path_info, Ego_status ego_info, int& cur_idx, Ego_status& next_N_index_pos, int N){
    int k = path_info.position.size();
    double min_dist = 100;
    int index = -1;
    int step_size = 8000;
    if(k >0){
        for(int i = std::max(cur_idx - step_size, 0); i < std::min(k, cur_idx + step_size); ++i) {
            double dist = sqrt((ego_info.curr.x - path_info.position[i][0])*(ego_info.curr.x - path_info.position[i][0])
                + (ego_info.curr.y - path_info.position[i][1])*(ego_info.curr.y - path_info.position[i][1]));
            if(dist < min_dist){
                index = path_info.position[i][2];
                min_dist = (dist);
            }
        }
    }

    if(index + N < (k-1) ){
        next_N_index_pos.curr.x = path_info.position[index + N][0];
        next_N_index_pos.curr.y = path_info.position[index + N][1];
    }else{
        next_N_index_pos.curr.x = path_info.position[k-1][0];
        next_N_index_pos.curr.y = path_info.position[k-1][1];
    }  
    return index;
}

pcl::PointCloud<PointType>::Ptr transformPointCloud(pcl::PointCloud<PointType>::Ptr cloudIn, Ego_status& ego_info){

    pcl::PointCloud<PointType>::Ptr cloudOut(new pcl::PointCloud<PointType>());

    PointType *pointFrom;
    PointType pointTo;

    int cloudSize = cloudIn->points.size();
    cloudOut->resize(cloudSize);
        
    for (int i = 0; i < cloudSize; ++i){

        pointFrom = &cloudIn->points[i];
        
        pointFrom->x += LiDAR_to_GPS;
        
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
double cal_diff(Ego_status ego_info , VectorXf idx_loc){
    double dx = ego_info.curr.x - idx_loc[0];
    double dy = ego_info.curr.y - idx_loc[1]; 
        
    return sqrt(dx*dx + dy*dy);
}

double magnitude(const VectorXf& v) {
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[1] * v[1]);
}

PointType vector2point(const VectorXf& v, PointType start_point){
    PointType tmp_point;
    tmp_point.x = v[0]+start_point.x;
    tmp_point.y = v[1]+start_point.y;
    tmp_point.z = v[1]+start_point.z;

    return tmp_point;
} 

double do_dot_product(PointType point, Ego_status ego_info){
    PointType thisPoint;
    thisPoint.x = point.x - ego_info.curr.x;
    thisPoint.y = point.y - ego_info.curr.y;

    PointType refPoint;
    refPoint.x = cos(ego_info.yaw);
    refPoint.y = sin(ego_info.yaw);

    double output = thisPoint.x*refPoint.x + thisPoint.y*refPoint.y;

    return output;

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
    if (normal_(1) < 0) { for(int i=0; i<3; i++) normal_(i) *= -1; }
        
    return normal_;// 법선 벡터를 추출
}


void clustering(pcl::PointCloud<PointType>::Ptr input_cloud, vector<pcl::PointCloud<PointType>::Ptr>& output_cloud_vec,
    double clusterTolerance, int minSize , int maxSize){
        
    int clusternum =1;
        
    std::vector<int> indice;
    pcl::removeNaNFromPointCloud(*input_cloud,*input_cloud,indice);
    pcl::PointCloud<PointType>::Ptr downsampled_cloud(new pcl::PointCloud<PointType>);
        
    pcl::VoxelGrid<PointType> sor;
    sor.setInputCloud(input_cloud);  // 입력 클라우드 설정
    sor.setLeafSize(.2f, .2f, .05f);  // Voxel 크기 설정 (x, y, z)
    //다운샘플링을 수행
    sor.filter(*downsampled_cloud);

    if (downsampled_cloud->points.size() > 0){
        pcl::search::KdTree<pcl::PointXYZI>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZI>);
        tree->setInputCloud(downsampled_cloud);
        std::vector<pcl::PointIndices> clusterIndices;
        pcl::EuclideanClusterExtraction<pcl::PointXYZI> ec;
        ec.setClusterTolerance(clusterTolerance);
        ec.setMinClusterSize(minSize);
        ec.setMaxClusterSize(maxSize);
        ec.setSearchMethod(tree);
        ec.setInputCloud(downsampled_cloud);
        ec.extract(clusterIndices);

        for (std::vector<pcl::PointIndices>::const_iterator it = clusterIndices.begin (); it != clusterIndices.end (); ++it)
        {
            pcl::PointCloud<PointType>::Ptr ClusterCloud(new pcl::PointCloud<PointType>);
            for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); ++pit)
            {   

                pcl::PointXYZI pt = downsampled_cloud->points[*pit];
                if(maxSize == 800) pt.intensity = 10*clusternum;
                ClusterCloud->points.push_back(pt);
            }
            clusternum++;

            output_cloud_vec.push_back(ClusterCloud);
        }       
    }
        
}

#endif
