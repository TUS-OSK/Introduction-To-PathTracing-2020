#ifndef _FILM_H
#define _FILM_H
#include <vector>

#include "mogumogu/core/vec3.hpp"

class Film {
 public:
  unsigned int width;
  unsigned int height;
  float width_length;
  float height_length;

  float* pixels;

  Film(unsigned int _width, unsigned int _height, float _width_length = 0.036,
       float _height_length = 0.024);
  ~Film();

  // delete copy constructor
  Film(const Film& film) = delete;

  // move constructor
  Film(Film&& film);

  // move = operator
  Film& operator=(Film&& film);

  Vec3 getPixel(unsigned int i, unsigned int j) const;
  void setPixel(unsigned int i, unsigned int j, const Vec3& rgb);

 private:
  float getR(unsigned int i, unsigned int j) const;
  float getG(unsigned int i, unsigned int j) const;
  float getB(unsigned int i, unsigned int j) const;

  void setR(unsigned int i, unsigned int j, float value);
  void setG(unsigned int i, unsigned int j, float value);
  void setB(unsigned int i, unsigned int j, float value);

  unsigned int computeRIndex(unsigned int i, unsigned int j) const;
  unsigned int computeGIndex(unsigned int i, unsigned int j) const;
  unsigned int computeBIndex(unsigned int i, unsigned int j) const;
};

#endif