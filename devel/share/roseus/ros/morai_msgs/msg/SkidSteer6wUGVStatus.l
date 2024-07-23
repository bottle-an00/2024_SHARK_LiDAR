;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::SkidSteer6wUGVStatus)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'SkidSteer6wUGVStatus (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::SKIDSTEER6WUGVSTATUS")
  (make-package "MORAI_MSGS::SKIDSTEER6WUGVSTATUS"))

(in-package "ROS")
;;//! \htmlinclude SkidSteer6wUGVStatus.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass morai_msgs::SkidSteer6wUGVStatus
  :super ros::object
  :slots (_header _unique_id _ctrl_mode _acceleration _position _linear_velocity _angular_velocity _heading _cmd_type _left_front_wheel_rpm _left_middle_wheel_rpm _left_rear_wheel_rpm _right_front_wheel_rpm _right_middle_wheel_rpm _right_rear_wheel_rpm _lateral_offset ))

(defmethod morai_msgs::SkidSteer6wUGVStatus
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:unique_id __unique_id) 0)
    ((:ctrl_mode __ctrl_mode) 0)
    ((:acceleration __acceleration) (instance geometry_msgs::Vector3 :init))
    ((:position __position) (instance geometry_msgs::Vector3 :init))
    ((:linear_velocity __linear_velocity) (instance geometry_msgs::Vector3 :init))
    ((:angular_velocity __angular_velocity) (instance geometry_msgs::Vector3 :init))
    ((:heading __heading) 0.0)
    ((:cmd_type __cmd_type) 0)
    ((:left_front_wheel_rpm __left_front_wheel_rpm) 0.0)
    ((:left_middle_wheel_rpm __left_middle_wheel_rpm) 0.0)
    ((:left_rear_wheel_rpm __left_rear_wheel_rpm) 0.0)
    ((:right_front_wheel_rpm __right_front_wheel_rpm) 0.0)
    ((:right_middle_wheel_rpm __right_middle_wheel_rpm) 0.0)
    ((:right_rear_wheel_rpm __right_rear_wheel_rpm) 0.0)
    ((:lateral_offset __lateral_offset) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _unique_id (round __unique_id))
   (setq _ctrl_mode (round __ctrl_mode))
   (setq _acceleration __acceleration)
   (setq _position __position)
   (setq _linear_velocity __linear_velocity)
   (setq _angular_velocity __angular_velocity)
   (setq _heading (float __heading))
   (setq _cmd_type (round __cmd_type))
   (setq _left_front_wheel_rpm (float __left_front_wheel_rpm))
   (setq _left_middle_wheel_rpm (float __left_middle_wheel_rpm))
   (setq _left_rear_wheel_rpm (float __left_rear_wheel_rpm))
   (setq _right_front_wheel_rpm (float __right_front_wheel_rpm))
   (setq _right_middle_wheel_rpm (float __right_middle_wheel_rpm))
   (setq _right_rear_wheel_rpm (float __right_rear_wheel_rpm))
   (setq _lateral_offset (float __lateral_offset))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:unique_id
   (&optional __unique_id)
   (if __unique_id (setq _unique_id __unique_id)) _unique_id)
  (:ctrl_mode
   (&optional __ctrl_mode)
   (if __ctrl_mode (setq _ctrl_mode __ctrl_mode)) _ctrl_mode)
  (:acceleration
   (&rest __acceleration)
   (if (keywordp (car __acceleration))
       (send* _acceleration __acceleration)
     (progn
       (if __acceleration (setq _acceleration (car __acceleration)))
       _acceleration)))
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:linear_velocity
   (&rest __linear_velocity)
   (if (keywordp (car __linear_velocity))
       (send* _linear_velocity __linear_velocity)
     (progn
       (if __linear_velocity (setq _linear_velocity (car __linear_velocity)))
       _linear_velocity)))
  (:angular_velocity
   (&rest __angular_velocity)
   (if (keywordp (car __angular_velocity))
       (send* _angular_velocity __angular_velocity)
     (progn
       (if __angular_velocity (setq _angular_velocity (car __angular_velocity)))
       _angular_velocity)))
  (:heading
   (&optional __heading)
   (if __heading (setq _heading __heading)) _heading)
  (:cmd_type
   (&optional __cmd_type)
   (if __cmd_type (setq _cmd_type __cmd_type)) _cmd_type)
  (:left_front_wheel_rpm
   (&optional __left_front_wheel_rpm)
   (if __left_front_wheel_rpm (setq _left_front_wheel_rpm __left_front_wheel_rpm)) _left_front_wheel_rpm)
  (:left_middle_wheel_rpm
   (&optional __left_middle_wheel_rpm)
   (if __left_middle_wheel_rpm (setq _left_middle_wheel_rpm __left_middle_wheel_rpm)) _left_middle_wheel_rpm)
  (:left_rear_wheel_rpm
   (&optional __left_rear_wheel_rpm)
   (if __left_rear_wheel_rpm (setq _left_rear_wheel_rpm __left_rear_wheel_rpm)) _left_rear_wheel_rpm)
  (:right_front_wheel_rpm
   (&optional __right_front_wheel_rpm)
   (if __right_front_wheel_rpm (setq _right_front_wheel_rpm __right_front_wheel_rpm)) _right_front_wheel_rpm)
  (:right_middle_wheel_rpm
   (&optional __right_middle_wheel_rpm)
   (if __right_middle_wheel_rpm (setq _right_middle_wheel_rpm __right_middle_wheel_rpm)) _right_middle_wheel_rpm)
  (:right_rear_wheel_rpm
   (&optional __right_rear_wheel_rpm)
   (if __right_rear_wheel_rpm (setq _right_rear_wheel_rpm __right_rear_wheel_rpm)) _right_rear_wheel_rpm)
  (:lateral_offset
   (&optional __lateral_offset)
   (if __lateral_offset (setq _lateral_offset __lateral_offset)) _lateral_offset)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _unique_id
    4
    ;; int32 _ctrl_mode
    4
    ;; geometry_msgs/Vector3 _acceleration
    (send _acceleration :serialization-length)
    ;; geometry_msgs/Vector3 _position
    (send _position :serialization-length)
    ;; geometry_msgs/Vector3 _linear_velocity
    (send _linear_velocity :serialization-length)
    ;; geometry_msgs/Vector3 _angular_velocity
    (send _angular_velocity :serialization-length)
    ;; float64 _heading
    8
    ;; int32 _cmd_type
    4
    ;; float64 _left_front_wheel_rpm
    8
    ;; float64 _left_middle_wheel_rpm
    8
    ;; float64 _left_rear_wheel_rpm
    8
    ;; float64 _right_front_wheel_rpm
    8
    ;; float64 _right_middle_wheel_rpm
    8
    ;; float64 _right_rear_wheel_rpm
    8
    ;; float64 _lateral_offset
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _unique_id
       (write-long _unique_id s)
     ;; int32 _ctrl_mode
       (write-long _ctrl_mode s)
     ;; geometry_msgs/Vector3 _acceleration
       (send _acceleration :serialize s)
     ;; geometry_msgs/Vector3 _position
       (send _position :serialize s)
     ;; geometry_msgs/Vector3 _linear_velocity
       (send _linear_velocity :serialize s)
     ;; geometry_msgs/Vector3 _angular_velocity
       (send _angular_velocity :serialize s)
     ;; float64 _heading
       (sys::poke _heading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _cmd_type
       (write-long _cmd_type s)
     ;; float64 _left_front_wheel_rpm
       (sys::poke _left_front_wheel_rpm (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _left_middle_wheel_rpm
       (sys::poke _left_middle_wheel_rpm (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _left_rear_wheel_rpm
       (sys::poke _left_rear_wheel_rpm (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_front_wheel_rpm
       (sys::poke _right_front_wheel_rpm (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_middle_wheel_rpm
       (sys::poke _right_middle_wheel_rpm (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _right_rear_wheel_rpm
       (sys::poke _right_rear_wheel_rpm (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _lateral_offset
       (sys::poke _lateral_offset (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _unique_id
     (setq _unique_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _ctrl_mode
     (setq _ctrl_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Vector3 _acceleration
     (send _acceleration :deserialize buf ptr-) (incf ptr- (send _acceleration :serialization-length))
   ;; geometry_msgs/Vector3 _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; geometry_msgs/Vector3 _linear_velocity
     (send _linear_velocity :deserialize buf ptr-) (incf ptr- (send _linear_velocity :serialization-length))
   ;; geometry_msgs/Vector3 _angular_velocity
     (send _angular_velocity :deserialize buf ptr-) (incf ptr- (send _angular_velocity :serialization-length))
   ;; float64 _heading
     (setq _heading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _cmd_type
     (setq _cmd_type (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _left_front_wheel_rpm
     (setq _left_front_wheel_rpm (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _left_middle_wheel_rpm
     (setq _left_middle_wheel_rpm (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _left_rear_wheel_rpm
     (setq _left_rear_wheel_rpm (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_front_wheel_rpm
     (setq _right_front_wheel_rpm (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_middle_wheel_rpm
     (setq _right_middle_wheel_rpm (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _right_rear_wheel_rpm
     (setq _right_rear_wheel_rpm (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _lateral_offset
     (setq _lateral_offset (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get morai_msgs::SkidSteer6wUGVStatus :md5sum-) "d741d34a68b143895b122f334a1afe31")
(setf (get morai_msgs::SkidSteer6wUGVStatus :datatype-) "morai_msgs/SkidSteer6wUGVStatus")
(setf (get morai_msgs::SkidSteer6wUGVStatus :definition-)
      "Header header

int32 unique_id
int32 ctrl_mode

geometry_msgs/Vector3 acceleration
geometry_msgs/Vector3 position
geometry_msgs/Vector3 linear_velocity
geometry_msgs/Vector3 angular_velocity

float64 heading
int32 cmd_type

float64 left_front_wheel_rpm
float64 left_middle_wheel_rpm
float64 left_rear_wheel_rpm
float64 right_front_wheel_rpm
float64 right_middle_wheel_rpm
float64 right_rear_wheel_rpm

float64 lateral_offset

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

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :morai_msgs/SkidSteer6wUGVStatus "d741d34a68b143895b122f334a1afe31")


