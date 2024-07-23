// Generated by gencpp from file morai_msgs/MoraiSyncModeSetGearSrvResponse.msg
// DO NOT EDIT!


#ifndef MORAI_MSGS_MESSAGE_MORAISYNCMODESETGEARSRVRESPONSE_H
#define MORAI_MSGS_MESSAGE_MORAISYNCMODESETGEARSRVRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <morai_msgs/SyncModeResultResponse.h>

namespace morai_msgs
{
template <class ContainerAllocator>
struct MoraiSyncModeSetGearSrvResponse_
{
  typedef MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> Type;

  MoraiSyncModeSetGearSrvResponse_()
    : response()  {
    }
  MoraiSyncModeSetGearSrvResponse_(const ContainerAllocator& _alloc)
    : response(_alloc)  {
  (void)_alloc;
    }



   typedef  ::morai_msgs::SyncModeResultResponse_<ContainerAllocator>  _response_type;
  _response_type response;





  typedef boost::shared_ptr< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct MoraiSyncModeSetGearSrvResponse_

typedef ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<std::allocator<void> > MoraiSyncModeSetGearSrvResponse;

typedef boost::shared_ptr< ::morai_msgs::MoraiSyncModeSetGearSrvResponse > MoraiSyncModeSetGearSrvResponsePtr;
typedef boost::shared_ptr< ::morai_msgs::MoraiSyncModeSetGearSrvResponse const> MoraiSyncModeSetGearSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator1> & lhs, const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.response == rhs.response;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator1> & lhs, const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace morai_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4039c80fa74cc3be5f583706bf97e6b0";
  }

  static const char* value(const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4039c80fa74cc3beULL;
  static const uint64_t static_value2 = 0x5f583706bf97e6b0ULL;
};

template<class ContainerAllocator>
struct DataType< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "morai_msgs/MoraiSyncModeSetGearSrvResponse";
  }

  static const char* value(const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "SyncModeResultResponse response\n"
"\n"
"\n"
"================================================================================\n"
"MSG: morai_msgs/SyncModeResultResponse\n"
"bool result\n"
;
  }

  static const char* value(const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.response);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MoraiSyncModeSetGearSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::morai_msgs::MoraiSyncModeSetGearSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "response: ";
    s << std::endl;
    Printer< ::morai_msgs::SyncModeResultResponse_<ContainerAllocator> >::stream(s, indent + "  ", v.response);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MORAI_MSGS_MESSAGE_MORAISYNCMODESETGEARSRVRESPONSE_H
