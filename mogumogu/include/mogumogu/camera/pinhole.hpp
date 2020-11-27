#ifndef _PINHOLE_H
#define _PINHOLE_H

#include "mogumogu/camera/camera.hpp"

class PinholeCamera final : public Camera {
 public:
  PinholeCamera(const Vec3& _camPos, const Vec3& _camForward) : Camera(_camPos, _camForward) {}

  std::tuple<Ray, float> sampleRay(const Vec3& pFilm) const override {
    const Vec3 pPinhole = camPos + pinholeDistance * camForward;
    return {Ray(pPinhole, normalize(pPinhole - camPos)), 1.0f};
  }

 private:
  static constexpr float pinholeDistance = 1.0f;
};
#endif