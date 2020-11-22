#ifndef _SHAPE_H
#define _SHAPE_H

#include "mogumogu/intersect-info.hpp"
#include "mogumogu/ray.hpp"

class Shape {
 public:
  virtual bool intersect(const Ray& ray, IntersectInfo& info) const = 0;
};

#endif