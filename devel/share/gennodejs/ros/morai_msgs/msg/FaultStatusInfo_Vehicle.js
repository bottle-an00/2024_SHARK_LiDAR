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

class FaultStatusInfo_Vehicle {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.accel = null;
      this.brake = null;
      this.steer = null;
      this.tires = null;
    }
    else {
      if (initObj.hasOwnProperty('accel')) {
        this.accel = initObj.accel
      }
      else {
        this.accel = new FaultStatusInfo_Overall();
      }
      if (initObj.hasOwnProperty('brake')) {
        this.brake = initObj.brake
      }
      else {
        this.brake = new FaultStatusInfo_Overall();
      }
      if (initObj.hasOwnProperty('steer')) {
        this.steer = initObj.steer
      }
      else {
        this.steer = new FaultStatusInfo_Overall();
      }
      if (initObj.hasOwnProperty('tires')) {
        this.tires = initObj.tires
      }
      else {
        this.tires = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FaultStatusInfo_Vehicle
    // Serialize message field [accel]
    bufferOffset = FaultStatusInfo_Overall.serialize(obj.accel, buffer, bufferOffset);
    // Serialize message field [brake]
    bufferOffset = FaultStatusInfo_Overall.serialize(obj.brake, buffer, bufferOffset);
    // Serialize message field [steer]
    bufferOffset = FaultStatusInfo_Overall.serialize(obj.steer, buffer, bufferOffset);
    // Serialize message field [tires]
    // Serialize the length for message field [tires]
    bufferOffset = _serializer.uint32(obj.tires.length, buffer, bufferOffset);
    obj.tires.forEach((val) => {
      bufferOffset = FaultStatusInfo_Overall.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FaultStatusInfo_Vehicle
    let len;
    let data = new FaultStatusInfo_Vehicle(null);
    // Deserialize message field [accel]
    data.accel = FaultStatusInfo_Overall.deserialize(buffer, bufferOffset);
    // Deserialize message field [brake]
    data.brake = FaultStatusInfo_Overall.deserialize(buffer, bufferOffset);
    // Deserialize message field [steer]
    data.steer = FaultStatusInfo_Overall.deserialize(buffer, bufferOffset);
    // Deserialize message field [tires]
    // Deserialize array length for message field [tires]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.tires = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.tires[i] = FaultStatusInfo_Overall.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += FaultStatusInfo_Overall.getMessageSize(object.accel);
    length += FaultStatusInfo_Overall.getMessageSize(object.brake);
    length += FaultStatusInfo_Overall.getMessageSize(object.steer);
    object.tires.forEach((val) => {
      length += FaultStatusInfo_Overall.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/FaultStatusInfo_Vehicle';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'dcd69cdf7980329f2014366617eda419';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    FaultStatusInfo_Overall accel
    FaultStatusInfo_Overall brake
    FaultStatusInfo_Overall steer
    FaultStatusInfo_Overall[] tires
    
    
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
    const resolved = new FaultStatusInfo_Vehicle(null);
    if (msg.accel !== undefined) {
      resolved.accel = FaultStatusInfo_Overall.Resolve(msg.accel)
    }
    else {
      resolved.accel = new FaultStatusInfo_Overall()
    }

    if (msg.brake !== undefined) {
      resolved.brake = FaultStatusInfo_Overall.Resolve(msg.brake)
    }
    else {
      resolved.brake = new FaultStatusInfo_Overall()
    }

    if (msg.steer !== undefined) {
      resolved.steer = FaultStatusInfo_Overall.Resolve(msg.steer)
    }
    else {
      resolved.steer = new FaultStatusInfo_Overall()
    }

    if (msg.tires !== undefined) {
      resolved.tires = new Array(msg.tires.length);
      for (let i = 0; i < resolved.tires.length; ++i) {
        resolved.tires[i] = FaultStatusInfo_Overall.Resolve(msg.tires[i]);
      }
    }
    else {
      resolved.tires = []
    }

    return resolved;
    }
};

module.exports = FaultStatusInfo_Vehicle;
