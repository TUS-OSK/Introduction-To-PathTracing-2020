#include "mogumogu/camera/pinhole.hpp"

PinholeCamera::PinholeCamera(const Vec3& _camPos, const Vec3& _camForward)
    : Camera(_camPos, _camForward) {}

std::tuple<Ray, float> PinholeCamera::sampleRay(const Vec3& pFilm) const {
  const Vec3 pPinhole = camPos + pinholeDistance * camForward;
  return {Ray(pPinhole, normalize(pPinhole - camPos)), 1.0f};
}