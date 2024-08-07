#ifndef _TRACKING_TOOLS_
#define _TRACKING_TOOLS_

#include "perception/data_struction.h"
#include "perception/fixedQueue.h"

using FeatureType = pcl::FPFHSignature33;

struct bbox_2D
{
    vector<double> minP;
    vector<double> maxP;
};

class tracking_tools
{
private:
    pcl::KdTreeFLANN<PointType> obj_kdtree;

    pcl::PointCloud<PointType>::Ptr detected_object_cloud;

    int current_max_id = 0; //처음 init될 때는 0 점점 추가하는 형식

    double iou_threshold = 0.05;

    bool first_tracking = true;

public:
    tracking_tools(){};
    ~tracking_tools(){};

    void preprocessing(vector<Object_info>& Object_DB){
        detected_object_cloud.reset(new pcl::PointCloud<PointType>());
        detected_object_cloud->clear();

        int i=0;
        
        for(auto& object : Object_DB){

            if(i > current_max_id) break;
            
            object.mid_point.intensity = static_cast<float>(object.id);
            
            detected_object_cloud->push_back(object.mid_point);
            
            i++;
        }
        
        //kdtree 생성
        obj_kdtree.setInputCloud(detected_object_cloud);
    }

    double intersection_area(const bbox_2D& rect1, const bbox_2D& rect2) {
        
        double x_left = std::max(rect1.minP[0], rect2.minP[0]);
        double y_bottom = std::max(rect1.minP[1], rect2.minP[1]);

        double x_right = std::min(rect1.maxP[0], rect2.maxP[0]);
        double y_top = std::min(rect1.maxP[1], rect2.maxP[1]);

        if (x_right < x_left || y_top < y_bottom) {
            return 0.0f;
        }

        return (x_right - x_left) * (y_top - y_bottom);
    }

    double union_area(const bbox_2D& rect1, const bbox_2D& rect2, float inter_area) {

        double area1 = (rect1.maxP[0] - rect1.minP[0]) * (rect1.maxP[1] - rect1.minP[1]);
        
        double area2 = (rect2.maxP[0] - rect2.minP[0]) * (rect2.maxP[1] - rect2.minP[1]);

        return area1 + area2 - inter_area;
    }

    double cal_iou(Object_info object, vector<Object_info>& Object_DB, int id){
        bbox_2D object_bbox, target_bbox;//target_bbox는 DB에 저장되어있는 object의 bbox
        object_bbox.minP.resize(2);object_bbox.maxP.resize(2);
        target_bbox.minP.resize(2);target_bbox.maxP.resize(2);
        
            
        object_bbox.minP[0] = object.min_point.x; object_bbox.minP[1] = object.min_point.y;
        object_bbox.maxP[0] = object.max_point.x; object_bbox.maxP[1] = object.max_point.y;

        target_bbox.minP[0] = Object_DB[id].min_point.x; target_bbox.minP[1] = Object_DB[id].min_point.y;
        target_bbox.maxP[0] = Object_DB[id].max_point.x; target_bbox.maxP[1] = Object_DB[id].max_point.y;

        double inter_val = intersection_area(object_bbox,target_bbox);
        double union_val = union_area(object_bbox,target_bbox, inter_val);
        cout << "id " << id <<"result " <<  inter_val/union_val << endl;
        if (union_val == 0.0) {
            return 0.0;
        }
        else{
            return inter_val/union_val; 
        }
    }

    Eigen::Matrix4f computeInverseRT(const Eigen::Matrix4f& M) {

        Eigen::Matrix3f R = M.block<3, 3>(0, 0);
        Eigen::Vector3f T = M.block<3, 1>(0, 3);
    
        Eigen::Matrix3f R_transpose = R.transpose();
        Eigen::Vector3f T_inverse = -R_transpose * T;
    
        Eigen::Matrix4f M_inverse = Eigen::Matrix4f::Identity();
        M_inverse.block<3, 3>(0, 0) = R_transpose;
        M_inverse.block<3, 1>(0, 3) = T_inverse;
    
        return M_inverse;
    }

    void applyRTToPointCloud(pcl::PointCloud<PointType>::Ptr& pointCloud, const Eigen::Matrix4f& RT) {

        for (auto& point : pointCloud->points) {

            // 동차 좌표로 변환
            Eigen::Vector4f homogenousPoint(point.x, point.y, point.z, 1.0f);

            // RT 행렬 적용
            Eigen::Vector4f transformedPoint = RT * homogenousPoint;

            // 카티지안 좌표로 변환
            point.x = transformedPoint(0);
            point.y = transformedPoint(1);
            point.z = transformedPoint(2);
        }
    }



    void computeNormals(pcl::PointCloud<PointType>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals) {
        pcl::NormalEstimation<PointType, pcl::Normal> ne;
        ne.setInputCloud(cloud);
        pcl::search::KdTree<PointType>::Ptr tree(new pcl::search::KdTree<PointType>());
        ne.setSearchMethod(tree);
        ne.setRadiusSearch(0.03);
        ne.compute(*normals);
    }

    void computeFPFHFeatures(pcl::PointCloud<PointType>::Ptr cloud, pcl::PointCloud<pcl::Normal>::Ptr normals, pcl::PointCloud<FeatureType>::Ptr features) {
        pcl::FPFHEstimation<PointType, pcl::Normal, FeatureType> fpfh;
        fpfh.setInputCloud(cloud);
        fpfh.setInputNormals(normals);
        pcl::search::KdTree<PointType>::Ptr tree(new pcl::search::KdTree<PointType>());
        fpfh.setSearchMethod(tree);
        fpfh.setRadiusSearch(0.05);
        fpfh.compute(*features);
    }
    
    void process_matching(vector<Object_info>& detected_obj, vector<Object_info>& Object_DB, vector<int>& id_list){
        
        if(first_tracking){
            int count =0;

            for(auto object : detected_obj){
                object.id = count;
                Object_DB[object.id] = object;
                count++;
            }

            first_tracking =false;
            
        }else{

            preprocessing(Object_DB);
            
            for(auto& object : detected_obj){
                //가장 가까운 물체 info 탐색
                std::vector<int> indices;
                std::vector<float> distances;
                obj_kdtree.nearestKSearch(object.mid_point, 1 ,indices, distances);

                int obj_id;

                if(distances[0] < 5){
                    int id_  = static_cast<int>(detected_object_cloud->points[indices[0]].intensity);

                    // if(cal_iou(object,Object_DB, id_) > 0) {

                        Object_DB[id_].min_point = object.min_point;
                        Object_DB[id_].max_point = object.max_point;

                        Object_DB[id_].mid_point.x = (object.max_point.x + object.min_point.x)/2;
                        Object_DB[id_].mid_point.y = (object.max_point.y + object.min_point.y)/2;
                        Object_DB[id_].mid_point.z = (object.max_point.z + object.min_point.z)/2;

                        obj_id = id_;

                    // }else{
                    //     //새로운 object 추가
                    //     obj_id = current_max_id+1;

                    //     object.id =obj_id;
                    //     Object_DB[obj_id] = object;
                    //     current_max_id++;
                    // }

                }else{
                    //새로운 object 추가
                    obj_id = current_max_id+1;

                    object.id =obj_id;
                    Object_DB[current_max_id+1] = object;
                    
                    current_max_id++;
                }

                id_list.push_back(obj_id);
                
            }
        }
    }

};

#endif