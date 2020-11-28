#ifndef _SHAPE_H
#define _SHAPE_H
#include <optional>

#include "mogumogu/core/intersect-info.hpp"
#include "mogumogu/core/ray.hpp"

class Shape {
 public:
  virtual std::optional<IntersectInfo> intersect(const Ray& ray) const = 0;
};

#endif