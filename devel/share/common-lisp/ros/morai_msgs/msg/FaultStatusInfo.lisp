; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude FaultStatusInfo.msg.html

(cl:defclass <FaultStatusInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (unique_id
    :reader unique_id
    :initarg :unique_id
    :type cl:integer
    :initform 0)
   (vehicle
    :reader vehicle
    :initarg :vehicle
    :type morai_msgs-msg:FaultStatusInfo_Vehicle
    :initform (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Vehicle))
   (sensors
    :reader sensors
    :initarg :sensors
    :type (cl:vector morai_msgs-msg:FaultStatusInfo_Sensor)
   :initform (cl:make-array 0 :element-type 'morai_msgs-msg:FaultStatusInfo_Sensor :initial-element (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Sensor))))
)

(cl:defclass FaultStatusInfo (<FaultStatusInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultStatusInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultStatusInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<FaultStatusInfo> is deprecated: use morai_msgs-msg:FaultStatusInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <FaultStatusInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:header-val is deprecated.  Use morai_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'unique_id-val :lambda-list '(m))
(cl:defmethod unique_id-val ((m <FaultStatusInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:unique_id-val is deprecated.  Use morai_msgs-msg:unique_id instead.")
  (unique_id m))

(cl:ensure-generic-function 'vehicle-val :lambda-list '(m))
(cl:defmethod vehicle-val ((m <FaultStatusInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:vehicle-val is deprecated.  Use morai_msgs-msg:vehicle instead.")
  (vehicle m))

(cl:ensure-generic-function 'sensors-val :lambda-list '(m))
(cl:defmethod sensors-val ((m <FaultStatusInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:sensors-val is deprecated.  Use morai_msgs-msg:sensors instead.")
  (sensors m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultStatusInfo>) ostream)
  "Serializes a message object of type '<FaultStatusInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'unique_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'vehicle) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'sensors))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'sensors))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultStatusInfo>) istream)
  "Deserializes a message object of type '<FaultStatusInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'unique_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'vehicle) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'sensors) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'sensors)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Sensor))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultStatusInfo>)))
  "Returns string type for a message object of type '<FaultStatusInfo>"
  "morai_msgs/FaultStatusInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultStatusInfo)))
  "Returns string type for a message object of type 'FaultStatusInfo"
  "morai_msgs/FaultStatusInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultStatusInfo>)))
  "Returns md5sum for a message object of type '<FaultStatusInfo>"
  "514c099d9ef1148c019de61e11a471bb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultStatusInfo)))
  "Returns md5sum for a message object of type 'FaultStatusInfo"
  "514c099d9ef1148c019de61e11a471bb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultStatusInfo>)))
  "Returns full string definition for message of type '<FaultStatusInfo>"
  (cl:format cl:nil "Header header~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultStatusInfo)))
  "Returns full string definition for message of type 'FaultStatusInfo"
  (cl:format cl:nil "Header header~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultStatusInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicle))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'sensors) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultStatusInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultStatusInfo
    (cl:cons ':header (header msg))
    (cl:cons ':unique_id (unique_id msg))
    (cl:cons ':vehicle (vehicle msg))
    (cl:cons ':sensors (sensors msg))
))
