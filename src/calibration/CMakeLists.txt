cmake_minimum_required(VERSION 3.0.2)
project(calibration)

find_package(catkin REQUIRED COMPONENTS
  tf
  roscpp
  rospy
  cv_bridge
  image_transport

  pcl_ros
  pcl_conversions

  std_msgs
  sensor_msgs
  geometry_msgs
  nav_msgs
)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package(GTSAM REQUIRED QUIET)
find_package(PCL REQUIRED QUIET)
find_package(OpenCV REQUIRED QUIET)

catkin_package(
  INCLUDE_DIRS include
  DEPENDS PCL
)

include_directories(
	include
	${catkin_INCLUDE_DIRS}
	${PCL_INCLUDE_DIRS}
	${OpenCV_INCLUDE_DIRS}
	${GTSAM_INCLUDE_DIR}
)

link_directories(
	include
	${OpenCV_LIBRARY_DIRS}
	${PCL_LIBRARY_DIRS}
	${GTSAM_LIBRARY_DIRS}
)

add_executable(cloud_maker src/cloud_maker.cpp)
target_link_libraries(cloud_maker ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(sync src/synchronizor.cpp)
target_link_libraries(sync ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(rotator src/pointcloud_rotator.cpp)
target_link_libraries(rotator ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${OpenCV_LIBRARIES})


add_executable(imu src/convert_imu_jj.cpp)
target_link_libraries(imu ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(imu_jba src/convert_imu_jba.cpp)
target_link_libraries(imu_jba ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${OpenCV_LIBRARIES})