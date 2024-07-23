;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultInjection_Sensor)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultInjection_Sensor (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTINJECTION_SENSOR")
  (make-package "MORAI_MSGS::FAULTINJECTION_SENSOR"))

(in-package "ROS")
;;//! \htmlinclude FaultInjection_Sensor.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass morai_msgs::FaultInjection_Sensor
  :super ros::object
  :slots (_unique_id _sensor_id _fault_class _fault_subclass _local_position_offset _local_rotation_offset ))

(defmethod morai_msgs::FaultInjection_Sensor
  (:init
   (&key
    ((:unique_id __unique_id) 0)
    ((:sensor_id __sensor_id) 0)
    ((:fault_class __fault_class) 0)
    ((:fault_subclass __fault_subclass) 0)
    ((:local_position_offset __local_position_offset) (instance geometry_msgs::Vector3 :init))
    ((:local_rotation_offset __local_rotation_offset) (instance geometry_msgs::Vector3 :init))
    )
   (send-super :init)
   (setq _unique_id (round __unique_id))
   (setq _sensor_id (round __sensor_id))
   (setq _fault_class (round __fault_class))
   (setq _fault_subclass (round __fault_subclass))
   (setq _local_position_offset __local_position_offset)
   (setq _local_rotation_offset __local_rotation_offset)
   self)
  (:unique_id
   (&optional __unique_id)
   (if __unique_id (setq _unique_id __unique_id)) _unique_id)
  (:sensor_id
   (&optional __sensor_id)
   (if __sensor_id (setq _sensor_id __sensor_id)) _sensor_id)
  (:fault_class
   (&optional __fault_class)
   (if __fault_class (setq _fault_class __fault_class)) _fault_class)
  (:fault_subclass
   (&optional __fault_subclass)
   (if __fault_subclass (setq _fault_subclass __fault_subclass)) _fault_subclass)
  (:local_position_offset
   (&rest __local_position_offset)
   (if (keywordp (car __local_position_offset))
       (send* _local_position_offset __local_position_offset)
     (progn
       (if __local_position_offset (setq _local_position_offset (car __local_position_offset)))
       _local_position_offset)))
  (:local_rotation_offset
   (&rest __local_rotation_offset)
   (if (keywordp (car __local_rotation_offset))
       (send* _local_rotation_offset __local_rotation_offset)
     (progn
       (if __local_rotation_offset (setq _local_rotation_offset (car __local_rotation_offset)))
       _local_rotation_offset)))
  (:serialization-length
   ()
   (+
    ;; int32 _unique_id
    4
    ;; int32 _sensor_id
    4
    ;; int32 _fault_class
    4
    ;; int32 _fault_subclass
    4
    ;; geometry_msgs/Vector3 _local_position_offset
    (send _local_position_offset :serialization-length)
    ;; geometry_msgs/Vector3 _local_rotation_offset
    (send _local_rotation_offset :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _unique_id
       (write-long _unique_id s)
     ;; int32 _sensor_id
       (write-long _sensor_id s)
     ;; int32 _fault_class
       (write-long _fault_class s)
     ;; int32 _fault_subclass
       (write-long _fault_subclass s)
     ;; geometry_msgs/Vector3 _local_position_offset
       (send _local_position_offset :serialize s)
     ;; geometry_msgs/Vector3 _local_rotation_offset
       (send _local_rotation_offset :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _unique_id
     (setq _unique_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _sensor_id
     (setq _sensor_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _fault_class
     (setq _fault_class (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _fault_subclass
     (setq _fault_subclass (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Vector3 _local_position_offset
     (send _local_position_offset :deserialize buf ptr-) (incf ptr- (send _local_position_offset :serialization-length))
   ;; geometry_msgs/Vector3 _local_rotation_offset
     (send _local_rotation_offset :deserialize buf ptr-) (incf ptr- (send _local_rotation_offset :serialization-length))
   ;;
   self)
  )

(setf (get morai_msgs::FaultInjection_Sensor :md5sum-) "1d09067e718a7214f8177394317316b2")
(setf (get morai_msgs::FaultInjection_Sensor :datatype-) "morai_msgs/FaultInjection_Sensor")
(setf (get morai_msgs::FaultInjection_Sensor :definition-)
      "int32 unique_id
int32 sensor_id

int32 fault_class
int32 fault_subclass

geometry_msgs/Vector3 local_position_offset
geometry_msgs/Vector3 local_rotation_offset

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



(provide :morai_msgs/FaultInjection_Sensor "1d09067e718a7214f8177394317316b2")


