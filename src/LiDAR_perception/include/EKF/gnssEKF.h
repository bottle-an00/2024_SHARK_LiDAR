#ifndef GPSEKF_H_
#define GPSEKF_H_

#include "measurement_package.h"
#include "Eigen/Dense"
#include <vector>
#include <string>
#include <fstream>
#include "kalman_filter.h"
#include "tools.h"
#include <iostream>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;

#define PI_ 3.141592

class GNSSEKF {
public:
  /**
  * Constructor.
  */
  GNSSEKF() {
    is_initialized_ = false;

    previous_timestamp_ = 0;

    // initializing matrices
    R_ = MatrixXd(2, 2);
    H_ = MatrixXd(2, 4);

    //measurement covariance matrix - GNSS
    R_ << 0.0225, 0,
                0, 0.0225;

    /*TODO:
      * Finish initializing the FusionEKF.
      * Set the process and measurement noises
    */
    H_ << 1, 0, 0, 0,
                0, 1, 0, 0;
  	// initialize the kalman filter variables
    ekf_.P_ = MatrixXd(4, 4);
    ekf_.P_ << 1, 0, 0, 0,
               0, 1, 0, 0,
               0, 0, 10, 0,
               0, 0, 0, 10;
    ekf_.F_ = MatrixXd(4, 4);
    ekf_.F_ << 1, 0, 0, 0,
               0, 1, 0, 0,
               0, 0, 1, 0,
               0, 0, 0, 1;
    // set measurement noises
    noise_ax = 4;
    noise_ay = 4;
    
  }

  /**
  * Destructor.
  */
  virtual ~GNSSEKF() {}

  /**
  * Run the whole flow of the Kalman Filter from here.
  */
  void initialization(const MeasurementPackage &measurement_pack) {


    /*****************************************************************************
     *  Initialization
     ****************************************************************************/
    if (!is_initialized_) {

      ekf_.x_ = VectorXd(4);
      ekf_.x_ << measurement_pack.raw_measurements_[0], measurement_pack.raw_measurements_[1], 0, 0; // x, y, vx, vy

      previous_timestamp_ = measurement_pack.timestamp_;

      // done initializing, no need to predict or update
      is_initialized_ = true;
      return;
    }
  }

  void ekf_predict(const long long currnet_time, double angular_vel_z){
    /*****************************************************************************
     *  Prediction
     ****************************************************************************/

    /**
       * Update the state transition matrix F according to the new elapsed time.
        - Time is measured in seconds.
       * Update the process noise covariance matrix.
       * Use noise_ax = 9 and noise_ay = 9 for your Q matrix.
     */

    // compute the time elapsed between the current and previous measurements

    float dt = (currnet_time - previous_timestamp_) / 1000000000.0;  //  in seconds

    float dt_2 = dt * dt;
    float dt_3 = dt_2 * dt;
    float dt_4 = dt_3 * dt;

    // Modify the F matrix so that the time is integrated
    double d_yaw = angular_vel_z*dt;

    // ekf_.F_(0, 2) =  cos(d_yaw)*dt;
    // ekf_.F_(0, 3) = -sin(d_yaw)*dt;
    // ekf_.F_(1, 2) =  sin(d_yaw)*dt;
    // ekf_.F_(1, 3) =  cos(d_yaw)*dt;
    
    ekf_.F_(0, 2) = dt;
    ekf_.F_(1, 3) = dt;

    //set the process covariance matrix Q
    ekf_.Q_ = MatrixXd(4, 4);
    ekf_.Q_ << dt_4/4*noise_ax,   0,                dt_3/2*noise_ax,  0,
               0,                 dt_4/4*noise_ay,  0,                dt_3/2*noise_ay,
               dt_3/2*noise_ax,   0,                dt_2*noise_ax,    0,
               0,                 dt_3/2*noise_ay,  0,                dt_2*noise_ay;

    ekf_.Predict();
  }

  void ekf_update(const MeasurementPackage &measurement_pack){
    /*****************************************************************************
     *  Update
     ****************************************************************************/

    /**
       * Use the sensor type to perform the update step.
       * Update the state and covariance matrices.
     */
    previous_timestamp_ = measurement_pack.timestamp_;//측정치가 update될 때를 기준!

    
    // Laser updates
    ekf_.H_ = H_;
    ekf_.R_ = R_;
    ekf_.Update(measurement_pack.raw_measurements_);

    // print the output
  //  cout << "x_ = " << ekf_.x_ << endl;
  //  cout << "P_ = " << ekf_.P_ << endl;
  }
  
  /**
  * Kalman Filter update and prediction math lives in here.
  */
  KalmanFilter ekf_;

private:
  // check whether the tracking toolbox was initiallized or not (first measurement)
  bool is_initialized_;

  // previous timestamp
  long long previous_timestamp_;

  // tool object used to compute Jacobian and RMSE
  Tools tools;
  Eigen::MatrixXd R_;    // laser measurement noise
  Eigen::MatrixXd H_;    // measurement function for laser

  float noise_ax;
  float noise_ay;
};

#endif 
