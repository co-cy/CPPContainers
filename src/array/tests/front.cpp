//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArrayFrontTest : public testing::Test {};

using ArrayFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayFrontTest, ArrayFrontTypes);

TYPED_TEST(ArrayFrontTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(ArrayFrontTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(a.front(), value_1);
}
