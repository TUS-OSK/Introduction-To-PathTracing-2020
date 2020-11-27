#ifndef _CAMERA_H
#define _CAMERA_H
#include <memory>
#include <tuple>

#include "mogumogu/core/ray.hpp"
#include "mogumogu/core/vec2.hpp"
#include "mogumogu/core/vec3.hpp"

class Camera {
 protected:
  Vec3 camPos;
  Vec3 camForward;
  Vec3 camRight;
  Vec3 camUp;

 public:
  Camera(const Vec3& _camPos, const Vec3& _camForward)
      : camPos(_camPos), camForward(normalize(_camForward)) {
    camRight = cross(camForward, Vec3(0, 1, 0));
    camUp = cross(camRight, camForward);
  }

  virtual std::tuple<Ray, float> sampleRay(const Vec3& pFilm) const = 0;
};

#endif