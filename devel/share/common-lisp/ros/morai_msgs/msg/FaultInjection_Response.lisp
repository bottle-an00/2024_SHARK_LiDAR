; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude FaultInjection_Response.msg.html

(cl:defclass <FaultInjection_Response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:boolean
    :initform cl:nil)
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

(cl:defclass FaultInjection_Response (<FaultInjection_Response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultInjection_Response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultInjection_Response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<FaultInjection_Response> is deprecated: use morai_msgs-msg:FaultInjection_Response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <FaultInjection_Response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:result-val is deprecated.  Use morai_msgs-msg:result instead.")
  (result m))

(cl:ensure-generic-function 'unique_id-val :lambda-list '(m))
(cl:defmethod unique_id-val ((m <FaultInjection_Response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:unique_id-val is deprecated.  Use morai_msgs-msg:unique_id instead.")
  (unique_id m))

(cl:ensure-generic-function 'vehicle-val :lambda-list '(m))
(cl:defmethod vehicle-val ((m <FaultInjection_Response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:vehicle-val is deprecated.  Use morai_msgs-msg:vehicle instead.")
  (vehicle m))

(cl:ensure-generic-function 'sensors-val :lambda-list '(m))
(cl:defmethod sensors-val ((m <FaultInjection_Response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:sensors-val is deprecated.  Use morai_msgs-msg:sensors instead.")
  (sensors m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultInjection_Response>) ostream)
  "Serializes a message object of type '<FaultInjection_Response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'result) 1 0)) ostream)
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultInjection_Response>) istream)
  "Deserializes a message object of type '<FaultInjection_Response>"
    (cl:setf (cl:slot-value msg 'result) (cl:not (cl:zerop (cl:read-byte istream))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultInjection_Response>)))
  "Returns string type for a message object of type '<FaultInjection_Response>"
  "morai_msgs/FaultInjection_Response")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultInjection_Response)))
  "Returns string type for a message object of type 'FaultInjection_Response"
  "morai_msgs/FaultInjection_Response")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultInjection_Response>)))
  "Returns md5sum for a message object of type '<FaultInjection_Response>"
  "62056bf4fc5f4a1c260169ca104b9ebf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultInjection_Response)))
  "Returns md5sum for a message object of type 'FaultInjection_Response"
  "62056bf4fc5f4a1c260169ca104b9ebf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultInjection_Response>)))
  "Returns full string definition for message of type '<FaultInjection_Response>"
  (cl:format cl:nil "bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultInjection_Response)))
  "Returns full string definition for message of type 'FaultInjection_Response"
  (cl:format cl:nil "bool result~%~%int32 unique_id~%FaultStatusInfo_Vehicle vehicle~%FaultStatusInfo_Sensor[] sensors~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Vehicle~%FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Sensor~%int32 sensor_id~%FaultStatusInfo_Overall sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultInjection_Response>))
  (cl:+ 0
     1
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'vehicle))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'sensors) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultInjection_Response>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultInjection_Response
    (cl:cons ':result (result msg))
    (cl:cons ':unique_id (unique_id msg))
    (cl:cons ':vehicle (vehicle msg))
    (cl:cons ':sensors (sensors msg))
))
