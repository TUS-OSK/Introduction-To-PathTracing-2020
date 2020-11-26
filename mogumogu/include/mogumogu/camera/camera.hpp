#ifndef _CAMERA_H
#define _CAMERA_H

#include "mogumogu/ray.hpp"

class Camera {
 public:
  virtual bool sampleRay(Ray& ray, float& pdf) const = 0;
};

#endif