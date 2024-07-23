; Auto-generated. Do not edit!


(cl:in-package morai_msgs-msg)


;//! \htmlinclude SkidSteer6wUGVCtrlCmd.msg.html

(cl:defclass <SkidSteer6wUGVCtrlCmd> (roslisp-msg-protocol:ros-message)
  ((cmd_type
    :reader cmd_type
    :initarg :cmd_type
    :type cl:integer
    :initform 0)
   (Forward_input
    :reader Forward_input
    :initarg :Forward_input
    :type cl:boolean
    :initform cl:nil)
   (Backward_input
    :reader Backward_input
    :initarg :Backward_input
    :type cl:boolean
    :initform cl:nil)
   (Left_Turn_input
    :reader Left_Turn_input
    :initarg :Left_Turn_input
    :type cl:boolean
    :initform cl:nil)
   (Right_Turn_input
    :reader Right_Turn_input
    :initarg :Right_Turn_input
    :type cl:boolean
    :initform cl:nil)
   (left_front_wheel_rpm
    :reader left_front_wheel_rpm
    :initarg :left_front_wheel_rpm
    :type cl:float
    :initform 0.0)
   (left_middle_wheel_rpm
    :reader left_middle_wheel_rpm
    :initarg :left_middle_wheel_rpm
    :type cl:float
    :initform 0.0)
   (left_rear_wheel_rpm
    :reader left_rear_wheel_rpm
    :initarg :left_rear_wheel_rpm
    :type cl:float
    :initform 0.0)
   (right_front_wheel_rpm
    :reader right_front_wheel_rpm
    :initarg :right_front_wheel_rpm
    :type cl:float
    :initform 0.0)
   (right_middle_wheel_rpm
    :reader right_middle_wheel_rpm
    :initarg :right_middle_wheel_rpm
    :type cl:float
    :initform 0.0)
   (right_rear_wheel_rpm
    :reader right_rear_wheel_rpm
    :initarg :right_rear_wheel_rpm
    :type cl:float
    :initform 0.0)
   (Target_linear_velocity
    :reader Target_linear_velocity
    :initarg :Target_linear_velocity
    :type cl:float
    :initform 0.0)
   (Target_angular_velocity
    :reader Target_angular_velocity
    :initarg :Target_angular_velocity
    :type cl:float
    :initform 0.0))
)

