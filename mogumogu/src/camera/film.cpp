#include "mogumogu/camera/film.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>

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

Vec3 Film::computePosition(const Vec2& uv) const {
  return Vec3(0.5f * width_length * uv.x(), 0.5f * width_length * uv.y(), 0);
}

void Film::writePPM(const std::string& filename) const {
  std::ofstream file(filename);
  if (!file) {
    std::cerr << "failed to open " << filename << std::endl;
    std::exit(EXIT_FAILURE);
  }

  file << "P3" << std::endl;
  file << width << " " << height << std::endl;
  file << "255" << std::endl;
  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      const Vec3 color = getPixel(i, j);
      const unsigned int R = std::clamp(static_cast<unsigned int>(255 * color.x()), 0u, 255u);
      const unsigned int G = std::clamp(static_cast<unsigned int>(255 * color.y()), 0u, 255u);
      const unsigned int B = std::clamp(static_cast<unsigned int>(255 * color.z()), 0u, 255u);
      file << R << " " << G << " " << B << std::endl;
    }
  }

  file.close();
}