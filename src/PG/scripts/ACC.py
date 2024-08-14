#!/usr/bin/env python

import rospy
from morai_msgs.msg import CtrlCmd
from morai_msgs.msg import EgoVehicleStatus
import sys, select, termios, tty
import math

velocity = 0.0
accel = 0.1
def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def publish_cmd(longlCmdType, accel, brake, steering, velocity, acceleration):
    cmd = CtrlCmd()
    cmd.longlCmdType = longlCmdType
    cmd.accel = accel
    cmd.brake = brake
    cmd.steering = steering
    cmd.velocity = velocity
    cmd.acceleration = acceleration
    pub.publish(cmd)


if __name__ == "__main__":
    settings = termios.tcgetattr(sys.stdin)

    rospy.init_node('vehicle_control')
    pub = rospy.Publisher('/ctrl_cmd', CtrlCmd, queue_size=10)
    
    speed =20.0  # 초기 속도 설정
    steering_angle = 0.0  # 초기 조향각 설정
    brake = 0.0
    rate = rospy.Rate(10)  # 10Hz
    try:
        print("Use arrow keys to steer. Press 'q' to quit.")
        while not rospy.is_shutdown():
            
            key = getKey()

            if key == 'q':
                break
            elif key == 'w':  # 위 방향키
                print("press up")
                speed = 15
            elif key == 's':  # 아래 방향키
                print("press down")
                speed -= 4
            elif key == 'd':  # 오른쪽 방향키
                print("press right")
                steering_angle += -0.1
            elif key == 'a':  # 왼쪽 방향키
                print("press left")
                steering_angle += 0.1

            publish_cmd(2, accel, brake, steering_angle, speed, accel)
            rate.sleep()

    except Exception as e:
        print(e)

    finally:
        publish_cmd(1, 0, 0, 0, 0, 0)
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
