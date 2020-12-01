#include <algorithm>

#include "mogumogu/accel/linear.hpp"
#include "mogumogu/camera/film.hpp"
#include "mogumogu/camera/pinhole.hpp"
#include "mogumogu/core/constant.hpp"
#include "mogumogu/material/lambert.hpp"
#include "mogumogu/shape/sphere.hpp"

int main() {
  const int width = 512;
  const int height = 512;
  const Vec3 lightDir = normalize(Vec3(1, 1, 1));

  const auto film = std::make_shared<Film>(width, height);
  PinholeCamera camera(Vec3(0, 0, 5), Vec3(0, 0, -1), film, PI_DIV_2);

  const auto sphere1 = std::make_shared<Sphere>(Vec3(0, 0, 0), 1.0);
  const auto sphere2 = std::make_shared<Sphere>(Vec3(1, 0, 1), 1.0);
  const auto sphere3 = std::make_shared<Sphere>(Vec3(0, -10001, 0), 10000.0);

  const auto lambert = std::make_shared<Lambert>(Vec3(0.9));

  LinearAccel accel;
  accel.addPrimitive(Primitive(sphere1, lambert));
  accel.addPrimitive(Primitive(sphere2, lambert));
  accel.addPrimitive(Primitive(sphere3, lambert));

  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      const float u = (2.0f * i - width) / height;
      const float v = (2.0f * j - height) / height;
      const auto [ray, pdf] = camera.sampleRay(Vec2(u, v));

      const auto info = accel.intersect(ray);
      if (info) {
        Vec3 color;

        // shadow test
        const Ray shadowRay(info->hitPos, lightDir);
        const auto shadowInfo = accel.intersect(shadowRay);
        if (!shadowInfo) {
          color = PI * lambert->BRDF(-ray.direction, lightDir) *
                  std::max(dot(lightDir, info->hitNormal), 0.0f);
        }

        camera.setPixel(i, j, color);
      } else {
        camera.setPixel(i, j, Vec3(0));
      }
    }
  }

  camera.writePPM("output.ppm");

  return 0;
}