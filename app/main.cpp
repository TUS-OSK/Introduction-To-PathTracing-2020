#include <iostream>

#include "mogumogu/vec.hpp"

int main() {
  std::cout << cross(Vec3(1.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f)) << std::endl;
  return 0;
}