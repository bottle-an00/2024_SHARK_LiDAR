;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultInjectionSensorSrv)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultInjectionSensorSrv (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTINJECTIONSENSORSRV")
  (make-package "MORAI_MSGS::FAULTINJECTIONSENSORSRV"))
(unless (find-package "MORAI_MSGS::FAULTINJECTIONSENSORSRVREQUEST")
  (make-package "MORAI_MSGS::FAULTINJECTIONSENSORSRVREQUEST"))
(unless (find-package "MORAI_MSGS::FAULTINJECTIONSENSORSRVRESPONSE")
  (make-package "MORAI_MSGS::FAULTINJECTIONSENSORSRVRESPONSE"))

(in-package "ROS")





(defclass morai_msgs::FaultInjectionSensorSrvRequest
  :super ros::object
  :slots (_request ))

(defmethod morai_msgs::FaultInjectionSensorSrvRequest
  (:init
   (&key
    ((:request __request) (instance morai_msgs::FaultInjection_Sensor :init))
    )
   (send-super :init)
   (setq _request __request)
   self)
  (:request
   (&rest __request)
   (if (keywordp (car __request))
       (send* _request __request)
     (progn
       (if __request (setq _request (car __request)))
       _request)))
  (:serialization-length
   ()
   (+
    ;; morai_msgs/FaultInjection_Sensor _request
    (send _request :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; morai_msgs/FaultInjection_Sensor _request
       (send _request :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; morai_msgs/FaultInjection_Sensor _request
     (send _request :deserialize buf ptr-) (incf ptr- (send _request :serialization-length))
   ;;
   self)
  )

(defclass morai_msgs::FaultInjectionSensorSrvResponse
  :super ros::object
  :slots (_response ))

(defmethod morai_msgs::FaultInjectionSensorSrvResponse
  (:init
   (&key
    ((:response __response) (instance morai_msgs::FaultInjection_Response :init))
    )
   (send-super :init)
   (setq _response __response)
   self)
  (:response
   (&rest __response)
   (if (keywordp (car __response))
       (send* _response __response)
     (progn
       (if __response (setq _response (car __response)))
       _response)))
  (:serialization-length
   ()
   (+
    ;; morai_msgs/FaultInjection_Response _response
    (send _response :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; morai_msgs/FaultInjection_Response _response
       (send _response :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; morai_msgs/FaultInjection_Response _response
     (send _response :deserialize buf ptr-) (incf ptr- (send _response :serialization-length))
   ;;
   self)
  )

(defclass morai_msgs::FaultInjectionSensorSrv
  :super ros::object
  :slots ())

(setf (get morai_msgs::FaultInjectionSensorSrv :md5sum-) "7a22d370d63968f482f03b961f96bf2e")
(setf (get morai_msgs::FaultInjectionSensorSrv :datatype-) "morai_msgs/FaultInjectionSensorSrv")
(setf (get morai_msgs::FaultInjectionSensorSrv :request) morai_msgs::FaultInjectionSensorSrvRequest)
(setf (get morai_msgs::FaultInjectionSensorSrv :response) morai_msgs::FaultInjectionSensorSrvResponse)

(defmethod morai_msgs::FaultInjectionSensorSrvRequest
  (:response () (instance morai_msgs::FaultInjectionSensorSrvResponse :init)))

(setf (get morai_msgs::FaultInjectionSensorSrvRequest :md5sum-) "7a22d370d63968f482f03b961f96bf2e")
(setf (get morai_msgs::FaultInjectionSensorSrvRequest :datatype-) "morai_msgs/FaultInjectionSensorSrvRequest")
(setf (get morai_msgs::FaultInjectionSensorSrvRequest :definition-)
      "FaultInjection_Sensor request

================================================================================
MSG: morai_msgs/FaultInjection_Sensor
int32 unique_id
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
---
FaultInjection_Response response


================================================================================
MSG: morai_msgs/FaultInjection_Response
bool result

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

(setf (get morai_msgs::FaultInjectionSensorSrvResponse :md5sum-) "7a22d370d63968f482f03b961f96bf2e")
(setf (get morai_msgs::FaultInjectionSensorSrvResponse :datatype-) "morai_msgs/FaultInjectionSensorSrvResponse")
(setf (get morai_msgs::FaultInjectionSensorSrvResponse :definition-)
      "FaultInjection_Sensor request

================================================================================
MSG: morai_msgs/FaultInjection_Sensor
int32 unique_id
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
---
FaultInjection_Response response


================================================================================
MSG: morai_msgs/FaultInjection_Response
bool result

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



(provide :morai_msgs/FaultInjectionSensorSrv "7a22d370d63968f482f03b961f96bf2e")


