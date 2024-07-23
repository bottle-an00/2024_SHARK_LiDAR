// Generated by gencpp from file jsk_recognition_msgs/PolygonArray.msg
// DO NOT EDIT!


#ifndef JSK_RECOGNITION_MSGS_MESSAGE_POLYGONARRAY_H
#define JSK_RECOGNITION_MSGS_MESSAGE_POLYGONARRAY_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/PolygonStamped.h>

namespace jsk_recognition_msgs
{
template <class ContainerAllocator>
struct PolygonArray_
{
  typedef PolygonArray_<ContainerAllocator> Type;

  PolygonArray_()
    : header()
    , polygons()
    , labels()
    , likelihood()  {
    }
  PolygonArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , polygons(_alloc)
    , labels(_alloc)
    , likelihood(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::geometry_msgs::PolygonStamped_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::PolygonStamped_<ContainerAllocator> >> _polygons_type;
  _polygons_type polygons;

   typedef std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> _labels_type;
  _labels_type labels;

   typedef std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> _likelihood_type;
  _likelihood_type likelihood;





  typedef boost::shared_ptr< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> const> ConstPtr;

}; // struct PolygonArray_

typedef ::jsk_recognition_msgs::PolygonArray_<std::allocator<void> > PolygonArray;

typedef boost::shared_ptr< ::jsk_recognition_msgs::PolygonArray > PolygonArrayPtr;
typedef boost::shared_ptr< ::jsk_recognition_msgs::PolygonArray const> PolygonArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator1> & lhs, const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.polygons == rhs.polygons &&
    lhs.labels == rhs.labels &&
    lhs.likelihood == rhs.likelihood;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator1> & lhs, const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace jsk_recognition_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "709b37d39871cfdbbfbd5c41cf9bc2be";
  }

  static const char* value(const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x709b37d39871cfdbULL;
  static const uint64_t static_value2 = 0xbfbd5c41cf9bc2beULL;
};

template<class ContainerAllocator>
struct DataType< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "jsk_recognition_msgs/PolygonArray";
  }

  static const char* value(const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# PolygonArray is a list of PolygonStamped.\n"
"# You can use jsk_rviz_plugins to visualize PolygonArray on rviz.\n"
"Header header\n"
"geometry_msgs/PolygonStamped[] polygons\n"
"uint32[] labels\n"
"float32[] likelihood\n"
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
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PolygonStamped\n"
"# This represents a Polygon with reference coordinate frame and timestamp\n"
"Header header\n"
"Polygon polygon\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Polygon\n"
"#A specification of a polygon where the first and last points are assumed to be connected\n"
"Point32[] points\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point32\n"
"# This contains the position of a point in free space(with 32 bits of precision).\n"
"# It is recommeded to use Point wherever possible instead of Point32.  \n"
"# \n"
"# This recommendation is to promote interoperability.  \n"
"#\n"
"# This message is designed to take up less space when sending\n"
"# lots of points at once, as in the case of a PointCloud.  \n"
"\n"
"float32 x\n"
"float32 y\n"
"float32 z\n"
;
  }

  static const char* value(const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.polygons);
      stream.next(m.labels);
      stream.next(m.likelihood);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PolygonArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::jsk_recognition_msgs::PolygonArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "polygons[]" << std::endl;
    for (size_t i = 0; i < v.polygons.size(); ++i)
    {
      s << indent << "  polygons[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::PolygonStamped_<ContainerAllocator> >::stream(s, indent + "    ", v.polygons[i]);
    }
    s << indent << "labels[]" << std::endl;
    for (size_t i = 0; i < v.labels.size(); ++i)
    {
      s << indent << "  labels[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.labels[i]);
    }
    s << indent << "likelihood[]" << std::endl;
    for (size_t i = 0; i < v.likelihood.size(); ++i)
    {
      s << indent << "  likelihood[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.likelihood[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // JSK_RECOGNITION_MSGS_MESSAGE_POLYGONARRAY_H
