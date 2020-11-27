#ifndef _VEC2_H
#define _VEC2_H
#include <cmath>
#include <iostream>

struct Vec2 {
  float elements[2];

  constexpr Vec2() noexcept : elements{0, 0} {}
  constexpr Vec2(float _x) noexcept : elements{_x, _x} {}
  constexpr Vec2(float _x, float _y) noexcept : elements{_x, _y} {}

  constexpr float x() const { return elements[0]; }
  constexpr float y() const { return elements[1]; }

  constexpr bool operator==(const Vec2& v) const noexcept { return x() == v.x() && y() == v.y(); }
};

// binary operators
inline constexpr Vec2 operator+(const Vec2& lhs, const Vec2& rhs) noexcept {
  return Vec2(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}
inline constexpr Vec2 operator+(const Vec2& lhs, float rhs) noexcept {
  return Vec2(lhs.x() + rhs, lhs.y() + rhs);
}
inline constexpr Vec2 operator+(float lhs, const Vec2& rhs) noexcept { return rhs + lhs; }

inline constexpr Vec2 operator-(const Vec2& lhs, const Vec2& rhs) noexcept {
  return Vec2(lhs.x() - rhs.x(), lhs.y() - rhs.y());
}
inline constexpr Vec2 operator-(const Vec2& lhs, float rhs) noexcept {
  return Vec2(lhs.x() - rhs, lhs.y() - rhs);
}
inline constexpr Vec2 operator-(float lhs, const Vec2& rhs) noexcept {
  return Vec2(lhs - rhs.x(), lhs - rhs.y());
}

inline constexpr Vec2 operator*(const Vec2& lhs, const Vec2& rhs) noexcept {
  return Vec2(lhs.x() * rhs.x(), lhs.y() * rhs.y());
}
inline constexpr Vec2 operator*(const Vec2& lhs, float rhs) noexcept {
  return Vec2(lhs.x() * rhs, lhs.y() * rhs);
}
inline constexpr Vec2 operator*(float lhs, const Vec2& rhs) noexcept { return rhs * lhs; }

inline constexpr Vec2 operator/(const Vec2& lhs, const Vec2& rhs) noexcept {
  return Vec2(lhs.x() / rhs.x(), lhs.y() / rhs.y());
}
inline constexpr Vec2 operator/(const Vec2& lhs, float rhs) noexcept {
  return Vec2(lhs.x() / rhs, lhs.y() / rhs);
}
inline constexpr Vec2 operator/(float lhs, const Vec2& rhs) noexcept {
  return Vec2(lhs / rhs.x(), lhs / rhs.y());
}

// print
inline std::ostream& operator<<(std::ostream& stream, const Vec2& v) noexcept {
  stream << "(" << v.x() << ", " << v.y() << ")";
  return stream;
}

// dot product
inline constexpr float dot(const Vec2& lhs, const Vec2& rhs) noexcept {
  return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}

// length
inline constexpr float length2(const Vec2& v) noexcept { return dot(v, v); }
inline constexpr float length(const Vec2& v) noexcept { return std::sqrt(length2(v)); }

// normalize
inline constexpr Vec2 normalize(const Vec2& v) noexcept { return v / length(v); }

#endif