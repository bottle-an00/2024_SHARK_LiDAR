// Auto-generated. Do not edit!

// (in-package morai_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let DillyCmd = require('../msg/DillyCmd.js');

//-----------------------------------------------------------

let DillyCmdResponse = require('../msg/DillyCmdResponse.js');

//-----------------------------------------------------------

class WoowaDillyEventCmdSrvRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.request = null;
    }
    else {
      if (initObj.hasOwnProperty('request')) {
        this.request = initObj.request
      }
      else {
        this.request = new DillyCmd();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WoowaDillyEventCmdSrvRequest
    // Serialize message field [request]
    bufferOffset = DillyCmd.serialize(obj.request, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WoowaDillyEventCmdSrvRequest
    let len;
    let data = new WoowaDillyEventCmdSrvRequest(null);
    // Deserialize message field [request]
    data.request = DillyCmd.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'morai_msgs/WoowaDillyEventCmdSrvRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c536c20b59384f19247c2cf4a9d158aa';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    DillyCmd request
    
    ================================================================================
    MSG: morai_msgs/DillyCmd
    bool isPickup
    int32 deliveryItemIndex
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WoowaDillyEventCmdSrvRequest(null);
    if (msg.request !== undefined) {
      resolved.request = DillyCmd.Resolve(msg.request)
    }
    else {
      resolved.request = new DillyCmd()
    }

    return resolved;
    }
};

class WoowaDillyEventCmdSrvResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.response = null;
    }
    else {
      if (initObj.hasOwnProperty('response')) {
        this.response = initObj.response
      }
      else {
        this.response = new DillyCmdResponse();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WoowaDillyEventCmdSrvResponse
    // Serialize message field [response]
    bufferOffset = DillyCmdResponse.serialize(obj.response, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WoowaDillyEventCmdSrvResponse
    let len;
    let data = new WoowaDillyEventCmdSrvResponse(null);
    // Deserialize message field [response]
    data.response = DillyCmdResponse.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'morai_msgs/WoowaDillyEventCmdSrvResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4039c80fa74cc3be5f583706bf97e6b0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    DillyCmdResponse response
    
    ================================================================================
    MSG: morai_msgs/DillyCmdResponse
    bool result
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WoowaDillyEventCmdSrvResponse(null);
    if (msg.response !== undefined) {
      resolved.response = DillyCmdResponse.Resolve(msg.response)
    }
    else {
      resolved.response = new DillyCmdResponse()
    }

    return resolved;
    }
};

module.exports = {
  Request: WoowaDillyEventCmdSrvRequest,
  Response: WoowaDillyEventCmdSrvResponse,
  md5sum() { return '1955b6d4c59847467e59b20a60d97dee'; },
  datatype() { return 'morai_msgs/WoowaDillyEventCmdSrv'; }
};
