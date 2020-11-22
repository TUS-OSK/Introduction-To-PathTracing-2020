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

  template <typename... T>
  constexpr Vec(T... args) : v({static_cast<Real>(args)...}) {}

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

  bool operator==(const Vec<N>& rhs) const {
    bool ret = true;
    for (unsigned int i = 0; i < N; ++i) {
      if (v[i] != rhs.v[i]) {
        ret = false;
        break;
      }
    }
    return ret;
  }
};

// alias
using Vec2 = Vec<2>;
using Vec3 = Vec<3>;
using Vec4 = Vec<4>;

// binary operators
template <unsigned int N>
inline Vec<N> operator+(const Vec<N>& v1, const Vec<N>& v2) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] + v2.v[i];
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator+(const Vec<N>& v1, Real k) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] + k;
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator+(Real k, const Vec<N>& v2) {
  return v2 + k;
}

template <unsigned int N>
inline Vec<N> operator-(const Vec<N>& v1, const Vec<N>& v2) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] - v2.v[i];
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator-(const Vec<N>& v1, Real k) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] - k;
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator-(Real k, const Vec<N>& v2) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = k - v2.v[i];
  }
  return ret;
}

template <unsigned int N>
inline Vec<N> operator*(const Vec<N>& v1, const Vec<N>& v2) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] * v2.v[i];
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator*(const Vec<N>& v1, Real k) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] * k;
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator*(Real k, const Vec<N>& v2) {
  return v2 * k;
}

template <unsigned int N>
inline Vec<N> operator/(const Vec<N>& v1, const Vec<N>& v2) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] / v2.v[i];
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator/(const Vec<N>& v1, Real k) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = v1.v[i] / k;
  }
  return ret;
}
template <unsigned int N>
inline Vec<N> operator/(Real k, const Vec<N>& v2) {
  Vec<N> ret;
  for (unsigned int i = 0; i < N; ++i) {
    ret.v[i] = k / v2.v[i];
  }
  return ret;
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

// dot product
template <unsigned int N>
inline Real dot(const Vec<N>& v1, const Vec<N>& v2) {
  Real ret = 0;
  for (unsigned int i = 0; i < N; ++i) {
    ret += v1.v[i] * v2.v[i];
  }
  return ret;
}

// length
template <unsigned int N>
inline Real length2(const Vec<N>& v) {
  return dot(v, v);
}
template <unsigned int N>
inline Real length(const Vec<N>& v) {
  return std::sqrt(length2(v));
}

// cross product
inline Vec3 cross(const Vec3& v1, const Vec3& v2) {
  return Vec3(v1.y() * v2.z() - v1.z() * v2.y(), v1.z() * v2.x() - v1.x() * v2.z(), v1.x() * v2.y() - v2.x() * v1.y());
}

#endif