#include "mogumogu/camera/film.hpp"
#include "mogumogu/camera/pinhole.hpp"

int main() {
  constexpr int width = 512;
  constexpr int height = 512;
  Film film(512, 512);
  PinholeCamera camera(Vec3(0, 0, 0), Vec3(0, 0, 1));

  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      const float u = (2.0f * i - width) / height;
      const float v = (2.0f * j - height) / height;
      const Vec3 pFilm = film.computePosition(Vec2(u, v));
      const auto [ray, pdf] = camera.sampleRay(Vec3(pFilm.x(), pFilm.y(), 0));
      film.setPixel(i, j, 0.5f * (ray.direction + 1.0f));
    }
  }

  film.writePPM("output.ppm");

  return 0;
}