import rospy
from sensor_msgs.msg import CompressedImage, Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
import os

import os
import sys
import math

import cv2
import numpy as np
from numpy.linalg import inv

import rospy

from cv_bridge import CvBridge, CvBridgeError
import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import CompressedImage , PointCloud2
import math

g_save_rt_toggle = False
g_cmd_toggle = ['rvec',0]
# g_cmd = {'rvec':[0.0, 0.0, -90.0],'t_mat':[ 0.0, -0.85677, -0.26814], 'focal_length':[516.87,486.59], 'lock':[0]}
g_cmd = {'rvec':[0.0, 0.0, -90.0],'t_mat':[ 0.0, -0.85677, -0.0], 'focal_length':[1820.78,1792.51], 'lock':[0]}

# real_K_MAT = [1928, 0,964,0,1208,604,0,0,1]
# real_K_MAT = [2013.07, 0,1003.25,0,2006.52,593.02,0,0,1]
real_K_MAT = [2013.07, 0,640,0,2006.52,360,0,0,1]
intrinsic = real_K_MAT.copy()

init_toggle = True 
t_mat = []
rvec = []
projectionImage = np.zeros((1208,1928))
g_world = []

M_PI  = 3.141592/180

params_lidar = {
    "X": 0.0, # meterx``
    "Y": 0.0,
    "Z": 0.0,
    "YAW": 0.0, # deg
    "PITCH": 0.0,
    "ROLL": 0.0
}

# for front
params_cam = {
    "WIDTH": 1928, # image width
    "HEIGHT": 1208, # image height
    "FOV":60, # Field of view
    "X": -0.0, # meter
    "Y": -0,
    "Z": 0.0,
    "YAW": 0*M_PI, # deg
    "PITCH": 0*M_PI,
    "ROLL": 0*M_PI
}


IS_VIS = sys.argv
CV_BRIDGE = CvBridge() 
TF_BUFFER = None
TF_LISTENER = None

def getRotMat(RPY):
    cosR = math.cos(RPY[0])
    cosP = math.cos(RPY[1])
    cosY = math.cos(RPY[2])
    sinR = math.sin(RPY[0])
    sinP = math.sin(RPY[1])
    sinY = math.sin(RPY[2])
    rotRoll = np.array([1,0,0, 0,cosR,-sinR, 0,sinR,cosR]).reshape(3,3)
    rotPitch = np.array([cosP,0,sinP, 0,1,0, -sinP,0,cosP]).reshape(3,3)
    rotYaw = np.array([cosY,-sinY,0, sinY,cosY,0, 0,0,1]).reshape(3,3)
    
    rotMat = rotYaw.dot(rotPitch.dot(rotRoll))
    return rotMat


def matrixChanger(params_cam, params_lidar):
    lidarPosition = np.array([params_lidar.get(i) for i in (["X","Y","Z"])])
    camPosition = np.array([g_cmd["t_mat"][i] for i in range(3)])

    lidarRPY = np.array([params_lidar.get(i) for i in (["ROLL","PITCH","YAW"])])
    camRPY = np.array([g_cmd["rvec"][i]*M_PI for i in range(3)])
    camRPY = camRPY + np.array([-90*math.pi/180,0,-90*math.pi/180])

    camRot = getRotMat(camRPY)

    camTransl = np.array([camPosition])
    Tr_cam_to_vehicle = np.concatenate((camRot,camTransl.T),axis = 1)
    Tr_cam_to_vehicle = np.insert(Tr_cam_to_vehicle, 3, values=[0,0,0,1],axis = 0)
    
    lidarRot = getRotMat(lidarRPY)
    lidarTransl = np.array([lidarPosition])
    Tr_lidar_to_vehicle = np.concatenate((lidarRot,lidarTransl.T),axis = 1)
    Tr_lidar_to_vehicle = np.insert(Tr_lidar_to_vehicle, 3, values=[0,0,0,1],axis = 0)
    invTr = inv(Tr_cam_to_vehicle)
    Tr_lidar_to_cam = invTr.dot(Tr_lidar_to_vehicle).round(6)

    return Tr_lidar_to_cam

def camermatChanger():
    intrinsic[0] = g_cmd["focal_length"][0]
    intrinsic[4] = g_cmd["focal_length"][1]
    realCameraMat = np.array(intrinsic).reshape(3,3)
    return realCameraMat


def transformLiDARToCamera(TransformMat, pc_lidar):
    cam_temp = TransformMat.dot(pc_lidar)
    cam_temp = np.delete(cam_temp, 3, axis=0)
    return cam_temp

def transformCameraToImage(width, height, CameraMat, pc_camera, pc_lidar):
    cam_temp = pc_camera
    lid_temp = pc_lidar
    img_temp = CameraMat.dot(pc_camera)
    img_temp /= img_temp[2,:]
    return img_temp, cam_temp, lid_temp

def draw_pts_img(img, xi, yi):
    img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
    point_np = img
    for ctr in zip(xi, yi):
        cv2.circle(point_np, ctr, 1, (255,0,0),-1)
    return point_np

# mid point method (x 기준 가장 짧은 점)
def calc_distance_position2(points):
    mat_points = np.array(points).T
    position = []
    index = np.argmin(mat_points[0])
    position.append(min(mat_points[0]))
    position.append(mat_points[1][index])
    position.append(mat_points[2][index])
    tmp_position = np.array(position)

    dist = math.sqrt(tmp_position.dot(tmp_position))
    return dist, position

