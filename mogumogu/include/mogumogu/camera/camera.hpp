#ifndef _CAMERA_H
#define _CAMERA_H

#include "mogumogu/ray.hpp"
#include "mogumogu/vec3.hpp"

class Camera {
 private:
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

  virtual bool sampleRay(Ray& ray, float& pdf) const = 0;
};

#endif