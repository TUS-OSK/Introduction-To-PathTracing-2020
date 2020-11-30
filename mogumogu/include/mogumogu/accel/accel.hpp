#ifndef _ACCEL_H
#define _ACCEL_H
#include <optional>
#include <vector>

#include "mogumogu/core/primitive.hpp"

class Accel {
 protected:
  std::vector<Primitive> primitives;

 public:
  Accel();

  void addPrimitive(const Primitive& primitive);

  virtual std::optional<IntersectInfo> intersect(const Ray& ray) const = 0;
};

#endif