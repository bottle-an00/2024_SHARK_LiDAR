#!/usr/bin/env python
import rospy
from sensor_msgs.msg import PointCloud2
import sensor_msgs.point_cloud2 as pc2
import pcl
import os

def read_pcd_file(pcd_file):
    
    if os.path.exists(pcd_file):
        cloud = pcl.load(pcd_file)
        point_cloud_msg = PointCloud2()
        
        header = point_cloud_msg.header
        header.stamp = rospy.Time.now()
        header.frame_id = "map"  

        pcd_data = pc2.create_cloud_xyz32(header, cloud.to_array())
        return pcd_data

def main():
    try:
        directory = "/home/jba/2024_SHARK_LiDAR/maps/filtered/"

        pcd_files = [f for f in os.listdir(directory) if f.endswith('.pcd')]

        pcd_files_path = [directory + pcd_files[i] for i in range(len(pcd_files))]

        rospy.init_node('multi_pcd_publisher', anonymous=True)

        pub1 = rospy.Publisher("HD_MAP/"+pcd_files[0].split('.')[0], PointCloud2, queue_size=10)
        pub2 = rospy.Publisher("HD_MAP/"+pcd_files[1].split('.')[0], PointCloud2, queue_size=10)
        pub3 = rospy.Publisher("HD_MAP/"+pcd_files[2].split('.')[0], PointCloud2, queue_size=10)
        
        rospy.Rate(0.01)
        
        while not rospy.is_shutdown():
            print("----HD_map publining------")
            pub1.publish(read_pcd_file(pcd_files_path[0]))
            pub2.publish(read_pcd_file(pcd_files_path[1]))
            pub3.publish(read_pcd_file(pcd_files_path[2]))

    except rospy.ROSInterruptException:
        pass


if __name__ == '__main__':
    main()