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

class DillyCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.isPickup = null;
      this.deliveryItemIndex = null;
    }
    else {
      if (initObj.hasOwnProperty('isPickup')) {
        this.isPickup = initObj.isPickup
      }
      else {
        this.isPickup = false;
      }
      if (initObj.hasOwnProperty('deliveryItemIndex')) {
        this.deliveryItemIndex = initObj.deliveryItemIndex
      }
      else {
        this.deliveryItemIndex = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DillyCmd
    // Serialize message field [isPickup]
    bufferOffset = _serializer.bool(obj.isPickup, buffer, bufferOffset);
    // Serialize message field [deliveryItemIndex]
    bufferOffset = _serializer.int32(obj.deliveryItemIndex, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DillyCmd
    let len;
    let data = new DillyCmd(null);
    // Deserialize message field [isPickup]
    data.isPickup = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [deliveryItemIndex]
    data.deliveryItemIndex = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/DillyCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4c01be8e010c2bb6f36d7ace7c88decc';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool isPickup
    int32 deliveryItemIndex
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DillyCmd(null);
    if (msg.isPickup !== undefined) {
      resolved.isPickup = msg.isPickup;
    }
    else {
      resolved.isPickup = false
    }

    if (msg.deliveryItemIndex !== undefined) {
      resolved.deliveryItemIndex = msg.deliveryItemIndex;
    }
    else {
      resolved.deliveryItemIndex = 0
    }

    return resolved;
    }
};

module.exports = DillyCmd;
