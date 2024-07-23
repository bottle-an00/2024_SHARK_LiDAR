;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultStatusInfo_Sensor)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultStatusInfo_Sensor (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTSTATUSINFO_SENSOR")
  (make-package "MORAI_MSGS::FAULTSTATUSINFO_SENSOR"))

(in-package "ROS")
;;//! \htmlinclude FaultStatusInfo_Sensor.msg.html


(defclass morai_msgs::FaultStatusInfo_Sensor
  :super ros::object
  :slots (_sensor_id _sensor ))

(defmethod morai_msgs::FaultStatusInfo_Sensor
  (:init
   (&key
    ((:sensor_id __sensor_id) 0)
    ((:sensor __sensor) (instance morai_msgs::FaultStatusInfo_Overall :init))
    )
   (send-super :init)
   (setq _sensor_id (round __sensor_id))
   (setq _sensor __sensor)
   self)
  (:sensor_id
   (&optional __sensor_id)
   (if __sensor_id (setq _sensor_id __sensor_id)) _sensor_id)
  (:sensor
   (&rest __sensor)
   (if (keywordp (car __sensor))
       (send* _sensor __sensor)
     (progn
       (if __sensor (setq _sensor (car __sensor)))
       _sensor)))
  (:serialization-length
   ()
   (+
    ;; int32 _sensor_id
    4
    ;; morai_msgs/FaultStatusInfo_Overall _sensor
    (send _sensor :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sensor_id
       (write-long _sensor_id s)
     ;; morai_msgs/FaultStatusInfo_Overall _sensor
       (send _sensor :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sensor_id
     (setq _sensor_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; morai_msgs/FaultStatusInfo_Overall _sensor
     (send _sensor :deserialize buf ptr-) (incf ptr- (send _sensor :serialization-length))
   ;;
   self)
  )

(setf (get morai_msgs::FaultStatusInfo_Sensor :md5sum-) "9ffcbdb400d2f73cb504fbb8f540f234")
(setf (get morai_msgs::FaultStatusInfo_Sensor :datatype-) "morai_msgs/FaultStatusInfo_Sensor")
(setf (get morai_msgs::FaultStatusInfo_Sensor :definition-)
      "int32 sensor_id
FaultStatusInfo_Overall sensor


================================================================================
MSG: morai_msgs/FaultStatusInfo_Overall
bool status
int32[] fault_subclass

")



(provide :morai_msgs/FaultStatusInfo_Sensor "9ffcbdb400d2f73cb504fbb8f540f234")


