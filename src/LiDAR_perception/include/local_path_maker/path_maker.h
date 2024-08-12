#ifndef _PATH_MAKER_
#define _PATH_MAKER_

#include <opencv2/opencv.hpp>
#include <queue>
#include <unordered_map>
#include <vector>
#include <cmath>
#include "perception/data_struction.h"

using namespace std;
using namespace cv;

class Path_maker {
public:
    Path_maker(const Mat& costMat) : cost_mat(costMat) {}
    
    Point find_goal() {
        Point goal_pixel = start_pixel;
    
        Point up = Point(0, -1);    // 위의 픽셀 방향으로 이동
        Point right = Point(1, 0);  // 오른쪽 픽셀 방향으로 이동
        Point left = Point(-1, 0);  // 왼쪽 픽셀 방향으로 이동

        while (true) {
            if (goal_pixel.y <= 0) {// 위쪽 끝에 도달
                return goal_pixel;
            }

            if (goal_pixel.y > 0 && cost_mat.at<int>(goal_pixel + up) == 0) {// 위로 이동
                goal_pixel += up;
                traj.push_back(goal_pixel);

            } else {//위로 못가면
                turn_idx.push_back(traj.size()-1);//방향 전환 지점 index 저장

                bool moved_right = false;
                while (goal_pixel.x < cost_mat.cols - 1 && cost_mat.at<int>(goal_pixel + right) == 0) {// 오른쪽으로 최대한 이동
                    goal_pixel += right;
                    moved_right = true;
                    traj.push_back(goal_pixel);
                }

                
                if (goal_pixel.x >= cost_mat.cols - 1) {// 오른쪽 끝에 도달이면 종료
                    return goal_pixel; 
                }
                turn_idx.push_back(traj.size()-1);//방향 전환 지점 index 저장


                if (moved_right && goal_pixel.y > 0 && cost_mat.at<int>(goal_pixel + up) == 0) {// 오른쪽 끝 x 도달 상태에서 위로
                    goal_pixel += up;
                    traj.push_back(goal_pixel);
                } else {//위로 못가면 
                    turn_idx.push_back(traj.size()-1);//방향 전환 지점 index 저장

                    bool moved_left = false;
                    while (goal_pixel.x > 0 && cost_mat.at<int>(goal_pixel + left) == 0) {//왼쪽으로 이동
                        goal_pixel += left;
                        traj.push_back(goal_pixel);
                        moved_left = true;
                    }
                    
                    if (goal_pixel.x <= 0) {// 왼쪽 끝에 도달이면 종료
                        return goal_pixel;
                    }
                    turn_idx.push_back(traj.size()-1);//방향 전환 지점 index 저장

                   
                    if (moved_left && goal_pixel.y > 0 && cost_mat.at<int>(goal_pixel + up) == 0) {// 위로 갈 수 있으면 위로 이동 
                        goal_pixel += up;
                        traj.push_back(goal_pixel);
                    } else {
                        
                        return goal_pixel;
                    }
                }
            }

        }
        
    }

    vector<Point> apply_Bezier_Curves(pcl::PointCloud<PointType>::Ptr path_PC){
        vector<Point> output;
        
        turn_idx.erase(unique(turn_idx.begin(), turn_idx.end()) ,turn_idx.end());
        
        if(turn_idx.size() == 0 ){

            for(auto points : traj){

                PointType thisPoint;

                thisPoint.x = points.x;
                thisPoint.y = points.y;

                path_PC->push_back(thisPoint);

            }

            return traj;
        }

        else{
            
            vector<int> control_pt_idx;
            vector<Point> target_part;
            
            int prev_idx;

            control_pt_idx.resize(3);

            for(vector<int>::iterator iter = turn_idx.begin(); iter != turn_idx.end(); iter++){
                
                int interval = ( next(iter) == turn_idx.end() ? 
                (traj.size() - (*(iter)+1))     :   (*(next(iter)) - *(iter)) ) ;  

                if(iter == turn_idx.begin()){// 처음 출발 부분에서만 직선을 추가 
                    for(int i =0; i < *(iter) - (interval/2)-10 ; i++){
                        output.push_back(traj[i]);
                        
                        PointType thisPoint;
                        thisPoint.x = traj[i].x; thisPoint.y = traj[i].y;

                        path_PC->push_back(thisPoint);
                    }

                    control_pt_idx[0] = ( (*(iter) - interval/2 < 0) ? 0 : *(iter) - interval/2 - 10 );

                }else{
                    control_pt_idx[0] = prev_idx;

                }

                control_pt_idx[1] = *(iter);
                control_pt_idx[2] = *(iter) + interval/2;
                
                vector<Point> p = {traj[control_pt_idx[0]], traj[control_pt_idx[1]], traj[control_pt_idx[2]]};
                
                quadraticBezier(p[0], p[1], p[2], target_part, path_PC);
                prev_idx = control_pt_idx[2];
            }
            
        }
        return output;
    }

    void quadraticBezier(const Point& P0, const Point& P1, const Point& P2, vector<Point>& curve, pcl::PointCloud<PointType>::Ptr path_PC, int num_segments = 100) {
        
        for (int i = 0; i <= num_segments; ++i) {
            double t = (double)i / num_segments;
            double one_minus_t = 1.0 - t;

            double x = (one_minus_t * one_minus_t) * P0.x + 2 * one_minus_t * t * P1.x + (t * t) * P2.x;
            double y = (one_minus_t * one_minus_t) * P0.y + 2 * one_minus_t * t * P1.y + (t * t) * P2.y;

            curve.push_back(Point((int)x, (int)y));
            
            PointType thisPoint;
            thisPoint.x = x; thisPoint.y = y;

            path_PC->push_back(thisPoint);
        }
    }

    Point getStartPixel(){
        return start_pixel;
    }

    vector<Point> getTracjectory(){
        return traj;
    }

private:
    
    Point start_pixel = Point(100,200);

    Mat cost_mat;

    vector<Point> traj;

    vector<int> turn_idx;
};

#endif