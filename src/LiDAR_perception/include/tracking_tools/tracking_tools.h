#ifndef _TRACKING_TOOLS_
#define _TRACKING_TOOLS_

#include "perception/data_struction.h"

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

    double iou_threshold;

public:
    tracking_tools(){};
    ~tracking_tools(){};

    void preprocessing(vector<Object_info>& Object_DB){
        detected_object_cloud.reset(new pcl::PointCloud<PointType>());
        detected_object_cloud->clear();

        for(auto& object : Object_DB){
            PointType object_pt;
            object_pt = object.mid_point;
            object_pt.intensity = static_cast<float>(object.id);

            detected_object_cloud->push_back(object.mid_point);
        }

        //kdtree 생성
        obj_kdtree.setInputCloud(detected_object_cloud);
    }

    double intersection_area(const bbox_2D& rect1, const bbox_2D& rect2) {
        double x_left = std::max(rect1.minP[0], rect2.minP[0]);
        double y_bottom = std::min(rect1.minP[1], rect2.minP[1]);

        double x_right = std::min(rect1.maxP[0], rect2.maxP[0]);
        double y_top = std::max(rect1.maxP[1], rect2.maxP[1]);

        if (x_right < x_left || y_bottom > y_top) {
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

        if (union_val == 0.0) {
            return 0.0;
        }
        else{
            return inter_val/union_val; 
        }
    }

    void process_matching(vector<Object_info>& detected_obj, vector<Object_info>& Object_DB, vector<int>& id_list){
        
        if(Object_DB.size() > 0){
            preprocessing(Object_DB);
            
            for(auto& object : detected_obj){
                //가장 가까운 물체 info 탐색
                std::vector<int> indices;
                std::vector<float> distances;
                obj_kdtree.nearestKSearch(object.mid_point, 1 ,indices, distances);
                
                int obj_id;

                if(distances[0] < 2){
                    int id_  = static_cast<int>(detected_object_cloud->points[indices[0]].intensity);
                    //cal_iou
                    if(cal_iou(object,Object_DB, id_) > iou_threshold) {

                        //db의 pointcloud를 현재 detected된 object의 cloud에 registraction

                        pcl::IterativeClosestPoint<PointType, PointType> icp;
                        icp.setInputSource(Object_DB[id_].obj_cloud);
                        icp.setInputTarget(object.obj_cloud);//고정된(현재 object의 pointcloud)

                        pcl::PointCloud<PointType> output_cloud;
                        icp.align(output_cloud);

                        //

                        //object의 정보 update (min point, max point update)

                        PointType minPoint,maxPoint;
                        pcl::getMinMax3D(output_cloud, minPoint, maxPoint);
                        Object_DB[id_].min_point = minPoint;
                        Object_DB[id_].max_point = maxPoint;

                        *(Object_DB[id_].obj_cloud) = output_cloud;
                        //

                        obj_id = id_;
                    }else{
                        //새로운 object 추가
                        Object_DB[current_max_id+1] = object;
                        obj_id = current_max_id+1;
                        current_max_id++;
                    } 
                }else{
                    //새로운 object 추가
                    Object_DB[current_max_id+1] = object;
                    obj_id = current_max_id+1;
                    
                    current_max_id++;
                }

                id_list.push_back(obj_id);
                
            }
        }
    }

};

#endif