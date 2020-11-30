#include "mogumogu/accel/linear.hpp"

LinearAccel::LinearAccel() {}

std::optional<IntersectInfo> LinearAccel::intersect(const Ray& ray) const {
  std::optional<IntersectInfo> ret = std::nullopt;

  // return closest hit
  float t = ray.tmax;
  for (const auto& primitive : primitives) {
    const auto info = primitive.intersect(ray);
    if (info) {
      if (info->t < t) {
        t = info->t;
        ret = info;
      }
    }
  }

  return ret;
}