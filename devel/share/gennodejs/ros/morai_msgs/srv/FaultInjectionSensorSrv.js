// Auto-generated. Do not edit!

// (in-package morai_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let FaultInjection_Sensor = require('../msg/FaultInjection_Sensor.js');

//-----------------------------------------------------------

let FaultInjection_Response = require('../msg/FaultInjection_Response.js');

//-----------------------------------------------------------

class FaultInjectionSensorSrvRequest {
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
        this.request = new FaultInjection_Sensor();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultInjectionSensorSrvRequest
    // Serialize message field [request]
    bufferOffset = FaultInjection_Sensor.serialize(obj.request, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultInjectionSensorSrvRequest
    let len;
    let data = new FaultInjectionSensorSrvRequest(null);
    // Deserialize message field [request]
    data.request = FaultInjection_Sensor.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 64;
  }

  static datatype() {
    // Returns string type for a service object
    return 'morai_msgs/FaultInjectionSensorSrvRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cdcb6ce83ad332fbbad42c4b06d7ed5f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    FaultInjection_Sensor request
    
    ================================================================================
    MSG: morai_msgs/FaultInjection_Sensor
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
    const resolved = new FaultInjectionSensorSrvRequest(null);
    if (msg.request !== undefined) {
      resolved.request = FaultInjection_Sensor.Resolve(msg.request)
    }
    else {
      resolved.request = new FaultInjection_Sensor()
    }

    return resolved;
    }
};

class FaultInjectionSensorSrvResponse {
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
    // Serializes a message object of type FaultInjectionSensorSrvResponse
    // Serialize message field [response]
    bufferOffset = FaultInjection_Response.serialize(obj.response, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultInjectionSensorSrvResponse
    let len;
    let data = new FaultInjectionSensorSrvResponse(null);
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
    return 'morai_msgs/FaultInjectionSensorSrvResponse';
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
    const resolved = new FaultInjectionSensorSrvResponse(null);
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
  Request: FaultInjectionSensorSrvRequest,
  Response: FaultInjectionSensorSrvResponse,
  md5sum() { return '7a22d370d63968f482f03b961f96bf2e'; },
  datatype() { return 'morai_msgs/FaultInjectionSensorSrv'; }
};
