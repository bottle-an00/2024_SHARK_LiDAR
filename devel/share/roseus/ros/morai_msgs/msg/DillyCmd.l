;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::DillyCmd)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'DillyCmd (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::DILLYCMD")
  (make-package "MORAI_MSGS::DILLYCMD"))

(in-package "ROS")
;;//! \htmlinclude DillyCmd.msg.html


(defclass morai_msgs::DillyCmd
  :super ros::object
  :slots (_isPickup _deliveryItemIndex ))

(defmethod morai_msgs::DillyCmd
  (:init
   (&key
    ((:isPickup __isPickup) nil)
    ((:deliveryItemIndex __deliveryItemIndex) 0)
    )
   (send-super :init)
   (setq _isPickup __isPickup)
   (setq _deliveryItemIndex (round __deliveryItemIndex))
   self)
  (:isPickup
   (&optional (__isPickup :null))
   (if (not (eq __isPickup :null)) (setq _isPickup __isPickup)) _isPickup)
  (:deliveryItemIndex
   (&optional __deliveryItemIndex)
   (if __deliveryItemIndex (setq _deliveryItemIndex __deliveryItemIndex)) _deliveryItemIndex)
  (:serialization-length
   ()
   (+
    ;; bool _isPickup
    1
    ;; int32 _deliveryItemIndex
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _isPickup
       (if _isPickup (write-byte -1 s) (write-byte 0 s))
     ;; int32 _deliveryItemIndex
       (write-long _deliveryItemIndex s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _isPickup
     (setq _isPickup (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _deliveryItemIndex
     (setq _deliveryItemIndex (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get morai_msgs::DillyCmd :md5sum-) "4c01be8e010c2bb6f36d7ace7c88decc")
(setf (get morai_msgs::DillyCmd :datatype-) "morai_msgs/DillyCmd")
(setf (get morai_msgs::DillyCmd :definition-)
      "bool isPickup
int32 deliveryItemIndex

")



(provide :morai_msgs/DillyCmd "4c01be8e010c2bb6f36d7ace7c88decc")


