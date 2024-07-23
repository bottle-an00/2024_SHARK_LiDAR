; Auto-generated. Do not edit!


(cl:in-package morai_msgs-srv)


;//! \htmlinclude MultiPlayEventSrv-request.msg.html

(cl:defclass <MultiPlayEventSrv-request> (roslisp-msg-protocol:ros-message)
  ((request
    :reader request
    :initarg :request
    :type morai_msgs-msg:MultiPlayEventRequest
    :initform (cl:make-instance 'morai_msgs-msg:MultiPlayEventRequest)))
)

(cl:defclass MultiPlayEventSrv-request (<MultiPlayEventSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MultiPlayEventSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MultiPlayEventSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<MultiPlayEventSrv-request> is deprecated: use morai_msgs-srv:MultiPlayEventSrv-request instead.")))

(cl:ensure-generic-function 'request-val :lambda-list '(m))
(cl:defmethod request-val ((m <MultiPlayEventSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:request-val is deprecated.  Use morai_msgs-srv:request instead.")
  (request m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MultiPlayEventSrv-request>) ostream)
  "Serializes a message object of type '<MultiPlayEventSrv-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'request) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MultiPlayEventSrv-request>) istream)
  "Deserializes a message object of type '<MultiPlayEventSrv-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'request) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MultiPlayEventSrv-request>)))
  "Returns string type for a service object of type '<MultiPlayEventSrv-request>"
  "morai_msgs/MultiPlayEventSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MultiPlayEventSrv-request)))
  "Returns string type for a service object of type 'MultiPlayEventSrv-request"
  "morai_msgs/MultiPlayEventSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MultiPlayEventSrv-request>)))
  "Returns md5sum for a message object of type '<MultiPlayEventSrv-request>"
  "5ff2047bbd823c7a4e40fc93cb1bb42d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MultiPlayEventSrv-request)))
  "Returns md5sum for a message object of type 'MultiPlayEventSrv-request"
  "5ff2047bbd823c7a4e40fc93cb1bb42d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MultiPlayEventSrv-request>)))
  "Returns full string definition for message of type '<MultiPlayEventSrv-request>"
  (cl:format cl:nil "MultiPlayEventRequest request~%~%================================================================================~%MSG: morai_msgs/MultiPlayEventRequest~%bool requestRespawn~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MultiPlayEventSrv-request)))
  "Returns full string definition for message of type 'MultiPlayEventSrv-request"
  (cl:format cl:nil "MultiPlayEventRequest request~%~%================================================================================~%MSG: morai_msgs/MultiPlayEventRequest~%bool requestRespawn~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MultiPlayEventSrv-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'request))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MultiPlayEventSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MultiPlayEventSrv-request
    (cl:cons ':request (request msg))
))
;//! \htmlinclude MultiPlayEventSrv-response.msg.html

(cl:defclass <MultiPlayEventSrv-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type morai_msgs-msg:MultiPlayEventResponse
    :initform (cl:make-instance 'morai_msgs-msg:MultiPlayEventResponse)))
)

(cl:defclass MultiPlayEventSrv-response (<MultiPlayEventSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MultiPlayEventSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MultiPlayEventSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<MultiPlayEventSrv-response> is deprecated: use morai_msgs-srv:MultiPlayEventSrv-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <MultiPlayEventSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:response-val is deprecated.  Use morai_msgs-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MultiPlayEventSrv-response>) ostream)
  "Serializes a message object of type '<MultiPlayEventSrv-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'response) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MultiPlayEventSrv-response>) istream)
  "Deserializes a message object of type '<MultiPlayEventSrv-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'response) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MultiPlayEventSrv-response>)))
  "Returns string type for a service object of type '<MultiPlayEventSrv-response>"
  "morai_msgs/MultiPlayEventSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MultiPlayEventSrv-response)))
  "Returns string type for a service object of type 'MultiPlayEventSrv-response"
  "morai_msgs/MultiPlayEventSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MultiPlayEventSrv-response>)))
  "Returns md5sum for a message object of type '<MultiPlayEventSrv-response>"
  "5ff2047bbd823c7a4e40fc93cb1bb42d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MultiPlayEventSrv-response)))
  "Returns md5sum for a message object of type 'MultiPlayEventSrv-response"
  "5ff2047bbd823c7a4e40fc93cb1bb42d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MultiPlayEventSrv-response>)))
  "Returns full string definition for message of type '<MultiPlayEventSrv-response>"
  (cl:format cl:nil "MultiPlayEventResponse response~%~%~%================================================================================~%MSG: morai_msgs/MultiPlayEventResponse~%bool result~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MultiPlayEventSrv-response)))
  "Returns full string definition for message of type 'MultiPlayEventSrv-response"
  (cl:format cl:nil "MultiPlayEventResponse response~%~%~%================================================================================~%MSG: morai_msgs/MultiPlayEventResponse~%bool result~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MultiPlayEventSrv-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'response))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MultiPlayEventSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MultiPlayEventSrv-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MultiPlayEventSrv)))
  'MultiPlayEventSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MultiPlayEventSrv)))
  'MultiPlayEventSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MultiPlayEventSrv)))
  "Returns string type for a service object of type '<MultiPlayEventSrv>"
  "morai_msgs/MultiPlayEventSrv")