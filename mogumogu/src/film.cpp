#include "mogumogu/film.hpp"

Film::Film(unsigned int _width, unsigned int _height, float _width_length, float _height_length)
    : width(_width), height(_height), width_length(_width_length), height_length(_height_length) {
  pixels = new float[3 * width * height];
}

Film::~Film() { delete[] pixels; }

Film::Film(Film&& film) {
  pixels = film.pixels;
  film.pixels = nullptr;
}

Film& Film::operator=(Film&& film) {
  delete[] film.pixels;
  pixels = film.pixels;
  film.pixels = nullptr;
  return *this;
}

Vec3 Film::getPixel(unsigned int i, unsigned int j) const {
  return Vec3(getR(i, j), getG(i, j), getB(i, j));
}

void Film::setPixel(unsigned int i, unsigned int j, const Vec3& rgb) {
  setR(i, j, rgb.x());
  setG(i, j, rgb.y());
  setB(i, j, rgb.z());
}

float Film::getR(unsigned int i, unsigned int j) const { return pixels[computeRIndex(i, j)]; }
float Film::getG(unsigned int i, unsigned int j) const { return pixels[computeGIndex(i, j)]; }
float Film::getB(unsigned int i, unsigned int j) const { return pixels[computeBIndex(i, j)]; }

void Film::setR(unsigned int i, unsigned int j, float value) {
  pixels[computeRIndex(i, j)] = value;
}
void Film::setG(unsigned int i, unsigned int j, float value) {
  pixels[computeGIndex(i, j)] = value;
}
void Film::setB(unsigned int i, unsigned int j, float value) {
  pixels[computeBIndex(i, j)] = value;
}

unsigned int Film::computeRIndex(unsigned int i, unsigned int j) const {
  return 3 * i + 3 * width * j;
}
unsigned int Film::computeGIndex(unsigned int i, unsigned int j) const {
  return 3 * i + 3 * width * j + 1;
}
unsigned int Film::computeBIndex(unsigned int i, unsigned int j) const {
  return 3 * i + 3 * width * j + 2;
}