#include <algorithm>

#include "mogumogu/camera/film.hpp"
#include "mogumogu/camera/pinhole.hpp"
#include "mogumogu/core/constant.hpp"
#include "mogumogu/material/lambert.hpp"
#include "mogumogu/shape/sphere.hpp"

int main() {
  constexpr int width = 512;
  constexpr int height = 512;
  const Vec3 lightDir = normalize(Vec3(1, 1, 1));

  const auto film = std::make_shared<Film>(width, height);
  PinholeCamera camera(Vec3(0, 0, 3), Vec3(0, 0, -1), film, PI_DIV_2);
  Sphere sphere(Vec3(0, 0, 0), 1.0);
  Lambert lambert(Vec3(0.2, 0.8, 0.2));

  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      const float u = (2.0f * i - width) / height;
      const float v = (2.0f * j - height) / height;
      const auto [ray, pdf] = camera.sampleRay(Vec2(u, v));

      const auto info = sphere.intersect(ray);
      if (info) {
        const Vec3 color = PI * lambert.BRDF(-ray.direction, lightDir) *
                           std::max(dot(lightDir, info->hitNormal), 0.0f);
        camera.setPixel(i, j, color);
      } else {
        camera.setPixel(i, j, Vec3(0));
      }
    }
  }

  camera.writePPM("output.ppm");

  return 0;
}