#ifndef _PLANE_H
#define _PLANE_H

#include "mogumogu/shape/shape.hpp"

class Plane : public Shape {
 private:
  const Vec3 leftCornerPoint;
  const Vec3 right;
  const Vec3 up;
  const Vec3 normal;
  const Vec3 center;
  const Vec3 rightDir;
  const float rightLength;
  const Vec3 upDir;
  const float upLength;

 public:
  Plane(const Vec3& leftCornerPoint, const Vec3& right, const Vec3& up);

  std::optional<IntersectInfo> intersect(const Ray& ray) const override;
};

#endif