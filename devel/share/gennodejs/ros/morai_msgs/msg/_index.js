
"use strict";

let SyncModeAddObject = require('./SyncModeAddObject.js');
let IntersectionStatus = require('./IntersectionStatus.js');
let SkidSteer6wUGVStatus = require('./SkidSteer6wUGVStatus.js');
let ObjectStatus = require('./ObjectStatus.js');
let PRCtrlCmd = require('./PRCtrlCmd.js');
let ObjectStatusListExtended = require('./ObjectStatusListExtended.js');
let SkateboardStatus = require('./SkateboardStatus.js');
let EgoDdVehicleStatus = require('./EgoDdVehicleStatus.js');
let CtrlCmd = require('./CtrlCmd.js');
let SyncModeResultResponse = require('./SyncModeResultResponse.js');
let MoraiTLInfo = require('./MoraiTLInfo.js');
let FaultStatusInfo_Vehicle = require('./FaultStatusInfo_Vehicle.js');
let DdCtrlCmd = require('./DdCtrlCmd.js');
let SyncModeCmd = require('./SyncModeCmd.js');
let FaultInjection_Tire = require('./FaultInjection_Tire.js');
let ObjectStatusList = require('./ObjectStatusList.js');
let FaultInjection_Sensor = require('./FaultInjection_Sensor.js');
let SetTrafficLight = require('./SetTrafficLight.js');
let MoraiSrvResponse = require('./MoraiSrvResponse.js');
let SkateboardCtrlCmd = require('./SkateboardCtrlCmd.js');
let RadarDetections = require('./RadarDetections.js');
let WaitForTickResponse = require('./WaitForTickResponse.js');
let FaultInjection_Response = require('./FaultInjection_Response.js');
let VehicleCollision = require('./VehicleCollision.js');
let EgoVehicleStatus = require('./EgoVehicleStatus.js');
let VehicleSpecIndex = require('./VehicleSpecIndex.js');
let MapSpecIndex = require('./MapSpecIndex.js');
let GetTrafficLightStatus = require('./GetTrafficLightStatus.js');
let MoraiSimProcStatus = require('./MoraiSimProcStatus.js');
let TrafficLight = require('./TrafficLight.js');
let EgoVehicleStatusExtended = require('./EgoVehicleStatusExtended.js');
let SVADC = require('./SVADC.js');
let IntscnTL = require('./IntscnTL.js');
let Lamps = require('./Lamps.js');
let VehicleSpec = require('./VehicleSpec.js');
let PRStatus = require('./PRStatus.js');
let VehicleCollisionData = require('./VehicleCollisionData.js');
let SyncModeCmdResponse = require('./SyncModeCmdResponse.js');
let FaultStatusInfo_Sensor = require('./FaultStatusInfo_Sensor.js');
let ReplayInfo = require('./ReplayInfo.js');
let MoraiSimProcHandle = require('./MoraiSimProcHandle.js');
let WaitForTick = require('./WaitForTick.js');
let MultiEgoSetting = require('./MultiEgoSetting.js');
let FaultInjection_Controller = require('./FaultInjection_Controller.js');
let DillyCmd = require('./DillyCmd.js');
let ScenarioLoad = require('./ScenarioLoad.js');
let MultiPlayEventResponse = require('./MultiPlayEventResponse.js');
let SensorPosControl = require('./SensorPosControl.js');
let SyncModeScenarioLoad = require('./SyncModeScenarioLoad.js');
let SaveSensorData = require('./SaveSensorData.js');
let RadarDetection = require('./RadarDetection.js');
let ERP42Info = require('./ERP42Info.js');
let WoowaDillyStatus = require('./WoowaDillyStatus.js');
let PREvent = require('./PREvent.js');
let SyncModeInfo = require('./SyncModeInfo.js');
let FaultStatusInfo = require('./FaultStatusInfo.js');
let SkidSteer6wUGVCtrlCmd = require('./SkidSteer6wUGVCtrlCmd.js');
let MoraiTLIndex = require('./MoraiTLIndex.js');
let IntersectionControl = require('./IntersectionControl.js');
let CollisionData = require('./CollisionData.js');
let NpcGhostInfo = require('./NpcGhostInfo.js');
let GPSMessage = require('./GPSMessage.js');
let MapSpec = require('./MapSpec.js');
let EventInfo = require('./EventInfo.js');
let SyncModeCtrlCmd = require('./SyncModeCtrlCmd.js');
let SyncModeRemoveObject = require('./SyncModeRemoveObject.js');
let DillyCmdResponse = require('./DillyCmdResponse.js');
let GhostMessage = require('./GhostMessage.js');
let MultiPlayEventRequest = require('./MultiPlayEventRequest.js');
let NpcGhostCmd = require('./NpcGhostCmd.js');
let SyncModeSetGear = require('./SyncModeSetGear.js');
let FaultStatusInfo_Overall = require('./FaultStatusInfo_Overall.js');
let ObjectStatusExtended = require('./ObjectStatusExtended.js');

