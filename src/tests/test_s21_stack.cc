#include <gtest/gtest.h>

#include "../s21_containers.h"

TEST(s21_stack, empty_constructor) {
    s21::stack<int> s;
    ASSERT_EQ(0, s.size());
    ASSERT_TRUE(s.empty());
}

TEST(s21_stack, initializer_list_constructor) {
    s21::stack<int> s{1, 2, 3, 4, 5};
    ASSERT_EQ(5, s.size());
    ASSERT_FALSE(s.empty());
}

TEST(s21_stack, copy_constructor) {
    s21::stack<int> s1{1, 2, 3, 4, 5};
    s21::stack<int> s2(s1);
    ASSERT_EQ(5, s2.size());
    ASSERT_FALSE(s2.empty());
}

TEST(s21_stack, move_constructor) {
    s21::stack<int> s1{1, 2, 3, 4, 5};
    s21::stack<int> s2(std::move(s1));
    ASSERT_EQ(5, s2.size());
    ASSERT_FALSE(s2.empty());
}

TEST(s21_stack, move_assignment) {
    s21::stack<int> s1{1, 2, 3, 4, 5};
    s21::stack<int> s2;
    s2 = std::move(s1);
    ASSERT_EQ(5, s2.size());
    ASSERT_FALSE(s2.empty());
}

TEST(s21_stack, top) {
    s21::stack<int> s{1, 2, 3, 4, 5};
    ASSERT_EQ(5, s.top());
}

TEST(s21_stack, empty) {
    s21::stack<int> s;
    ASSERT_TRUE(s.empty());
    s.push(1);
    ASSERT_FALSE(s.empty());
}

TEST(s21_stack, size) {
    s21::stack<int> s;
    ASSERT_EQ(0, s.size());
    s.push(1);
    ASSERT_EQ(1, s.size());
}

TEST(s21_stack, push) {
    s21::stack<int> s;
    s.push(1);
    ASSERT_EQ(1, s.size());
    ASSERT_EQ(1, s.top());
    s.push(2);
    ASSERT_EQ(2, s.size());
    ASSERT_EQ(2, s.top());
}

TEST(s21_stack, pop) {
    s21::stack<int> s{1, 2, 3, 4, 5};
    s.pop();
    ASSERT_EQ(4, s.size());
    ASSERT_EQ(4, s.top());
    s.pop();
    ASSERT_EQ(3, s.size());
    ASSERT_EQ(3, s.top());
}

TEST(s21_stack, swap) {
    s21::stack<int> s1{1, 2, 3, 4, 5};
    s21::stack<int> s2{6, 7, 8, 9, 10};
    s1.swap(s2);
    ASSERT_EQ(5, s1.size());
    ASSERT_EQ(10, s1.top());
    ASSERT_EQ(5, s2.size());
    ASSERT_EQ(5, s2.top());
}

TEST(s21_stack, insert_many) {
  s21::stack<int> stack({0, 1, 4, 9});
  stack.insert_many_front(std::move(16), std::move(25), 36);

  EXPECT_EQ(7, stack.size());
  for (int i = 6; i >= 0; --i, stack.pop()) {
    EXPECT_EQ(i * i, stack.top());
  }
}
