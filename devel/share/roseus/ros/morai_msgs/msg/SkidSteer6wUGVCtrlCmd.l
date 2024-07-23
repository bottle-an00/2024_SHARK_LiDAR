;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::SkidSteer6wUGVCtrlCmd)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'SkidSteer6wUGVCtrlCmd (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::SKIDSTEER6WUGVCTRLCMD")
  (make-package "MORAI_MSGS::SKIDSTEER6WUGVCTRLCMD"))

(in-package "ROS")
;;//! \htmlinclude SkidSteer6wUGVCtrlCmd.msg.html


(defclass morai_msgs::SkidSteer6wUGVCtrlCmd
  :super ros::object
  :slots (_cmd_type _Forward_input _Backward_input _Left_Turn_input _Right_Turn_input _left_front_wheel_rpm _left_middle_wheel_rpm _left_rear_wheel_rpm _right_front_wheel_rpm _right_middle_wheel_rpm _right_rear_wheel_rpm _Target_linear_velocity _Target_angular_velocity ))

(defmethod morai_msgs::SkidSteer6wUGVCtrlCmd
  (:init
   (&key
    ((:cmd_type __cmd_type) 0)
    ((:Forward_input __Forward_input) nil)
    ((:Backward_input __Backward_input) nil)
    ((:Left_Turn_input __Left_Turn_input) nil)
    ((:Right_Turn_input __Right_Turn_input) nil)
    ((:left_front_wheel_rpm __left_front_wheel_rpm) 0.0)
    ((:left_middle_wheel_rpm __left_middle_wheel_rpm) 0.0)
    ((:left_rear_wheel_rpm __left_rear_wheel_rpm) 0.0)
    ((:right_front_wheel_rpm __right_front_wheel_rpm) 0.0)
    ((:right_middle_wheel_rpm __right_middle_wheel_rpm) 0.0)
    ((:right_rear_wheel_rpm __right_rear_wheel_rpm) 0.0)
    ((:Target_linear_velocity __Target_linear_velocity) 0.0)
    ((:Target_angular_velocity __Target_angular_velocity) 0.0)
    )
   (send-super :init)
   (setq _cmd_type (round __cmd_type))
   (setq _Forward_input __Forward_input)
   (setq _Backward_input __Backward_input)
   (setq _Left_Turn_input __Left_Turn_input)
   (setq _Right_Turn_input __Right_Turn_input)
   (setq _left_front_wheel_rpm (float __left_front_wheel_rpm))
   (setq _left_middle_wheel_rpm (float __left_middle_wheel_rpm))
   (setq _left_rear_wheel_rpm (float __left_rear_wheel_rpm))
   (setq _right_front_wheel_rpm (float __right_front_wheel_rpm))
   (setq _right_middle_wheel_rpm (float __right_middle_wheel_rpm))
   (setq _right_rear_wheel_rpm (float __right_rear_wheel_rpm))
   (setq _Target_linear_velocity (float __Target_linear_velocity))
   (setq _Target_angular_velocity (float __Target_angular_velocity))
   self)
  (:cmd_type
   (&optional __cmd_type)
   (if __cmd_type (setq _cmd_type __cmd_type)) _cmd_type)
  (:Forward_input
   (&optional (__Forward_input :null))
   (if (not (eq __Forward_input :null)) (setq _Forward_input __Forward_input)) _Forward_input)
  (:Backward_input
   (&optional (__Backward_input :null))
   (if (not (eq __Backward_input :null)) (setq _Backward_input __Backward_input)) _Backward_input)
  (:Left_Turn_input
   (&optional (__Left_Turn_input :null))
   (if (not (eq __Left_Turn_input :null)) (setq _Left_Turn_input __Left_Turn_input)) _Left_Turn_input)
  (:Right_Turn_input
   (&optional (__Right_Turn_input :null))
   (if (not (eq __Right_Turn_input :null)) (setq _Right_Turn_input __Right_Turn_input)) _Right_Turn_input)
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
  (:Target_linear_velocity
   (&optional __Target_linear_velocity)
   (if __Target_linear_velocity (setq _Target_linear_velocity __Target_linear_velocity)) _Target_linear_velocity)
  (:Target_angular_velocity
   (&optional __Target_angular_velocity)
   (if __Target_angular_velocity (setq _Target_angular_velocity __Target_angular_velocity)) _Target_angular_velocity)
  (:serialization-length
   ()
   (+
    ;; int32 _cmd_type
    4
    ;; bool _Forward_input
    1
    ;; bool _Backward_input
    1
    ;; bool _Left_Turn_input
    1
    ;; bool _Right_Turn_input
    1
    ;; float32 _left_front_wheel_rpm
    4
    ;; float32 _left_middle_wheel_rpm
    4
    ;; float32 _left_rear_wheel_rpm
    4
    ;; float32 _right_front_wheel_rpm
    4
    ;; float32 _right_middle_wheel_rpm
    4
    ;; float32 _right_rear_wheel_rpm
    4
    ;; float32 _Target_linear_velocity
    4
    ;; float32 _Target_angular_velocity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _cmd_type
       (write-long _cmd_type s)
     ;; bool _Forward_input
       (if _Forward_input (write-byte -1 s) (write-byte 0 s))
     ;; bool _Backward_input
       (if _Backward_input (write-byte -1 s) (write-byte 0 s))
     ;; bool _Left_Turn_input
       (if _Left_Turn_input (write-byte -1 s) (write-byte 0 s))
     ;; bool _Right_Turn_input
       (if _Right_Turn_input (write-byte -1 s) (write-byte 0 s))
     ;; float32 _left_front_wheel_rpm
       (sys::poke _left_front_wheel_rpm (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _left_middle_wheel_rpm
       (sys::poke _left_middle_wheel_rpm (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _left_rear_wheel_rpm
       (sys::poke _left_rear_wheel_rpm (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_front_wheel_rpm
       (sys::poke _right_front_wheel_rpm (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_middle_wheel_rpm
       (sys::poke _right_middle_wheel_rpm (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _right_rear_wheel_rpm
       (sys::poke _right_rear_wheel_rpm (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Target_linear_velocity
       (sys::poke _Target_linear_velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Target_angular_velocity
       (sys::poke _Target_angular_velocity (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _cmd_type
     (setq _cmd_type (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _Forward_input
     (setq _Forward_input (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _Backward_input
     (setq _Backward_input (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _Left_Turn_input
     (setq _Left_Turn_input (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _Right_Turn_input
     (setq _Right_Turn_input (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _left_front_wheel_rpm
     (setq _left_front_wheel_rpm (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _left_middle_wheel_rpm
     (setq _left_middle_wheel_rpm (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _left_rear_wheel_rpm
     (setq _left_rear_wheel_rpm (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_front_wheel_rpm
     (setq _right_front_wheel_rpm (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_middle_wheel_rpm
     (setq _right_middle_wheel_rpm (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _right_rear_wheel_rpm
     (setq _right_rear_wheel_rpm (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Target_linear_velocity
     (setq _Target_linear_velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Target_angular_velocity
     (setq _Target_angular_velocity (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get morai_msgs::SkidSteer6wUGVCtrlCmd :md5sum-) "cb8a43878b1b2c65f50bd53e5a4c03f4")
(setf (get morai_msgs::SkidSteer6wUGVCtrlCmd :datatype-) "morai_msgs/SkidSteer6wUGVCtrlCmd")
(setf (get morai_msgs::SkidSteer6wUGVCtrlCmd :definition-)
      "int32 cmd_type

bool Forward_input
bool Backward_input
bool Left_Turn_input
bool Right_Turn_input

float32 left_front_wheel_rpm
float32 left_middle_wheel_rpm
float32 left_rear_wheel_rpm
float32 right_front_wheel_rpm
float32 right_middle_wheel_rpm
float32 right_rear_wheel_rpm

float32 Target_linear_velocity
float32 Target_angular_velocity


")



(provide :morai_msgs/SkidSteer6wUGVCtrlCmd "cb8a43878b1b2c65f50bd53e5a4c03f4")


