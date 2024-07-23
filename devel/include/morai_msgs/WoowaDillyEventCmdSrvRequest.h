// Generated by gencpp from file morai_msgs/WoowaDillyEventCmdSrvRequest.msg
// DO NOT EDIT!


#ifndef MORAI_MSGS_MESSAGE_WOOWADILLYEVENTCMDSRVREQUEST_H
#define MORAI_MSGS_MESSAGE_WOOWADILLYEVENTCMDSRVREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <morai_msgs/DillyCmd.h>

namespace morai_msgs
{
template <class ContainerAllocator>
struct WoowaDillyEventCmdSrvRequest_
{
  typedef WoowaDillyEventCmdSrvRequest_<ContainerAllocator> Type;

  WoowaDillyEventCmdSrvRequest_()
    : request()  {
    }
  WoowaDillyEventCmdSrvRequest_(const ContainerAllocator& _alloc)
    : request(_alloc)  {
  (void)_alloc;
    }



   typedef  ::morai_msgs::DillyCmd_<ContainerAllocator>  _request_type;
  _request_type request;





  typedef boost::shared_ptr< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct WoowaDillyEventCmdSrvRequest_

typedef ::morai_msgs::WoowaDillyEventCmdSrvRequest_<std::allocator<void> > WoowaDillyEventCmdSrvRequest;

typedef boost::shared_ptr< ::morai_msgs::WoowaDillyEventCmdSrvRequest > WoowaDillyEventCmdSrvRequestPtr;
typedef boost::shared_ptr< ::morai_msgs::WoowaDillyEventCmdSrvRequest const> WoowaDillyEventCmdSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator1> & lhs, const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.request == rhs.request;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator1> & lhs, const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace morai_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c536c20b59384f19247c2cf4a9d158aa";
  }

  static const char* value(const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc536c20b59384f19ULL;
  static const uint64_t static_value2 = 0x247c2cf4a9d158aaULL;
};

template<class ContainerAllocator>
struct DataType< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "morai_msgs/WoowaDillyEventCmdSrvRequest";
  }

  static const char* value(const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "DillyCmd request\n"
"\n"
"================================================================================\n"
"MSG: morai_msgs/DillyCmd\n"
"bool isPickup\n"
"int32 deliveryItemIndex\n"
;
  }

  static const char* value(const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.request);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WoowaDillyEventCmdSrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::morai_msgs::WoowaDillyEventCmdSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "request: ";
    s << std::endl;
    Printer< ::morai_msgs::DillyCmd_<ContainerAllocator> >::stream(s, indent + "  ", v.request);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MORAI_MSGS_MESSAGE_WOOWADILLYEVENTCMDSRVREQUEST_H
