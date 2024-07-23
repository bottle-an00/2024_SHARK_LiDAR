
"use strict";

let TrafficLight = require('./TrafficLight.js');
let SyncModeScenarioLoad = require('./SyncModeScenarioLoad.js');
let ObjectStatusExtended = require('./ObjectStatusExtended.js');
let IntersectionControl = require('./IntersectionControl.js');
let EgoVehicleStatusExtended = require('./EgoVehicleStatusExtended.js');
let ObjectStatusListExtended = require('./ObjectStatusListExtended.js');
let MapSpecIndex = require('./MapSpecIndex.js');
let DillyCmd = require('./DillyCmd.js');
let SetTrafficLight = require('./SetTrafficLight.js');
let DillyCmdResponse = require('./DillyCmdResponse.js');
let SaveSensorData = require('./SaveSensorData.js');
let SVADC = require('./SVADC.js');
let SkateboardStatus = require('./SkateboardStatus.js');
let EgoVehicleStatus = require('./EgoVehicleStatus.js');
let EgoDdVehicleStatus = require('./EgoDdVehicleStatus.js');
let NpcGhostCmd = require('./NpcGhostCmd.js');
let NpcGhostInfo = require('./NpcGhostInfo.js');
let Lamps = require('./Lamps.js');
let MultiEgoSetting = require('./MultiEgoSetting.js');
let VehicleSpecIndex = require('./VehicleSpecIndex.js');
let MoraiSimProcStatus = require('./MoraiSimProcStatus.js');
let SensorPosControl = require('./SensorPosControl.js');
let WaitForTickResponse = require('./WaitForTickResponse.js');
let VehicleCollision = require('./VehicleCollision.js');
let FaultStatusInfo_Overall = require('./FaultStatusInfo_Overall.js');
let VehicleSpec = require('./VehicleSpec.js');
let ObjectStatus = require('./ObjectStatus.js');
let MoraiTLInfo = require('./MoraiTLInfo.js');
let GPSMessage = require('./GPSMessage.js');
let SyncModeResultResponse = require('./SyncModeResultResponse.js');
let ERP42Info = require('./ERP42Info.js');
let RadarDetection = require('./RadarDetection.js');
let FaultInjection_Sensor = require('./FaultInjection_Sensor.js');
let PREvent = require('./PREvent.js');
let SyncModeAddObject = require('./SyncModeAddObject.js');
let SkidSteer6wUGVCtrlCmd = require('./SkidSteer6wUGVCtrlCmd.js');
let MoraiSrvResponse = require('./MoraiSrvResponse.js');
let SyncModeRemoveObject = require('./SyncModeRemoveObject.js');
let FaultInjection_Response = require('./FaultInjection_Response.js');
let IntersectionStatus = require('./IntersectionStatus.js');
let SkidSteer6wUGVStatus = require('./SkidSteer6wUGVStatus.js');
let DdCtrlCmd = require('./DdCtrlCmd.js');
let SyncModeCmd = require('./SyncModeCmd.js');
let MoraiTLIndex = require('./MoraiTLIndex.js');
let MultiPlayEventRequest = require('./MultiPlayEventRequest.js');
let IntscnTL = require('./IntscnTL.js');
let PRCtrlCmd = require('./PRCtrlCmd.js');
let FaultInjection_Tire = require('./FaultInjection_Tire.js');
let GetTrafficLightStatus = require('./GetTrafficLightStatus.js');
let CtrlCmd = require('./CtrlCmd.js');
let GhostMessage = require('./GhostMessage.js');
let FaultStatusInfo_Vehicle = require('./FaultStatusInfo_Vehicle.js');
let ScenarioLoad = require('./ScenarioLoad.js');
let PRStatus = require('./PRStatus.js');
let SyncModeInfo = require('./SyncModeInfo.js');
let FaultStatusInfo = require('./FaultStatusInfo.js');
let CollisionData = require('./CollisionData.js');
let MultiPlayEventResponse = require('./MultiPlayEventResponse.js');
let MoraiSimProcHandle = require('./MoraiSimProcHandle.js');
let SyncModeSetGear = require('./SyncModeSetGear.js');
let ReplayInfo = require('./ReplayInfo.js');
let FaultInjection_Controller = require('./FaultInjection_Controller.js');
let WoowaDillyStatus = require('./WoowaDillyStatus.js');
let WaitForTick = require('./WaitForTick.js');
let FaultStatusInfo_Sensor = require('./FaultStatusInfo_Sensor.js');
let ObjectStatusList = require('./ObjectStatusList.js');
let VehicleCollisionData = require('./VehicleCollisionData.js');
let SyncModeCtrlCmd = require('./SyncModeCtrlCmd.js');
let SyncModeCmdResponse = require('./SyncModeCmdResponse.js');
let EventInfo = require('./EventInfo.js');
let SkateboardCtrlCmd = require('./SkateboardCtrlCmd.js');
let MapSpec = require('./MapSpec.js');
let RadarDetections = require('./RadarDetections.js');

