#!/usr/bin/env python3

#rosrun으로 실행했을때 위의 !/usr/bin/env python3를 !/usr/bin/env python로 한다면 python2버전으로 실행하는 것이 되어 오류가 발생할 수도 있음
#추가로 roslaunch로 실행했을 때 위의 이유로 프로세스가 죽어버리기도 한다. 

import rospy
from sensor_msgs.msg import PointCloud2, PointField
import sensor_msgs.point_cloud2 as pc2
import open3d as o3d
import numpy as np
import os


def read_pcd_file(pcd_file):
    # Check if the file exists
    if os.path.exists(pcd_file):
        # Read the point cloud using Open3D
        cloud = o3d.io.read_point_cloud(pcd_file)
        points = np.asarray(cloud.points)
        
        # Define the fields for the PointCloud2 message
        fields = [
            PointField('x', 0, PointField.FLOAT32, 1),
            PointField('y', 4, PointField.FLOAT32, 1),
            PointField('z', 8, PointField.FLOAT32, 1),
        ]
        
        # Create the header
        header = rospy.Header()
        header.stamp = rospy.Time.now()
        header.frame_id = "map"

        # Create the PointCloud2 message
        point_cloud_msg = pc2.create_cloud(header, fields, points)
        return point_cloud_msg
    else:
        rospy.logerr(f"PCD file {pcd_file} does not exist")
        return None

def main():
    try:
        rospy.init_node('multi_pcd_publisher', anonymous=True)

        home_dir = os.path.expanduser("~")
        directory = home_dir + "/2024_SHARK_LiDAR/src/LiDAR_perception/maps/filtered/"

        pcd_files = [f for f in os.listdir(directory) if f.endswith('.pcd')]

        pcd_files_path = [directory + pcd_files[i] for i in range(len(pcd_files))]


        pub1 = rospy.Publisher("HD_MAP/"+pcd_files[0].split('.')[0], PointCloud2, queue_size=10)
        pub2 = rospy.Publisher("HD_MAP/"+pcd_files[1].split('.')[0], PointCloud2, queue_size=10)
        pub3 = rospy.Publisher("HD_MAP/"+pcd_files[2].split('.')[0], PointCloud2, queue_size=10)
        
        rospy.Rate(0.01)
        
        while not rospy.is_shutdown():
            pub1.publish(read_pcd_file(pcd_files_path[0]))
            pub2.publish(read_pcd_file(pcd_files_path[1]))
            pub3.publish(read_pcd_file(pcd_files_path[2]))

    except rospy.ROSInterruptException:
        pass


if __name__ == '__main__':
    main()