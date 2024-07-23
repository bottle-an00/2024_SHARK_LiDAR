// Auto-generated. Do not edit!

// (in-package morai_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class FaultInjection_Controller {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.unique_id = null;
      this.fault_location = null;
      this.fault_class = null;
      this.fault_subclass = null;
    }
    else {
      if (initObj.hasOwnProperty('unique_id')) {
        this.unique_id = initObj.unique_id
      }
      else {
        this.unique_id = 0;
      }
      if (initObj.hasOwnProperty('fault_location')) {
        this.fault_location = initObj.fault_location
      }
      else {
        this.fault_location = 0;
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
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultInjection_Controller
    // Serialize message field [unique_id]
    bufferOffset = _serializer.int32(obj.unique_id, buffer, bufferOffset);
    // Serialize message field [fault_location]
    bufferOffset = _serializer.int32(obj.fault_location, buffer, bufferOffset);
    // Serialize message field [fault_class]
    bufferOffset = _serializer.int32(obj.fault_class, buffer, bufferOffset);
    // Serialize message field [fault_subclass]
    bufferOffset = _serializer.int32(obj.fault_subclass, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultInjection_Controller
    let len;
    let data = new FaultInjection_Controller(null);
    // Deserialize message field [unique_id]
    data.unique_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [fault_location]
    data.fault_location = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [fault_class]
    data.fault_class = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [fault_subclass]
    data.fault_subclass = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/FaultInjection_Controller';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '29fcfb33853ca6e2114fbfdf30c06eaf';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 unique_id
    
    int32 fault_location
    int32 fault_class
    int32 fault_subclass
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FaultInjection_Controller(null);
    if (msg.unique_id !== undefined) {
      resolved.unique_id = msg.unique_id;
    }
    else {
      resolved.unique_id = 0
    }

    if (msg.fault_location !== undefined) {
      resolved.fault_location = msg.fault_location;
    }
    else {
      resolved.fault_location = 0
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

    return resolved;
    }
};

module.exports = FaultInjection_Controller;
