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
       Real _height_length = 0.024)
      : width(_width), height(_height) _width_length(_width_length), height_length(_height_length) {
    pixels = new Real[3 * width * height];
  }
  ~Film() { delete[] pixels; }

  // delete copy constructor
  Film(const Film& film) = delete;

  // move constructor
  Film(const Film&& film) {
    pixels = film.pixels;
    film.pixels = nullptr;
  }

  // move = operator
  Film& operator=(Film&& film) {
    delete[] film.pixels;
    pixels = film.pixels;
    film.pixels = nullptr;
    return *this;
  }

  Vec3 getPixel(unsigned int i, unsigned int j) const {
    return Vec3(getR(i, j), getG(i, j), getB(i, j));
  }
  Vec3 setPixel(unsigned int i, unsigned int j, const Vec3& rgb) {
    setR(i, j, rgb.x());
    setG(i, j, rgb.y());
    setB(i, j, rgb.z());
  }

 private:
  Real getR(unsigned int i, unsigned int j) { return pixels[computeRIndex(i, j)]; }
  Real getG(unsigned int i, unsigned int j) { return pixels[computeGIndex(i, j)]; }
  Real getB(unsigned int i, unsigned int j) { return pixels[computeBIndex(i, j)]; }

  void setR(unsigned int i, unsigned int j, Real value) { pixels[computeRIndex(i, j)] = value; }
  void setG(unsigned int i, unsigned int j, Real value) { pixels[computeGIndex(i, j)] = value; }
  void setB(unsigned int i, unsigned int j, Real value) { pixels[computeBIndex(i, j)] = value; }

  unsigned int computeRIndex(unsigned int i, unsigned int j) { return 3 * i + 3 * width * j; }
  unsigned int computeGIndex(unsigned int i, unsigned int j) { return 3 * i + 3 * width * j + 1; }
  unsigned int computeBIndex(unsigned int i, unsigned int j) { return 3 * i + 3 * width * j + 2; }
}

#endif