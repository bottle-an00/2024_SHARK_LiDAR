#ifndef _RAY_CASTING_ALGORITHM_
#define _RAY_CASTING_ALGORITHM_

#include <iostream>
#include <vector>
#include "perception/data_struction.h"
#include <map>

namespace fs = boost::filesystem;

struct Point {
    double x, y;
};

struct Polygon {
    std::vector<Point> vertices;
    PointType mid_point;
};

class Ray_Casting_Algorithm
{
private:
    /* data */
public:
    Ray_Casting_Algorithm(){};

    ~Ray_Casting_Algorithm(){};

    Polygon readPolygon(string file_path, int mode = 0){

        // 텍스트 파일을 읽기 위한 입력 파일 스트림 객체
        std::ifstream input_file(file_path);

        Polygon points;

        // 입력 파일이 제대로 열렸는지 확인
        if (!input_file.is_open()) {
            std::cerr << "Could not open the file!" << std::endl;
            return points;
        }

        // 점들을 저장할 벡터
        std::string line;

        // 파일의 각 줄을 읽어서 파싱
        while (std::getline(input_file, line)) {
            // 줄 끝 공백 제거
            line.erase(line.find_last_not_of(" \n\r\t")+1);

            // 쉼표로 구분된 값을 파싱
            std::stringstream ss(line);
            std::string item;
            std::vector<std::string> values;
            while (std::getline(ss, item, ',')) {
                values.push_back(item);
            }

            // 점 정보 추출
            if (values.size() == 3) {
                Point point = {std::stod(values[1]), std::stod(values[2]) };

                if(mode ==1 ){
                    points.mid_point.x +=point.x; 
                    points.mid_point.y +=point.y; 
                }

                points.vertices.push_back(point);
            }
        }

        if(mode ==1 ){
            points.mid_point.x /=4;
            points.mid_point.y /=4;
        }

        // 파일 스트림 닫기
        input_file.close();

        return points;
    }

 

    Polygon readOuterPolygon(){

        string home_path = getHomeDirectory();
        
        Polygon output_Polygon = readPolygon(home_path + "/2024_SHARK_LiDAR/src/LiDAR_perception/include/RCA/Outer.txt");

        cout << "Outer::" << "point num :: " << output_Polygon.vertices.size() << endl;

        return output_Polygon;
    }

