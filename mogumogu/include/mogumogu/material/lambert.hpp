#ifndef _LAMBERT_H
#define _LAMBERT_H

#include "mogumogu/material/material.hpp"

class Lambert : public Material {
 private:
  const Vec3 kd;

 public:
  Lambert(const Vec3& kd);

  Vec3 BRDF(const Vec3& wo, const Vec3& wi) const override;
  std::optional<std::tuple<Vec3, float>> sampleBRDF(const Vec3& wo) const override;
};

#endif