// Auto-generated. Do not edit!

// (in-package morai_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let FaultStatusInfo_Vehicle = require('./FaultStatusInfo_Vehicle.js');
let FaultStatusInfo_Sensor = require('./FaultStatusInfo_Sensor.js');

//-----------------------------------------------------------

class FaultInjection_Response {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
      this.unique_id = null;
      this.vehicle = null;
      this.sensors = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = false;
      }
      if (initObj.hasOwnProperty('unique_id')) {
        this.unique_id = initObj.unique_id
      }
      else {
        this.unique_id = 0;
      }
      if (initObj.hasOwnProperty('vehicle')) {
        this.vehicle = initObj.vehicle
      }
      else {
        this.vehicle = new FaultStatusInfo_Vehicle();
      }
      if (initObj.hasOwnProperty('sensors')) {
        this.sensors = initObj.sensors
      }
      else {
        this.sensors = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultInjection_Response
    // Serialize message field [result]
    bufferOffset = _serializer.bool(obj.result, buffer, bufferOffset);
    // Serialize message field [unique_id]
    bufferOffset = _serializer.int32(obj.unique_id, buffer, bufferOffset);
    // Serialize message field [vehicle]
    bufferOffset = FaultStatusInfo_Vehicle.serialize(obj.vehicle, buffer, bufferOffset);
    // Serialize message field [sensors]
    // Serialize the length for message field [sensors]
    bufferOffset = _serializer.uint32(obj.sensors.length, buffer, bufferOffset);
    obj.sensors.forEach((val) => {
      bufferOffset = FaultStatusInfo_Sensor.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultInjection_Response
    let len;
    let data = new FaultInjection_Response(null);
    // Deserialize message field [result]
    data.result = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [unique_id]
    data.unique_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [vehicle]
    data.vehicle = FaultStatusInfo_Vehicle.deserialize(buffer, bufferOffset);
    // Deserialize message field [sensors]
    // Deserialize array length for message field [sensors]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.sensors = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.sensors[i] = FaultStatusInfo_Sensor.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += FaultStatusInfo_Vehicle.getMessageSize(object.vehicle);
    object.sensors.forEach((val) => {
      length += FaultStatusInfo_Sensor.getMessageSize(val);
    });
    return length + 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/FaultInjection_Response';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '62056bf4fc5f4a1c260169ca104b9ebf';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new FaultInjection_Response(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = false
    }

    if (msg.unique_id !== undefined) {
      resolved.unique_id = msg.unique_id;
    }
    else {
      resolved.unique_id = 0
    }

    if (msg.vehicle !== undefined) {
      resolved.vehicle = FaultStatusInfo_Vehicle.Resolve(msg.vehicle)
    }
    else {
      resolved.vehicle = new FaultStatusInfo_Vehicle()
    }

    if (msg.sensors !== undefined) {
      resolved.sensors = new Array(msg.sensors.length);
      for (let i = 0; i < resolved.sensors.length; ++i) {
        resolved.sensors[i] = FaultStatusInfo_Sensor.Resolve(msg.sensors[i]);
      }
    }
    else {
      resolved.sensors = []
    }

    return resolved;
    }
};

module.exports = FaultInjection_Response;