    vector<Polygon> readInnerPolygon(){

        vector<Polygon> innerPolygon;

        string home_path = getHomeDirectory();

        string folder_path = home_path +  "/2024_SHARK_LiDAR/src/LiDAR_perception/include/RCA/Inner/";

        for (const auto& entry : fs::directory_iterator(folder_path)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".txt") {
                innerPolygon.push_back(readPolygon(entry.path().string()));
            }
        }
        cout <<"Inner" <<"zone :: " << innerPolygon.size() << endl;
        return innerPolygon;
    }
    
    vector<Polygon> readParkingPolygon(){

        vector<Polygon> ParkingPolygon;

        string home_path = getHomeDirectory();

        string folder_path = home_path +  "/2024_SHARK_LiDAR/src/LiDAR_perception/include/RCA/Parking/";

        for (const auto& entry : fs::directory_iterator(folder_path)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".txt") {
                ParkingPolygon.push_back(readPolygon(entry.path().string(),1));
            }
        }
        cout <<"Parking " <<"zone :: " << ParkingPolygon.size() << endl;
        return ParkingPolygon;
    }

    bool onSegment(Point p, Point q, Point r) {
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y))
        return true;
    return false;   
    }

    int orientation(Point p, Point q, Point r) {
        double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0;  // 일직선
        return (val > 0) ? 1 : 2; // 시계 방향 또는 반시계 방향
    }

    bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        // 일반적인 경우
        if (o1 != o2 && o3 != o4)
            return true;

        // 특수한 경우
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;

        return false; // 어떤 경우에도 해당하지 않음
    }

    bool isInsidePolygon(const std::vector<Point>& polygon, Point p) {
        int n = polygon.size();
        if (n < 3) return false; // 다각형은 최소한 3개의 정점을 가져야 함

        Point extreme = {1e9, p.y}; // 오른쪽으로 멀리 떨어진 점

        int count = 0, i = 0;
        do {
            int next = (i + 1) % n;

            if (doIntersect(polygon[i], polygon[next], p, extreme)) {
                if (orientation(polygon[i], p, polygon[next]) == 0)
                    return onSegment(polygon[i], p, polygon[next]);
                count++;
            }
            i = next;
        } while (i != 0);

        return count & 1; // count % 2 == 1 과 동일
    }

    bool isInside(Polygon outer, const std::vector<Polygon>& inners, Point p) {
        // 외부 경계 내부에 있는지 확인
        if (!isInsidePolygon(outer.vertices, p)) {
            return false;
        }

        // 모든 내부 경계를 확인
        for (const auto& inner : inners) {
            if (isInsidePolygon(inner.vertices, p)) {
                return false;
            }
        }

        return true;
    }
    
    vector<Polygon> get_nearest_N_zone(int N, vector<Polygon>& inners, Ego_status& ego_info, int mode = 0){
        map<double,Polygon> inner_zone_info;

        vector<Polygon> output;

        for(auto inner :inners){//각각의 inner zone에 현재 위치에 가장 가까운 점까지의 거리를 추출
            map<double,Point> nearest4points_per_inner_zone;
            
            double min_dst;

            for(auto point : inner.vertices){

                double dst = sqrt((point.x - ego_info.curr.x)*(point.x - ego_info.curr.x) 
                    + (point.y - ego_info.curr.y)*(point.y - ego_info.curr.y));
                
                

                if(mode == 1){
                    PointType tmp;
                    tmp.x =point.x;
                    tmp.y =point.y;

                    if(do_dot_product(tmp,ego_info) > 0){
                        nearest4points_per_inner_zone[dst] = point;
                    }
                    else{
                        break;
                    }
                }else{
                    nearest4points_per_inner_zone[dst] = point;
                }
            }

            auto iter = nearest4points_per_inner_zone.begin();

            min_dst = iter->first;
            
            inner_zone_info[min_dst] = inner;
        }
        
        auto iter = inner_zone_info.begin();

        for(int i =0; i< N; i++){

            if(iter == inner_zone_info.end()) {
                cout << "N over Inner zone number" << endl;
                return output;
            }

            if(mode == 1 && iter->first >10){
                continue;
            }
            output.push_back(iter->second);
            ++iter;

        }

        return output;
    }

    void get_foward_ROI(path_info path, Polygon& roi_points,int current_index, int N, double width){
        
        roi_points.vertices.resize(2*N);

        for (int i = 0; i < N; ++i) {
            int idx = current_index + i;

            if (idx >= path.position.size()) {
                //cout << "Index out of bounds: " << idx << endl;
                break;
            }

            Point thisPoint, nextPoint;
            thisPoint.x = path.position[idx][0];
            thisPoint.y = path.position[idx][1];

            if (idx + 1 < path.position.size()) {
                nextPoint.x = path.position[idx + 1][0];
                nextPoint.y = path.position[idx + 1][1];
            } else {
                nextPoint = thisPoint;
            }

            double dx = nextPoint.x - thisPoint.x;
            double dy = nextPoint.y - thisPoint.y;
            double dst = sqrt(dx * dx + dy * dy);

            if (dst == 0) {
                continue; // Avoid division by zero
            }

            Point new_Point;
            new_Point.x = -width * dy / dst + thisPoint.x;
            new_Point.y =  width * dx / dst + thisPoint.y;
            roi_points.vertices[i] = new_Point;

            new_Point.x =  width * dy / dst + thisPoint.x;
            new_Point.y = -width * dx / dst + thisPoint.y;
            roi_points.vertices[2 * N - 1 - i] = new_Point;
        }

    }

    vector<Polygon> get_available_parking_area(vector<Polygon>& parking_zone, pcl::PointCloud<PointType>::Ptr roi_cloud, Ego_status& ego_info ){

        pcl::KdTreeFLANN<PointType> RPC_kdtree;
        RPC_kdtree.setInputCloud(roi_cloud);

        vector<Polygon> near_ego_parking_zone = get_nearest_N_zone(4,parking_zone,ego_info,1);//가장 가까운 parking zone 4개를 보되 10m이상 떨어진 parking zone에 대해서는 판단하지 않는다.
        
        vector<Polygon> parking_available_area;
        for(auto parking_zone : near_ego_parking_zone){

            bool empty_parkin_zone = true;

            int point_num =5;
            std::vector<int> indices;
            std::vector<float> distances;


            RPC_kdtree.nearestKSearch(parking_zone.mid_point, point_num ,indices, distances);

            for(int i=0;i <point_num; i++){
                Point p = {roi_cloud->points[indices[i]].x, roi_cloud->points[indices[i]].y}; 

                if(isInsidePolygon(parking_zone.vertices, p)){
                    empty_parkin_zone = false;
                    break;
                }
            }

            if(empty_parkin_zone) parking_available_area.push_back(parking_zone);

        }
        return parking_available_area;
    }
    
    void getOutliar(pcl::PointCloud<PointType>::Ptr input_cloud, pcl::PointCloud<PointType>::Ptr output_cloud, Polygon& outer, vector<Polygon>& inners, Ego_status& ego_info){
        
        pcl::PointCloud<PointType>::Ptr downsampled_cloud(new pcl::PointCloud<PointType>);
        
        pcl::VoxelGrid<PointType> sor;
        sor.setInputCloud(input_cloud);  
        sor.setLeafSize(0.10f, 0.10f, 0.10f);  
        
        sor.filter(*downsampled_cloud);

        size_t cloud_size = downsampled_cloud->points.size();

        for(int i = 0; i < cloud_size; i++){    
            Point p = {downsampled_cloud->points[i].x, downsampled_cloud->points[i].y}; 
            
            if(isInsidePolygon(outer.vertices, p)){
                output_cloud->push_back(downsampled_cloud->points[i]);
            }
        }
    }

    void set_ROI_RCA(pcl::PointCloud<PointType>::Ptr input_cloud, pcl::PointCloud<PointType>::Ptr output_cloud, pcl::PointCloud<PointType>::Ptr ndt_cloud, Polygon& outer, vector<Polygon>& inners, Ego_status& ego_info){

        pcl::PointCloud<PointType>::Ptr downsampled_cloud(new pcl::PointCloud<PointType>);
        pcl::PointCloud<PointType>::Ptr near_ego_cloud(new pcl::PointCloud<PointType>);
        
        pcl::VoxelGrid<PointType> sor;
        sor.setInputCloud(input_cloud);  
        sor.setLeafSize(0.10f, 0.10f, 0.10f);  
        
        sor.filter(*downsampled_cloud);


        size_t cloud_size = downsampled_cloud->points.size();

        for(int i = 0; i < cloud_size; i++){
            if(downsampled_cloud->points[i].z < 0.1 && downsampled_cloud->points[i].z > -1 * LiDAR_Height + 0.1 && downsampled_cloud->points[i].x >0){
                if(cal_range(downsampled_cloud->points[i]) < 40 && cal_range(downsampled_cloud->points[i]) > 1.5){
                    near_ego_cloud->push_back(downsampled_cloud->points[i]);
                    downsampled_cloud->points[i].x +=LiDAR_to_GPS;
                    ndt_cloud->push_back(downsampled_cloud->points[i]);

                }
            }
        }
        
        *near_ego_cloud = *transformPointCloud(near_ego_cloud,ego_info);

        cloud_size = near_ego_cloud->points.size();

        for(int i = 0; i < cloud_size; i++){    
            Point p = {near_ego_cloud->points[i].x, near_ego_cloud->points[i].y}; 
            
            if(isInside(outer, inners, p)){
                output_cloud->push_back(near_ego_cloud->points[i]);
            }else{

            }
        }
    }
};

#endif