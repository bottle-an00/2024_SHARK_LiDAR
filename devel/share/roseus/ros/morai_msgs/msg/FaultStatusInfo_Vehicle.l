;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultStatusInfo_Vehicle)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultStatusInfo_Vehicle (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTSTATUSINFO_VEHICLE")
  (make-package "MORAI_MSGS::FAULTSTATUSINFO_VEHICLE"))

(in-package "ROS")
;;//! \htmlinclude FaultStatusInfo_Vehicle.msg.html


(defclass morai_msgs::FaultStatusInfo_Vehicle
  :super ros::object
  :slots (_accel _brake _steer _tires ))

(defmethod morai_msgs::FaultStatusInfo_Vehicle
  (:init
   (&key
    ((:accel __accel) (instance morai_msgs::FaultStatusInfo_Overall :init))
    ((:brake __brake) (instance morai_msgs::FaultStatusInfo_Overall :init))
    ((:steer __steer) (instance morai_msgs::FaultStatusInfo_Overall :init))
    ((:tires __tires) ())
    )
   (send-super :init)
   (setq _accel __accel)
   (setq _brake __brake)
   (setq _steer __steer)
   (setq _tires __tires)
   self)
  (:accel
   (&rest __accel)
   (if (keywordp (car __accel))
       (send* _accel __accel)
     (progn
       (if __accel (setq _accel (car __accel)))
       _accel)))
  (:brake
   (&rest __brake)
   (if (keywordp (car __brake))
       (send* _brake __brake)
     (progn
       (if __brake (setq _brake (car __brake)))
       _brake)))
  (:steer
   (&rest __steer)
   (if (keywordp (car __steer))
       (send* _steer __steer)
     (progn
       (if __steer (setq _steer (car __steer)))
       _steer)))
  (:tires
   (&rest __tires)
   (if (keywordp (car __tires))
       (send* _tires __tires)
     (progn
       (if __tires (setq _tires (car __tires)))
       _tires)))
  (:serialization-length
   ()
   (+
    ;; morai_msgs/FaultStatusInfo_Overall _accel
    (send _accel :serialization-length)
    ;; morai_msgs/FaultStatusInfo_Overall _brake
    (send _brake :serialization-length)
    ;; morai_msgs/FaultStatusInfo_Overall _steer
    (send _steer :serialization-length)
    ;; morai_msgs/FaultStatusInfo_Overall[] _tires
    (apply #'+ (send-all _tires :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; morai_msgs/FaultStatusInfo_Overall _accel
       (send _accel :serialize s)
     ;; morai_msgs/FaultStatusInfo_Overall _brake
       (send _brake :serialize s)
     ;; morai_msgs/FaultStatusInfo_Overall _steer
       (send _steer :serialize s)
     ;; morai_msgs/FaultStatusInfo_Overall[] _tires
     (write-long (length _tires) s)
     (dolist (elem _tires)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; morai_msgs/FaultStatusInfo_Overall _accel
     (send _accel :deserialize buf ptr-) (incf ptr- (send _accel :serialization-length))
   ;; morai_msgs/FaultStatusInfo_Overall _brake
     (send _brake :deserialize buf ptr-) (incf ptr- (send _brake :serialization-length))
   ;; morai_msgs/FaultStatusInfo_Overall _steer
     (send _steer :deserialize buf ptr-) (incf ptr- (send _steer :serialization-length))
   ;; morai_msgs/FaultStatusInfo_Overall[] _tires
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _tires (let (r) (dotimes (i n) (push (instance morai_msgs::FaultStatusInfo_Overall :init) r)) r))
     (dolist (elem- _tires)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get morai_msgs::FaultStatusInfo_Vehicle :md5sum-) "dcd69cdf7980329f2014366617eda419")
(setf (get morai_msgs::FaultStatusInfo_Vehicle :datatype-) "morai_msgs/FaultStatusInfo_Vehicle")
(setf (get morai_msgs::FaultStatusInfo_Vehicle :definition-)
      "FaultStatusInfo_Overall accel
FaultStatusInfo_Overall brake
FaultStatusInfo_Overall steer
FaultStatusInfo_Overall[] tires


================================================================================
MSG: morai_msgs/FaultStatusInfo_Overall
bool status
int32[] fault_subclass

")



(provide :morai_msgs/FaultStatusInfo_Vehicle "dcd69cdf7980329f2014366617eda419")


