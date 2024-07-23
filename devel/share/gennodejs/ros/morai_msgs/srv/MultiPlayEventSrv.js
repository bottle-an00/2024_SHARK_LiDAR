// Auto-generated. Do not edit!

// (in-package morai_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let MultiPlayEventRequest = require('../msg/MultiPlayEventRequest.js');

//-----------------------------------------------------------

let MultiPlayEventResponse = require('../msg/MultiPlayEventResponse.js');

//-----------------------------------------------------------

class MultiPlayEventSrvRequest {
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
        this.request = new MultiPlayEventRequest();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MultiPlayEventSrvRequest
    // Serialize message field [request]
    bufferOffset = MultiPlayEventRequest.serialize(obj.request, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MultiPlayEventSrvRequest
    let len;
    let data = new MultiPlayEventSrvRequest(null);
    // Deserialize message field [request]
    data.request = MultiPlayEventRequest.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'morai_msgs/MultiPlayEventSrvRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8d5ae069e4cb4123583348dd208092eb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    MultiPlayEventRequest request
    
    ================================================================================
    MSG: morai_msgs/MultiPlayEventRequest
    bool requestRespawn
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MultiPlayEventSrvRequest(null);
    if (msg.request !== undefined) {
      resolved.request = MultiPlayEventRequest.Resolve(msg.request)
    }
    else {
      resolved.request = new MultiPlayEventRequest()
    }

    return resolved;
    }
};

class MultiPlayEventSrvResponse {
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
        this.response = new MultiPlayEventResponse();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MultiPlayEventSrvResponse
    // Serialize message field [response]
    bufferOffset = MultiPlayEventResponse.serialize(obj.response, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MultiPlayEventSrvResponse
    let len;
    let data = new MultiPlayEventSrvResponse(null);
    // Deserialize message field [response]
    data.response = MultiPlayEventResponse.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'morai_msgs/MultiPlayEventSrvResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4039c80fa74cc3be5f583706bf97e6b0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    MultiPlayEventResponse response
    
    
    ================================================================================
    MSG: morai_msgs/MultiPlayEventResponse
    bool result
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MultiPlayEventSrvResponse(null);
    if (msg.response !== undefined) {
      resolved.response = MultiPlayEventResponse.Resolve(msg.response)
    }
    else {
      resolved.response = new MultiPlayEventResponse()
    }

    return resolved;
    }
};

module.exports = {
  Request: MultiPlayEventSrvRequest,
  Response: MultiPlayEventSrvResponse,
  md5sum() { return '5ff2047bbd823c7a4e40fc93cb1bb42d'; },
  datatype() { return 'morai_msgs/MultiPlayEventSrv'; }
};
