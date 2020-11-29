#ifndef _MATERIAL_H
#define _MATERIAL_H
#include <optional>

#include "mogumogu/core/vec3.hpp"

class Material {
  virtual Vec3 BRDF(const Vec3& wo, const Vec3& wi) const = 0;
  virtual std::optional<std::tuple<Vec3, float>> sampleBRDF(const Vec3& wo) const = 0;
};

#endif