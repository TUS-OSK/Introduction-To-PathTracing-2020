#include "mogumogu/material/lambert.hpp"

#include "mogumogu/core/constant.hpp"

Lambert::Lambert(const Vec3& _kd) : kd(_kd) {}

Vec3 Lambert::BRDF(const Vec3& wo, const Vec3& wi) const { return kd * INV_PI; }

std::optional<std::tuple<Vec3, float>> Lambert::sampleBRDF(const Vec3& wo) const {
  return std::nullopt;
}