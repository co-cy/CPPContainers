//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorClearTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorClearTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorClearTest, VectorClearTypes);

TYPED_TEST(VectorClearTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);
  EXPECT_NO_THROW(a.data());

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);
  EXPECT_NO_THROW(a.data());

  TypeParam value{13};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
  EXPECT_NO_THROW(a.data());
  EXPECT_EQ(iter, a.data());

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
  EXPECT_NO_THROW(a.data());
}

TYPED_TEST(VectorClearTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);
  EXPECT_NO_THROW(a.data());

  TypeParam value{26};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 14);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
  EXPECT_NO_THROW(a.data());
  EXPECT_EQ(iter, a.data());

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
  EXPECT_NO_THROW(a.data());
}

TYPED_TEST(VectorClearTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);
  EXPECT_NO_THROW(a.data());

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);
  EXPECT_NO_THROW(a.data());

  TypeParam value{98};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.end(), value));
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.back());

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);
  EXPECT_NO_THROW(a.data());

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);
  EXPECT_NO_THROW(a.data());
}