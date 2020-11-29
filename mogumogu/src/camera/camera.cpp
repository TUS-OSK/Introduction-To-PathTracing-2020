#include "mogumogu/camera/camera.hpp"

Camera::Camera(const Vec3& _camPos, const Vec3& _camForward, const std::shared_ptr<Film>& _film)
    : camPos(_camPos),
      camForward(normalize(_camForward)),
      camRight(cross(camForward, Vec3(0, 1, 0))),
      camUp(cross(camRight, camForward)),
      film(_film) {}

Vec3 Camera::computePositionOnFilm(const Vec2& uv) const noexcept {
  return Vec3(0.5f * film->getWidthLength() * uv.x(), 0.5f * film->getHeightLength() * uv.y(), 0) +
         camPos;
}

Vec3 Camera::getPixel(unsigned int i, unsigned int j) const { return film->getPixel(i, j); }
void Camera::setPixel(unsigned int i, unsigned int j, const Vec3& RGB) {
  film->setPixel(i, j, RGB);
}

void Camera::writePPM(const std::string& filename) const { film->writePPM(filename); }