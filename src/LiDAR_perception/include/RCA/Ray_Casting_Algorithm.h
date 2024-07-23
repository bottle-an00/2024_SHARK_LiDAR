#ifndef _RAY_CASTING_ALGORITHM_
#define _RAY_CASTING_ALGORITHM_

#include <iostream>
#include <vector>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

struct Point {
    double x, y;
};

struct Polygon {
    std::vector<Point> vertices;
};

class Ray_Casting_Algorithm
{
private:
    /* data */
public:
    Ray_Casting_Algorithm(){};

    ~Ray_Casting_Algorithm(){};

    Polygon readPolygon(string file_path){

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
                points.vertices.push_back(point);
            }
        }
        // 파일 스트림 닫기
        input_file.close();

        return points;
    }
    
    Polygon readOuterPolygon(){

        Polygon output_Polygon = readPolygon("/home/jba/shark_ws/src/LiDAR_perception/include/RCA/Outer.txt");

        cout << "Outer::" << "point num :: " << output_Polygon.vertices.size() << endl;

        return output_Polygon;
    }

    vector<Polygon> readInnerPolygon(){

        vector<Polygon> innerPolygon;

        string folder_path = "/home/jba/shark_ws/src/LiDAR_perception/include/RCA/Inner/";

        for (const auto& entry : fs::directory_iterator(folder_path)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".txt") {
                innerPolygon.push_back(readPolygon(entry.path().string()));
            }
        }
        cout <<"Inner" <<"zone :: " << innerPolygon.size() << endl;
        return innerPolygon;
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
};

#endif