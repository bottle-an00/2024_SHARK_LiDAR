; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude FaultInjection_Tire.msg.html

(cl:defclass <FaultInjection_Tire> (roslisp-msg-protocol:ros-message)
  ((unique_id
    :reader unique_id
    :initarg :unique_id
    :type cl:integer
    :initform 0)
   (tire_index
    :reader tire_index
    :initarg :tire_index
    :type cl:integer
    :initform 0)
   (fault_class
    :reader fault_class
    :initarg :fault_class
    :type cl:integer
    :initform 0)
   (fault_subclass
    :reader fault_subclass
    :initarg :fault_subclass
    :type cl:integer
    :initform 0))
)

(cl:defclass FaultInjection_Tire (<FaultInjection_Tire>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjection_Tire>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjection_Tire)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<FaultInjection_Tire> is deprecated: use morai_msgs-msg:FaultInjection_Tire instead.")))

(cl:ensure-generic-function 'unique_id-val :lambda-list '(m))
(cl:defmethod unique_id-val ((m <FaultInjection_Tire>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:unique_id-val is deprecated.  Use morai_msgs-msg:unique_id instead.")
  (unique_id m))

(cl:ensure-generic-function 'tire_index-val :lambda-list '(m))
(cl:defmethod tire_index-val ((m <FaultInjection_Tire>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:tire_index-val is deprecated.  Use morai_msgs-msg:tire_index instead.")
  (tire_index m))

(cl:ensure-generic-function 'fault_class-val :lambda-list '(m))
(cl:defmethod fault_class-val ((m <FaultInjection_Tire>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:fault_class-val is deprecated.  Use morai_msgs-msg:fault_class instead.")
  (fault_class m))

(cl:ensure-generic-function 'fault_subclass-val :lambda-list '(m))
(cl:defmethod fault_subclass-val ((m <FaultInjection_Tire>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:fault_subclass-val is deprecated.  Use morai_msgs-msg:fault_subclass instead.")
  (fault_subclass m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjection_Tire>) ostream)
  "Serializes a message object of type '<FaultInjection_Tire>"
  (cl:let* ((signed (cl:slot-value msg 'unique_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'tire_index)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'fault_class)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'fault_subclass)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjection_Tire>) istream)
  "Deserializes a message object of type '<FaultInjection_Tire>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'unique_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tire_index) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'fault_class) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'fault_subclass) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjection_Tire>)))
  "Returns string type for a message object of type '<FaultInjection_Tire>"
  "morai_msgs/FaultInjection_Tire")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjection_Tire)))
  "Returns string type for a message object of type 'FaultInjection_Tire"
  "morai_msgs/FaultInjection_Tire")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjection_Tire>)))
  "Returns md5sum for a message object of type '<FaultInjection_Tire>"
  "390f98f80684e87e512f8ec107a7d8c1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjection_Tire)))
  "Returns md5sum for a message object of type 'FaultInjection_Tire"
  "390f98f80684e87e512f8ec107a7d8c1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjection_Tire>)))
  "Returns full string definition for message of type '<FaultInjection_Tire>"
  (cl:format cl:nil "int32 unique_id~%int32 tire_index~%~%int32 fault_class~%int32 fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjection_Tire)))
  "Returns full string definition for message of type 'FaultInjection_Tire"
  (cl:format cl:nil "int32 unique_id~%int32 tire_index~%~%int32 fault_class~%int32 fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjection_Tire>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjection_Tire>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjection_Tire
    (cl:cons ':unique_id (unique_id msg))
    (cl:cons ':tire_index (tire_index msg))
    (cl:cons ':fault_class (fault_class msg))
    (cl:cons ':fault_subclass (fault_subclass msg))
))
