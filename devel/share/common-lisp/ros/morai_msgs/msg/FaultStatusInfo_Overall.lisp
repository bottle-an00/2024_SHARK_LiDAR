; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude FaultStatusInfo_Overall.msg.html

(cl:defclass <FaultStatusInfo_Overall> (roslisp-msg-protocol:ros-message)
  ((status
    :reader status
    :initarg :status
    :type cl:boolean
    :initform cl:nil)
   (fault_subclass
    :reader fault_subclass
    :initarg :fault_subclass
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass FaultStatusInfo_Overall (<FaultStatusInfo_Overall>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultStatusInfo_Overall>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultStatusInfo_Overall)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<FaultStatusInfo_Overall> is deprecated: use morai_msgs-msg:FaultStatusInfo_Overall instead.")))

(cl:ensure-generic-function 'status-val :lambda-list '(m))
(cl:defmethod status-val ((m <FaultStatusInfo_Overall>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:status-val is deprecated.  Use morai_msgs-msg:status instead.")
  (status m))

(cl:ensure-generic-function 'fault_subclass-val :lambda-list '(m))
(cl:defmethod fault_subclass-val ((m <FaultStatusInfo_Overall>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:fault_subclass-val is deprecated.  Use morai_msgs-msg:fault_subclass instead.")
  (fault_subclass m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultStatusInfo_Overall>) ostream)
  "Serializes a message object of type '<FaultStatusInfo_Overall>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'status) 1 0)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'fault_subclass))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'fault_subclass))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultStatusInfo_Overall>) istream)
  "Deserializes a message object of type '<FaultStatusInfo_Overall>"
    (cl:setf (cl:slot-value msg 'status) (cl:not (cl:zerop (cl:read-byte istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'fault_subclass) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'fault_subclass)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultStatusInfo_Overall>)))
  "Returns string type for a message object of type '<FaultStatusInfo_Overall>"
  "morai_msgs/FaultStatusInfo_Overall")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultStatusInfo_Overall)))
  "Returns string type for a message object of type 'FaultStatusInfo_Overall"
  "morai_msgs/FaultStatusInfo_Overall")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultStatusInfo_Overall>)))
  "Returns md5sum for a message object of type '<FaultStatusInfo_Overall>"
  "49c4320f71e991dad6fc697eff35406f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultStatusInfo_Overall)))
  "Returns md5sum for a message object of type 'FaultStatusInfo_Overall"
  "49c4320f71e991dad6fc697eff35406f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultStatusInfo_Overall>)))
  "Returns full string definition for message of type '<FaultStatusInfo_Overall>"
  (cl:format cl:nil "bool status~%int32[] fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultStatusInfo_Overall)))
  "Returns full string definition for message of type 'FaultStatusInfo_Overall"
  (cl:format cl:nil "bool status~%int32[] fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultStatusInfo_Overall>))
  (cl:+ 0
     1
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'fault_subclass) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultStatusInfo_Overall>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultStatusInfo_Overall
    (cl:cons ':status (status msg))
    (cl:cons ':fault_subclass (fault_subclass msg))
))
