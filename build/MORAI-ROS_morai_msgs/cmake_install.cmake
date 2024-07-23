# Install script for directory: /home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/jba/2024_SHARK_LiDAR/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/msg" TYPE FILE FILES
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/CtrlCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/EgoVehicleStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/EgoVehicleStatusExtended.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/GPSMessage.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/GhostMessage.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/ObjectStatusList.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/ObjectStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/ObjectStatusExtended.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/ObjectStatusListExtended.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/TrafficLight.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/ERP42Info.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/GetTrafficLightStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SetTrafficLight.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/IntersectionControl.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/IntersectionStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/CollisionData.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MultiEgoSetting.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/IntscnTL.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SensorPosControl.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MoraiSimProcHandle.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MoraiSimProcStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MoraiSrvResponse.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/ScenarioLoad.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MoraiTLIndex.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MoraiTLInfo.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SaveSensorData.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/ReplayInfo.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/EventInfo.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/Lamps.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/VehicleSpec.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/VehicleSpecIndex.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/NpcGhostCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/NpcGhostInfo.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/VehicleCollisionData.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/VehicleCollision.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeAddObject.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeInfo.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/WaitForTickResponse.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeRemoveObject.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeCmdResponse.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/WaitForTick.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MapSpec.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MapSpecIndex.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeCtrlCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeSetGear.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeResultResponse.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SyncModeScenarioLoad.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/RadarDetection.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/RadarDetections.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/PRStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/PRCtrlCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/PREvent.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SkateboardCtrlCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SkateboardStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SkidSteer6wUGVCtrlCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SkidSteer6wUGVStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MultiPlayEventResponse.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/MultiPlayEventRequest.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/DillyCmdResponse.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/DillyCmd.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/WoowaDillyStatus.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/SVADC.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultInjection_Controller.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultInjection_Response.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultInjection_Sensor.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultInjection_Tire.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultStatusInfo_Overall.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultStatusInfo_Sensor.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultStatusInfo_Vehicle.msg"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/msg/FaultStatusInfo.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/srv" TYPE FILE FILES
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiScenarioLoadSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiSimProcSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiTLInfoSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiEventCmdSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiVehicleSpecSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiSyncModeCmdSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiWaitForTickSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiMapSpecSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiSyncModeCtrlCmdSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiSyncModeSetGearSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiSyncModeSLSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/PREventSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiSyncModeAddObjectSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MoraiSyncModeRemoveObjectSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/MultiPlayEventSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/WoowaDillyEventCmdSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/FaultInjectionCtrlSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/FaultInjectionSensorSrv.srv"
    "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/srv/FaultInjectionTireSrv.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/cmake" TYPE FILE FILES "/home/jba/2024_SHARK_LiDAR/build/MORAI-ROS_morai_msgs/catkin_generated/installspace/morai_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/jba/2024_SHARK_LiDAR/devel/include/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/jba/2024_SHARK_LiDAR/devel/share/roseus/ros/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/jba/2024_SHARK_LiDAR/devel/share/common-lisp/ros/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/jba/2024_SHARK_LiDAR/devel/share/gennodejs/ros/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/jba/2024_SHARK_LiDAR/devel/lib/python2.7/dist-packages/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/jba/2024_SHARK_LiDAR/devel/lib/python2.7/dist-packages/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/jba/2024_SHARK_LiDAR/build/MORAI-ROS_morai_msgs/catkin_generated/installspace/morai_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/cmake" TYPE FILE FILES "/home/jba/2024_SHARK_LiDAR/build/MORAI-ROS_morai_msgs/catkin_generated/installspace/morai_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/cmake" TYPE FILE FILES
    "/home/jba/2024_SHARK_LiDAR/build/MORAI-ROS_morai_msgs/catkin_generated/installspace/morai_msgsConfig.cmake"
    "/home/jba/2024_SHARK_LiDAR/build/MORAI-ROS_morai_msgs/catkin_generated/installspace/morai_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs" TYPE FILE FILES "/home/jba/2024_SHARK_LiDAR/src/MORAI-ROS_morai_msgs/package.xml")
endif()

