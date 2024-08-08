#include "data_struction.h"
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
    ros::Publisher pubPath;

    pcl::PointCloud<pcl::PointXYZ>::Ptr groundCloudIn;
    pcl::PointCloud<pcl::PointXYZ>::Ptr nongroundCloudIn;
    pcl::PointCloud<pcl::PointXYZ>::Ptr preprocessedCloud;

    std_msgs::Header cloudHeader;
    cv::Mat cost_mat;
    
    int cost_mat_row = 200;//전방 20m (10cm단위, x와 연관)
    int cost_mat_col = 101;//좌우 50개씩 (y와 연관)

    std::mutex image_mutex; 
    bool update_image = false; 

public:
    local_path_maker() : nh("~")
    {
        subNonGroundCloud = nh.subscribe<sensor_msgs::PointCloud2>("/ground_segmentation/nonground", 1, &local_path_maker::cloudHandler, this);

        pubPreprocessedCloud = nh.advertise<sensor_msgs::PointCloud2>("/preprocessed_pointcloud", 1);

        pubPath = nh.advertise<nav_msgs::Path>("local_path", 1);

        allocateMemory();
        resetParameters();

        std::thread(&local_path_maker::visualizeImage, this).detach();
    }

    void allocateMemory()
    {
        groundCloudIn.reset(new pcl::PointCloud<pcl::PointXYZ>());
        nongroundCloudIn.reset(new pcl::PointCloud<pcl::PointXYZ>());
        preprocessedCloud.reset(new pcl::PointCloud<pcl::PointXYZ>());
        cost_mat = cv::Mat(cost_mat_row, cost_mat_col, CV_32SC1, cv::Scalar::all(255));
    }

    void resetParameters()
    {
        groundCloudIn->clear();
        nongroundCloudIn->clear();
        
        preprocessedCloud->clear();

        cost_mat = cv::Mat(cost_mat_row, cost_mat_col, CV_32SC1, cv::Scalar::all(255));

    }

    ~local_path_maker() {}

    void cloudHandler(const sensor_msgs::PointCloud2ConstPtr &laserCloudMsg)
    {
        auto start_time = std::chrono::high_resolution_clock::now();

        copyPointCloud(laserCloudMsg);
        preprocessing();

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        ros::NodeHandle tmp_nh;
        tmp_nh.setParam("/local_path_maker_process_time", static_cast<double>(duration.count()));

        publish_info();
        resetParameters();

        // Notify the image visualization thread to update the image
        {
            std::lock_guard<std::mutex> lock(image_mutex);
            update_image = true;
        }
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
        pcl::PointCloud<pcl::PointXYZ>::Ptr downsampled_cloud(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::VoxelGrid<pcl::PointXYZ> sor;
        sor.setInputCloud(nongroundCloudIn);
        sor.setLeafSize(0.10f, 0.10f, 0.10f);
        sor.filter(*downsampled_cloud);

        size_t cloud_size = downsampled_cloud->points.size();

        for (size_t i = 0; i < cloud_size; i++)
        {
            
            pcl::PointXYZ thisPoint = downsampled_cloud->points[i];


            if (thisPoint.z < (-1 * (LiDAR_Height + 0.2)))
            {
                continue;
            }

            if (abs(thisPoint.y) < ((cost_mat_col-1)/10) && thisPoint.x > 0 && thisPoint.x < (cost_mat_row/10) )
            {
                thisPoint.z = 0; // 2D로 변환


                int row_idx = -1 * static_cast<int>(thisPoint.y * 10) + 50;
                int col_idx = -1 * static_cast<int>(thisPoint.x * 10) + 100;
                
                thisPoint.x = col_idx;
                thisPoint.y = row_idx;

                preprocessedCloud->push_back(thisPoint);
                
                if ((row_idx <= 100 && row_idx >= 0) && (col_idx <= 101 && col_idx >= 0))
                {
                    cost_mat.at<int>(row_idx, col_idx) = 0;
                    cout << "row :: " << row_idx << " col :: " << col_idx << " == " << cost_mat.at<int>(row_idx, col_idx) <<endl;
                }
            }
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
    }

    void visualizeImage()
    {
        while (ros::ok())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Short sleep to avoid high CPU usage

            {
                std::lock_guard<std::mutex> lock(image_mutex);
                if (update_image)
                {
                    cv::Mat display_mat;
                    
                    cost_mat.convertTo(display_mat, CV_8UC1, 1);

                    cv::imshow("Binary Image", display_mat);
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
