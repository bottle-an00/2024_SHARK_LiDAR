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

class SkidSteer6wUGVCtrlCmd {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.cmd_type = null;
      this.Forward_input = null;
      this.Backward_input = null;
      this.Left_Turn_input = null;
      this.Right_Turn_input = null;
      this.left_front_wheel_rpm = null;
      this.left_middle_wheel_rpm = null;
      this.left_rear_wheel_rpm = null;
      this.right_front_wheel_rpm = null;
      this.right_middle_wheel_rpm = null;
      this.right_rear_wheel_rpm = null;
      this.Target_linear_velocity = null;
      this.Target_angular_velocity = null;
    }
    else {
      if (initObj.hasOwnProperty('cmd_type')) {
        this.cmd_type = initObj.cmd_type
      }
      else {
        this.cmd_type = 0;
      }
      if (initObj.hasOwnProperty('Forward_input')) {
        this.Forward_input = initObj.Forward_input
      }
      else {
        this.Forward_input = false;
      }
      if (initObj.hasOwnProperty('Backward_input')) {
        this.Backward_input = initObj.Backward_input
      }
      else {
        this.Backward_input = false;
      }
      if (initObj.hasOwnProperty('Left_Turn_input')) {
        this.Left_Turn_input = initObj.Left_Turn_input
      }
      else {
        this.Left_Turn_input = false;
      }
      if (initObj.hasOwnProperty('Right_Turn_input')) {
        this.Right_Turn_input = initObj.Right_Turn_input
      }
      else {
        this.Right_Turn_input = false;
      }
      if (initObj.hasOwnProperty('left_front_wheel_rpm')) {
        this.left_front_wheel_rpm = initObj.left_front_wheel_rpm
      }
      else {
        this.left_front_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('left_middle_wheel_rpm')) {
        this.left_middle_wheel_rpm = initObj.left_middle_wheel_rpm
      }
      else {
        this.left_middle_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('left_rear_wheel_rpm')) {
        this.left_rear_wheel_rpm = initObj.left_rear_wheel_rpm
      }
      else {
        this.left_rear_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('right_front_wheel_rpm')) {
        this.right_front_wheel_rpm = initObj.right_front_wheel_rpm
      }
      else {
        this.right_front_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('right_middle_wheel_rpm')) {
        this.right_middle_wheel_rpm = initObj.right_middle_wheel_rpm
      }
      else {
        this.right_middle_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('right_rear_wheel_rpm')) {
        this.right_rear_wheel_rpm = initObj.right_rear_wheel_rpm
      }
      else {
        this.right_rear_wheel_rpm = 0.0;
      }
      if (initObj.hasOwnProperty('Target_linear_velocity')) {
        this.Target_linear_velocity = initObj.Target_linear_velocity
      }
      else {
        this.Target_linear_velocity = 0.0;
      }
      if (initObj.hasOwnProperty('Target_angular_velocity')) {
        this.Target_angular_velocity = initObj.Target_angular_velocity
      }
      else {
        this.Target_angular_velocity = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SkidSteer6wUGVCtrlCmd
    // Serialize message field [cmd_type]
    bufferOffset = _serializer.int32(obj.cmd_type, buffer, bufferOffset);
    // Serialize message field [Forward_input]
    bufferOffset = _serializer.bool(obj.Forward_input, buffer, bufferOffset);
    // Serialize message field [Backward_input]
    bufferOffset = _serializer.bool(obj.Backward_input, buffer, bufferOffset);
    // Serialize message field [Left_Turn_input]
    bufferOffset = _serializer.bool(obj.Left_Turn_input, buffer, bufferOffset);
    // Serialize message field [Right_Turn_input]
    bufferOffset = _serializer.bool(obj.Right_Turn_input, buffer, bufferOffset);
    // Serialize message field [left_front_wheel_rpm]
    bufferOffset = _serializer.float32(obj.left_front_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [left_middle_wheel_rpm]
    bufferOffset = _serializer.float32(obj.left_middle_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [left_rear_wheel_rpm]
    bufferOffset = _serializer.float32(obj.left_rear_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [right_front_wheel_rpm]
    bufferOffset = _serializer.float32(obj.right_front_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [right_middle_wheel_rpm]
    bufferOffset = _serializer.float32(obj.right_middle_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [right_rear_wheel_rpm]
    bufferOffset = _serializer.float32(obj.right_rear_wheel_rpm, buffer, bufferOffset);
    // Serialize message field [Target_linear_velocity]
    bufferOffset = _serializer.float32(obj.Target_linear_velocity, buffer, bufferOffset);
    // Serialize message field [Target_angular_velocity]
    bufferOffset = _serializer.float32(obj.Target_angular_velocity, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SkidSteer6wUGVCtrlCmd
    let len;
    let data = new SkidSteer6wUGVCtrlCmd(null);
    // Deserialize message field [cmd_type]
    data.cmd_type = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [Forward_input]
    data.Forward_input = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Backward_input]
    data.Backward_input = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Left_Turn_input]
    data.Left_Turn_input = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [Right_Turn_input]
    data.Right_Turn_input = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [left_front_wheel_rpm]
    data.left_front_wheel_rpm = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_middle_wheel_rpm]
    data.left_middle_wheel_rpm = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [left_rear_wheel_rpm]
    data.left_rear_wheel_rpm = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_front_wheel_rpm]
    data.right_front_wheel_rpm = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_middle_wheel_rpm]
    data.right_middle_wheel_rpm = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [right_rear_wheel_rpm]
    data.right_rear_wheel_rpm = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Target_linear_velocity]
    data.Target_linear_velocity = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [Target_angular_velocity]
    data.Target_angular_velocity = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'morai_msgs/SkidSteer6wUGVCtrlCmd';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cb8a43878b1b2c65f50bd53e5a4c03f4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 cmd_type
    
    bool Forward_input
    bool Backward_input
    bool Left_Turn_input
    bool Right_Turn_input
    
    float32 left_front_wheel_rpm
    float32 left_middle_wheel_rpm
    float32 left_rear_wheel_rpm
    float32 right_front_wheel_rpm
    float32 right_middle_wheel_rpm
    float32 right_rear_wheel_rpm
    
    float32 Target_linear_velocity
    float32 Target_angular_velocity
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SkidSteer6wUGVCtrlCmd(null);
    if (msg.cmd_type !== undefined) {
      resolved.cmd_type = msg.cmd_type;
    }
    else {
      resolved.cmd_type = 0
    }

    if (msg.Forward_input !== undefined) {
      resolved.Forward_input = msg.Forward_input;
    }
    else {
      resolved.Forward_input = false
    }

    if (msg.Backward_input !== undefined) {
      resolved.Backward_input = msg.Backward_input;
    }
    else {
      resolved.Backward_input = false
    }

    if (msg.Left_Turn_input !== undefined) {
      resolved.Left_Turn_input = msg.Left_Turn_input;
    }
    else {
      resolved.Left_Turn_input = false
    }

    if (msg.Right_Turn_input !== undefined) {
      resolved.Right_Turn_input = msg.Right_Turn_input;
    }
    else {
      resolved.Right_Turn_input = false
    }

    if (msg.left_front_wheel_rpm !== undefined) {
      resolved.left_front_wheel_rpm = msg.left_front_wheel_rpm;
    }
    else {
      resolved.left_front_wheel_rpm = 0.0
    }

    if (msg.left_middle_wheel_rpm !== undefined) {
      resolved.left_middle_wheel_rpm = msg.left_middle_wheel_rpm;
    }
    else {
      resolved.left_middle_wheel_rpm = 0.0
    }

    if (msg.left_rear_wheel_rpm !== undefined) {
      resolved.left_rear_wheel_rpm = msg.left_rear_wheel_rpm;
    }
    else {
      resolved.left_rear_wheel_rpm = 0.0
    }

    if (msg.right_front_wheel_rpm !== undefined) {
      resolved.right_front_wheel_rpm = msg.right_front_wheel_rpm;
    }
    else {
      resolved.right_front_wheel_rpm = 0.0
    }

    if (msg.right_middle_wheel_rpm !== undefined) {
      resolved.right_middle_wheel_rpm = msg.right_middle_wheel_rpm;
    }
    else {
      resolved.right_middle_wheel_rpm = 0.0
    }

    if (msg.right_rear_wheel_rpm !== undefined) {
      resolved.right_rear_wheel_rpm = msg.right_rear_wheel_rpm;
    }
    else {
      resolved.right_rear_wheel_rpm = 0.0
    }

    if (msg.Target_linear_velocity !== undefined) {
      resolved.Target_linear_velocity = msg.Target_linear_velocity;
    }
    else {
      resolved.Target_linear_velocity = 0.0
    }

    if (msg.Target_angular_velocity !== undefined) {
      resolved.Target_angular_velocity = msg.Target_angular_velocity;
    }
    else {
      resolved.Target_angular_velocity = 0.0
    }

    return resolved;
    }
};

module.exports = SkidSteer6wUGVCtrlCmd;
