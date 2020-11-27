#ifndef _SPHERE_H
#define _SPHERE_H

#include "mogumogu/core/vec3.hpp"
#include "mogumogu/shape/shape.hpp"

class Sphere : public Shape {
 private:
  const Vec3 center;
  const float radius;

 public:
  Sphere(const Vec3& center, float radius);

  bool intersect(const Ray& ray, IntersectInfo& info) const override;
};

#endif