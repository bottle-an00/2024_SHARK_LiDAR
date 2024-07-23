; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude MultiPlayEventRequest.msg.html

(cl:defclass <MultiPlayEventRequest> (roslisp-msg-protocol:ros-message)
  ((requestRespawn
    :reader requestRespawn
    :initarg :requestRespawn
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MultiPlayEventRequest (<MultiPlayEventRequest>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MultiPlayEventRequest>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MultiPlayEventRequest)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<MultiPlayEventRequest> is deprecated: use morai_msgs-msg:MultiPlayEventRequest instead.")))

(cl:ensure-generic-function 'requestRespawn-val :lambda-list '(m))
(cl:defmethod requestRespawn-val ((m <MultiPlayEventRequest>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:requestRespawn-val is deprecated.  Use morai_msgs-msg:requestRespawn instead.")
  (requestRespawn m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MultiPlayEventRequest>) ostream)
  "Serializes a message object of type '<MultiPlayEventRequest>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'requestRespawn) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MultiPlayEventRequest>) istream)
  "Deserializes a message object of type '<MultiPlayEventRequest>"
    (cl:setf (cl:slot-value msg 'requestRespawn) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MultiPlayEventRequest>)))
  "Returns string type for a message object of type '<MultiPlayEventRequest>"
  "morai_msgs/MultiPlayEventRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MultiPlayEventRequest)))
  "Returns string type for a message object of type 'MultiPlayEventRequest"
  "morai_msgs/MultiPlayEventRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MultiPlayEventRequest>)))
  "Returns md5sum for a message object of type '<MultiPlayEventRequest>"
  "6d7b6e13e2c1671b06638e7f201595a3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MultiPlayEventRequest)))
  "Returns md5sum for a message object of type 'MultiPlayEventRequest"
  "6d7b6e13e2c1671b06638e7f201595a3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MultiPlayEventRequest>)))
  "Returns full string definition for message of type '<MultiPlayEventRequest>"
  (cl:format cl:nil "bool requestRespawn~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MultiPlayEventRequest)))
  "Returns full string definition for message of type 'MultiPlayEventRequest"
  (cl:format cl:nil "bool requestRespawn~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MultiPlayEventRequest>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MultiPlayEventRequest>))
  "Converts a ROS message object to a list"
  (cl:list 'MultiPlayEventRequest
    (cl:cons ':requestRespawn (requestRespawn msg))
))
