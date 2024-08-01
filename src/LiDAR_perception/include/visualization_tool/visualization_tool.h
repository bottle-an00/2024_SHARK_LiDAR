#ifndef _VISAULIZATION_TOOL_
#define _VISAULIZATION_TOOL_

#include <visualization_msgs/MarkerArray.h>

#include <visualization_msgs/Marker.h>

#include <geometry_msgs/PoseStamped.h>

#include <geometry_msgs/Pose.h>

#include <vision_msgs/Detection2DArray.h>

#include <vector>

#include <iostream>

#include "perception/data_struction.h"

#include <ros/ros.h>

#include "RCA/Ray_Casting_Algorithm.h"

using namespace std;

class Visualization_tool
{
private:
    /* data */
public:

    Visualization_tool(){};

    ~Visualization_tool(){};

    void visual_object_center(vector<Object_info> obj_center_point, visualization_msgs::MarkerArray& cone_center_markerarray, string frame_id){
        //visual marker
        visualization_msgs::Marker marker;
        int id_ =0;
        for(const auto& obj : obj_center_point){            
            marker.header.frame_id = frame_id;
            marker.header.stamp = ros::Time().now();
            marker.ns ="cone's center point";
            marker.id = id_;
            
            //cout << "marker id :: " << marker.id <<endl;
            marker.type = visualization_msgs::Marker::SPHERE; 
            marker.action = visualization_msgs::Marker::ADD;
            marker.pose.position.x = obj.mid_point.x;
            marker.pose.position.y = obj.mid_point.y;
            marker.pose.position.z = obj.mid_point.z;
            
            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;
            
            marker.scale.x = 0.5;
            marker.scale.y = 0.5;
            marker.scale.z = 0.5;

            marker.color.r = 1.0;
            marker.color.g = 1.0;
            marker.color.b = 1.0;
            marker.color.a = 1;
            marker.lifetime = ros::Duration(0.11);

            cone_center_markerarray.markers.push_back(marker);

            id_++;

        }
    }
     void visual_vector(PointType start_position, PointType end_position,float r, float g, float b, int Id,vector<Object_info> obj_center_point, visualization_msgs::MarkerArray& normal_vectors, string frame_id){
        //visual marker
        
        for(vector<Object_info>::const_iterator iter = obj_center_point.begin();iter != obj_center_point.end();iter++){
            visualization_msgs::Marker marker;
            
            marker.header.frame_id = frame_id;
            marker.header.stamp = ros::Time().now();
            marker.ns ="vector";
            marker.id = Id;
            
            marker.type = visualization_msgs::Marker::ARROW; 
            marker.action = visualization_msgs::Marker::ADD;

            geometry_msgs::Point start_point;
            start_point.x = start_position.x;
            start_point.y = start_position.y;
            start_point.z = start_position.z;

            geometry_msgs::Point end_point;
            end_point.x = end_position.x;
            end_point.y = end_position.y;
            end_point.z = end_position.z;

            marker.points.push_back(geometry_msgs::Point());
            marker.points[0] = start_point;
            marker.points.push_back(geometry_msgs::Point()); 
            marker.points[1] = end_point;

            marker.pose.orientation.x = 0.0;
            marker.pose.orientation.y = 0.0;
            marker.pose.orientation.z = 0.0;

            marker.scale.x = 0.05;
            marker.scale.y = 0.1;

            marker.color.r = r;
            marker.color.g = g;
            marker.color.b = b;
            marker.color.a = 1;
            marker.lifetime = ros::Duration(0.2);

            normal_vectors.markers.push_back(marker);

        }
    }

    geometry_msgs::Point make_Geo_Point(float x, float y, float z){
        geometry_msgs::Point point;
        
        point.x = x;
        point.y = y;
        point.z = z;
        
        return point;
    }

