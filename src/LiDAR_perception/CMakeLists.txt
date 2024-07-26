cmake_minimum_required(VERSION 3.0.2)

project(LiDAR_perception)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  pcl_ros
  pcl_conversions
  geometry_msgs
  morai_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES LiDAR_perception
  CATKIN_DEPENDS roscpp rospy std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(main src/main.cpp )
add_dependencies(main ${catkin_EXPORTED_TARGETS})
target_link_libraries(main ${catkin_LIBRARIES}${PCL_LIBRARIES})

add_executable(local src/local.cpp )
add_dependencies(local ${catkin_EXPORTED_TARGETS})
target_link_libraries(local ${catkin_LIBRARIES}${PCL_LIBRARIES})

add_executable(gpslam include/gpslam/PC_processing.cpp )
add_dependencies(gpslam ${catkin_EXPORTED_TARGETS})
target_link_libraries(gpslam ${catkin_LIBRARIES}${PCL_LIBRARIES})

add_executable(point_clicker src/point_clicker.cpp )
add_dependencies(point_clicker ${catkin_EXPORTED_TARGETS} ${PCL_LIBRARIES} ${OpenCV_LIBS})
target_link_libraries(point_clicker ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${OpenCV_LIBS} pcl_visualization)

catkin_install_python(PROGRAMS
  scripts/pub_map.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)