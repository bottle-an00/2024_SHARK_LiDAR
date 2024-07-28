#!/usr/bin/env python

import rospy
from morai_msgs.msg import CtrlCmd

class s_drive():
    def __init__(self):
        rospy.init_node('s_drive', anonymous=True)
        cmd_pub = rospy.Publisher('/ctrl_cmd', CtrlCmd, queue_size=1) 
        rate = rospy.Rate(30) 
        cmd = CtrlCmd() 
        cmd.longlCmdType = 2 
        cmd.velocity = 30 
        steering_cmd = [0.1, -0.1] 
        cmd_cnts = 30 

        while not rospy.is_shutdown():
            for i in range(2):
                cmd.steering = steering_cmd[i]
                rospy.loginfo(cmd)
                for _ in range(cmd_cnts):
                    cmd_pub.publish(cmd)
                    rate.sleep()


if __name__ == '__main__':
    try:
        s_d = s_drive()
    except rospy.ROSInterruptException:
        pass
