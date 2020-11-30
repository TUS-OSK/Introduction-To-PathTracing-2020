#include "mogumogu/core/primitive.hpp"

Primitive::Primitive(const std::shared_ptr<Shape>& _shape,
                     const std::shared_ptr<Material>& _material)
    : shape(_shape), material(_material) {}

std::optional<IntersectInfo> Primitive::intersect(const Ray& ray) const {
  auto info = shape->intersect(ray);

  // set intersect primitive
  if (info) {
    info->hitPrimitive = this;
  }

  return info;
}