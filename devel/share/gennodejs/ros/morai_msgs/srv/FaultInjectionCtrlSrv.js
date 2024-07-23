// Auto-generated. Do not edit!

// (in-package morai_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let FaultInjection_Controller = require('../msg/FaultInjection_Controller.js');

//-----------------------------------------------------------

let FaultInjection_Response = require('../msg/FaultInjection_Response.js');

//-----------------------------------------------------------

class FaultInjectionCtrlSrvRequest {
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
        this.request = new FaultInjection_Controller();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultInjectionCtrlSrvRequest
    // Serialize message field [request]
    bufferOffset = FaultInjection_Controller.serialize(obj.request, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultInjectionCtrlSrvRequest
    let len;
    let data = new FaultInjectionCtrlSrvRequest(null);
    // Deserialize message field [request]
    data.request = FaultInjection_Controller.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a service object
    return 'morai_msgs/FaultInjectionCtrlSrvRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1119e5015e2782c5efa7454105a3b757';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    FaultInjection_Controller request
    
    ================================================================================
    MSG: morai_msgs/FaultInjection_Controller
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
    const resolved = new FaultInjectionCtrlSrvRequest(null);
    if (msg.request !== undefined) {
      resolved.request = FaultInjection_Controller.Resolve(msg.request)
    }
    else {
      resolved.request = new FaultInjection_Controller()
    }

    return resolved;
    }
};

class FaultInjectionCtrlSrvResponse {
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
        this.response = new FaultInjection_Response();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultInjectionCtrlSrvResponse
    // Serialize message field [response]
    bufferOffset = FaultInjection_Response.serialize(obj.response, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultInjectionCtrlSrvResponse
    let len;
    let data = new FaultInjectionCtrlSrvResponse(null);
    // Deserialize message field [response]
    data.response = FaultInjection_Response.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += FaultInjection_Response.getMessageSize(object.response);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'morai_msgs/FaultInjectionCtrlSrvResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b095c5b66e667567179177eaff1ea884';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    FaultInjection_Response response
    
    
    ================================================================================
    MSG: morai_msgs/FaultInjection_Response
    bool result
    
    int32 unique_id
    FaultStatusInfo_Vehicle vehicle
    FaultStatusInfo_Sensor[] sensors
    
    ================================================================================
    MSG: morai_msgs/FaultStatusInfo_Vehicle
    FaultStatusInfo_Overall accel
    FaultStatusInfo_Overall brake
    FaultStatusInfo_Overall steer
    FaultStatusInfo_Overall[] tires
    
    
    ================================================================================
    MSG: morai_msgs/FaultStatusInfo_Overall
    bool status
    int32[] fault_subclass
    
    ================================================================================
    MSG: morai_msgs/FaultStatusInfo_Sensor
    int32 sensor_id
    FaultStatusInfo_Overall sensor
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FaultInjectionCtrlSrvResponse(null);
    if (msg.response !== undefined) {
      resolved.response = FaultInjection_Response.Resolve(msg.response)
    }
    else {
      resolved.response = new FaultInjection_Response()
    }

    return resolved;
    }
};

module.exports = {
  Request: FaultInjectionCtrlSrvRequest,
  Response: FaultInjectionCtrlSrvResponse,
  md5sum() { return '903881dc09163ac5bf8f905e4d1ee274'; },
  datatype() { return 'morai_msgs/FaultInjectionCtrlSrv'; }
};
