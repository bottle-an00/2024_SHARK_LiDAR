;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::WoowaDillyStatus)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'WoowaDillyStatus (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::WOOWADILLYSTATUS")
  (make-package "MORAI_MSGS::WOOWADILLYSTATUS"))

(in-package "ROS")
;;//! \htmlinclude WoowaDillyStatus.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass morai_msgs::WoowaDillyStatus
  :super ros::object
  :slots (_header _deliveryItem ))

(defmethod morai_msgs::WoowaDillyStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:deliveryItem __deliveryItem) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _header __header)
   (setq _deliveryItem __deliveryItem)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:deliveryItem
   (&optional __deliveryItem)
   (if __deliveryItem (setq _deliveryItem __deliveryItem)) _deliveryItem)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32[] _deliveryItem
    (* 4    (length _deliveryItem)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32[] _deliveryItem
     (write-long (length _deliveryItem) s)
     (dotimes (i (length _deliveryItem))
       (write-long (elt _deliveryItem i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32[] _deliveryItem
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _deliveryItem (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _deliveryItem i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get morai_msgs::WoowaDillyStatus :md5sum-) "336610afe157caca7c85fe22948c1ded")
(setf (get morai_msgs::WoowaDillyStatus :datatype-) "morai_msgs/WoowaDillyStatus")
(setf (get morai_msgs::WoowaDillyStatus :definition-)
      "Header header
int32[] deliveryItem

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



(provide :morai_msgs/WoowaDillyStatus "336610afe157caca7c85fe22948c1ded")


