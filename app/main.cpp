#include <iostream>

#include "mogumogu/vec.hpp"

int main() {
  Vec3 v3 = Vec3(0.0f, 1.0f, 2.0f) * Vec3(0.0f, 1.0f, 2.0f);
  std::cout << v3 << std::endl;
  return 0;
}