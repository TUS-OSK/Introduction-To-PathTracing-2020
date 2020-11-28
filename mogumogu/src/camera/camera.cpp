#include "mogumogu/camera/camera.hpp"

Camera::Camera(const Vec3& _camPos, const Vec3& _camForward, const std::shared_ptr<Film>& _film)
    : camPos(_camPos),
      camForward(normalize(_camForward)),
      film(_film),
      camRight(cross(camForward, Vec3(0, 1, 0))),
      camUp(cross(camRight, camForward)) {}

Vec3 Camera::computePositionOnFilm(const Vec2& uv) const noexcept {
  return Vec3(0.5f * film->widthLength * uv.x(), 0.5f * film->heightLength * uv.y(), 0) + camPos;
}