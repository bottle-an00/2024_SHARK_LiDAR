// Auto-generated. Do not edit!

// (in-package morai_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let FaultStatusInfo_Overall = require('./FaultStatusInfo_Overall.js');

//-----------------------------------------------------------

class FaultStatusInfo_Sensor {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.sensor_id = null;
      this.sensor = null;
    }
    else {
      if (initObj.hasOwnProperty('sensor_id')) {
        this.sensor_id = initObj.sensor_id
      }
      else {
        this.sensor_id = 0;
      }
      if (initObj.hasOwnProperty('sensor')) {
        this.sensor = initObj.sensor
      }
      else {
        this.sensor = new FaultStatusInfo_Overall();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultStatusInfo_Sensor
    // Serialize message field [sensor_id]
    bufferOffset = _serializer.int32(obj.sensor_id, buffer, bufferOffset);
    // Serialize message field [sensor]
    bufferOffset = FaultStatusInfo_Overall.serialize(obj.sensor, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultStatusInfo_Sensor
    let len;
    let data = new FaultStatusInfo_Sensor(null);
    // Deserialize message field [sensor_id]
    data.sensor_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [sensor]
    data.sensor = FaultStatusInfo_Overall.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += FaultStatusInfo_Overall.getMessageSize(object.sensor);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/FaultStatusInfo_Sensor';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9ffcbdb400d2f73cb504fbb8f540f234';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 sensor_id
    FaultStatusInfo_Overall sensor
    
    
    ================================================================================
    MSG: morai_msgs/FaultStatusInfo_Overall
    bool status
    int32[] fault_subclass
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FaultStatusInfo_Sensor(null);
    if (msg.sensor_id !== undefined) {
      resolved.sensor_id = msg.sensor_id;
    }
    else {
      resolved.sensor_id = 0
    }

    if (msg.sensor !== undefined) {
      resolved.sensor = FaultStatusInfo_Overall.Resolve(msg.sensor)
    }
    else {
      resolved.sensor = new FaultStatusInfo_Overall()
    }

    return resolved;
    }
};

module.exports = FaultStatusInfo_Sensor;
