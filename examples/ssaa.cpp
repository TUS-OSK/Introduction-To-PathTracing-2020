#include <algorithm>

#include "mogumogu/accel/linear.hpp"
#include "mogumogu/camera/film.hpp"
#include "mogumogu/camera/pinhole.hpp"
#include "mogumogu/core/constant.hpp"
#include "mogumogu/material/lambert.hpp"
#include "mogumogu/sampler/uniform.hpp"
#include "mogumogu/shape/plane.hpp"
#include "mogumogu/shape/sphere.hpp"

int main() {
  const int width = 512;
  const int height = 512;
  const int samples = 16;
  const Vec3 lightDir = normalize(Vec3(1, 1, 1));

  const auto film = std::make_shared<Film>(width, height);
  PinholeCamera camera(Vec3(0, 1, 5), Vec3(0, 0, -1), film, PI_DIV_2);

  const auto sphere1 = std::make_shared<Sphere>(Vec3(0, 1, 0), 1.0);
  const auto sphere2 = std::make_shared<Sphere>(Vec3(1, 1, 1), 1.0);
  const auto plane = std::make_shared<Plane>(Vec3(-3, 0, -3), Vec3(6, 0, 0), Vec3(0, 0, 6));

  const auto lambert = std::make_shared<Lambert>(Vec3(0.9));

  LinearAccel accel;
  accel.addPrimitive(Primitive(sphere1, lambert));
  accel.addPrimitive(Primitive(sphere2, lambert));
  accel.addPrimitive(Primitive(plane, lambert));

  UniformSampler sampler;
  sampler.setSeed(1);

  for (int j = 0; j < height; ++j) {
    for (int i = 0; i < width; ++i) {
      Vec3 color;
      for (int k = 0; k < samples; ++k) {
        const float u = (2.0f * (i + sampler.getNext()) - width) / height;
        const float v = (2.0f * (j + sampler.getNext()) - height) / height;
        const auto [ray, pdf] = camera.sampleRay(Vec2(u, v));

        const auto info = accel.intersect(ray);
        if (info) {
          // shadow test
          const Ray shadowRay(info->hitPos, lightDir);
          const auto shadowInfo = accel.intersect(shadowRay);
          if (!shadowInfo) {
            const auto hitPrimitive = info->hitPrimitive;
            color += PI * hitPrimitive->BRDF(-ray.direction, lightDir, info.value()) *
                     std::max(dot(lightDir, info->hitNormal), 0.0f);
          }
        }
      }
      camera.setPixel(i, j, color / samples);
    }
  }

  camera.writePPM("output.ppm");

  return 0;
}