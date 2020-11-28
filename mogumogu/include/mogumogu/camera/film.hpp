#ifndef _FILM_H
#define _FILM_H
#include <string>
#include <vector>

#include "mogumogu/core/vec2.hpp"
#include "mogumogu/core/vec3.hpp"

class Film {
 public:
  const unsigned int width;
  const unsigned int height;
  const float widthLength;
  const float heightLength;
  const float diagonalLength;

  std::vector<float> pixels;

  Film(unsigned int width, unsigned int height, float widthLength = 0.024f,
       float heightLength = 0.024f);

  Vec3 getPixel(unsigned int i, unsigned int j) const;
  void setPixel(unsigned int i, unsigned int j, const Vec3& rgb);

  void writePPM(const std::string& filename) const;
};

#endif