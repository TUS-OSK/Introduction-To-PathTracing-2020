#ifndef _RAY_H
#define _RAY_H
#include <iostream>

#include "mogumogu/vec.hpp"

class Ray {
 public:
  static constexpr Real tmin = static_cast<Real>(1e-5);
  static constexpr Real tmax = static_cast<Real>(1e9);
  Vec3 origin;
  Vec3 direction;

  Ray() : origin(Vec3(0, 0, 0)), direction(Vec3(0, 0, 0)) {}
  Ray(const Vec3& _origin, const Vec3& _direction) : origin(_origin), direction(_direction) {}

  Vec3 operator()(Real t) const {
    return origin + t * direction;
  }
};

std::ostream& operator<<(std::ostream& stream, const Ray& ray) {
  stream << "origin: " << ray.origin << " direction: " << ray.direction;
  return stream;
}

#endif