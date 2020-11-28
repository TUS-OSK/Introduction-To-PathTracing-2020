#include "mogumogu/camera/pinhole.hpp"

PinholeCamera::PinholeCamera(const Vec3& _camPos, const Vec3& _camForward,
                             const std::shared_ptr<Film>& _film, float FOV)
    : Camera(_camPos, _camForward, _film) {
  pinholeDistance = 0.5f * film->diagonalLength / std::tan(0.5 * FOV);
}

std::tuple<Ray, float> PinholeCamera::sampleRay(const Vec2& uv) const {
  const Vec3 pFilm = film->computePosition(uv) + camPos;
  const Vec3 pPinhole = camPos + pinholeDistance * camForward;
  return {Ray(pPinhole, normalize(pPinhole - pFilm)), 1.0f};
}