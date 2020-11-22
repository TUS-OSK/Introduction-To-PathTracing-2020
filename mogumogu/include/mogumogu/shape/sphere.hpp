#ifndef _SPHERE_H
#define _SPHERE_H

#include "mogumogu/shape/shape.hpp"

class Sphere : public Shape {
 public:
  Vec3 center;
  Real radius;

  Sphere(const Vec3& _center, Real _radius) : center(_center), radius(_radius) {}

  bool intersect(const Ray& ray, IntersectInfo& info) const { return false; }
};

#endif