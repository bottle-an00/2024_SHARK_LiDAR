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

class MultiPlayEventRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.requestRespawn = null;
    }
    else {
      if (initObj.hasOwnProperty('requestRespawn')) {
        this.requestRespawn = initObj.requestRespawn
      }
      else {
        this.requestRespawn = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MultiPlayEventRequest
    // Serialize message field [requestRespawn]
    bufferOffset = _serializer.bool(obj.requestRespawn, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MultiPlayEventRequest
    let len;
    let data = new MultiPlayEventRequest(null);
    // Deserialize message field [requestRespawn]
    data.requestRespawn = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/MultiPlayEventRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6d7b6e13e2c1671b06638e7f201595a3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool requestRespawn
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MultiPlayEventRequest(null);
    if (msg.requestRespawn !== undefined) {
      resolved.requestRespawn = msg.requestRespawn;
    }
    else {
      resolved.requestRespawn = false
    }

    return resolved;
    }
};

module.exports = MultiPlayEventRequest;
