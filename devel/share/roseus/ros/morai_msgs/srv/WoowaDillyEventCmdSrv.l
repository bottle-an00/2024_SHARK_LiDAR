;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::WoowaDillyEventCmdSrv)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'WoowaDillyEventCmdSrv (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::WOOWADILLYEVENTCMDSRV")
  (make-package "MORAI_MSGS::WOOWADILLYEVENTCMDSRV"))
(unless (find-package "MORAI_MSGS::WOOWADILLYEVENTCMDSRVREQUEST")
  (make-package "MORAI_MSGS::WOOWADILLYEVENTCMDSRVREQUEST"))
(unless (find-package "MORAI_MSGS::WOOWADILLYEVENTCMDSRVRESPONSE")
  (make-package "MORAI_MSGS::WOOWADILLYEVENTCMDSRVRESPONSE"))

(in-package "ROS")





(defclass morai_msgs::WoowaDillyEventCmdSrvRequest
  :super ros::object
  :slots (_request ))

(defmethod morai_msgs::WoowaDillyEventCmdSrvRequest
  (:init
   (&key
    ((:request __request) (instance morai_msgs::DillyCmd :init))
    )
   (send-super :init)
   (setq _request __request)
   self)
  (:request
   (&rest __request)
   (if (keywordp (car __request))
       (send* _request __request)
     (progn
       (if __request (setq _request (car __request)))
       _request)))
  (:serialization-length
   ()
   (+
    ;; morai_msgs/DillyCmd _request
    (send _request :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; morai_msgs/DillyCmd _request
       (send _request :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; morai_msgs/DillyCmd _request
     (send _request :deserialize buf ptr-) (incf ptr- (send _request :serialization-length))
   ;;
   self)
  )

(defclass morai_msgs::WoowaDillyEventCmdSrvResponse
  :super ros::object
  :slots (_response ))

(defmethod morai_msgs::WoowaDillyEventCmdSrvResponse
  (:init
   (&key
    ((:response __response) (instance morai_msgs::DillyCmdResponse :init))
    )
   (send-super :init)
   (setq _response __response)
   self)
  (:response
   (&rest __response)
   (if (keywordp (car __response))
       (send* _response __response)
     (progn
       (if __response (setq _response (car __response)))
       _response)))
  (:serialization-length
   ()
   (+
    ;; morai_msgs/DillyCmdResponse _response
    (send _response :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; morai_msgs/DillyCmdResponse _response
       (send _response :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; morai_msgs/DillyCmdResponse _response
     (send _response :deserialize buf ptr-) (incf ptr- (send _response :serialization-length))
   ;;
   self)
  )

(defclass morai_msgs::WoowaDillyEventCmdSrv
  :super ros::object
  :slots ())

(setf (get morai_msgs::WoowaDillyEventCmdSrv :md5sum-) "1955b6d4c59847467e59b20a60d97dee")
(setf (get morai_msgs::WoowaDillyEventCmdSrv :datatype-) "morai_msgs/WoowaDillyEventCmdSrv")
(setf (get morai_msgs::WoowaDillyEventCmdSrv :request) morai_msgs::WoowaDillyEventCmdSrvRequest)
(setf (get morai_msgs::WoowaDillyEventCmdSrv :response) morai_msgs::WoowaDillyEventCmdSrvResponse)

(defmethod morai_msgs::WoowaDillyEventCmdSrvRequest
  (:response () (instance morai_msgs::WoowaDillyEventCmdSrvResponse :init)))

(setf (get morai_msgs::WoowaDillyEventCmdSrvRequest :md5sum-) "1955b6d4c59847467e59b20a60d97dee")
(setf (get morai_msgs::WoowaDillyEventCmdSrvRequest :datatype-) "morai_msgs/WoowaDillyEventCmdSrvRequest")
(setf (get morai_msgs::WoowaDillyEventCmdSrvRequest :definition-)
      "DillyCmd request

================================================================================
MSG: morai_msgs/DillyCmd
bool isPickup
int32 deliveryItemIndex
---
DillyCmdResponse response

================================================================================
MSG: morai_msgs/DillyCmdResponse
")

(setf (get morai_msgs::WoowaDillyEventCmdSrvResponse :md5sum-) "1955b6d4c59847467e59b20a60d97dee")
(setf (get morai_msgs::WoowaDillyEventCmdSrvResponse :datatype-) "morai_msgs/WoowaDillyEventCmdSrvResponse")
(setf (get morai_msgs::WoowaDillyEventCmdSrvResponse :definition-)
      "DillyCmd request

================================================================================
MSG: morai_msgs/DillyCmd
bool isPickup
int32 deliveryItemIndex
---
DillyCmdResponse response

================================================================================
MSG: morai_msgs/DillyCmdResponse
")



(provide :morai_msgs/WoowaDillyEventCmdSrv "1955b6d4c59847467e59b20a60d97dee")


