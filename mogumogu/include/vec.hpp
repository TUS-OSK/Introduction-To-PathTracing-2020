#ifndef _VEC3_H
#define _VEC3_H
#include <array>

#include "type.hpp"

template <unsigned int N>
class Vec {
  public:
   std::array<Real, N> v;

   template <typename... Args>
   constexpr Vec(Args... args) : v({args...}) {}
};

using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;

#endif