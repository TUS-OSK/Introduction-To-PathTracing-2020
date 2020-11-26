#ifndef _PINHOLE_H
#define _PINHOLE_H
#include "mogumogu/camera/camera.hpp"

class PinholeCamera : public Camera {
 public:
  PinholeCamera(const Vec3& _camPos, const Vec3& _camForward, const Film* _film)
      : Camera(_camPos, _camForward, _film) {}

  bool sampleRay(Ray& ray, float& pdf) const { return false; }

 private:
  static constexpr float pinhole_distance = 1;
};
#endif