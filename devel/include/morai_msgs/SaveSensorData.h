// Generated by gencpp from file morai_msgs/SaveSensorData.msg
// DO NOT EDIT!


#ifndef MORAI_MSGS_MESSAGE_SAVESENSORDATA_H
#define MORAI_MSGS_MESSAGE_SAVESENSORDATA_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace morai_msgs
{
template <class ContainerAllocator>
struct SaveSensorData_
{
  typedef SaveSensorData_<ContainerAllocator> Type;

  SaveSensorData_()
    : is_custom_file_name(false)
    , custom_file_name()
    , file_dir()  {
    }
  SaveSensorData_(const ContainerAllocator& _alloc)
    : is_custom_file_name(false)
    , custom_file_name(_alloc)
    , file_dir(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _is_custom_file_name_type;
  _is_custom_file_name_type is_custom_file_name;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _custom_file_name_type;
  _custom_file_name_type custom_file_name;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _file_dir_type;
  _file_dir_type file_dir;





  typedef boost::shared_ptr< ::morai_msgs::SaveSensorData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::morai_msgs::SaveSensorData_<ContainerAllocator> const> ConstPtr;

}; // struct SaveSensorData_

typedef ::morai_msgs::SaveSensorData_<std::allocator<void> > SaveSensorData;

typedef boost::shared_ptr< ::morai_msgs::SaveSensorData > SaveSensorDataPtr;
typedef boost::shared_ptr< ::morai_msgs::SaveSensorData const> SaveSensorDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::morai_msgs::SaveSensorData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::morai_msgs::SaveSensorData_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::morai_msgs::SaveSensorData_<ContainerAllocator1> & lhs, const ::morai_msgs::SaveSensorData_<ContainerAllocator2> & rhs)
{
  return lhs.is_custom_file_name == rhs.is_custom_file_name &&
    lhs.custom_file_name == rhs.custom_file_name &&
    lhs.file_dir == rhs.file_dir;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::morai_msgs::SaveSensorData_<ContainerAllocator1> & lhs, const ::morai_msgs::SaveSensorData_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace morai_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::morai_msgs::SaveSensorData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::morai_msgs::SaveSensorData_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::morai_msgs::SaveSensorData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dad180f0ff2328c64bf118f8cf118abe";
  }

  static const char* value(const ::morai_msgs::SaveSensorData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdad180f0ff2328c6ULL;
  static const uint64_t static_value2 = 0x4bf118f8cf118abeULL;
};

template<class ContainerAllocator>
struct DataType< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "morai_msgs/SaveSensorData";
  }

  static const char* value(const ::morai_msgs::SaveSensorData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool is_custom_file_name\n"
"string custom_file_name\n"
"string file_dir\n"
;
  }

  static const char* value(const ::morai_msgs::SaveSensorData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.is_custom_file_name);
      stream.next(m.custom_file_name);
      stream.next(m.file_dir);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SaveSensorData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::morai_msgs::SaveSensorData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::morai_msgs::SaveSensorData_<ContainerAllocator>& v)
  {
    s << indent << "is_custom_file_name: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_custom_file_name);
    s << indent << "custom_file_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.custom_file_name);
    s << indent << "file_dir: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.file_dir);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MORAI_MSGS_MESSAGE_SAVESENSORDATA_H
