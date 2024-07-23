// Generated by gencpp from file morai_msgs/IntersectionStatus.msg
// DO NOT EDIT!


#ifndef MORAI_MSGS_MESSAGE_INTERSECTIONSTATUS_H
#define MORAI_MSGS_MESSAGE_INTERSECTIONSTATUS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace morai_msgs
{
template <class ContainerAllocator>
struct IntersectionStatus_
{
  typedef IntersectionStatus_<ContainerAllocator> Type;

  IntersectionStatus_()
    : header()
    , intersection_index(0)
    , intersection_status(0)
    , intersection_status_time(0.0)  {
    }
  IntersectionStatus_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , intersection_index(0)
    , intersection_status(0)
    , intersection_status_time(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _intersection_index_type;
  _intersection_index_type intersection_index;

   typedef int16_t _intersection_status_type;
  _intersection_status_type intersection_status;

   typedef float _intersection_status_time_type;
  _intersection_status_time_type intersection_status_time;





  typedef boost::shared_ptr< ::morai_msgs::IntersectionStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::morai_msgs::IntersectionStatus_<ContainerAllocator> const> ConstPtr;

}; // struct IntersectionStatus_

typedef ::morai_msgs::IntersectionStatus_<std::allocator<void> > IntersectionStatus;

typedef boost::shared_ptr< ::morai_msgs::IntersectionStatus > IntersectionStatusPtr;
typedef boost::shared_ptr< ::morai_msgs::IntersectionStatus const> IntersectionStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::morai_msgs::IntersectionStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::morai_msgs::IntersectionStatus_<ContainerAllocator1> & lhs, const ::morai_msgs::IntersectionStatus_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.intersection_index == rhs.intersection_index &&
    lhs.intersection_status == rhs.intersection_status &&
    lhs.intersection_status_time == rhs.intersection_status_time;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::morai_msgs::IntersectionStatus_<ContainerAllocator1> & lhs, const ::morai_msgs::IntersectionStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace morai_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::IntersectionStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::IntersectionStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::IntersectionStatus_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "69acc500559cc08bdac17774946018e0";
  }

  static const char* value(const ::morai_msgs::IntersectionStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x69acc500559cc08bULL;
  static const uint64_t static_value2 = 0xdac17774946018e0ULL;
};

template<class ContainerAllocator>
struct DataType< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "morai_msgs/IntersectionStatus";
  }

  static const char* value(const ::morai_msgs::IntersectionStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"int32 intersection_index\n"
"int16 intersection_status\n"
"float32 intersection_status_time\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::morai_msgs::IntersectionStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.intersection_index);
      stream.next(m.intersection_status);
      stream.next(m.intersection_status_time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct IntersectionStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::morai_msgs::IntersectionStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::morai_msgs::IntersectionStatus_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "intersection_index: ";
    Printer<int32_t>::stream(s, indent + "  ", v.intersection_index);
    s << indent << "intersection_status: ";
    Printer<int16_t>::stream(s, indent + "  ", v.intersection_status);
    s << indent << "intersection_status_time: ";
    Printer<float>::stream(s, indent + "  ", v.intersection_status_time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MORAI_MSGS_MESSAGE_INTERSECTIONSTATUS_H
