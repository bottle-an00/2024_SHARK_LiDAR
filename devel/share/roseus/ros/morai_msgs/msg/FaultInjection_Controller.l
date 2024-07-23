;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultInjection_Controller)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultInjection_Controller (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTINJECTION_CONTROLLER")
  (make-package "MORAI_MSGS::FAULTINJECTION_CONTROLLER"))

(in-package "ROS")
;;//! \htmlinclude FaultInjection_Controller.msg.html


(defclass morai_msgs::FaultInjection_Controller
  :super ros::object
  :slots (_unique_id _fault_location _fault_class _fault_subclass ))

(defmethod morai_msgs::FaultInjection_Controller
  (:init
   (&key
    ((:unique_id __unique_id) 0)
    ((:fault_location __fault_location) 0)
    ((:fault_class __fault_class) 0)
    ((:fault_subclass __fault_subclass) 0)
    )
   (send-super :init)
   (setq _unique_id (round __unique_id))
   (setq _fault_location (round __fault_location))
   (setq _fault_class (round __fault_class))
   (setq _fault_subclass (round __fault_subclass))
   self)
  (:unique_id
   (&optional __unique_id)
   (if __unique_id (setq _unique_id __unique_id)) _unique_id)
  (:fault_location
   (&optional __fault_location)
   (if __fault_location (setq _fault_location __fault_location)) _fault_location)
  (:fault_class
   (&optional __fault_class)
   (if __fault_class (setq _fault_class __fault_class)) _fault_class)
  (:fault_subclass
   (&optional __fault_subclass)
   (if __fault_subclass (setq _fault_subclass __fault_subclass)) _fault_subclass)
  (:serialization-length
   ()
   (+
    ;; int32 _unique_id
    4
    ;; int32 _fault_location
    4
    ;; int32 _fault_class
    4
    ;; int32 _fault_subclass
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _unique_id
       (write-long _unique_id s)
     ;; int32 _fault_location
       (write-long _fault_location s)
     ;; int32 _fault_class
       (write-long _fault_class s)
     ;; int32 _fault_subclass
       (write-long _fault_subclass s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _unique_id
     (setq _unique_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _fault_location
     (setq _fault_location (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _fault_class
     (setq _fault_class (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _fault_subclass
     (setq _fault_subclass (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get morai_msgs::FaultInjection_Controller :md5sum-) "29fcfb33853ca6e2114fbfdf30c06eaf")
(setf (get morai_msgs::FaultInjection_Controller :datatype-) "morai_msgs/FaultInjection_Controller")
(setf (get morai_msgs::FaultInjection_Controller :definition-)
      "int32 unique_id

int32 fault_location
int32 fault_class
int32 fault_subclass

")



(provide :morai_msgs/FaultInjection_Controller "29fcfb33853ca6e2114fbfdf30c06eaf")


