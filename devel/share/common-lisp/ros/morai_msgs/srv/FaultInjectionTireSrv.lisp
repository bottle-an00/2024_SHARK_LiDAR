; Auto-generated. Do not edit!


(cl:in-package morai_msgs-srv)


;//! \htmlinclude FaultInjectionTireSrv-request.msg.html

(cl:defclass <FaultInjectionTireSrv-request> (roslisp-msg-protocol:ros-message)
  ((request
    :reader request
    :initarg :request
    :type morai_msgs-msg:FaultInjection_Tire
    :initform (cl:make-instance 'morai_msgs-msg:FaultInjection_Tire)))
)

(cl:defclass FaultInjectionTireSrv-request (<FaultInjectionTireSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjectionTireSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjectionTireSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<FaultInjectionTireSrv-request> is deprecated: use morai_msgs-srv:FaultInjectionTireSrv-request instead.")))

(cl:ensure-generic-function 'request-val :lambda-list '(m))
(cl:defmethod request-val ((m <FaultInjectionTireSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:request-val is deprecated.  Use morai_msgs-srv:request instead.")
  (request m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjectionTireSrv-request>) ostream)
  "Serializes a message object of type '<FaultInjectionTireSrv-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'request) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjectionTireSrv-request>) istream)
  "Deserializes a message object of type '<FaultInjectionTireSrv-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'request) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjectionTireSrv-request>)))
  "Returns string type for a service object of type '<FaultInjectionTireSrv-request>"
  "morai_msgs/FaultInjectionTireSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionTireSrv-request)))
  "Returns string type for a service object of type 'FaultInjectionTireSrv-request"
  "morai_msgs/FaultInjectionTireSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjectionTireSrv-request>)))
  "Returns md5sum for a message object of type '<FaultInjectionTireSrv-request>"
  "4c1cd51f8732dd56891a353f6f931b8a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjectionTireSrv-request)))
  "Returns md5sum for a message object of type 'FaultInjectionTireSrv-request"
  "4c1cd51f8732dd56891a353f6f931b8a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjectionTireSrv-request>)))
  "Returns full string definition for message of type '<FaultInjectionTireSrv-request>"
  (cl:format cl:nil "FaultInjection_Tire request~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Tire~%int32 unique_id~%int32 tire_index~%~%int32 fault_class~%int32 fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjectionTireSrv-request)))
  "Returns full string definition for message of type 'FaultInjectionTireSrv-request"
  (cl:format cl:nil "FaultInjection_Tire request~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Tire~%int32 unique_id~%int32 tire_index~%~%int32 fault_class~%int32 fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjectionTireSrv-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'request))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjectionTireSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjectionTireSrv-request
    (cl:cons ':request (request msg))
))
;//! \htmlinclude FaultInjectionTireSrv-response.msg.html

(cl:defclass <FaultInjectionTireSrv-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type morai_msgs-msg:FaultInjection_Response
    :initform (cl:make-instance 'morai_msgs-msg:FaultInjection_Response)))
)

(cl:defclass FaultInjectionTireSrv-response (<FaultInjectionTireSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjectionTireSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjectionTireSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<FaultInjectionTireSrv-response> is deprecated: use morai_msgs-srv:FaultInjectionTireSrv-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <FaultInjectionTireSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:response-val is deprecated.  Use morai_msgs-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjectionTireSrv-response>) ostream)
  "Serializes a message object of type '<FaultInjectionTireSrv-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'response) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjectionTireSrv-response>) istream)
  "Deserializes a message object of type '<FaultInjectionTireSrv-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'response) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjectionTireSrv-response>)))
  "Returns string type for a service object of type '<FaultInjectionTireSrv-response>"
  "morai_msgs/FaultInjectionTireSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionTireSrv-response)))
  "Returns string type for a service object of type 'FaultInjectionTireSrv-response"
  "morai_msgs/FaultInjectionTireSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjectionTireSrv-response>)))
  "Returns md5sum for a message object of type '<FaultInjectionTireSrv-response>"
  "4c1cd51f8732dd56891a353f6f931b8a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjectionTireSrv-response)))
  "Returns md5sum for a message object of type 'FaultInjectionTireSrv-response"
  "4c1cd51f8732dd56891a353f6f931b8a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjectionTireSrv-response>)))
  "Returns full string definition for message of type '<FaultInjectionTireSrv-response>"
  (cl:format cl:nil "FaultInjection_Response response~%~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Response~%bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjectionTireSrv-response)))
  "Returns full string definition for message of type 'FaultInjectionTireSrv-response"
  (cl:format cl:nil "FaultInjection_Response response~%~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Response~%bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjectionTireSrv-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'response))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjectionTireSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjectionTireSrv-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'FaultInjectionTireSrv)))
  'FaultInjectionTireSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'FaultInjectionTireSrv)))
  'FaultInjectionTireSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionTireSrv)))
  "Returns string type for a service object of type '<FaultInjectionTireSrv>"
  "morai_msgs/FaultInjectionTireSrv")