module.exports = {
  SyncModeAddObject: SyncModeAddObject,
  IntersectionStatus: IntersectionStatus,
  SkidSteer6wUGVStatus: SkidSteer6wUGVStatus,
  ObjectStatus: ObjectStatus,
  PRCtrlCmd: PRCtrlCmd,
  ObjectStatusListExtended: ObjectStatusListExtended,
  SkateboardStatus: SkateboardStatus,
  EgoDdVehicleStatus: EgoDdVehicleStatus,
  CtrlCmd: CtrlCmd,
  SyncModeResultResponse: SyncModeResultResponse,
  MoraiTLInfo: MoraiTLInfo,
  FaultStatusInfo_Vehicle: FaultStatusInfo_Vehicle,
  DdCtrlCmd: DdCtrlCmd,
  SyncModeCmd: SyncModeCmd,
  FaultInjection_Tire: FaultInjection_Tire,
  ObjectStatusList: ObjectStatusList,
  FaultInjection_Sensor: FaultInjection_Sensor,
  SetTrafficLight: SetTrafficLight,
  MoraiSrvResponse: MoraiSrvResponse,
  SkateboardCtrlCmd: SkateboardCtrlCmd,
  RadarDetections: RadarDetections,
  WaitForTickResponse: WaitForTickResponse,
  FaultInjection_Response: FaultInjection_Response,
  VehicleCollision: VehicleCollision,
  EgoVehicleStatus: EgoVehicleStatus,
  VehicleSpecIndex: VehicleSpecIndex,
  MapSpecIndex: MapSpecIndex,
  GetTrafficLightStatus: GetTrafficLightStatus,
  MoraiSimProcStatus: MoraiSimProcStatus,
  TrafficLight: TrafficLight,
  EgoVehicleStatusExtended: EgoVehicleStatusExtended,
  SVADC: SVADC,
  IntscnTL: IntscnTL,
  Lamps: Lamps,
  VehicleSpec: VehicleSpec,
  PRStatus: PRStatus,
  VehicleCollisionData: VehicleCollisionData,
  SyncModeCmdResponse: SyncModeCmdResponse,
  FaultStatusInfo_Sensor: FaultStatusInfo_Sensor,
  ReplayInfo: ReplayInfo,
  MoraiSimProcHandle: MoraiSimProcHandle,
  WaitForTick: WaitForTick,
  MultiEgoSetting: MultiEgoSetting,
  FaultInjection_Controller: FaultInjection_Controller,
  DillyCmd: DillyCmd,
  ScenarioLoad: ScenarioLoad,
  MultiPlayEventResponse: MultiPlayEventResponse,
  SensorPosControl: SensorPosControl,
  SyncModeScenarioLoad: SyncModeScenarioLoad,
  SaveSensorData: SaveSensorData,
  RadarDetection: RadarDetection,
  ERP42Info: ERP42Info,
  WoowaDillyStatus: WoowaDillyStatus,
  PREvent: PREvent,
  SyncModeInfo: SyncModeInfo,
  FaultStatusInfo: FaultStatusInfo,
  SkidSteer6wUGVCtrlCmd: SkidSteer6wUGVCtrlCmd,
  MoraiTLIndex: MoraiTLIndex,
  IntersectionControl: IntersectionControl,
  CollisionData: CollisionData,
  NpcGhostInfo: NpcGhostInfo,
  GPSMessage: GPSMessage,
  MapSpec: MapSpec,
  EventInfo: EventInfo,
  SyncModeCtrlCmd: SyncModeCtrlCmd,
  SyncModeRemoveObject: SyncModeRemoveObject,
  DillyCmdResponse: DillyCmdResponse,
  GhostMessage: GhostMessage,
  MultiPlayEventRequest: MultiPlayEventRequest,
  NpcGhostCmd: NpcGhostCmd,
  SyncModeSetGear: SyncModeSetGear,
  FaultStatusInfo_Overall: FaultStatusInfo_Overall,
  ObjectStatusExtended: ObjectStatusExtended,
};
