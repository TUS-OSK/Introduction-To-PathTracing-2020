#include "mogumogu/vec.hpp"

#include "gtest/gtest.h"

TEST(Vec3Test, Add) {
  EXPECT_EQ(Vec3(1, 2, 3) + Vec3(4, 5, 6), Vec3(5, 7, 9));
  EXPECT_EQ(Vec3(1, 2, 3) + 1, Vec3(2, 3, 4));
  EXPECT_EQ(1 + Vec3(1, 2, 3), Vec3(2, 3, 4));
}

TEST(Vec3Test, Sub) {
  EXPECT_EQ(Vec3(1, 2, 3) - Vec3(4, 5, 6), Vec3(-3, -3, -3));
  EXPECT_EQ(Vec3(1, 2, 3) - 1, Vec3(0, 1, 2));
  EXPECT_EQ(1 - Vec3(1, 2, 3), Vec3(0, -1, -2));
}

TEST(Vec3Test, Mul) {
  EXPECT_EQ(Vec3(1, 2, 3) * Vec3(4, 5, 6), Vec3(4, 10, 18));
  EXPECT_EQ(Vec3(1, 2, 3) * 2, Vec3(2, 4, 6));
  EXPECT_EQ(2 * Vec3(1, 2, 3), Vec3(2, 4, 6));
}

TEST(Vec3Test, Div) {
  EXPECT_EQ(Vec3(2, 4, 6) / Vec3(1, 2, 3), Vec3(2, 2, 2));
  EXPECT_EQ(Vec3(2, 4, 6) / 2, Vec3(1, 2, 3));
  EXPECT_EQ(6 / Vec3(1, 2, 3), Vec3(6, 3, 2));
}

TEST(Vec3Test, Length) {
  EXPECT_EQ(length(Vec3(1, 2, 2)), 3);
}

TEST(Vec3Test, Dot) {
  EXPECT_EQ(dot(Vec3(1, 2, 3), Vec3(4, 5, 6)), 32);
}

TEST(Vec3Test, Cross) {
  EXPECT_EQ(cross(Vec3(1, 0, 0), Vec3(0, 1, 0)), Vec3(0, 0, 1));
}