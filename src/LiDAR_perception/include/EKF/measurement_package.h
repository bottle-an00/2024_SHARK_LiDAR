#ifndef MEASUREMENT_PACKAGE_H_
#define MEASUREMENT_PACKAGE_H_

#include "Eigen/Dense"

class MeasurementPackage {
public:
  long long timestamp_;
  int id;
  Eigen::VectorXd raw_measurements_;
  int count = 0;
  bool is_dynamic = false;
};

#endif /* MEASUREMENT_PACKAGE_H_ */
