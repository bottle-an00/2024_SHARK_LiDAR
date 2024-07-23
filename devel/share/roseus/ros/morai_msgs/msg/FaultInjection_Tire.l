;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultInjection_Tire)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultInjection_Tire (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTINJECTION_TIRE")
  (make-package "MORAI_MSGS::FAULTINJECTION_TIRE"))

(in-package "ROS")
;;//! \htmlinclude FaultInjection_Tire.msg.html


(defclass morai_msgs::FaultInjection_Tire
  :super ros::object
  :slots (_unique_id _tire_index _fault_class _fault_subclass ))

(defmethod morai_msgs::FaultInjection_Tire
  (:init
   (&key
    ((:unique_id __unique_id) 0)
    ((:tire_index __tire_index) 0)
    ((:fault_class __fault_class) 0)
    ((:fault_subclass __fault_subclass) 0)
    )
   (send-super :init)
   (setq _unique_id (round __unique_id))
   (setq _tire_index (round __tire_index))
   (setq _fault_class (round __fault_class))
   (setq _fault_subclass (round __fault_subclass))
   self)
  (:unique_id
   (&optional __unique_id)
   (if __unique_id (setq _unique_id __unique_id)) _unique_id)
  (:tire_index
   (&optional __tire_index)
   (if __tire_index (setq _tire_index __tire_index)) _tire_index)
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
    ;; int32 _tire_index
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
     ;; int32 _tire_index
       (write-long _tire_index s)
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
   ;; int32 _tire_index
     (setq _tire_index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _fault_class
     (setq _fault_class (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _fault_subclass
     (setq _fault_subclass (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get morai_msgs::FaultInjection_Tire :md5sum-) "390f98f80684e87e512f8ec107a7d8c1")
(setf (get morai_msgs::FaultInjection_Tire :datatype-) "morai_msgs/FaultInjection_Tire")
(setf (get morai_msgs::FaultInjection_Tire :definition-)
      "int32 unique_id
int32 tire_index

int32 fault_class
int32 fault_subclass

")



(provide :morai_msgs/FaultInjection_Tire "390f98f80684e87e512f8ec107a7d8c1")


