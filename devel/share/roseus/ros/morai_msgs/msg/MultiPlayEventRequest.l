;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::MultiPlayEventRequest)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'MultiPlayEventRequest (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::MULTIPLAYEVENTREQUEST")
  (make-package "MORAI_MSGS::MULTIPLAYEVENTREQUEST"))

(in-package "ROS")
;;//! \htmlinclude MultiPlayEventRequest.msg.html


(defclass morai_msgs::MultiPlayEventRequest
  :super ros::object
  :slots (_requestRespawn ))

(defmethod morai_msgs::MultiPlayEventRequest
  (:init
   (&key
    ((:requestRespawn __requestRespawn) nil)
    )
   (send-super :init)
   (setq _requestRespawn __requestRespawn)
   self)
  (:requestRespawn
   (&optional (__requestRespawn :null))
   (if (not (eq __requestRespawn :null)) (setq _requestRespawn __requestRespawn)) _requestRespawn)
  (:serialization-length
   ()
   (+
    ;; bool _requestRespawn
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _requestRespawn
       (if _requestRespawn (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _requestRespawn
     (setq _requestRespawn (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get morai_msgs::MultiPlayEventRequest :md5sum-) "6d7b6e13e2c1671b06638e7f201595a3")
(setf (get morai_msgs::MultiPlayEventRequest :datatype-) "morai_msgs/MultiPlayEventRequest")
(setf (get morai_msgs::MultiPlayEventRequest :definition-)
      "bool requestRespawn
")



(provide :morai_msgs/MultiPlayEventRequest "6d7b6e13e2c1671b06638e7f201595a3")


