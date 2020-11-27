#include "mogumogu/camera/camera.hpp"

Camera::Camera(const Vec3& _camPos, const Vec3& _camForward)
    : camPos(_camPos), camForward(normalize(_camForward)) {
  camRight = cross(camForward, Vec3(0, 1, 0));
  camUp = cross(camRight, camForward);
}