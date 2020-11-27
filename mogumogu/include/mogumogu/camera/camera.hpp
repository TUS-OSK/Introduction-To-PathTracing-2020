#ifndef _CAMERA_H
#define _CAMERA_H
#include <memory>
#include <tuple>

#include "mogumogu/camera/film.hpp"
#include "mogumogu/core/ray.hpp"
#include "mogumogu/core/vec2.hpp"
#include "mogumogu/core/vec3.hpp"

class Camera {
 public:
  const Vec3 camPos;
  const Vec3 camForward;
  const Vec3 camRight;
  const Vec3 camUp;
  const std::shared_ptr<Film> film;

  Camera(const Vec3& camPos, const Vec3& camForward, const std::shared_ptr<Film>& film);

  virtual std::tuple<Ray, float> sampleRay(const Vec2& uv) const = 0;
};

#endif