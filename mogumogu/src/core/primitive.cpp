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

Vec3 Primitive::BRDF(const Vec3& wo, const Vec3& wi, const IntersectInfo& info) const {
  const Vec3 wo_local = worldToLocal(wo, info.dpdu, info.hitNormal, info.dpdv);
  const Vec3 wi_local = worldToLocal(wi, info.dpdu, info.hitNormal, info.dpdv);
  return material->BRDF(wo_local, wi_local);
}

std::optional<std::tuple<Vec3, float>> Primitive::sampleBRDF(const Vec3& wo,
                                                             const IntersectInfo& info) const {
  const Vec3 wo_local = worldToLocal(wo, info.dpdu, info.hitNormal, info.dpdv);
  return material->sampleBRDF(wo_local);
}