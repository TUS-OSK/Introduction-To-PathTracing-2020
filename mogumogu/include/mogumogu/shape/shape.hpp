#ifndef _SHAPE_H
#define _SHAPE_H

#include "mogumogu/core/intersect-info.hpp"
#include "mogumogu/core/ray.hpp"

class Shape {
 public:
  virtual bool intersect(const Ray& ray, IntersectInfo& info) const = 0;
};

#endif