    void visual_cones_boundary(vector<Object_info> obj_center_point, visualization_msgs::MarkerArray& cone_boundary_markerarray, string frame_id){
        //visual marker
        visualization_msgs::Marker marker;
        int Id=1000;
      
        for(vector<Object_info>::const_iterator iter = obj_center_point.begin();iter != obj_center_point.end();iter++){
            
            marker.header.frame_id = frame_id;
            marker.header.stamp = ros::Time().now();
            marker.id =  Id;
            
            marker.type = visualization_msgs::Marker::LINE_LIST; // 선 리스트 유형
            marker.action = visualization_msgs::Marker::ADD;
            marker.scale.x = 0.02; // 선의 두께

            geometry_msgs::Point minPoint;
            minPoint.x = iter->min_point.x;
            minPoint.y = iter->min_point.y;
            minPoint.z = iter->min_point.z;

            geometry_msgs::Point maxPoint;
            maxPoint.x = iter->max_point.x;
            maxPoint.y = iter->max_point.y;
            maxPoint.z = iter->max_point.z;

            // 바운딩 박스를 구성하는 선들을 추가
            marker.points.push_back(minPoint);
            marker.points.push_back(make_Geo_Point(minPoint.x, minPoint.y, maxPoint.z));

            marker.points.push_back(minPoint);
            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y, minPoint.z));

