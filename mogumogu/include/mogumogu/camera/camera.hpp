#ifndef _CAMERA_H
#define _CAMERA_H
#include <memory>
#include <string>
#include <tuple>

#include "mogumogu/camera/film.hpp"
#include "mogumogu/core/ray.hpp"
#include "mogumogu/core/vec2.hpp"
#include "mogumogu/core/vec3.hpp"

class Camera {
 protected:
  const Vec3 camPos;
  const Vec3 camForward;
  const Vec3 camRight;
  const Vec3 camUp;
  const std::shared_ptr<Film> film;

 public:
  Camera(const Vec3& camPos, const Vec3& camForward, const std::shared_ptr<Film>& film);

  Vec3 computePositionOnFilm(const Vec2& uv) const noexcept;

  Vec3 getPixel(unsigned int i, unsigned int j) const;
  void setPixel(unsigned int i, unsigned int j, const Vec3& RGB);

  void writePPM(const std::string& filename) const;

  virtual std::tuple<Ray, float> sampleRay(const Vec2& uv) const = 0;
};

#endif