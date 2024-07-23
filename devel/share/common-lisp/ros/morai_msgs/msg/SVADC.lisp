; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude SVADC.msg.html

(cl:defclass <SVADC> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (collisionCount
    :reader collisionCount
    :initarg :collisionCount
    :type cl:integer
    :initform 0)
   (signalViolationCount
    :reader signalViolationCount
    :initarg :signalViolationCount
    :type cl:integer
    :initform 0)
   (speedLimitCount
    :reader speedLimitCount
    :initarg :speedLimitCount
    :type cl:integer
    :initform 0))
)

(cl:defclass SVADC (<SVADC>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SVADC>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SVADC)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<SVADC> is deprecated: use morai_msgs-msg:SVADC instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SVADC>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:header-val is deprecated.  Use morai_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'collisionCount-val :lambda-list '(m))
(cl:defmethod collisionCount-val ((m <SVADC>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:collisionCount-val is deprecated.  Use morai_msgs-msg:collisionCount instead.")
  (collisionCount m))

(cl:ensure-generic-function 'signalViolationCount-val :lambda-list '(m))
(cl:defmethod signalViolationCount-val ((m <SVADC>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:signalViolationCount-val is deprecated.  Use morai_msgs-msg:signalViolationCount instead.")
  (signalViolationCount m))

(cl:ensure-generic-function 'speedLimitCount-val :lambda-list '(m))
(cl:defmethod speedLimitCount-val ((m <SVADC>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:speedLimitCount-val is deprecated.  Use morai_msgs-msg:speedLimitCount instead.")
  (speedLimitCount m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SVADC>) ostream)
  "Serializes a message object of type '<SVADC>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'collisionCount)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'signalViolationCount)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'speedLimitCount)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SVADC>) istream)
  "Deserializes a message object of type '<SVADC>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'collisionCount) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'signalViolationCount) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'speedLimitCount) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SVADC>)))
  "Returns string type for a message object of type '<SVADC>"
  "morai_msgs/SVADC")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SVADC)))
  "Returns string type for a message object of type 'SVADC"
  "morai_msgs/SVADC")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SVADC>)))
  "Returns md5sum for a message object of type '<SVADC>"
  "c180496093e554e39b1b25419d7fdd6e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SVADC)))
  "Returns md5sum for a message object of type 'SVADC"
  "c180496093e554e39b1b25419d7fdd6e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SVADC>)))
  "Returns full string definition for message of type '<SVADC>"
  (cl:format cl:nil "Header header~%int32 collisionCount~%int32 signalViolationCount~%int32 speedLimitCount~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SVADC)))
  "Returns full string definition for message of type 'SVADC"
  (cl:format cl:nil "Header header~%int32 collisionCount~%int32 signalViolationCount~%int32 speedLimitCount~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SVADC>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SVADC>))
  "Converts a ROS message object to a list"
  (cl:list 'SVADC
    (cl:cons ':header (header msg))
    (cl:cons ':collisionCount (collisionCount msg))
    (cl:cons ':signalViolationCount (signalViolationCount msg))
    (cl:cons ':speedLimitCount (speedLimitCount msg))
))
