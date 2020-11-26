#ifndef _CAMERA_H
#define _CAMERA_H
#include <memory>

#include "mogumogu/camera/film.hpp"
#include "mogumogu/core/ray.hpp"
#include "mogumogu/core/vec2.hpp"
#include "mogumogu/core/vec3.hpp"

class Camera {
 private:
  Vec3 camPos;
  Vec3 camForward;
  Vec3 camRight;
  Vec3 camUp;

  const Film* film;

 public:
  Camera(const Vec3& _camPos, const Vec3& _camForward, const Film* _film)
      : camPos(_camPos), camForward(normalize(_camForward)), film(_film) {
    camRight = cross(camForward, Vec3(0, 1, 0));
    camUp = cross(camRight, camForward);
  }

  virtual bool sampleRay(const Vec2& uv, Ray& ray, float& pdf) const = 0;
};

#endif