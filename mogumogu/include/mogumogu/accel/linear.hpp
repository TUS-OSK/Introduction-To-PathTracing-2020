#ifndef _LINEAR_H
#define _LINEAR_H
#include "mogumogu/accel/accel.hpp"

class LinearAccel : public Accel {
 public:
  LinearAccel();

  std::optional<IntersectInfo> intersect(const Ray& ray) const override;
};

#endif