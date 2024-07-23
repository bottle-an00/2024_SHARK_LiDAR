; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude FaultStatusInfo_Sensor.msg.html

(cl:defclass <FaultStatusInfo_Sensor> (roslisp-msg-protocol:ros-message)
  ((sensor_id
    :reader sensor_id
    :initarg :sensor_id
    :type cl:integer
    :initform 0)
   (sensor
    :reader sensor
    :initarg :sensor
    :type morai_msgs-msg:FaultStatusInfo_Overall
    :initform (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Overall)))
)

(cl:defclass FaultStatusInfo_Sensor (<FaultStatusInfo_Sensor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultStatusInfo_Sensor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultStatusInfo_Sensor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<FaultStatusInfo_Sensor> is deprecated: use morai_msgs-msg:FaultStatusInfo_Sensor instead.")))

(cl:ensure-generic-function 'sensor_id-val :lambda-list '(m))
(cl:defmethod sensor_id-val ((m <FaultStatusInfo_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:sensor_id-val is deprecated.  Use morai_msgs-msg:sensor_id instead.")
  (sensor_id m))

(cl:ensure-generic-function 'sensor-val :lambda-list '(m))
(cl:defmethod sensor-val ((m <FaultStatusInfo_Sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:sensor-val is deprecated.  Use morai_msgs-msg:sensor instead.")
  (sensor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultStatusInfo_Sensor>) ostream)
  "Serializes a message object of type '<FaultStatusInfo_Sensor>"
  (cl:let* ((signed (cl:slot-value msg 'sensor_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'sensor) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultStatusInfo_Sensor>) istream)
  "Deserializes a message object of type '<FaultStatusInfo_Sensor>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sensor_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'sensor) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultStatusInfo_Sensor>)))
  "Returns string type for a message object of type '<FaultStatusInfo_Sensor>"
  "morai_msgs/FaultStatusInfo_Sensor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultStatusInfo_Sensor)))
  "Returns string type for a message object of type 'FaultStatusInfo_Sensor"
  "morai_msgs/FaultStatusInfo_Sensor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultStatusInfo_Sensor>)))
  "Returns md5sum for a message object of type '<FaultStatusInfo_Sensor>"
  "9ffcbdb400d2f73cb504fbb8f540f234")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultStatusInfo_Sensor)))
  "Returns md5sum for a message object of type 'FaultStatusInfo_Sensor"
  "9ffcbdb400d2f73cb504fbb8f540f234")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultStatusInfo_Sensor>)))
  "Returns full string definition for message of type '<FaultStatusInfo_Sensor>"
  (cl:format cl:nil "int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultStatusInfo_Sensor)))
  "Returns full string definition for message of type 'FaultStatusInfo_Sensor"
  (cl:format cl:nil "int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultStatusInfo_Sensor>))
  (cl:+ 0
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'sensor))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultStatusInfo_Sensor>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultStatusInfo_Sensor
    (cl:cons ':sensor_id (sensor_id msg))
    (cl:cons ':sensor (sensor msg))
))