            marker.points.push_back(minPoint);
            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y, minPoint.z));

            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y, minPoint.z));
            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y, maxPoint.z));

            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y, minPoint.z));
            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y, maxPoint.z));

            marker.points.push_back(make_Geo_Point(minPoint.x, minPoint.y, maxPoint.z));
            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y, maxPoint.z));

            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y, maxPoint.z));
            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y, maxPoint.z));

            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y, maxPoint.z));
            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y, maxPoint.z));

            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y, minPoint.z));
            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y, minPoint.z));

            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y, minPoint.z));
            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y, minPoint.z));

            marker.points.push_back(make_Geo_Point(minPoint.x, minPoint.y, maxPoint.z));
            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y, maxPoint.z));

            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y, minPoint.z));
            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y, maxPoint.z));

            marker.color.r = 1.0;
            marker.color.g = 1.0;
            marker.color.b = 0.0;
            marker.color.a = 1;
            marker.lifetime = ros::Duration(0.11);

            Id++;
            cone_boundary_markerarray.markers.push_back(marker);

        }
    }
    
    void visual_kalman_info_kf(vector<int>& id_list, vector<VectorXd>& pred_position, vector<Object_info>& Object_BD, visualization_msgs::MarkerArray& markerarray){
        //visual marker
        
        for(const auto& id : id_list){            
            if(pred_position[id].size()>0){
                visualization_msgs::Marker marker_arrow;
                visualization_msgs::Marker marker;
                visualization_msgs::Marker marker_num;

                // marker.header.frame_id = cloudHeader.frame_id;
                marker.header.frame_id = "map";
                marker.header.stamp = ros::Time().now();
                marker.ns ="cone's center point";
                marker.id = 10*id;
                float Nsec =0.5;

                marker.type = visualization_msgs::Marker::CUBE; 
                marker.action = visualization_msgs::Marker::ADD;
                marker.pose.position.x = pred_position[id][0];//+Nsec*pred_position[id][2];
                marker.pose.position.y = pred_position[id][1];//+Nsec*pred_position[id][3];
                marker.pose.position.z = 0.0;
                marker.pose.orientation.x = 0.0;
                marker.pose.orientation.y = 0.0;
                marker.pose.orientation.z = 0.0;

                marker.scale.x = 0.8;
                marker.scale.y = 0.8;
                marker.scale.z = 0.8;

                marker.color.r = 1.0;
                marker.color.g = 1.0;
                marker.color.b = 1.0;
                marker.color.a = 1;
                marker.lifetime = ros::Duration(0.11);
                markerarray.markers.push_back(marker);

                // marker.id = 10*id + 1;
                // marker.pose.position.x = pred_position[id][0]+2*Nsec*pred_position[id][2];
                // marker.pose.position.y = pred_position[id][1]+2*Nsec*pred_position[id][3];
                // markerarray.markers.push_back(marker);

                // marker.id = 10*id + 2;
                // marker.pose.position.x = pred_position[id][0]+3*Nsec*pred_position[id][2];
                // marker.pose.position.y = pred_position[id][1]+3*Nsec*pred_position[id][3];
                // markerarray.markers.push_back(marker);

                // marker_num.header.frame_id = cloudHeader.frame_id;
                marker_num.header.frame_id = "map";
                marker_num.header.stamp = ros::Time().now();
                marker_num.id = 20000 + id;
                marker_num.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
                marker_num.action = visualization_msgs::Marker::ADD;
                marker_num.pose.position.x = pred_position[id][0];
                marker_num.pose.position.y = pred_position[id][1];
                marker_num.pose.position.z = 0.0;
                marker_num.text = "OBJ Id:: " + to_string(id);
                marker_num.color.r = 1;
                marker_num.color.g = 1;
                marker_num.color.b = 0;
                marker_num.color.a = 1;
                marker_num.scale.z = 1;
                marker_num.lifetime = ros::Duration(0.11);

                markerarray.markers.push_back(marker_num);

                // // marker_arrow.header.frame_id = cloudHeader.frame_id;
                // marker_arrow.header.frame_id = "map";
                // marker_arrow.header.stamp = ros::Time().now();
                // marker_arrow.id = 40000 + 10*id;
                // marker_arrow.type = visualization_msgs::Marker::LINE_LIST;
                // marker_arrow.action = visualization_msgs::Marker::ADD;
                // geometry_msgs::Point start_p, end_p;
                // start_p.x = pred_position[id][0];
                // start_p.y = pred_position[id][1];
                // marker_arrow.points.push_back(start_p);
                 
                // end_p.x = pred_position[id][0]+Nsec*pred_position[id][2];
                // end_p.y = pred_position[id][1]+Nsec*pred_position[id][3];
                // marker_arrow.points.push_back(end_p);
                // marker_arrow.pose.orientation.w = 1.0;

                // marker_arrow.color.r = 1;
                // marker_arrow.color.g = 1;
                // marker_arrow.color.b = 0;
                // marker_arrow.color.a = 1;
                // marker_arrow.scale.x = 0.1; // 선의 두께

                // marker_arrow.lifetime = ros::Duration(0.11);
                // markerarray.markers.push_back(marker_arrow);
                
                // marker_arrow.id = 40000 + 10*id+1;
                // start_p.x = pred_position[id][0]+Nsec*pred_position[id][2];
                // start_p.y = pred_position[id][1]+Nsec*pred_position[id][3];
                // marker_arrow.points.push_back(start_p);

                // end_p.x = pred_position[id][0]+2*Nsec*pred_position[id][2];
                // end_p.y = pred_position[id][1]+2*Nsec*pred_position[id][3];
                // marker_arrow.points.push_back(end_p);
                // markerarray.markers.push_back(marker_num);

                // marker_arrow.id = 40000 + 10*id+2;
                // start_p.x = pred_position[id][0]+2*Nsec*pred_position[id][2];
                // start_p.y = pred_position[id][1]+2*Nsec*pred_position[id][3];
                // marker_arrow.points.push_back(start_p);

                // end_p.x = pred_position[id][0]+3*Nsec*pred_position[id][2];
                // end_p.y = pred_position[id][1]+3*Nsec*pred_position[id][3];
                // marker_arrow.points.push_back(end_p);
            }
        }
    }

    void visual_EKF_OBJ_boundary(vector<int>& id_list, vector<Object_info>& Object_BD, visualization_msgs::MarkerArray& obj_boundary_markerarray){
        //visual marker
        for(auto id : id_list){
            visualization_msgs::Marker marker;
            
            marker.header.frame_id = "map";
            marker.header.stamp = ros::Time().now();
            marker.id = id;
            
            marker.type = visualization_msgs::Marker::LINE_LIST; // 선 리스트 유형
            marker.action = visualization_msgs::Marker::ADD;
            marker.scale.x = 0.1; // 선의 두께

            geometry_msgs::Point minPoint;
            minPoint.x = Object_BD[id].min_point.x;
            minPoint.y = Object_BD[id].min_point.y;

            geometry_msgs::Point maxPoint;
            maxPoint.x = Object_BD[id].max_point.x;
            maxPoint.y = Object_BD[id].max_point.y;

            // 바운딩 박스를 구성하는 선들을 추가
            marker.points.push_back(make_Geo_Point(minPoint.x, minPoint.y,0.0));
            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y,0.0));

            marker.points.push_back(make_Geo_Point(minPoint.x, minPoint.y,0.0));
            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y,0.0));

            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y,0.0));
            marker.points.push_back(make_Geo_Point(maxPoint.x, minPoint.y,0.0));

            marker.points.push_back(make_Geo_Point(maxPoint.x, maxPoint.y,0.0));
            marker.points.push_back(make_Geo_Point(minPoint.x, maxPoint.y,0.0));

            marker.color.r = 1.0;
            marker.color.g = 1.0;
            marker.color.b = 0.0;
            marker.color.a = 1;
            marker.lifetime = ros::Duration(0.11);

            obj_boundary_markerarray.markers.push_back(marker);

        }
    }

    void nearestNInnerZone_visualization(visualization_msgs::MarkerArray& nearest_Inner_Lines, vector<Polygon>& nearestInners){
        int id=0;
        for(auto inner : nearestInners){
            int inner_start =id;
            getPolygonInfo(id,nearest_Inner_Lines,inner, inner_start, 0.0, 0.0, 1.0);
        }
    }

    void ROIzonevisualization(visualization_msgs::MarkerArray& RCA_Lines ,Polygon &outer, vector<Polygon>& Inners){

        int id =0; 
        getPolygonInfo(id, RCA_Lines,outer);
        
        for(auto inner : Inners){
            int inner_start =id;
            getPolygonInfo(id, RCA_Lines,inner, inner_start);
        }
        
    }

    void getPolygonInfo(int& id, visualization_msgs::MarkerArray& RCA_Lines ,Polygon &zone, int start_num =0, float r = 1.0, float g = 1.0 ,float b = 0.0){
        geometry_msgs::Point first_points;

        for(vector<Point>::const_iterator iter = zone.vertices.begin();iter != zone.vertices.end();iter++){
            visualization_msgs::Marker line_strip;
            line_strip.header.frame_id = "map";
            line_strip.header.stamp = ros::Time::now();
            line_strip.ns = "polygons";
            line_strip.action = visualization_msgs::Marker::ADD;
            line_strip.pose.orientation.w = 1.0;
            line_strip.id = id;
            line_strip.type = visualization_msgs::Marker::LINE_STRIP;

            line_strip.scale.x = 0.5;

            line_strip.color.r = r;
            line_strip.color.g = g;
            line_strip.color.b = b;
            line_strip.color.a = 1.0;

            geometry_msgs::Point p;
            p.x = iter->x;
            p.y = iter->y;
            p.z = 0.0;  // 2D plane, z=0
            line_strip.points.push_back(p);
            if(id-start_num ==0 ) first_points = p;

            vector<Point>::const_iterator next_iter = ++iter;
            if(next_iter !=  zone.vertices.end()){
                geometry_msgs::Point next_p;
                next_p.x = next_iter->x;
                next_p.y = next_iter->y;
                next_p.z = 0.0;
                line_strip.points.push_back(next_p);
            }else{
                line_strip.points.push_back(first_points);
            }

            iter--;
            
            RCA_Lines.markers.push_back(line_strip);
            
            id++;
        }
    }
};


#endif