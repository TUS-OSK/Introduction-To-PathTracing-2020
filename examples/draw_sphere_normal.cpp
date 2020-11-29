#include "mogumogu/camera/film.hpp"
#include "mogumogu/camera/pinhole.hpp"
#include "mogumogu/core/constant.hpp"
#include "mogumogu/shape/sphere.hpp"

int main() {
  constexpr int width = 512;
  constexpr int height = 512;
  const auto film = std::make_shared<Film>(width, height);
  PinholeCamera camera(Vec3(0, 0, 3), Vec3(0, 0, -1), film, PI_DIV_2);
  Sphere sphere(Vec3(0, 0, 0), 1.0);

  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      const float u = (2.0f * i - width) / height;
      const float v = (2.0f * j - height) / height;
      const auto [ray, pdf] = camera.sampleRay(Vec2(u, v));

      const auto info = sphere.intersect(ray);
      if (info) {
        camera.setPixel(i, j, 0.5f * (info->hitNormal + 1.0f));
      } else {
        camera.setPixel(i, j, Vec3(0));
      }
    }
  }

  camera.writePPM("output.ppm");

  return 0;
}