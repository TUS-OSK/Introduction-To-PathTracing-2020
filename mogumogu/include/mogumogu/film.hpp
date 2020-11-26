#ifndef _FILM_H
#define _FILM_H
#include <vector>

#include "mogumogu/core/vec3.hpp"

class Film {
 public:
  Film(unsigned int _width, unsigned int _height, float _width_length = 0.036f,
       float _height_length = 0.024f);

  Vec3 getPixel(unsigned int i, unsigned int j) const;
  void setPixel(unsigned int i, unsigned int j, const Vec3& rgb);

 private:
  unsigned int width;
  unsigned int height;
  float width_length;
  float height_length;

  std::vector<float> pixels;
};

#endif