;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::FaultStatusInfo_Overall)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'FaultStatusInfo_Overall (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::FAULTSTATUSINFO_OVERALL")
  (make-package "MORAI_MSGS::FAULTSTATUSINFO_OVERALL"))

(in-package "ROS")
;;//! \htmlinclude FaultStatusInfo_Overall.msg.html


(defclass morai_msgs::FaultStatusInfo_Overall
  :super ros::object
  :slots (_status _fault_subclass ))

(defmethod morai_msgs::FaultStatusInfo_Overall
  (:init
   (&key
    ((:status __status) nil)
    ((:fault_subclass __fault_subclass) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _status __status)
   (setq _fault_subclass __fault_subclass)
   self)
  (:status
   (&optional (__status :null))
   (if (not (eq __status :null)) (setq _status __status)) _status)
  (:fault_subclass
   (&optional __fault_subclass)
   (if __fault_subclass (setq _fault_subclass __fault_subclass)) _fault_subclass)
  (:serialization-length
   ()
   (+
    ;; bool _status
    1
    ;; int32[] _fault_subclass
    (* 4    (length _fault_subclass)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _status
       (if _status (write-byte -1 s) (write-byte 0 s))
     ;; int32[] _fault_subclass
     (write-long (length _fault_subclass) s)
     (dotimes (i (length _fault_subclass))
       (write-long (elt _fault_subclass i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _status
     (setq _status (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32[] _fault_subclass
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _fault_subclass (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _fault_subclass i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get morai_msgs::FaultStatusInfo_Overall :md5sum-) "49c4320f71e991dad6fc697eff35406f")
(setf (get morai_msgs::FaultStatusInfo_Overall :datatype-) "morai_msgs/FaultStatusInfo_Overall")
(setf (get morai_msgs::FaultStatusInfo_Overall :definition-)
      "bool status
int32[] fault_subclass

")



(provide :morai_msgs/FaultStatusInfo_Overall "49c4320f71e991dad6fc697eff35406f")


