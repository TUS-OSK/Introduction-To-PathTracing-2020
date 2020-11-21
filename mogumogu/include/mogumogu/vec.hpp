#ifndef _VEC3_H
#define _VEC3_H
#include <array>
#include <cmath>
#include <iostream>

#include "mogumogu/type.hpp"

template <unsigned int N>
class Vec {
 public:
  std::array<Real, N> v;

  template <typename... Real>
  constexpr Vec(Real... args) : v({args...}) {}
  constexpr Vec(const std::array<Real, N>&& _v) : v(_v) {}

  constexpr Real x() const {
    return v[0];
  }
  constexpr Real y() const {
    return v[1];
  }
  constexpr Real z() const {
    return v[2];
  }
  constexpr Real w() const {
    return v[3];
  }
};

// binary operators
template <unsigned int N>
inline Vec<N> operator+(const Vec<N>& v1, const Vec<N>& v2) {
  std::array<Real, N> v;
  for (unsigned int i = 0; i < N; ++i) {
    v[i] = v1.v[i] + v2.v[i];
  }
  return Vec<N>(v);
}
template <unsigned int N>
inline Vec<N> operator+(const Vec<N>& v1, Real k) {
  std::array<Real, N> v;
  for (unsigned int i = 0; i < N; ++i) {
    v[i] = v1.v[i] + k;
  }
  return Vec<N>(v);
}
template <unsigned int N>
inline Vec<N> operator+(Real k, const Vec<N>& v2) {
  return v2 + k;
}

// print
template <unsigned int N>
inline std::ostream& operator<<(std::ostream& stream, const Vec<N>& v) {
  stream << "(";
  for (unsigned int i = 0; i < N; ++i) {
    stream << v.v[i];
    if (i != N - 1) {
      stream << ", ";
    }
  }
  stream << ")";
  return stream;
}

// alias
using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;

#endif