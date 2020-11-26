#include "mogumogu/camera/film.hpp"

Film::Film(unsigned int _width, unsigned int _height, float _width_length, float _height_length)
    : width(_width), height(_height), width_length(_width_length), height_length(_height_length) {
  pixels.resize(3 * width * height);
}

Vec3 Film::getPixel(unsigned int i, unsigned int j) const {
  const float R = pixels[3 * i + 3 * width * j];
  const float G = pixels[3 * i + 3 * width * j + 1];
  const float B = pixels[3 * i + 3 * width * j + 2];
  return Vec3(R, G, B);
}

void Film::setPixel(unsigned int i, unsigned int j, const Vec3& rgb) {
  pixels[3 * i + 3 * width * j] = rgb.x();
  pixels[3 * i + 3 * width * j] = rgb.y();
  pixels[3 * i + 3 * width * j] = rgb.z();
}