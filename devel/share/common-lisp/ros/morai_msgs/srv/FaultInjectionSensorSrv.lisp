; Auto-generated. Do not edit!


(cl:in-package morai_msgs-srv)


;//! \htmlinclude FaultInjectionSensorSrv-request.msg.html

(cl:defclass <FaultInjectionSensorSrv-request> (roslisp-msg-protocol:ros-message)
  ((request
    :reader request
    :initarg :request
    :type morai_msgs-msg:FaultInjection_Sensor
    :initform (cl:make-instance 'morai_msgs-msg:FaultInjection_Sensor)))
)

(cl:defclass FaultInjectionSensorSrv-request (<FaultInjectionSensorSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjectionSensorSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjectionSensorSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<FaultInjectionSensorSrv-request> is deprecated: use morai_msgs-srv:FaultInjectionSensorSrv-request instead.")))

(cl:ensure-generic-function 'request-val :lambda-list '(m))
(cl:defmethod request-val ((m <FaultInjectionSensorSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:request-val is deprecated.  Use morai_msgs-srv:request instead.")
  (request m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjectionSensorSrv-request>) ostream)
  "Serializes a message object of type '<FaultInjectionSensorSrv-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'request) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjectionSensorSrv-request>) istream)
  "Deserializes a message object of type '<FaultInjectionSensorSrv-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'request) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjectionSensorSrv-request>)))
  "Returns string type for a service object of type '<FaultInjectionSensorSrv-request>"
  "morai_msgs/FaultInjectionSensorSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionSensorSrv-request)))
  "Returns string type for a service object of type 'FaultInjectionSensorSrv-request"
  "morai_msgs/FaultInjectionSensorSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjectionSensorSrv-request>)))
  "Returns md5sum for a message object of type '<FaultInjectionSensorSrv-request>"
  "7a22d370d63968f482f03b961f96bf2e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjectionSensorSrv-request)))
  "Returns md5sum for a message object of type 'FaultInjectionSensorSrv-request"
  "7a22d370d63968f482f03b961f96bf2e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjectionSensorSrv-request>)))
  "Returns full string definition for message of type '<FaultInjectionSensorSrv-request>"
  (cl:format cl:nil "FaultInjection_Sensor request~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Sensor~%int32 unique_id~%int32 sensor_id~%~%int32 fault_class~%int32 fault_subclass~%~%geometry_msgs/Vector3 local_position_offset~%geometry_msgs/Vector3 local_rotation_offset~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjectionSensorSrv-request)))
  "Returns full string definition for message of type 'FaultInjectionSensorSrv-request"
  (cl:format cl:nil "FaultInjection_Sensor request~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Sensor~%int32 unique_id~%int32 sensor_id~%~%int32 fault_class~%int32 fault_subclass~%~%geometry_msgs/Vector3 local_position_offset~%geometry_msgs/Vector3 local_rotation_offset~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjectionSensorSrv-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'request))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjectionSensorSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjectionSensorSrv-request
    (cl:cons ':request (request msg))
))
;//! \htmlinclude FaultInjectionSensorSrv-response.msg.html

(cl:defclass <FaultInjectionSensorSrv-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type morai_msgs-msg:FaultInjection_Response
    :initform (cl:make-instance 'morai_msgs-msg:FaultInjection_Response)))
)

(cl:defclass FaultInjectionSensorSrv-response (<FaultInjectionSensorSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjectionSensorSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjectionSensorSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<FaultInjectionSensorSrv-response> is deprecated: use morai_msgs-srv:FaultInjectionSensorSrv-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <FaultInjectionSensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:response-val is deprecated.  Use morai_msgs-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjectionSensorSrv-response>) ostream)
  "Serializes a message object of type '<FaultInjectionSensorSrv-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'response) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjectionSensorSrv-response>) istream)
  "Deserializes a message object of type '<FaultInjectionSensorSrv-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'response) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjectionSensorSrv-response>)))
  "Returns string type for a service object of type '<FaultInjectionSensorSrv-response>"
  "morai_msgs/FaultInjectionSensorSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionSensorSrv-response)))
  "Returns string type for a service object of type 'FaultInjectionSensorSrv-response"
  "morai_msgs/FaultInjectionSensorSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjectionSensorSrv-response>)))
  "Returns md5sum for a message object of type '<FaultInjectionSensorSrv-response>"
  "7a22d370d63968f482f03b961f96bf2e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjectionSensorSrv-response)))
  "Returns md5sum for a message object of type 'FaultInjectionSensorSrv-response"
  "7a22d370d63968f482f03b961f96bf2e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjectionSensorSrv-response>)))
  "Returns full string definition for message of type '<FaultInjectionSensorSrv-response>"
  (cl:format cl:nil "FaultInjection_Response response~%~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Response~%bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjectionSensorSrv-response)))
  "Returns full string definition for message of type 'FaultInjectionSensorSrv-response"
  (cl:format cl:nil "FaultInjection_Response response~%~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Response~%bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjectionSensorSrv-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'response))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjectionSensorSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjectionSensorSrv-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'FaultInjectionSensorSrv)))
  'FaultInjectionSensorSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'FaultInjectionSensorSrv)))
  'FaultInjectionSensorSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionSensorSrv)))
  "Returns string type for a service object of type '<FaultInjectionSensorSrv>"
  "morai_msgs/FaultInjectionSensorSrv")