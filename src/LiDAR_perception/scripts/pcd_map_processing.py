#!/usr/bin/env python3

import open3d as o3d
import numpy as np
import os

def change_coordinate(file_path):
    pcd_map = o3d.io.read_point_cloud(file_path)

    # PCD 데이터를 numpy 배열로 변환
    point_cloud_np = np.asarray(pcd_map.points)

    # 좌표 순서 바꾸기 (x, y, z -> z, x, y)
    point_cloud_np[:, [0, 1, 2]] = point_cloud_np[:, [0, 1, 2]]

    # 변경된 데이터를 다시 PCD로 변환
    new_pcd_map = o3d.geometry.PointCloud()
    new_pcd_map.points = o3d.utility.Vector3dVector(point_cloud_np)

    return new_pcd_map


def roi_z(pcd_map_data,min_z):
    
    point_cloud_np = np.asarray(pcd_map_data.points)
    
    roi_indices = np.where((point_cloud_np[:, 2] >= min_z))

    roi_pcd_data = pcd_map_data.select_by_index(roi_indices[0])
    
    return roi_pcd_data


def remove_statistical_outliers(pcd, nb_neighbors=50, std_ratio=90.0):

    cl, ind = pcd.remove_statistical_outlier(nb_neighbors=nb_neighbors, std_ratio=std_ratio)

    inlier_cloud = pcd.select_by_index(ind)

    outlier_cloud = pcd.select_by_index(ind, invert=True)

    return inlier_cloud, outlier_cloud


def remove_radius_outliers(pcd, nb_points=16, radius=0.05):

    cl, ind = pcd.remove_radius_outlier(nb_points=nb_points, radius=radius)

    inlier_cloud = pcd.select_by_index(ind)

    outlier_cloud = pcd.select_by_index(ind, invert=True)

    return inlier_cloud, outlier_cloud


def main():
    home_dir = os.path.expanduser("~")

    directory = home_dir + "/2024_SHARK_LiDAR/src/LiDAR_perception/maps/"

    pcd_files = [f for f in os.listdir(directory) if f.endswith('.pcd')]
    print(pcd_files)
    merged_pcd = o3d.geometry.PointCloud()

    for file in pcd_files:
        filepath = os.path.join(directory, file)

        new_pcd_map = change_coordinate(filepath)
        if file == 'NongroundMap.pcd' or file == 'Ground.pcd':
            print(file)
            merged_pcd += new_pcd_map
        if file == "NongroundMap.pcd":
            new_pcd_map = roi_z(new_pcd_map,-1.7)
        new_pcd_map, _ = remove_statistical_outliers(new_pcd_map) 
        
        
        # 새로운 PCD 파일로 저장
        new_pcd_file = directory + "filtered/filtered_" + file 
        o3d.io.write_point_cloud(new_pcd_file,new_pcd_map)

    merged_pcd_file = directory + "/merged_map.pcd" 
    o3d.io.write_point_cloud(merged_pcd_file,merged_pcd)
    print("finish converting")


if __name__ == "__main__":
    main()

