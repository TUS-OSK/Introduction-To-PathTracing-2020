#ifndef _PINHOLE_H
#define _PINHOLE_H

#include "mogumogu/camera/camera.hpp"

class PinholeCamera final : public Camera {
 public:
  PinholeCamera(const Vec3& camPos, const Vec3& camForward, const std::shared_ptr<Film>& film,
                float FOV);

  std::tuple<Ray, float> sampleRay(const Vec3& pFilm) const override;

 private:
  float pinholeDistance;
};
#endif