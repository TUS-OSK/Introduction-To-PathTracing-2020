#include "mogumogu/shape/plane.hpp"

Plane::Plane(const Vec3& _leftCornerPoint, const Vec3& _right, const Vec3& _up)
    : leftCornerPoint(_leftCornerPoint),
      right(_right),
      up(_up),
      normal(normalize(cross(right, up))),
      center(leftCornerPoint + 0.5 * right + 0.5 * up),
      rightDir(normalize(right)),
      rightLength(length(right)),
      upDir(normalize(up)),
      upLength(length(up)) {}

std::optional<IntersectInfo> Plane::intersect(const Ray& ray) const {
  const float t = -dot(ray.origin - center, normal) / dot(ray.direction, normal);
  if (t < ray.tmin || t > ray.tmax) return std::nullopt;

  const Vec3 hitPos = ray(t);
  const float dx = dot(hitPos - leftCornerPoint, rightDir);
  const float dy = dot(hitPos - leftCornerPoint, upDir);
  if (dx < 0 || dx > rightLength || dy < 0 || dy > upLength) return std::nullopt;

  IntersectInfo info;
  info.t = t;
  info.hitPos = hitPos;
  info.hitNormal = dot(-ray.direction, normal) > 0 ? normal : -normal;
  return info;
}