def pcdcallback(ouster):
    global TF_BUFFER, TF_LISTENER, IS_VIS
    global g_cmd, t_mat, rvec, init_toggle, g_save_rt_toggle, g_cmd_toggle

    rospy.loginfo('Fusion Processing_pcl')

    width = params_cam["WIDTH"]
    height = params_cam["HEIGHT"]

    TransformMat = matrixChanger(params_cam, params_lidar)
    print(TransformMat)
    
    RealCameraMat = camermatChanger()
    print(RealCameraMat)

    point_list = []
    for point in pc2.read_points(ouster, skip_nans=True):
        if point[1] < 0:
            point_list.append((point[0], point[1], point[2], 1))
    pc_np = np.array(point_list, np.float32)
 
    filtered_xyz_p = pc_np[:, 0:3]
    filtered_xyz_p = filtered_xyz_p.T
    xyz_p = pc_np[:, 0:3]
    xyz_p = np.insert(xyz_p,3,1,axis=1).T   # Transpose
    

    xyz_c = transformLiDARToCamera(TransformMat, xyz_p)
    xy_i, filtered_xyz_c, filtered_xyz_p = transformCameraToImage(width, height, RealCameraMat, xyz_c, filtered_xyz_p)
   
    xy_i = xy_i.astype(np.int32)
    
    projectionImage = draw_pts_img(img, xy_i[0,:], xy_i[1,:])

    projectionImage = cv2.resize(projectionImage,(1280,720))
    cv2.putText(projectionImage,"cmd mode : {} index : {}".format(g_cmd_toggle[0], g_cmd_toggle[1]),(0,50),cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2,lineType=cv2.LINE_AA)
    cv2.putText(projectionImage,"rvec : {} t mat : {}".format(np.round(g_cmd['rvec'],2),np.round(g_cmd['t_mat'],2)),(0,100),cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2,lineType=cv2.LINE_AA)
    cv2.putText(projectionImage,"focal_length : {} ".format(np.round(g_cmd['focal_length'],2)),(0,150),cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255),2,lineType=cv2.LINE_AA)
    
    cv2.imshow("LidartoCameraProjection", projectionImage)


    key = cv2.waitKeyEx(1)

    key %= 256
    if key == 113:
        sys.exit()
    if key == 114 : g_save_rt_toggle = False if g_save_rt_toggle else True
    if key == 48 : g_cmd = {'rvec':[0,0,0],'t_mat':[0,0,0], 'focal_length':[.0,.0]}
    if key == 49: g_cmd_toggle = ['rvec',0] # 1
    if key == 50 : g_cmd_toggle = ['rvec',1]# 2
    if key == 51 : g_cmd_toggle = ['rvec',2]# 3
    if key == 52 : g_cmd_toggle = ['t_mat',0]# 4
    if key == 53 : g_cmd_toggle = ['t_mat',1]# 5
    if key == 54 : g_cmd_toggle = ['t_mat',2]# 6
    if key == 55 : g_cmd_toggle = ['focal_length', 0]# 7
    if key == 56 : g_cmd_toggle = ['focal_length', 1]# 8
    if key == 105 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] += 0.01 #i
    if key == 106 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] -= 0.01 #j  
    if key == 111 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] += 0.1  #o
    if key == 107 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] -= 0.1  #k
    if key == 112 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] += 1.   #p
    if key == 108 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] -= 1.   #l
    if key == 117 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] += 50.  #u
    if key == 104 : g_cmd[g_cmd_toggle[0]][g_cmd_toggle[1]] -= 50.  #h
    print(key)

def imgcallback(image_color):
    
    #rospy.loginfo('Fusion Processing_img')
    # rospy.loginfo('Setting up camera model')
    # CAMERA_MODEL.fromCameraInfo(camera_info)
    
    # TF listener
    # TF_BUFFER = tf2_ros.Buffer()
    # TF_LISTENER = tf2_ros.TransformListener(TF_BUFFER)

    
    # image callback function
    try:
        global img
        bridge = CvBridge()
        img = bridge.compressed_imgmsg_to_cv2(image_color)
        height,width,channels = img.shape
        #print(height )
        #print(width )

    except CvBridgeError as e:
        rospy.logerr("CvBridge Error: {}".format(e))

def listener(image_color, ouster):
    # Start node
    rospy.init_node('fusion_camera_lidar', anonymous=True)
    rospy.loginfo('Current PID: [{}]'.format(os.getpid()))
    rospy.loginfo('PointCloud2 topic: {}'.format(ouster))
    rospy.loginfo('Image topic: {}'.format(image_color))

    
    # Subscribe to topicsfters.Subscriber(velodyne_points, PointCloud2)
    image_sub = rospy.Subscriber(image_color, CompressedImage , imgcallback)
    velodyne_sub = rospy.Subscriber(ouster, PointCloud2 ,pcdcallback)


    # Keep python from exiting until this node is stopped
    try:
        rospy.spin()
    except rospy.ROSInterruptException:
        rospy.loginfo('Shutting down')

if __name__ == '__main__':
    # YOLO, LiDAR Topic name
    ouster = 'jba_cloud'
    image_color = '/gmsl_camera/dev/video0/compressed'

    # Start subscriber
    listener(image_color, ouster)