module.exports = {
  TrafficLight: TrafficLight,
  SyncModeScenarioLoad: SyncModeScenarioLoad,
  ObjectStatusExtended: ObjectStatusExtended,
  IntersectionControl: IntersectionControl,
  EgoVehicleStatusExtended: EgoVehicleStatusExtended,
  ObjectStatusListExtended: ObjectStatusListExtended,
  MapSpecIndex: MapSpecIndex,
  DillyCmd: DillyCmd,
  SetTrafficLight: SetTrafficLight,
  DillyCmdResponse: DillyCmdResponse,
  SaveSensorData: SaveSensorData,
  SVADC: SVADC,
  SkateboardStatus: SkateboardStatus,
  EgoVehicleStatus: EgoVehicleStatus,
  EgoDdVehicleStatus: EgoDdVehicleStatus,
  NpcGhostCmd: NpcGhostCmd,
  NpcGhostInfo: NpcGhostInfo,
  Lamps: Lamps,
  MultiEgoSetting: MultiEgoSetting,
  VehicleSpecIndex: VehicleSpecIndex,
  MoraiSimProcStatus: MoraiSimProcStatus,
  SensorPosControl: SensorPosControl,
  WaitForTickResponse: WaitForTickResponse,
  VehicleCollision: VehicleCollision,
  FaultStatusInfo_Overall: FaultStatusInfo_Overall,
  VehicleSpec: VehicleSpec,
  ObjectStatus: ObjectStatus,
  MoraiTLInfo: MoraiTLInfo,
  GPSMessage: GPSMessage,
  SyncModeResultResponse: SyncModeResultResponse,
  ERP42Info: ERP42Info,
  RadarDetection: RadarDetection,
  FaultInjection_Sensor: FaultInjection_Sensor,
  PREvent: PREvent,
  SyncModeAddObject: SyncModeAddObject,
  SkidSteer6wUGVCtrlCmd: SkidSteer6wUGVCtrlCmd,
  MoraiSrvResponse: MoraiSrvResponse,
  SyncModeRemoveObject: SyncModeRemoveObject,
  FaultInjection_Response: FaultInjection_Response,
  IntersectionStatus: IntersectionStatus,
  SkidSteer6wUGVStatus: SkidSteer6wUGVStatus,
  DdCtrlCmd: DdCtrlCmd,
  SyncModeCmd: SyncModeCmd,
  MoraiTLIndex: MoraiTLIndex,
  MultiPlayEventRequest: MultiPlayEventRequest,
  IntscnTL: IntscnTL,
  PRCtrlCmd: PRCtrlCmd,
  FaultInjection_Tire: FaultInjection_Tire,
  GetTrafficLightStatus: GetTrafficLightStatus,
  CtrlCmd: CtrlCmd,
  GhostMessage: GhostMessage,
  FaultStatusInfo_Vehicle: FaultStatusInfo_Vehicle,
  ScenarioLoad: ScenarioLoad,
  PRStatus: PRStatus,
  SyncModeInfo: SyncModeInfo,
  FaultStatusInfo: FaultStatusInfo,
  CollisionData: CollisionData,
  MultiPlayEventResponse: MultiPlayEventResponse,
  MoraiSimProcHandle: MoraiSimProcHandle,
  SyncModeSetGear: SyncModeSetGear,
  ReplayInfo: ReplayInfo,
  FaultInjection_Controller: FaultInjection_Controller,
  WoowaDillyStatus: WoowaDillyStatus,
  WaitForTick: WaitForTick,
  FaultStatusInfo_Sensor: FaultStatusInfo_Sensor,
  ObjectStatusList: ObjectStatusList,
  VehicleCollisionData: VehicleCollisionData,
  SyncModeCtrlCmd: SyncModeCtrlCmd,
  SyncModeCmdResponse: SyncModeCmdResponse,
  EventInfo: EventInfo,
  SkateboardCtrlCmd: SkateboardCtrlCmd,
  MapSpec: MapSpec,
  RadarDetections: RadarDetections,
};
