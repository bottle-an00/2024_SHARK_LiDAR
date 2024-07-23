; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude DillyCmd.msg.html

(cl:defclass <DillyCmd> (roslisp-msg-protocol:ros-message)
  ((isPickup
    :reader isPickup
    :initarg :isPickup
    :type cl:boolean
    :initform cl:nil)
   (deliveryItemIndex
    :reader deliveryItemIndex
    :initarg :deliveryItemIndex
    :type cl:integer
    :initform 0))
)

(cl:defclass DillyCmd (<DillyCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DillyCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DillyCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<DillyCmd> is deprecated: use morai_msgs-msg:DillyCmd instead.")))

(cl:ensure-generic-function 'isPickup-val :lambda-list '(m))
(cl:defmethod isPickup-val ((m <DillyCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:isPickup-val is deprecated.  Use morai_msgs-msg:isPickup instead.")
  (isPickup m))

(cl:ensure-generic-function 'deliveryItemIndex-val :lambda-list '(m))
(cl:defmethod deliveryItemIndex-val ((m <DillyCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:deliveryItemIndex-val is deprecated.  Use morai_msgs-msg:deliveryItemIndex instead.")
  (deliveryItemIndex m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DillyCmd>) ostream)
  "Serializes a message object of type '<DillyCmd>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'isPickup) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'deliveryItemIndex)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DillyCmd>) istream)
  "Deserializes a message object of type '<DillyCmd>"
    (cl:setf (cl:slot-value msg 'isPickup) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'deliveryItemIndex) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DillyCmd>)))
  "Returns string type for a message object of type '<DillyCmd>"
  "morai_msgs/DillyCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DillyCmd)))
  "Returns string type for a message object of type 'DillyCmd"
  "morai_msgs/DillyCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DillyCmd>)))
  "Returns md5sum for a message object of type '<DillyCmd>"
  "4c01be8e010c2bb6f36d7ace7c88decc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DillyCmd)))
  "Returns md5sum for a message object of type 'DillyCmd"
  "4c01be8e010c2bb6f36d7ace7c88decc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DillyCmd>)))
  "Returns full string definition for message of type '<DillyCmd>"
  (cl:format cl:nil "bool isPickup~%int32 deliveryItemIndex~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DillyCmd)))
  "Returns full string definition for message of type 'DillyCmd"
  (cl:format cl:nil "bool isPickup~%int32 deliveryItemIndex~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DillyCmd>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DillyCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'DillyCmd
    (cl:cons ':isPickup (isPickup msg))
    (cl:cons ':deliveryItemIndex (deliveryItemIndex msg))
))
