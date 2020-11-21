#include <iostream>

#include "vec.hpp"

int main() {
  Vec3 v1(0.0f, 1.0f, 2.0f);
  Vec3 v2(0.0f, 1.0f, 2.0f);
  Vec3 v3 = v1 + v2;
  std::cout << v3 << std::endl;
  return 0;
}