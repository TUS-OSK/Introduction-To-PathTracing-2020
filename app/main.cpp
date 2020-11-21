#include <iostream>
#include <array>
#include "vec.hpp"

int main() {
  std::array<float, 3> arr{1.0f};
  std::cout << arr[0] << std::endl;
  Vec3 v(0);
  return 0;
}