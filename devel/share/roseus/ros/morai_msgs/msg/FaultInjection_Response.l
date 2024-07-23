;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultInjection_Response)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultInjection_Response (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTINJECTION_RESPONSE")
  (make-package "MORAI_MSGS::FAULTINJECTION_RESPONSE"))

(in-package "ROS")
;;//! \htmlinclude FaultInjection_Response.msg.html


(defclass morai_msgs::FaultInjection_Response
  :super ros::object
  :slots (_result _unique_id _vehicle _sensors ))

(defmethod morai_msgs::FaultInjection_Response
  (:init
   (&key
    ((:result __result) nil)
    ((:unique_id __unique_id) 0)
    ((:vehicle __vehicle) (instance morai_msgs::FaultStatusInfo_Vehicle :init))
    ((:sensors __sensors) ())
    )
   (send-super :init)
   (setq _result __result)
   (setq _unique_id (round __unique_id))
   (setq _vehicle __vehicle)
   (setq _sensors __sensors)
   self)
  (:result
   (&optional (__result :null))
   (if (not (eq __result :null)) (setq _result __result)) _result)
  (:unique_id
   (&optional __unique_id)
   (if __unique_id (setq _unique_id __unique_id)) _unique_id)
  (:vehicle
   (&rest __vehicle)
   (if (keywordp (car __vehicle))
       (send* _vehicle __vehicle)
     (progn
       (if __vehicle (setq _vehicle (car __vehicle)))
       _vehicle)))
  (:sensors
   (&rest __sensors)
   (if (keywordp (car __sensors))
       (send* _sensors __sensors)
     (progn
       (if __sensors (setq _sensors (car __sensors)))
       _sensors)))
  (:serialization-length
   ()
   (+
    ;; bool _result
    1
    ;; int32 _unique_id
    4
    ;; morai_msgs/FaultStatusInfo_Vehicle _vehicle
    (send _vehicle :serialization-length)
    ;; morai_msgs/FaultStatusInfo_Sensor[] _sensors
    (apply #'+ (send-all _sensors :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _result
       (if _result (write-byte -1 s) (write-byte 0 s))
     ;; int32 _unique_id
       (write-long _unique_id s)
     ;; morai_msgs/FaultStatusInfo_Vehicle _vehicle
       (send _vehicle :serialize s)
     ;; morai_msgs/FaultStatusInfo_Sensor[] _sensors
     (write-long (length _sensors) s)
     (dolist (elem _sensors)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _result
     (setq _result (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _unique_id
     (setq _unique_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; morai_msgs/FaultStatusInfo_Vehicle _vehicle
     (send _vehicle :deserialize buf ptr-) (incf ptr- (send _vehicle :serialization-length))
   ;; morai_msgs/FaultStatusInfo_Sensor[] _sensors
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _sensors (let (r) (dotimes (i n) (push (instance morai_msgs::FaultStatusInfo_Sensor :init) r)) r))
     (dolist (elem- _sensors)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get morai_msgs::FaultInjection_Response :md5sum-) "62056bf4fc5f4a1c260169ca104b9ebf")
(setf (get morai_msgs::FaultInjection_Response :datatype-) "morai_msgs/FaultInjection_Response")
(setf (get morai_msgs::FaultInjection_Response :definition-)
      "bool result

int32 unique_id
FaultStatusInfo_Vehicle vehicle
FaultStatusInfo_Sensor[] sensors

================================================================================
MSG: morai_msgs/FaultStatusInfo_Vehicle
FaultStatusInfo_Overall accel
FaultStatusInfo_Overall brake
FaultStatusInfo_Overall steer
FaultStatusInfo_Overall[] tires


================================================================================
MSG: morai_msgs/FaultStatusInfo_Overall
bool status
int32[] fault_subclass

================================================================================
MSG: morai_msgs/FaultStatusInfo_Sensor
int32 sensor_id
FaultStatusInfo_Overall sensor


")



(provide :morai_msgs/FaultInjection_Response "62056bf4fc5f4a1c260169ca104b9ebf")


