#include "mogumogu/shape/sphere.hpp"

Sphere::Sphere(const Vec3& _center, float _radius) : center(_center), radius(_radius) {}

std::optional<IntersectInfo> Sphere::intersect(const Ray& ray) const {
  const float b = dot(ray.direction, ray.origin - center);
  const float c = length2(ray.origin - center) - radius * radius;
  const float D = b * b - c;
  if (D < 0) return std::nullopt;

  const float t0 = -b - std::sqrt(D);
  const float t1 = -b + std::sqrt(D);
  float t = t0;
  if (t < ray.tmin || t > ray.tmax) {
    t = t1;
    if (t < ray.tmin || t > ray.tmax) {
      return std::nullopt;
    }
  }

  IntersectInfo info;
  info.t = t;
  info.hitPos = ray(t);
  info.hitNormal = normalize(info.hitPos - center);
  return info;
}