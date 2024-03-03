#include <gtest/gtest.h>

#include "../s21_containers.h"

TEST(s21_array, empty_constructor) {
    s21::array<int, 5> a;
    ASSERT_EQ(5, a.size());
    ASSERT_FALSE(a.empty());
}

TEST(s21_array, initializer_list_constructor) {
    s21::array<int, 5> a{1, 2, 3, 4, 5};
    ASSERT_EQ(5, a.size());
    ASSERT_FALSE(a.empty());
}

TEST(s21_array, copy_constructor) {
    s21::array<int, 5> a1{1, 2, 3, 4, 5};
    s21::array<int, 5> a2(a1);
    ASSERT_EQ(5, a2.size());
    ASSERT_FALSE(a2.empty());
}

TEST(s21_array, move_constructor) {
    s21::array<int, 5> a1{1, 2, 3, 4, 5};
    s21::array<int, 5> a2(std::move(a1));
    ASSERT_EQ(5, a2.size());
    ASSERT_FALSE(a2.empty());
}

TEST(s21_array, move_assignment) {
    s21::array<int, 5> a1{1, 2, 3, 4, 5};
    s21::array<int, 5> a2;
    a2 = std::move(a1);
    ASSERT_EQ(5, a2.size());
    ASSERT_FALSE(a2.empty());
}

TEST(s21_array, front) {
    s21::array<int, 5> a{1, 2, 3, 4, 5};
    ASSERT_EQ(1, a.front());
}

TEST(s21_array, back) {
    s21::array<int, 5> a{1, 2, 3, 4, 5};
    ASSERT_EQ(5, a.back());
}

TEST(s21_array, empty) {
    s21::array<int, 5> a;
    ASSERT_FALSE(a.empty());
}

TEST(s21_array, size) {
    s21::array<int, 5> a;
    ASSERT_EQ(5, a.size());
}

TEST(s21_array, max_size) {
    s21::array<int, 5> a;
    ASSERT_EQ(5, a.max_size());
}

TEST(s21_array, swap) {
    s21::array<int, 5> a1{1, 2, 3, 4, 5};
    s21::array<int, 5> a2{5, 4, 3, 2, 1};
    a1.swap(a2);
    ASSERT_EQ(5, a1[0]);
    ASSERT_EQ(1, a2[0]);
}

TEST(s21_array, fill) {
    s21::array<int, 5> a;
    a.fill(42);
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(42, a[i]);
    }
}

TEST(s21_array, begin_end) {
    s21::array<int, 5> a{1, 2, 3, 4, 5};
    int i = 1;
    for (auto it = a.begin(); it != a.end(); ++it) {
        ASSERT_EQ(i++, *it);
    }
}

TEST(s21_array, array_at) {
    s21::array<int, 5> a{1, 2, 3, 4, 5};
    ASSERT_EQ(1, a.at(0));
    ASSERT_EQ(5, a.at(4));
    ASSERT_THROW(a.at(5), std::out_of_range);
}

TEST(s21_array, getData) {
    s21::array<int, 5> a{1, 2, 3, 4, 5};
    int* data = a.getData();
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(i + 1, data[i]);
    }
}
