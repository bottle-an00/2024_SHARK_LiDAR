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

class FaultStatusInfo_Overall {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status = null;
      this.fault_subclass = null;
    }
    else {
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = false;
      }
      if (initObj.hasOwnProperty('fault_subclass')) {
        this.fault_subclass = initObj.fault_subclass
      }
      else {
        this.fault_subclass = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultStatusInfo_Overall
    // Serialize message field [status]
    bufferOffset = _serializer.bool(obj.status, buffer, bufferOffset);
    // Serialize message field [fault_subclass]
    bufferOffset = _arraySerializer.int32(obj.fault_subclass, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultStatusInfo_Overall
    let len;
    let data = new FaultStatusInfo_Overall(null);
    // Deserialize message field [status]
    data.status = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [fault_subclass]
    data.fault_subclass = _arrayDeserializer.int32(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.fault_subclass.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/FaultStatusInfo_Overall';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '49c4320f71e991dad6fc697eff35406f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool status
    int32[] fault_subclass
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FaultStatusInfo_Overall(null);
    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = false
    }

    if (msg.fault_subclass !== undefined) {
      resolved.fault_subclass = msg.fault_subclass;
    }
    else {
      resolved.fault_subclass = []
    }

    return resolved;
    }
};

module.exports = FaultStatusInfo_Overall;
