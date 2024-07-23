; Auto-generated. Do not edit!


(cl:in-package morai_msgs-srv)


;//! \htmlinclude FaultInjectionCtrlSrv-request.msg.html

(cl:defclass <FaultInjectionCtrlSrv-request> (roslisp-msg-protocol:ros-message)
  ((request
    :reader request
    :initarg :request
    :type morai_msgs-msg:FaultInjection_Controller
    :initform (cl:make-instance 'morai_msgs-msg:FaultInjection_Controller)))
)

(cl:defclass FaultInjectionCtrlSrv-request (<FaultInjectionCtrlSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjectionCtrlSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjectionCtrlSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<FaultInjectionCtrlSrv-request> is deprecated: use morai_msgs-srv:FaultInjectionCtrlSrv-request instead.")))

(cl:ensure-generic-function 'request-val :lambda-list '(m))
(cl:defmethod request-val ((m <FaultInjectionCtrlSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:request-val is deprecated.  Use morai_msgs-srv:request instead.")
  (request m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjectionCtrlSrv-request>) ostream)
  "Serializes a message object of type '<FaultInjectionCtrlSrv-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'request) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjectionCtrlSrv-request>) istream)
  "Deserializes a message object of type '<FaultInjectionCtrlSrv-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'request) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjectionCtrlSrv-request>)))
  "Returns string type for a service object of type '<FaultInjectionCtrlSrv-request>"
  "morai_msgs/FaultInjectionCtrlSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionCtrlSrv-request)))
  "Returns string type for a service object of type 'FaultInjectionCtrlSrv-request"
  "morai_msgs/FaultInjectionCtrlSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjectionCtrlSrv-request>)))
  "Returns md5sum for a message object of type '<FaultInjectionCtrlSrv-request>"
  "903881dc09163ac5bf8f905e4d1ee274")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjectionCtrlSrv-request)))
  "Returns md5sum for a message object of type 'FaultInjectionCtrlSrv-request"
  "903881dc09163ac5bf8f905e4d1ee274")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjectionCtrlSrv-request>)))
  "Returns full string definition for message of type '<FaultInjectionCtrlSrv-request>"
  (cl:format cl:nil "FaultInjection_Controller request~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Controller~%int32 unique_id~%~%int32 fault_location~%int32 fault_class~%int32 fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjectionCtrlSrv-request)))
  "Returns full string definition for message of type 'FaultInjectionCtrlSrv-request"
  (cl:format cl:nil "FaultInjection_Controller request~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Controller~%int32 unique_id~%~%int32 fault_location~%int32 fault_class~%int32 fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjectionCtrlSrv-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'request))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjectionCtrlSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjectionCtrlSrv-request
    (cl:cons ':request (request msg))
))
;//! \htmlinclude FaultInjectionCtrlSrv-response.msg.html

(cl:defclass <FaultInjectionCtrlSrv-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type morai_msgs-msg:FaultInjection_Response
    :initform (cl:make-instance 'morai_msgs-msg:FaultInjection_Response)))
)

(cl:defclass FaultInjectionCtrlSrv-response (<FaultInjectionCtrlSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjectionCtrlSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjectionCtrlSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<FaultInjectionCtrlSrv-response> is deprecated: use morai_msgs-srv:FaultInjectionCtrlSrv-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <FaultInjectionCtrlSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:response-val is deprecated.  Use morai_msgs-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjectionCtrlSrv-response>) ostream)
  "Serializes a message object of type '<FaultInjectionCtrlSrv-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'response) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjectionCtrlSrv-response>) istream)
  "Deserializes a message object of type '<FaultInjectionCtrlSrv-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'response) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjectionCtrlSrv-response>)))
  "Returns string type for a service object of type '<FaultInjectionCtrlSrv-response>"
  "morai_msgs/FaultInjectionCtrlSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionCtrlSrv-response)))
  "Returns string type for a service object of type 'FaultInjectionCtrlSrv-response"
  "morai_msgs/FaultInjectionCtrlSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjectionCtrlSrv-response>)))
  "Returns md5sum for a message object of type '<FaultInjectionCtrlSrv-response>"
  "903881dc09163ac5bf8f905e4d1ee274")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjectionCtrlSrv-response)))
  "Returns md5sum for a message object of type 'FaultInjectionCtrlSrv-response"
  "903881dc09163ac5bf8f905e4d1ee274")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjectionCtrlSrv-response>)))
  "Returns full string definition for message of type '<FaultInjectionCtrlSrv-response>"
  (cl:format cl:nil "FaultInjection_Response response~%~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Response~%bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjectionCtrlSrv-response)))
  "Returns full string definition for message of type 'FaultInjectionCtrlSrv-response"
  (cl:format cl:nil "FaultInjection_Response response~%~%~%================================================================================~%MSG: morai_msgs/FaultInjection_Response~%bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjectionCtrlSrv-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'response))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjectionCtrlSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjectionCtrlSrv-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'FaultInjectionCtrlSrv)))
  'FaultInjectionCtrlSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'FaultInjectionCtrlSrv)))
  'FaultInjectionCtrlSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjectionCtrlSrv)))
  "Returns string type for a service object of type '<FaultInjectionCtrlSrv>"
  "morai_msgs/FaultInjectionCtrlSrv")