#ifndef _PROCESS_INFO_
#define _PROCESS_INFO_

/*ndt_localization 관련*/
extern bool ndt_working = false;
extern double ndt_process_time = 0.0;

/*patchwork++ 관련*/
extern bool patchworkpp_working = false;
extern double patchworkpp_process_time = 0.0;
extern int patchworkpp_input_size = 0.0;
extern int patchworkpp_ground_size = 0.0;
extern int patchworkpp_nonground_size = 0.0;

/*multi LiDAR Calbration 관련*/
extern bool multi_LiDAR_Calibration_working = false;

/*local 관련*/
extern bool local_working = false;

extern bool ego_location_x =0.0; 
extern bool ego_location_y =0.0; 

/*Lidar perception 관련*/
extern bool OD_working =false;
extern double OD_process_time = 0.0;
#endif