#ifndef KALMAN_FILTER_H_
#define KALMAN_FILTER_H_
#include "Eigen/Dense"
#include <math.h>
#include <vector>
#include <string>
#include "perception/fixedQueue.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

class KalmanFilter {
public:
  const float PI2 = 2 * M_PI;
  
  FixedSizeQueue<int> fixed_queue;

  int is_dynamic =0;

  std::vector<std::string> status;

  // state vector
  Eigen::VectorXd x_;

  // state covariance matrix
  Eigen::MatrixXd P_;

  // state transistion matrix
  Eigen::MatrixXd F_;
  
  // process covariance matrix
  Eigen::MatrixXd Q_;

  // measurement matrix
  Eigen::MatrixXd H_;

  // measurement covariance matrix
  Eigen::MatrixXd R_;

  /**
   * Constructor
   */
  KalmanFilter(){
    is_dynamic = false;
    status.resize(3);
    
    status[0] = "";
    status[1] = "dynamic";
    status[2] = "static";

  } 

  /**
   * Destructor
   */
  virtual ~KalmanFilter(){}

  /**
   * Init Initializes Kalman filter
   * @param x_in Initial state
   * @param u_in Initial control 
   * @param P_in Initial state covariance
   * @param F_in Transition matrix
   * @param H_in Measurement matrix
   * @param R_in Measurement covariance matrix
   * @param Q_in Process covariance matrix
   */
  void InitInit(VectorXd &x_in, MatrixXd &P_in, MatrixXd &F_in,
                        MatrixXd &H_in, MatrixXd &R_in, MatrixXd &Q_in) {
      x_ = x_in;
      P_ = P_in;
      F_ = F_in;
      H_ = H_in;
      R_ = R_in;
      Q_ = Q_in;
  }

  /**
   * Prediction Predicts the state and the state covariance
   * using the process model
   * @param delta_T Time between k and k+1 in s
   */
  void Predict() {
      /**
      TODO:
        * predict the state
      */
      x_ = F_ * x_ ;
      MatrixXd Ft = F_.transpose();
      P_ = F_ * P_ * Ft + Q_;
  }

  /**
   * Updates the state by using standard Kalman Filter equations
   * @param z The measurement at k+1
   */
  void Update(const VectorXd &z) {
      /**
      TODO:
        * update the state by using Kalman Filter equations
      */

      VectorXd z_pred = H_ * x_;

      VectorXd y = z - z_pred;
      MatrixXd Ht = H_.transpose();
      MatrixXd PHt = P_ * Ht;
      MatrixXd S = H_ * PHt + R_;
      MatrixXd Si = S.inverse();
      MatrixXd K = PHt * Si;

      //new estimate

      x_ = x_ + (K * y);
      // MatrixXd add_Nsec = MatrixXd(4,4);
      // float Nsec = 2.0;
      // add_Nsec << 1,0,Nsec,0,
      //             0,1,0,Nsec,
      //             0,0,1,0,
      //             0,0,0,1;
      // x_ = add_Nsec * x_;

      long x_size = x_.size();
      MatrixXd I = MatrixXd::Identity(x_size, x_size);
      P_ = (I - K * H_) * P_;

  }

  /**
   * Updates the state by using Extended Kalman Filter equations
   * @param z The measurement at k+1
   */
  void UpdateEKF(const VectorXd &z) {
      /**
        * update the state by using Extended Kalman Filter equations
      */
      VectorXd z_pred = H_ * x_;
      VectorXd y = z - z_pred;

      // following is exact the same as in the function of KalmanFilter::Update()
      MatrixXd Ht = H_.transpose();
      MatrixXd PHt = P_ * Ht;
      MatrixXd S = H_ * PHt + R_;
      MatrixXd Si = S.inverse();
      MatrixXd K = PHt * Si;

      //new estimate
      x_ = x_ + (K * y);
      long x_size = x_.size();
      MatrixXd I = MatrixXd::Identity(x_size, x_size);
      P_ = (I - K * H_) * P_;
  }

  void check_status(){
    int count =0;
    deque<int> count_deque = fixed_queue.getData();
    int size = count_deque.size();
    int max_size =fixed_queue.getMaxSize(); 
    
    if(size <max_size -2) {
      std::cout<< " Checking..."<<std::endl;
      return;
    }

    for(auto e = count_deque.begin(); e != count_deque.end(); e++){
      count += *e;
    }

    if(count >= 2 ){
      is_dynamic = 1; 
      //0 : NONE
      //1 : dynamic
      //2 : static
    }else{
      is_dynamic = 2;
    }
    
  }

};

#endif /* KALMAN_FILTER_H_ */
