#include "perception/data_struction.h"
#include "path_maker.h"
// #include "visualization_tool/visualization_tool.h"

#include <opencv2/opencv.hpp>
#include <ros/ros.h>
#include <pcl_ros/point_cloud.h>
#include <sensor_msgs/PointCloud2.h>
#include <nav_msgs/Path.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/conversions.h>
#include <thread>
#include <mutex>

class local_path_maker
{
private:
    ros::NodeHandle nh;
    ros::Subscriber subNonGroundCloud;
    ros::Publisher pubPreprocessedCloud;
    ros::Publisher pubPathCloud;
    ros::Publisher pubPath;

    pcl::PointCloud<PointType>::Ptr groundCloudIn;
    pcl::PointCloud<PointType>::Ptr nongroundCloudIn;
    pcl::PointCloud<PointType>::Ptr preprocessedCloud;
    pcl::PointCloud<PointType>::Ptr pathCloud;

    std_msgs::Header cloudHeader;
    cv::Mat cost_mat;
        
    int cost_mat_row = 200; // 전방 20m (10cm단위, x와 연관)
    int cost_mat_col = 201; // 좌우 50개씩 (y와 연관)

    std::mutex image_mutex; 
    bool update_image = false; 

    vector<Point> path_vec;
    
    // Visualization_tool Vt;
    
public:
    local_path_maker() : nh("~")
    {
        subNonGroundCloud = nh.subscribe<sensor_msgs::PointCloud2>("/ground_segmentation/nonground", 1, &local_path_maker::cloudHandler, this);

        pubPreprocessedCloud = nh.advertise<sensor_msgs::PointCloud2>("/preprocessed_pointcloud", 1);
        pubPathCloud = nh.advertise<sensor_msgs::PointCloud2>("/path_pointcloud", 1);
        
        pubPath = nh.advertise<nav_msgs::Path>("local_path", 1);
        
        allocateMemory();
        std::thread(&local_path_maker::visualizeImage, this).detach();
        resetParameters();
    }

    void allocateMemory()
    {
        groundCloudIn.reset(new pcl::PointCloud<PointType>());
        nongroundCloudIn.reset(new pcl::PointCloud<PointType>());
        preprocessedCloud.reset(new pcl::PointCloud<PointType>());
        pathCloud.reset(new pcl::PointCloud<PointType>());
        cost_mat = cv::Mat(cost_mat_col,cost_mat_row, CV_32SC1, cv::Scalar::all(0));
    }

    void resetParameters()
    {
        groundCloudIn->clear();
        nongroundCloudIn->clear();
        preprocessedCloud->clear();
        pathCloud->clear();
        cost_mat = cv::Mat(cost_mat_col,cost_mat_row, CV_32SC1, cv::Scalar::all(0));
    }

    ~local_path_maker() {}

    void cloudHandler(const sensor_msgs::PointCloud2ConstPtr &laserCloudMsg)
    {
        auto start_time = std::chrono::high_resolution_clock::now();

        copyPointCloud(laserCloudMsg);

        preprocessing();

        make_path();

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        ros::NodeHandle tmp_nh;
        tmp_nh.setParam("/local_path_maker_process_time", static_cast<double>(duration.count()));

        publish_info();
        
        // Notify the image visualization thread to update the image
        {
            std::lock_guard<std::mutex> lock(image_mutex);
            update_image = true;
        }

        // Wait for the visualization thread to finish before resetting parameters
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Adjust sleep duration if needed
        resetParameters();
    }

    void copyPointCloud(const sensor_msgs::PointCloud2ConstPtr &laserCloudMsg)
    {
        cloudHeader = laserCloudMsg->header;
        cloudHeader.frame_id = "base_link";
        cloudHeader.stamp = ros::Time::now();
        pcl::fromROSMsg(*laserCloudMsg, *nongroundCloudIn);
        std::vector<int> indices;
        pcl::removeNaNFromPointCloud(*nongroundCloudIn, *nongroundCloudIn, indices);
    }

