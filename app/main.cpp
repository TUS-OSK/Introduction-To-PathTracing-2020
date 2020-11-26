#include <iostream>

#include "mogumogu/camera/pinhole.hpp"
#include "mogumogu/core/ray.hpp"
#include "mogumogu/core/vec3.hpp"

int main() {
  std::cout << cross(Vec3(1, 0, 0), Vec3(0, 1, 0)) << std::endl;
  Ray ray;
  std::cout << ray << std::endl;
  return 0;
}