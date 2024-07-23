;; Auto-generated. Do not edit!


(when (boundp 'morai_msgs::MultiPlayEventSrv)
  (if (not (find-package "MORAI_MSGS"))
    (make-package "MORAI_MSGS"))
  (shadow 'MultiPlayEventSrv (find-package "MORAI_MSGS")))
(unless (find-package "MORAI_MSGS::MULTIPLAYEVENTSRV")
  (make-package "MORAI_MSGS::MULTIPLAYEVENTSRV"))
(unless (find-package "MORAI_MSGS::MULTIPLAYEVENTSRVREQUEST")
  (make-package "MORAI_MSGS::MULTIPLAYEVENTSRVREQUEST"))
(unless (find-package "MORAI_MSGS::MULTIPLAYEVENTSRVRESPONSE")
  (make-package "MORAI_MSGS::MULTIPLAYEVENTSRVRESPONSE"))

(in-package "ROS")





(defclass morai_msgs::MultiPlayEventSrvRequest
  :super ros::object
  :slots (_request ))

(defmethod morai_msgs::MultiPlayEventSrvRequest
  (:init
   (&key
    ((:request __request) (instance morai_msgs::MultiPlayEventRequest :init))
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
    ;; morai_msgs/MultiPlayEventRequest _request
    (send _request :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; morai_msgs/MultiPlayEventRequest _request
       (send _request :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; morai_msgs/MultiPlayEventRequest _request
     (send _request :deserialize buf ptr-) (incf ptr- (send _request :serialization-length))
   ;;
   self)
  )

(defclass morai_msgs::MultiPlayEventSrvResponse
  :super ros::object
  :slots (_response ))

(defmethod morai_msgs::MultiPlayEventSrvResponse
  (:init
   (&key
    ((:response __response) (instance morai_msgs::MultiPlayEventResponse :init))
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
    ;; morai_msgs/MultiPlayEventResponse _response
    (send _response :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; morai_msgs/MultiPlayEventResponse _response
       (send _response :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; morai_msgs/MultiPlayEventResponse _response
     (send _response :deserialize buf ptr-) (incf ptr- (send _response :serialization-length))
   ;;
   self)
  )

(defclass morai_msgs::MultiPlayEventSrv
  :super ros::object
  :slots ())

(setf (get morai_msgs::MultiPlayEventSrv :md5sum-) "5ff2047bbd823c7a4e40fc93cb1bb42d")
(setf (get morai_msgs::MultiPlayEventSrv :datatype-) "morai_msgs/MultiPlayEventSrv")
(setf (get morai_msgs::MultiPlayEventSrv :request) morai_msgs::MultiPlayEventSrvRequest)
(setf (get morai_msgs::MultiPlayEventSrv :response) morai_msgs::MultiPlayEventSrvResponse)

(defmethod morai_msgs::MultiPlayEventSrvRequest
  (:response () (instance morai_msgs::MultiPlayEventSrvResponse :init)))

(setf (get morai_msgs::MultiPlayEventSrvRequest :md5sum-) "5ff2047bbd823c7a4e40fc93cb1bb42d")
(setf (get morai_msgs::MultiPlayEventSrvRequest :datatype-) "morai_msgs/MultiPlayEventSrvRequest")
(setf (get morai_msgs::MultiPlayEventSrvRequest :definition-)
      "MultiPlayEventRequest request

================================================================================
MSG: morai_msgs/MultiPlayEventRequest
---
MultiPlayEventResponse response


================================================================================
MSG: morai_msgs/MultiPlayEventResponse
")

(setf (get morai_msgs::MultiPlayEventSrvResponse :md5sum-) "5ff2047bbd823c7a4e40fc93cb1bb42d")
(setf (get morai_msgs::MultiPlayEventSrvResponse :datatype-) "morai_msgs/MultiPlayEventSrvResponse")
(setf (get morai_msgs::MultiPlayEventSrvResponse :definition-)
      "MultiPlayEventRequest request

================================================================================
MSG: morai_msgs/MultiPlayEventRequest
---
MultiPlayEventResponse response


================================================================================
MSG: morai_msgs/MultiPlayEventResponse
")



(provide :morai_msgs/MultiPlayEventSrv "5ff2047bbd823c7a4e40fc93cb1bb42d")


