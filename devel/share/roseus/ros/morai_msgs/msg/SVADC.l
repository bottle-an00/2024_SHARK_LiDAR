;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::SVADC)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'SVADC (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::SVADC")
  (make-package "MORAI_MSGS::SVADC"))

(in-package "ROS")
;;//! \htmlinclude SVADC.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass morai_msgs::SVADC
  :super ros::object
  :slots (_header _collisionCount _signalViolationCount _speedLimitCount ))

(defmethod morai_msgs::SVADC
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:collisionCount __collisionCount) 0)
    ((:signalViolationCount __signalViolationCount) 0)
    ((:speedLimitCount __speedLimitCount) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _collisionCount (round __collisionCount))
   (setq _signalViolationCount (round __signalViolationCount))
   (setq _speedLimitCount (round __speedLimitCount))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:collisionCount
   (&optional __collisionCount)
   (if __collisionCount (setq _collisionCount __collisionCount)) _collisionCount)
  (:signalViolationCount
   (&optional __signalViolationCount)
   (if __signalViolationCount (setq _signalViolationCount __signalViolationCount)) _signalViolationCount)
  (:speedLimitCount
   (&optional __speedLimitCount)
   (if __speedLimitCount (setq _speedLimitCount __speedLimitCount)) _speedLimitCount)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _collisionCount
    4
    ;; int32 _signalViolationCount
    4
    ;; int32 _speedLimitCount
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _collisionCount
       (write-long _collisionCount s)
     ;; int32 _signalViolationCount
       (write-long _signalViolationCount s)
     ;; int32 _speedLimitCount
       (write-long _speedLimitCount s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _collisionCount
     (setq _collisionCount (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _signalViolationCount
     (setq _signalViolationCount (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _speedLimitCount
     (setq _speedLimitCount (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get morai_msgs::SVADC :md5sum-) "c180496093e554e39b1b25419d7fdd6e")
(setf (get morai_msgs::SVADC :datatype-) "morai_msgs/SVADC")
(setf (get morai_msgs::SVADC :definition-)
      "Header header
int32 collisionCount
int32 signalViolationCount
int32 speedLimitCount

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :morai_msgs/SVADC "c180496093e554e39b1b25419d7fdd6e")


