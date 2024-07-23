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

//-----------------------------------------------------------

class FaultInjection_Sensor {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.unique_id = null;
      this.sensor_id = null;
      this.fault_class = null;
      this.fault_subclass = null;
      this.local_position_offset = null;
      this.local_rotation_offset = null;
    }
    else {
      if (initObj.hasOwnProperty('unique_id')) {
        this.unique_id = initObj.unique_id
      }
      else {
        this.unique_id = 0;
      }
      if (initObj.hasOwnProperty('sensor_id')) {
        this.sensor_id = initObj.sensor_id
      }
      else {
        this.sensor_id = 0;
      }
      if (initObj.hasOwnProperty('fault_class')) {
        this.fault_class = initObj.fault_class
      }
      else {
        this.fault_class = 0;
      }
      if (initObj.hasOwnProperty('fault_subclass')) {
        this.fault_subclass = initObj.fault_subclass
      }
      else {
        this.fault_subclass = 0;
      }
      if (initObj.hasOwnProperty('local_position_offset')) {
        this.local_position_offset = initObj.local_position_offset
      }
      else {
        this.local_position_offset = new geometry_msgs.msg.Vector3();
      }
      if (initObj.hasOwnProperty('local_rotation_offset')) {
        this.local_rotation_offset = initObj.local_rotation_offset
      }
      else {
        this.local_rotation_offset = new geometry_msgs.msg.Vector3();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultInjection_Sensor
    // Serialize message field [unique_id]
    bufferOffset = _serializer.int32(obj.unique_id, buffer, bufferOffset);
    // Serialize message field [sensor_id]
    bufferOffset = _serializer.int32(obj.sensor_id, buffer, bufferOffset);
    // Serialize message field [fault_class]
    bufferOffset = _serializer.int32(obj.fault_class, buffer, bufferOffset);
    // Serialize message field [fault_subclass]
    bufferOffset = _serializer.int32(obj.fault_subclass, buffer, bufferOffset);
    // Serialize message field [local_position_offset]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.local_position_offset, buffer, bufferOffset);
    // Serialize message field [local_rotation_offset]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.local_rotation_offset, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultInjection_Sensor
    let len;
    let data = new FaultInjection_Sensor(null);
    // Deserialize message field [unique_id]
    data.unique_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [sensor_id]
    data.sensor_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [fault_class]
    data.fault_class = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [fault_subclass]
    data.fault_subclass = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [local_position_offset]
    data.local_position_offset = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    // Deserialize message field [local_rotation_offset]
    data.local_rotation_offset = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 64;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/FaultInjection_Sensor';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1d09067e718a7214f8177394317316b2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 unique_id
    int32 sensor_id
    
    int32 fault_class
    int32 fault_subclass
    
    geometry_msgs/Vector3 local_position_offset
    geometry_msgs/Vector3 local_rotation_offset
    
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
    const resolved = new FaultInjection_Sensor(null);
    if (msg.unique_id !== undefined) {
      resolved.unique_id = msg.unique_id;
    }
    else {
      resolved.unique_id = 0
    }

    if (msg.sensor_id !== undefined) {
      resolved.sensor_id = msg.sensor_id;
    }
    else {
      resolved.sensor_id = 0
    }

    if (msg.fault_class !== undefined) {
      resolved.fault_class = msg.fault_class;
    }
    else {
      resolved.fault_class = 0
    }

    if (msg.fault_subclass !== undefined) {
      resolved.fault_subclass = msg.fault_subclass;
    }
    else {
      resolved.fault_subclass = 0
    }

    if (msg.local_position_offset !== undefined) {
      resolved.local_position_offset = geometry_msgs.msg.Vector3.Resolve(msg.local_position_offset)
    }
    else {
      resolved.local_position_offset = new geometry_msgs.msg.Vector3()
    }

    if (msg.local_rotation_offset !== undefined) {
      resolved.local_rotation_offset = geometry_msgs.msg.Vector3.Resolve(msg.local_rotation_offset)
    }
    else {
      resolved.local_rotation_offset = new geometry_msgs.msg.Vector3()
    }

    return resolved;
    }
};

module.exports = FaultInjection_Sensor;