(cl:defclass SkidSteer6wUGVCtrlCmd (<SkidSteer6wUGVCtrlCmd>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SkidSteer6wUGVCtrlCmd>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SkidSteer6wUGVCtrlCmd)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name morai_msgs-msg:<SkidSteer6wUGVCtrlCmd> is deprecated: use morai_msgs-msg:SkidSteer6wUGVCtrlCmd instead.")))

(cl:ensure-generic-function 'cmd_type-val :lambda-list '(m))
(cl:defmethod cmd_type-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:cmd_type-val is deprecated.  Use morai_msgs-msg:cmd_type instead.")
  (cmd_type m))

(cl:ensure-generic-function 'Forward_input-val :lambda-list '(m))
(cl:defmethod Forward_input-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:Forward_input-val is deprecated.  Use morai_msgs-msg:Forward_input instead.")
  (Forward_input m))

(cl:ensure-generic-function 'Backward_input-val :lambda-list '(m))
(cl:defmethod Backward_input-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:Backward_input-val is deprecated.  Use morai_msgs-msg:Backward_input instead.")
  (Backward_input m))

(cl:ensure-generic-function 'Left_Turn_input-val :lambda-list '(m))
(cl:defmethod Left_Turn_input-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:Left_Turn_input-val is deprecated.  Use morai_msgs-msg:Left_Turn_input instead.")
  (Left_Turn_input m))

(cl:ensure-generic-function 'Right_Turn_input-val :lambda-list '(m))
(cl:defmethod Right_Turn_input-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:Right_Turn_input-val is deprecated.  Use morai_msgs-msg:Right_Turn_input instead.")
  (Right_Turn_input m))

(cl:ensure-generic-function 'left_front_wheel_rpm-val :lambda-list '(m))
(cl:defmethod left_front_wheel_rpm-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:left_front_wheel_rpm-val is deprecated.  Use morai_msgs-msg:left_front_wheel_rpm instead.")
  (left_front_wheel_rpm m))

(cl:ensure-generic-function 'left_middle_wheel_rpm-val :lambda-list '(m))
(cl:defmethod left_middle_wheel_rpm-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:left_middle_wheel_rpm-val is deprecated.  Use morai_msgs-msg:left_middle_wheel_rpm instead.")
  (left_middle_wheel_rpm m))

(cl:ensure-generic-function 'left_rear_wheel_rpm-val :lambda-list '(m))
(cl:defmethod left_rear_wheel_rpm-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:left_rear_wheel_rpm-val is deprecated.  Use morai_msgs-msg:left_rear_wheel_rpm instead.")
  (left_rear_wheel_rpm m))

(cl:ensure-generic-function 'right_front_wheel_rpm-val :lambda-list '(m))
(cl:defmethod right_front_wheel_rpm-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:right_front_wheel_rpm-val is deprecated.  Use morai_msgs-msg:right_front_wheel_rpm instead.")
  (right_front_wheel_rpm m))

(cl:ensure-generic-function 'right_middle_wheel_rpm-val :lambda-list '(m))
(cl:defmethod right_middle_wheel_rpm-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:right_middle_wheel_rpm-val is deprecated.  Use morai_msgs-msg:right_middle_wheel_rpm instead.")
  (right_middle_wheel_rpm m))

(cl:ensure-generic-function 'right_rear_wheel_rpm-val :lambda-list '(m))
(cl:defmethod right_rear_wheel_rpm-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:right_rear_wheel_rpm-val is deprecated.  Use morai_msgs-msg:right_rear_wheel_rpm instead.")
  (right_rear_wheel_rpm m))

(cl:ensure-generic-function 'Target_linear_velocity-val :lambda-list '(m))
(cl:defmethod Target_linear_velocity-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:Target_linear_velocity-val is deprecated.  Use morai_msgs-msg:Target_linear_velocity instead.")
  (Target_linear_velocity m))

(cl:ensure-generic-function 'Target_angular_velocity-val :lambda-list '(m))
(cl:defmethod Target_angular_velocity-val ((m <SkidSteer6wUGVCtrlCmd>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader morai_msgs-msg:Target_angular_velocity-val is deprecated.  Use morai_msgs-msg:Target_angular_velocity instead.")
  (Target_angular_velocity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SkidSteer6wUGVCtrlCmd>) ostream)
  "Serializes a message object of type '<SkidSteer6wUGVCtrlCmd>"
  (cl:let* ((signed (cl:slot-value msg 'cmd_type)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Forward_input) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Backward_input) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Left_Turn_input) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Right_Turn_input) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_front_wheel_rpm))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_middle_wheel_rpm))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'left_rear_wheel_rpm))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_front_wheel_rpm))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_middle_wheel_rpm))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'right_rear_wheel_rpm))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Target_linear_velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Target_angular_velocity))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SkidSteer6wUGVCtrlCmd>) istream)
  "Deserializes a message object of type '<SkidSteer6wUGVCtrlCmd>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'cmd_type) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'Forward_input) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'Backward_input) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'Left_Turn_input) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'Right_Turn_input) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_front_wheel_rpm) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_middle_wheel_rpm) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_rear_wheel_rpm) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_front_wheel_rpm) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_middle_wheel_rpm) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_rear_wheel_rpm) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Target_linear_velocity) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Target_angular_velocity) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SkidSteer6wUGVCtrlCmd>)))
  "Returns string type for a message object of type '<SkidSteer6wUGVCtrlCmd>"
  "morai_msgs/SkidSteer6wUGVCtrlCmd")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SkidSteer6wUGVCtrlCmd)))
  "Returns string type for a message object of type 'SkidSteer6wUGVCtrlCmd"
  "morai_msgs/SkidSteer6wUGVCtrlCmd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SkidSteer6wUGVCtrlCmd>)))
  "Returns md5sum for a message object of type '<SkidSteer6wUGVCtrlCmd>"
  "cb8a43878b1b2c65f50bd53e5a4c03f4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SkidSteer6wUGVCtrlCmd)))
  "Returns md5sum for a message object of type 'SkidSteer6wUGVCtrlCmd"
  "cb8a43878b1b2c65f50bd53e5a4c03f4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SkidSteer6wUGVCtrlCmd>)))
  "Returns full string definition for message of type '<SkidSteer6wUGVCtrlCmd>"
  (cl:format cl:nil "int32 cmd_type~%~%bool Forward_input~%bool Backward_input~%bool Left_Turn_input~%bool Right_Turn_input~%~%float32 left_front_wheel_rpm~%float32 left_middle_wheel_rpm~%float32 left_rear_wheel_rpm~%float32 right_front_wheel_rpm~%float32 right_middle_wheel_rpm~%float32 right_rear_wheel_rpm~%~%float32 Target_linear_velocity~%float32 Target_angular_velocity~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SkidSteer6wUGVCtrlCmd)))
  "Returns full string definition for message of type 'SkidSteer6wUGVCtrlCmd"
  (cl:format cl:nil "int32 cmd_type~%~%bool Forward_input~%bool Backward_input~%bool Left_Turn_input~%bool Right_Turn_input~%~%float32 left_front_wheel_rpm~%float32 left_middle_wheel_rpm~%float32 left_rear_wheel_rpm~%float32 right_front_wheel_rpm~%float32 right_middle_wheel_rpm~%float32 right_rear_wheel_rpm~%~%float32 Target_linear_velocity~%float32 Target_angular_velocity~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SkidSteer6wUGVCtrlCmd>))
  (cl:+ 0
     4
     1
     1
     1
     1
     4
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SkidSteer6wUGVCtrlCmd>))
  "Converts a ROS message object to a list"
  (cl:list 'SkidSteer6wUGVCtrlCmd
    (cl:cons ':cmd_type (cmd_type msg))
    (cl:cons ':Forward_input (Forward_input msg))
    (cl:cons ':Backward_input (Backward_input msg))
    (cl:cons ':Left_Turn_input (Left_Turn_input msg))
    (cl:cons ':Right_Turn_input (Right_Turn_input msg))
    (cl:cons ':left_front_wheel_rpm (left_front_wheel_rpm msg))
    (cl:cons ':left_middle_wheel_rpm (left_middle_wheel_rpm msg))
    (cl:cons ':left_rear_wheel_rpm (left_rear_wheel_rpm msg))
    (cl:cons ':right_front_wheel_rpm (right_front_wheel_rpm msg))
    (cl:cons ':right_middle_wheel_rpm (right_middle_wheel_rpm msg))
    (cl:cons ':right_rear_wheel_rpm (right_rear_wheel_rpm msg))
    (cl:cons ':Target_linear_velocity (Target_linear_velocity msg))
    (cl:cons ':Target_angular_velocity (Target_angular_velocity msg))
))
