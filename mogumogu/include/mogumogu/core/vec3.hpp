#ifndef _VEC3_H
#define _VEC3_H
#include <cmath>
#include <iostream>

struct Vec3 {
  float elements[3];

  constexpr Vec3() noexcept : elements{0, 0, 0} {}
  constexpr explicit Vec3(float _x) noexcept : elements{_x, _x, _x} {}
  constexpr Vec3(float _x, float _y, float _z) noexcept : elements{_x, _y, _z} {}

  constexpr float x() const { return elements[0]; }
  constexpr float y() const { return elements[1]; }
  constexpr float z() const { return elements[2]; }

  Vec3 operator-() const noexcept { return Vec3(-x(), -y(), -z()); }

  constexpr bool operator==(const Vec3& v) const noexcept {
    return x() == v.x() && y() == v.y() && z() == v.z();
  }
};

// binary operators
inline constexpr Vec3 operator+(const Vec3& lhs, const Vec3& rhs) noexcept {
  return Vec3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}
inline constexpr Vec3 operator+(const Vec3& lhs, float rhs) noexcept {
  return Vec3(lhs.x() + rhs, lhs.y() + rhs, lhs.z() + rhs);
}
inline constexpr Vec3 operator+(float lhs, const Vec3& rhs) noexcept { return rhs + lhs; }

inline constexpr Vec3 operator-(const Vec3& lhs, const Vec3& rhs) noexcept {
  return Vec3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}
inline constexpr Vec3 operator-(const Vec3& lhs, float rhs) noexcept {
  return Vec3(lhs.x() - rhs, lhs.y() - rhs, lhs.z() - rhs);
}
inline constexpr Vec3 operator-(float lhs, const Vec3& rhs) noexcept {
  return Vec3(lhs - rhs.x(), lhs - rhs.y(), lhs - rhs.z());
}

inline constexpr Vec3 operator*(const Vec3& lhs, const Vec3& rhs) noexcept {
  return Vec3(lhs.x() * rhs.x(), lhs.y() * rhs.y(), lhs.z() * rhs.z());
}
inline constexpr Vec3 operator*(const Vec3& lhs, float rhs) noexcept {
  return Vec3(lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs);
}
inline constexpr Vec3 operator*(float lhs, const Vec3& rhs) noexcept { return rhs * lhs; }

inline constexpr Vec3 operator/(const Vec3& lhs, const Vec3& rhs) noexcept {
  return Vec3(lhs.x() / rhs.x(), lhs.y() / rhs.y(), lhs.z() / rhs.z());
}
inline constexpr Vec3 operator/(const Vec3& lhs, float rhs) noexcept {
  return Vec3(lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs);
}
inline constexpr Vec3 operator/(float lhs, const Vec3& rhs) noexcept {
  return Vec3(lhs / rhs.x(), lhs / rhs.y(), lhs / rhs.z());
}

// print
inline std::ostream& operator<<(std::ostream& stream, const Vec3& v) noexcept {
  stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
  return stream;
}

// dot product
inline constexpr float dot(const Vec3& lhs, const Vec3& rhs) noexcept {
  return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}

// length
inline constexpr float length2(const Vec3& v) noexcept { return dot(v, v); }
inline constexpr float length(const Vec3& v) { return std::sqrt(length2(v)); }

// cross product
inline constexpr Vec3 cross(const Vec3& v1, const Vec3& v2) noexcept {
  return Vec3(v1.y() * v2.z() - v1.z() * v2.y(), v1.z() * v2.x() - v1.x() * v2.z(),
              v1.x() * v2.y() - v2.x() * v1.y());
}

// normalize
inline constexpr Vec3 normalize(const Vec3& v) noexcept { return v / length(v); }

#endif