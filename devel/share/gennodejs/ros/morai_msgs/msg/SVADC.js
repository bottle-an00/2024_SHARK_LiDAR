// Auto-generated. Do not edit!

// (in-package morai_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class SVADC {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.collisionCount = null;
      this.signalViolationCount = null;
      this.speedLimitCount = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('collisionCount')) {
        this.collisionCount = initObj.collisionCount
      }
      else {
        this.collisionCount = 0;
      }
      if (initObj.hasOwnProperty('signalViolationCount')) {
        this.signalViolationCount = initObj.signalViolationCount
      }
      else {
        this.signalViolationCount = 0;
      }
      if (initObj.hasOwnProperty('speedLimitCount')) {
        this.speedLimitCount = initObj.speedLimitCount
      }
      else {
        this.speedLimitCount = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SVADC
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [collisionCount]
    bufferOffset = _serializer.int32(obj.collisionCount, buffer, bufferOffset);
    // Serialize message field [signalViolationCount]
    bufferOffset = _serializer.int32(obj.signalViolationCount, buffer, bufferOffset);
    // Serialize message field [speedLimitCount]
    bufferOffset = _serializer.int32(obj.speedLimitCount, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SVADC
    let len;
    let data = new SVADC(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [collisionCount]
    data.collisionCount = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [signalViolationCount]
    data.signalViolationCount = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [speedLimitCount]
    data.speedLimitCount = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/SVADC';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c180496093e554e39b1b25419d7fdd6e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int32 collisionCount
    int32 signalViolationCount
    int32 speedLimitCount
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SVADC(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.collisionCount !== undefined) {
      resolved.collisionCount = msg.collisionCount;
    }
    else {
      resolved.collisionCount = 0
    }

    if (msg.signalViolationCount !== undefined) {
      resolved.signalViolationCount = msg.signalViolationCount;
    }
    else {
      resolved.signalViolationCount = 0
    }

    if (msg.speedLimitCount !== undefined) {
      resolved.speedLimitCount = msg.speedLimitCount;
    }
    else {
      resolved.speedLimitCount = 0
    }

    return resolved;
    }
};

module.exports = SVADC;
