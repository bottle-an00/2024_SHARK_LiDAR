#ifndef FusionEKF_H_
#define FusionEKF_H_

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

class FusionEKF {
public:
  /**
  * Constructor.
  */
  FusionEKF() {
    is_initialized_ = false;

    previous_timestamp_ = 0;

    // initializing matrices
    R_laser_ = MatrixXd(2, 2);
    H_laser_ = MatrixXd(2, 4);

    //measurement covariance matrix - laser
    R_laser_ << 0.0225, 0,
                0, 0.0225;

    /*TODO:
      * Finish initializing the FusionEKF.
      * Set the process and measurement noises
    */
    H_laser_ << 1, 0, 0, 0,
                0, 1, 0, 0;
  	// initialize the kalman filter variables
    ekf_.P_ = MatrixXd(4, 4);
    ekf_.P_ << 1, 0, 0, 0,
               0, 1, 0, 0,
               0, 0, 10, 0,
               0, 0, 0, 10;
    ekf_.F_ = MatrixXd(4, 4);
    ekf_.F_ << 1, 0, 1, 0,
               0, 1, 0, 1,
               0, 0, 1, 0,
               0, 0, 0, 1;
    // set measurement noises
    noise_ax = 10;
    noise_ay = 10;
    
  }

  /**
  * Destructor.
  */
  virtual ~FusionEKF() {}

  /**
  * Run the whole flow of the Kalman Filter from here.
  */
  void ProcessMeasurement(const MeasurementPackage &measurement_pack) {


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

    float dt = (measurement_pack.timestamp_ - previous_timestamp_) / 1000000000.0;  //  in seconds
    //cout << "time :: " << previous_timestamp_<<" ttttttttttt   " << measurement_pack.timestamp_  << "dt :: " << dt << endl<< endl;
    previous_timestamp_ = measurement_pack.timestamp_;

    float dt_2 = dt * dt;
    float dt_3 = dt_2 * dt;
    float dt_4 = dt_3 * dt;

    // Modify the F matrix so that the time is integrated
    ekf_.F_(0, 2) = dt;
    ekf_.F_(1, 3) = dt;

    //set the process covariance matrix Q
    ekf_.Q_ = MatrixXd(4, 4);
    ekf_.Q_ << dt_4/4*noise_ax,   0,                dt_3/2*noise_ax,  0,
               0,                 dt_4/4*noise_ay,  0,                dt_3/2*noise_ay,
               dt_3/2*noise_ax,   0,                dt_2*noise_ax,    0,
               0,                 dt_3/2*noise_ay,  0,                dt_2*noise_ay;

    ekf_.Predict();

    /*****************************************************************************
     *  Update
     ****************************************************************************/

    /**
       * Use the sensor type to perform the update step.
       * Update the state and covariance matrices.
     */

    
    // Laser updates
    ekf_.H_ = H_laser_;
    ekf_.R_ = R_laser_;
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
  Eigen::MatrixXd R_laser_;    // laser measurement noise
  Eigen::MatrixXd H_laser_;    // measurement function for laser

  float noise_ax;
  float noise_ay;
};

#endif /* FusionEKF_H_ */
