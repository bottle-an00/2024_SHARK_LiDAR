; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude FaultInjection_Sensor.msg.html

(cl:defclass <FaultInjection_Sensor> (roslisp-msg-protocol:ros-message)
  ((unique_id
    :reader unique_id
    :initarg :unique_id
    :type cl:integer
    :initform 0)
   (sensor_id
    :reader sensor_id
    :initarg :sensor_id
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
    :initform 0)
   (local_position_offset
    :reader local_position_offset
    :initarg :local_position_offset
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (local_rotation_offset
    :reader local_rotation_offset
    :initarg :local_rotation_offset
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass FaultInjection_Sensor (<FaultInjection_Sensor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjection_Sensor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjection_Sensor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<FaultInjection_Sensor> is deprecated: use morai_msgs-msg:FaultInjection_Sensor instead.")))

(cl:ensure-generic-function 'unique_id-val :lambda-list '(m))
(cl:defmethod unique_id-val ((m <FaultInjection_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:unique_id-val is deprecated.  Use morai_msgs-msg:unique_id instead.")
  (unique_id m))

(cl:ensure-generic-function 'sensor_id-val :lambda-list '(m))
(cl:defmethod sensor_id-val ((m <FaultInjection_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:sensor_id-val is deprecated.  Use morai_msgs-msg:sensor_id instead.")
  (sensor_id m))

(cl:ensure-generic-function 'fault_class-val :lambda-list '(m))
(cl:defmethod fault_class-val ((m <FaultInjection_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:fault_class-val is deprecated.  Use morai_msgs-msg:fault_class instead.")
  (fault_class m))

(cl:ensure-generic-function 'fault_subclass-val :lambda-list '(m))
(cl:defmethod fault_subclass-val ((m <FaultInjection_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:fault_subclass-val is deprecated.  Use morai_msgs-msg:fault_subclass instead.")
  (fault_subclass m))

(cl:ensure-generic-function 'local_position_offset-val :lambda-list '(m))
(cl:defmethod local_position_offset-val ((m <FaultInjection_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:local_position_offset-val is deprecated.  Use morai_msgs-msg:local_position_offset instead.")
  (local_position_offset m))

(cl:ensure-generic-function 'local_rotation_offset-val :lambda-list '(m))
(cl:defmethod local_rotation_offset-val ((m <FaultInjection_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:local_rotation_offset-val is deprecated.  Use morai_msgs-msg:local_rotation_offset instead.")
  (local_rotation_offset m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjection_Sensor>) ostream)
  "Serializes a message object of type '<FaultInjection_Sensor>"
  (cl:let* ((signed (cl:slot-value msg 'unique_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'sensor_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
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
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'local_position_offset) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'local_rotation_offset) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjection_Sensor>) istream)
  "Deserializes a message object of type '<FaultInjection_Sensor>"
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
      (cl:setf (cl:slot-value msg 'sensor_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
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
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'local_position_offset) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'local_rotation_offset) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjection_Sensor>)))
  "Returns string type for a message object of type '<FaultInjection_Sensor>"
  "morai_msgs/FaultInjection_Sensor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjection_Sensor)))
  "Returns string type for a message object of type 'FaultInjection_Sensor"
  "morai_msgs/FaultInjection_Sensor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjection_Sensor>)))
  "Returns md5sum for a message object of type '<FaultInjection_Sensor>"
  "1d09067e718a7214f8177394317316b2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjection_Sensor)))
  "Returns md5sum for a message object of type 'FaultInjection_Sensor"
  "1d09067e718a7214f8177394317316b2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjection_Sensor>)))
  "Returns full string definition for message of type '<FaultInjection_Sensor>"
  (cl:format cl:nil "int32 unique_id~%int32 sensor_id~%~%int32 fault_class~%int32 fault_subclass~%~%geometry_msgs/Vector3 local_position_offset~%geometry_msgs/Vector3 local_rotation_offset~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjection_Sensor)))
  "Returns full string definition for message of type 'FaultInjection_Sensor"
  (cl:format cl:nil "int32 unique_id~%int32 sensor_id~%~%int32 fault_class~%int32 fault_subclass~%~%geometry_msgs/Vector3 local_position_offset~%geometry_msgs/Vector3 local_rotation_offset~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjection_Sensor>))
  (cl:+ 0
     4
     4
     4
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'local_position_offset))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'local_rotation_offset))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjection_Sensor>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjection_Sensor
    (cl:cons ':unique_id (unique_id msg))
    (cl:cons ':sensor_id (sensor_id msg))
    (cl:cons ':fault_class (fault_class msg))
    (cl:cons ':fault_subclass (fault_subclass msg))
    (cl:cons ':local_position_offset (local_position_offset msg))
    (cl:cons ':local_rotation_offset (local_rotation_offset msg))
))
