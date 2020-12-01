#ifndef _PRIMITIVE_H
#define _PRIMITIVE_H
#include <memory>
#include <optional>

#include "mogumogu/core/intersect-info.hpp"
#include "mogumogu/material/material.hpp"
#include "mogumogu/shape/shape.hpp"

class Primitive {
 private:
  const std::shared_ptr<Shape> shape;
  const std::shared_ptr<Material> material;

 public:
  Primitive(const std::shared_ptr<Shape>& shape, const std::shared_ptr<Material>& material);

  std::optional<IntersectInfo> intersect(const Ray& ray) const;

  Vec3 BRDF(const Vec3& wo, const Vec3& wi, const IntersectInfo& info) const;
  std::optional<std::tuple<Vec3, float>> sampleBRDF(const Vec3& wo,
                                                    const IntersectInfo& info) const;
};

#endif