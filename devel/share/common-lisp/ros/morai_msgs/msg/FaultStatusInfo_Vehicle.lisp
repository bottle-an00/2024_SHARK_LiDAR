; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude FaultStatusInfo_Vehicle.msg.html

(cl:defclass <FaultStatusInfo_Vehicle> (roslisp-msg-protocol:ros-message)
  ((accel
    :reader accel
    :initarg :accel
    :type morai_msgs-msg:FaultStatusInfo_Overall
    :initform (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Overall))
   (brake
    :reader brake
    :initarg :brake
    :type morai_msgs-msg:FaultStatusInfo_Overall
    :initform (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Overall))
   (steer
    :reader steer
    :initarg :steer
    :type morai_msgs-msg:FaultStatusInfo_Overall
    :initform (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Overall))
   (tires
    :reader tires
    :initarg :tires
    :type (cl:vector morai_msgs-msg:FaultStatusInfo_Overall)
   :initform (cl:make-array 0 :element-type 'morai_msgs-msg:FaultStatusInfo_Overall :initial-element (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Overall))))
)

(cl:defclass FaultStatusInfo_Vehicle (<FaultStatusInfo_Vehicle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FaultStatusInfo_Vehicle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FaultStatusInfo_Vehicle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<FaultStatusInfo_Vehicle> is deprecated: use morai_msgs-msg:FaultStatusInfo_Vehicle instead.")))

(cl:ensure-generic-function 'accel-val :lambda-list '(m))
(cl:defmethod accel-val ((m <FaultStatusInfo_Vehicle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:accel-val is deprecated.  Use morai_msgs-msg:accel instead.")
  (accel m))

(cl:ensure-generic-function 'brake-val :lambda-list '(m))
(cl:defmethod brake-val ((m <FaultStatusInfo_Vehicle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:brake-val is deprecated.  Use morai_msgs-msg:brake instead.")
  (brake m))

(cl:ensure-generic-function 'steer-val :lambda-list '(m))
(cl:defmethod steer-val ((m <FaultStatusInfo_Vehicle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:steer-val is deprecated.  Use morai_msgs-msg:steer instead.")
  (steer m))

(cl:ensure-generic-function 'tires-val :lambda-list '(m))
(cl:defmethod tires-val ((m <FaultStatusInfo_Vehicle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:tires-val is deprecated.  Use morai_msgs-msg:tires instead.")
  (tires m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FaultStatusInfo_Vehicle>) ostream)
  "Serializes a message object of type '<FaultStatusInfo_Vehicle>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'accel) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'brake) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'steer) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'tires))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'tires))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FaultStatusInfo_Vehicle>) istream)
  "Deserializes a message object of type '<FaultStatusInfo_Vehicle>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'accel) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'brake) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'steer) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'tires) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'tires)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'morai_msgs-msg:FaultStatusInfo_Overall))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FaultStatusInfo_Vehicle>)))
  "Returns string type for a message object of type '<FaultStatusInfo_Vehicle>"
  "morai_msgs/FaultStatusInfo_Vehicle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FaultStatusInfo_Vehicle)))
  "Returns string type for a message object of type 'FaultStatusInfo_Vehicle"
  "morai_msgs/FaultStatusInfo_Vehicle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FaultStatusInfo_Vehicle>)))
  "Returns md5sum for a message object of type '<FaultStatusInfo_Vehicle>"
  "dcd69cdf7980329f2014366617eda419")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FaultStatusInfo_Vehicle)))
  "Returns md5sum for a message object of type 'FaultStatusInfo_Vehicle"
  "dcd69cdf7980329f2014366617eda419")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FaultStatusInfo_Vehicle>)))
  "Returns full string definition for message of type '<FaultStatusInfo_Vehicle>"
  (cl:format cl:nil "FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FaultStatusInfo_Vehicle)))
  "Returns full string definition for message of type 'FaultStatusInfo_Vehicle"
  (cl:format cl:nil "FaultStatusInfo_Overall accel~%FaultStatusInfo_Overall brake~%FaultStatusInfo_Overall steer~%FaultStatusInfo_Overall[] tires~%~%~%================================================================================~%MSG: morai_msgs/FaultStatusInfo_Overall~%bool status~%int32[] fault_subclass~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FaultStatusInfo_Vehicle>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'accel))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'brake))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'steer))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'tires) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FaultStatusInfo_Vehicle>))
  "Converts a ROS message object to a list"
  (cl:list 'FaultStatusInfo_Vehicle
    (cl:cons ':accel (accel msg))
    (cl:cons ':brake (brake msg))
    (cl:cons ':steer (steer msg))
    (cl:cons ':tires (tires msg))
))
