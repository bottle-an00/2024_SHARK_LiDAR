// Auto-generated. Do not edit!

// (in-package morai_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class SkidSteer6wUGVStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.unique_id = null;
      this.ctrl_mode = null;
      this.acceleration = null;
      this.position = null;
      this.linear_velocity = null;
      this.angular_velocity = null;
      this.heading = null;
      this.cmd_type = null;
      this.left_front_wheel_rpm = null;
      this.left_middle_wheel_rpm = null;
      this.left_rear_wheel_rpm = null;
      this.right_front_wheel_rpm = null;
      this.right_middle_wheel_rpm = null;
      this.right_rear_wheel_rpm = null;
      this.lateral_offset = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('unique_id')) {
        this.unique_id = initObj.unique_id
      }
      else {
        this.unique_id = 0;
      }
      if (initObj.hasOwnProperty('ctrl_mode')) {
        this.ctrl_mode = initObj.ctrl_mode
      }
      else {
        this.ctrl_mode = 0;
      }
      if (initObj.hasOwnProperty('acceleration')) {
        this.acceleration = initObj.acceleration
      }
      else {
        this.acceleration = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('linear_velocity')) {
        this.linear_velocity = initObj.linear_velocity
      }
      else {
        this.linear_velocity = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('angular_velocity')) {
        this.angular_velocity = initObj.angular_velocity
      }
      else {
        this.angular_velocity = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('heading')) {
        this.heading = initObj.heading
      }
      else {
        this.heading = 0.0;
      }
      if (initObj.hasOwnProperty('cmd_type')) {
        this.cmd_type = initObj.cmd_type
      }
      else {
        this.cmd_type = 0;
      }
      if (initObj.hasOwnProperty('left_front_wheel_rpm')) {
        this.left_front_wheel_rpm = initObj.left_front_wheel_rpm
      }
      else {
        this.left_front_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('left_middle_wheel_rpm')) {
        this.left_middle_wheel_rpm = initObj.left_middle_wheel_rpm
      }
      else {
        this.left_middle_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('left_rear_wheel_rpm')) {
        this.left_rear_wheel_rpm = initObj.left_rear_wheel_rpm
      }
      else {
        this.left_rear_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('right_front_wheel_rpm')) {
        this.right_front_wheel_rpm = initObj.right_front_wheel_rpm
      }
      else {
        this.right_front_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('right_middle_wheel_rpm')) {
        this.right_middle_wheel_rpm = initObj.right_middle_wheel_rpm
      }
      else {
        this.right_middle_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('right_rear_wheel_rpm')) {
        this.right_rear_wheel_rpm = initObj.right_rear_wheel_rpm
      }
      else {
        this.right_rear_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('lateral_offset')) {
        this.lateral_offset = initObj.lateral_offset
      }
      else {
        this.lateral_offset = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SkidSteer6wUGVStatus
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [unique_id]
    bufferOffset = _serializer.int32(obj.unique_id, buffer, bufferOffset);
    // Serialize message field [ctrl_mode]
    bufferOffset = _serializer.int32(obj.ctrl_mode, buffer, bufferOffset);
    // Serialize message field [acceleration]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.acceleration, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.position, buffer, bufferOffset);
    // Serialize message field [linear_velocity]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.linear_velocity, buffer, bufferOffset);
    // Serialize message field [angular_velocity]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.angular_velocity, buffer, bufferOffset);
    // Serialize message field [heading]
    bufferOffset = _serializer.float64(obj.heading, buffer, bufferOffset);
    // Serialize message field [cmd_type]
    bufferOffset = _serializer.int32(obj.cmd_type, buffer, bufferOffset);
    // Serialize message field [left_front_wheel_rpm]
    bufferOffset = _serializer.float64(obj.left_front_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [left_middle_wheel_rpm]
    bufferOffset = _serializer.float64(obj.left_middle_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [left_rear_wheel_rpm]
    bufferOffset = _serializer.float64(obj.left_rear_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [right_front_wheel_rpm]
    bufferOffset = _serializer.float64(obj.right_front_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [right_middle_wheel_rpm]
    bufferOffset = _serializer.float64(obj.right_middle_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [right_rear_wheel_rpm]
    bufferOffset = _serializer.float64(obj.right_rear_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [lateral_offset]
    bufferOffset = _serializer.float64(obj.lateral_offset, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SkidSteer6wUGVStatus
    let len;
    let data = new SkidSteer6wUGVStatus(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [unique_id]
    data.unique_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [ctrl_mode]
    data.ctrl_mode = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [acceleration]
    data.acceleration = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [linear_velocity]
    data.linear_velocity = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [angular_velocity]
    data.angular_velocity = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [heading]
    data.heading = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cmd_type]
    data.cmd_type = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [left_front_wheel_rpm]
    data.left_front_wheel_rpm = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [left_middle_wheel_rpm]
    data.left_middle_wheel_rpm = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [left_rear_wheel_rpm]
    data.left_rear_wheel_rpm = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_front_wheel_rpm]
    data.right_front_wheel_rpm = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_middle_wheel_rpm]
    data.right_middle_wheel_rpm = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [right_rear_wheel_rpm]
    data.right_rear_wheel_rpm = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lateral_offset]
    data.lateral_offset = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 172;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/SkidSteer6wUGVStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd741d34a68b143895b122f334a1afe31';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    int32 unique_id
    int32 ctrl_mode
    
    geometry_msgs/Vector3 acceleration
    geometry_msgs/Vector3 position
    geometry_msgs/Vector3 linear_velocity
    geometry_msgs/Vector3 angular_velocity
    
    float64 heading
    int32 cmd_type
    
    float64 left_front_wheel_rpm
    float64 left_middle_wheel_rpm
    float64 left_rear_wheel_rpm
    float64 right_front_wheel_rpm
    float64 right_middle_wheel_rpm
    float64 right_rear_wheel_rpm
    
    float64 lateral_offset
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SkidSteer6wUGVStatus(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.unique_id !== undefined) {
      resolved.unique_id = msg.unique_id;
    }
    else {
      resolved.unique_id = 0
    }

    if (msg.ctrl_mode !== undefined) {
      resolved.ctrl_mode = msg.ctrl_mode;
    }
    else {
      resolved.ctrl_mode = 0
    }

    if (msg.acceleration !== undefined) {
      resolved.acceleration = geometry_msgs.msg.Vector3.Resolve(msg.acceleration)
    }
    else {
      resolved.acceleration = new geometry_msgs.msg.Vector3()
    }

    if (msg.position !== undefined) {
      resolved.position = geometry_msgs.msg.Vector3.Resolve(msg.position)
    }
    else {
      resolved.position = new geometry_msgs.msg.Vector3()
    }

    if (msg.linear_velocity !== undefined) {
      resolved.linear_velocity = geometry_msgs.msg.Vector3.Resolve(msg.linear_velocity)
    }
    else {
      resolved.linear_velocity = new geometry_msgs.msg.Vector3()
    }

    if (msg.angular_velocity !== undefined) {
      resolved.angular_velocity = geometry_msgs.msg.Vector3.Resolve(msg.angular_velocity)
    }
    else {
      resolved.angular_velocity = new geometry_msgs.msg.Vector3()
    }

    if (msg.heading !== undefined) {
      resolved.heading = msg.heading;
    }
    else {
      resolved.heading = 0.0
    }

    if (msg.cmd_type !== undefined) {
      resolved.cmd_type = msg.cmd_type;
    }
    else {
      resolved.cmd_type = 0
    }

    if (msg.left_front_wheel_rpm !== undefined) {
      resolved.left_front_wheel_rpm = msg.left_front_wheel_rpm;
    }
    else {
      resolved.left_front_wheel_rpm = 0.0
    }

    if (msg.left_middle_wheel_rpm !== undefined) {
      resolved.left_middle_wheel_rpm = msg.left_middle_wheel_rpm;
    }
    else {
      resolved.left_middle_wheel_rpm = 0.0
    }

    if (msg.left_rear_wheel_rpm !== undefined) {
      resolved.left_rear_wheel_rpm = msg.left_rear_wheel_rpm;
    }
    else {
      resolved.left_rear_wheel_rpm = 0.0
    }

    if (msg.right_front_wheel_rpm !== undefined) {
      resolved.right_front_wheel_rpm = msg.right_front_wheel_rpm;
    }
    else {
      resolved.right_front_wheel_rpm = 0.0
    }

    if (msg.right_middle_wheel_rpm !== undefined) {
      resolved.right_middle_wheel_rpm = msg.right_middle_wheel_rpm;
    }
    else {
      resolved.right_middle_wheel_rpm = 0.0
    }

    if (msg.right_rear_wheel_rpm !== undefined) {
      resolved.right_rear_wheel_rpm = msg.right_rear_wheel_rpm;
    }
    else {
      resolved.right_rear_wheel_rpm = 0.0
    }

    if (msg.lateral_offset !== undefined) {
      resolved.lateral_offset = msg.lateral_offset;
    }
    else {
      resolved.lateral_offset = 0.0
    }

    return resolved;
    }
};

module.exports = SkidSteer6wUGVStatus;
