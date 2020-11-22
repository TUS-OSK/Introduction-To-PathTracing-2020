#ifndef _FILM_H
#define _FILM_H
#include <vector>

#include "mogumogu/type.hpp"
#include "mogumogu/vec.hpp"

class Film {
 public:
  unsigned int width;
  unsigned int height;
  Real width_length;
  Real height_length;

  Real* pixels;

  Film(unsigned int _width, unsigned int _height, Real _width_length = 0.036,
       Real _height_length = 0.024);
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
  Real getR(unsigned int i, unsigned int j) const;
  Real getG(unsigned int i, unsigned int j) const;
  Real getB(unsigned int i, unsigned int j) const;

  void setR(unsigned int i, unsigned int j, Real value);
  void setG(unsigned int i, unsigned int j, Real value);
  void setB(unsigned int i, unsigned int j, Real value);

  unsigned int computeRIndex(unsigned int i, unsigned int j) const;
  unsigned int computeGIndex(unsigned int i, unsigned int j) const;
  unsigned int computeBIndex(unsigned int i, unsigned int j) const;
};

#endif