    void preprocessing()
    {
        pcl::PointCloud<PointType>::Ptr downsampled_cloud(new pcl::PointCloud<PointType>);
        pcl::VoxelGrid<PointType> sor;
        sor.setInputCloud(nongroundCloudIn);
        sor.setLeafSize(0.10f, 0.10f, 0.10f);
        sor.filter(*downsampled_cloud);

        size_t cloud_size = downsampled_cloud->points.size();

        for (size_t i = 0; i < cloud_size; i++)
        {
            PointType thisPoint = downsampled_cloud->points[i];

            if (thisPoint.z < (-1 * (LiDAR_Height + 0.2)))
            {
                continue;
            }

            if (abs(thisPoint.y) < ((cost_mat_col-1)/10)/2 && thisPoint.x > 1.5 && thisPoint.x < (cost_mat_row/10) )
            {
                thisPoint.z = 0; // 2D로 변환

                int row_idx = -1 * static_cast<int>(thisPoint.x * 10) + cost_mat_row;
                int col_idx = -1 * static_cast<int>(thisPoint.y * 10) + cost_mat_col/2;

                thisPoint.x = row_idx;
                thisPoint.y = col_idx;

                preprocessedCloud->push_back(thisPoint);

                if ((row_idx <= cost_mat_row && row_idx >= 0) && (col_idx <= cost_mat_col && col_idx >= 0))
                {
                    cost_mat.at<int>(row_idx, col_idx) = 255;
                    set9x9Region(cost_mat, row_idx, col_idx);
                }
            }
        }// 이미지 생성 프로세스 종료

    }

    void set9x9Region(cv::Mat& img, int row, int col) {
        int regionSize = 21;
        int halfSize = regionSize / 2;

        int top = max(row - halfSize, 0);
        int bottom = min(row + halfSize + 1, img.rows);
        int left = max(col - halfSize, 0);
        int right = min(col + halfSize + 1, img.cols);

        img(cv::Rect(left, top, right - left, bottom - top)) = (255);
    }

    void make_path(){
        
        Path_maker path_m(cost_mat);
        
        cv::Point_<int> start_px = path_m.getStartPixel();
        cv::Point_<int> goal_px = path_m.find_goal();
        vector< cv::Point> traj = path_m.getTracjectory();
        
        vector< cv::Point> smooth_curve;
        
        smooth_curve = path_m.apply_Bezier_Curves(pathCloud);
        
        cost_mat.at<int>(start_px) = 150;
        cost_mat.at<int>(goal_px) = 150;
        
        cout << "path_vec size :: " << smooth_curve.size() << endl;
        
        size_t vec_size = traj.size();
        
        for(int i = 0; i < vec_size; i ++){
            cost_mat.at<int>(traj[i]) = 150;
        }

    }

    void publish_info()
    {
        sensor_msgs::PointCloud2 laserCloudTemp;

        if (pubPreprocessedCloud.getNumSubscribers() != 0)
        {
            pcl::toROSMsg(*preprocessedCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "base_link";
            pubPreprocessedCloud.publish(laserCloudTemp);
        }
        if (pubPathCloud.getNumSubscribers() != 0)
        {
            pcl::toROSMsg(*pathCloud, laserCloudTemp);
            laserCloudTemp.header.stamp = cloudHeader.stamp;
            laserCloudTemp.header.frame_id = "base_link";
            pubPathCloud.publish(laserCloudTemp);
        }
        if(pubPath.getNumSubscribers() !=0)
        {
            publish_local_path(pathCloud,pubPath);
        }
    }

    void publish_local_path(pcl::PointCloud<PointType>::Ptr path_PC, ros::Publisher& pub) {

        nav_msgs::Path path_msg;
        path_msg.header.stamp = ros::Time::now();
        path_msg.header.frame_id = "base_link";

        size_t cloud_size = path_PC->points.size();

        for (int i = 0; i < cloud_size; i++) {
            geometry_msgs::PoseStamped pose_stamped;
            pose_stamped.header.stamp = ros::Time::now();
            pose_stamped.header.frame_id = "base_link";
            pose_stamped.pose.position.x = 0.1*(200 - path_PC->points[i].y);
            pose_stamped.pose.position.y = 0.1*(100 - path_PC->points[i].x);
            pose_stamped.pose.position.z = 0.0;
            pose_stamped.pose.orientation.w = 1.0; // Default orientation

            path_msg.poses.push_back(pose_stamped);
        }

        pub.publish(path_msg);
    }

    void visualizeImage()
    {
        while (ros::ok())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Short sleep to avoid high CPU usage

            {
                std::lock_guard<std::mutex> lock(image_mutex);
                if (update_image)
                {
                    cv::Mat display_mat;
                    cv::Mat resized_mat;

                    cost_mat.convertTo(display_mat, CV_8UC1, 1); // Adjust scaling if necessary
                    std::cout << "Image size: " << cost_mat.size() << std::endl;
                    cv::resize(display_mat, resized_mat, cv::Size(), 5, 5, cv::INTER_NEAREST);

                    cv::imshow("Binary Image", resized_mat);
                    cv::waitKey(1); // 비동기적으로 키 입력을 대기

                    update_image = false;
                }
            }
        }
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "local_path_maker");
    local_path_maker lpm;
    ros::spin();
    return 0;
}
