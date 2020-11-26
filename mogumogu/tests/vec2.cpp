#include "mogumogu/core/vec2.hpp"

#include "gtest/gtest.h"

TEST(Vec2Test, Add) {
  EXPECT_EQ(Vec2(1, 2) + Vec2(4, 5), Vec2(5, 7));
  EXPECT_EQ(Vec2(1, 2) + 1, Vec2(2, 3));
  EXPECT_EQ(1 + Vec2(1, 2), Vec2(2, 3));
}

TEST(Vec2Test, Sub) {
  EXPECT_EQ(Vec2(1, 2) - Vec2(4, 5), Vec2(-3, -3));
  EXPECT_EQ(Vec2(1, 2) - 1, Vec2(0, 1));
  EXPECT_EQ(1 - Vec2(1, 2), Vec2(0, -1));
}

TEST(Vec2Test, Mul) {
  EXPECT_EQ(Vec2(1, 2) * Vec2(4, 5), Vec2(4, 10));
  EXPECT_EQ(Vec2(1, 2) * 2, Vec2(2, 4));
  EXPECT_EQ(2 * Vec2(1, 2), Vec2(2, 4));
}

TEST(Vec2Test, Div) {
  EXPECT_EQ(Vec2(2, 4) / Vec2(1, 2), Vec2(2, 2));
  EXPECT_EQ(Vec2(2, 4) / 2, Vec2(1, 2));
  EXPECT_EQ(6 / Vec2(1, 2), Vec2(6, 3));
}

TEST(Vec2Test, Length) { EXPECT_EQ(length(Vec2(3, 4)), 5); }

TEST(Vec2Test, Dot) { EXPECT_EQ(dot(Vec2(1, 2), Vec2(4, 5)), 14); }