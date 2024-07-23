; Auto-generated. Do not edit!


(cl:in-package morai_msgs-srv)


;//! \htmlinclude WoowaDillyEventCmdSrv-request.msg.html

(cl:defclass <WoowaDillyEventCmdSrv-request> (roslisp-msg-protocol:ros-message)
  ((request
    :reader request
    :initarg :request
    :type morai_msgs-msg:DillyCmd
    :initform (cl:make-instance 'morai_msgs-msg:DillyCmd)))
)

(cl:defclass WoowaDillyEventCmdSrv-request (<WoowaDillyEventCmdSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WoowaDillyEventCmdSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WoowaDillyEventCmdSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<WoowaDillyEventCmdSrv-request> is deprecated: use morai_msgs-srv:WoowaDillyEventCmdSrv-request instead.")))

(cl:ensure-generic-function 'request-val :lambda-list '(m))
(cl:defmethod request-val ((m <WoowaDillyEventCmdSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:request-val is deprecated.  Use morai_msgs-srv:request instead.")
  (request m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WoowaDillyEventCmdSrv-request>) ostream)
  "Serializes a message object of type '<WoowaDillyEventCmdSrv-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'request) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WoowaDillyEventCmdSrv-request>) istream)
  "Deserializes a message object of type '<WoowaDillyEventCmdSrv-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'request) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WoowaDillyEventCmdSrv-request>)))
  "Returns string type for a service object of type '<WoowaDillyEventCmdSrv-request>"
  "morai_msgs/WoowaDillyEventCmdSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WoowaDillyEventCmdSrv-request)))
  "Returns string type for a service object of type 'WoowaDillyEventCmdSrv-request"
  "morai_msgs/WoowaDillyEventCmdSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WoowaDillyEventCmdSrv-request>)))
  "Returns md5sum for a message object of type '<WoowaDillyEventCmdSrv-request>"
  "1955b6d4c59847467e59b20a60d97dee")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WoowaDillyEventCmdSrv-request)))
  "Returns md5sum for a message object of type 'WoowaDillyEventCmdSrv-request"
  "1955b6d4c59847467e59b20a60d97dee")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WoowaDillyEventCmdSrv-request>)))
  "Returns full string definition for message of type '<WoowaDillyEventCmdSrv-request>"
  (cl:format cl:nil "DillyCmd request~%~%================================================================================~%MSG: morai_msgs/DillyCmd~%bool isPickup~%int32 deliveryItemIndex~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WoowaDillyEventCmdSrv-request)))
  "Returns full string definition for message of type 'WoowaDillyEventCmdSrv-request"
  (cl:format cl:nil "DillyCmd request~%~%================================================================================~%MSG: morai_msgs/DillyCmd~%bool isPickup~%int32 deliveryItemIndex~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WoowaDillyEventCmdSrv-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'request))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WoowaDillyEventCmdSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'WoowaDillyEventCmdSrv-request
    (cl:cons ':request (request msg))
))
;//! \htmlinclude WoowaDillyEventCmdSrv-response.msg.html

(cl:defclass <WoowaDillyEventCmdSrv-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type morai_msgs-msg:DillyCmdResponse
    :initform (cl:make-instance 'morai_msgs-msg:DillyCmdResponse)))
)

(cl:defclass WoowaDillyEventCmdSrv-response (<WoowaDillyEventCmdSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WoowaDillyEventCmdSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WoowaDillyEventCmdSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-srv:<WoowaDillyEventCmdSrv-response> is deprecated: use morai_msgs-srv:WoowaDillyEventCmdSrv-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <WoowaDillyEventCmdSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-srv:response-val is deprecated.  Use morai_msgs-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WoowaDillyEventCmdSrv-response>) ostream)
  "Serializes a message object of type '<WoowaDillyEventCmdSrv-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'response) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WoowaDillyEventCmdSrv-response>) istream)
  "Deserializes a message object of type '<WoowaDillyEventCmdSrv-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'response) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WoowaDillyEventCmdSrv-response>)))
  "Returns string type for a service object of type '<WoowaDillyEventCmdSrv-response>"
  "morai_msgs/WoowaDillyEventCmdSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WoowaDillyEventCmdSrv-response)))
  "Returns string type for a service object of type 'WoowaDillyEventCmdSrv-response"
  "morai_msgs/WoowaDillyEventCmdSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WoowaDillyEventCmdSrv-response>)))
  "Returns md5sum for a message object of type '<WoowaDillyEventCmdSrv-response>"
  "1955b6d4c59847467e59b20a60d97dee")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WoowaDillyEventCmdSrv-response)))
  "Returns md5sum for a message object of type 'WoowaDillyEventCmdSrv-response"
  "1955b6d4c59847467e59b20a60d97dee")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WoowaDillyEventCmdSrv-response>)))
  "Returns full string definition for message of type '<WoowaDillyEventCmdSrv-response>"
  (cl:format cl:nil "DillyCmdResponse response~%~%================================================================================~%MSG: morai_msgs/DillyCmdResponse~%bool result~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WoowaDillyEventCmdSrv-response)))
  "Returns full string definition for message of type 'WoowaDillyEventCmdSrv-response"
  (cl:format cl:nil "DillyCmdResponse response~%~%================================================================================~%MSG: morai_msgs/DillyCmdResponse~%bool result~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WoowaDillyEventCmdSrv-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'response))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WoowaDillyEventCmdSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'WoowaDillyEventCmdSrv-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'WoowaDillyEventCmdSrv)))
  'WoowaDillyEventCmdSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'WoowaDillyEventCmdSrv)))
  'WoowaDillyEventCmdSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WoowaDillyEventCmdSrv)))
  "Returns string type for a service object of type '<WoowaDillyEventCmdSrv>"
  "morai_msgs/WoowaDillyEventCmdSrv")