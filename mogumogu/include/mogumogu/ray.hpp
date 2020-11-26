#ifndef _RAY_H
#define _RAY_H
#include <iostream>

#include "mogumogu/vec3.hpp"

class Ray {
 public:
  static constexpr float tmin = 1e-5f;
  static constexpr float tmax = 1e9f;
  const Vec3 origin;
  const Vec3 direction;

  constexpr Ray() : origin(Vec3(0, 0, 0)), direction(Vec3(0, 0, 0)) {}
  constexpr Ray(const Vec3& _origin, const Vec3& _direction)
      : origin(_origin), direction(_direction) {}

  constexpr Vec3 operator()(float t) const { return origin + t * direction; }
};

std::ostream& operator<<(std::ostream& stream, const Ray& ray) {
  stream << "origin: " << ray.origin << " direction: " << ray.direction;
  return stream;
}

#endif