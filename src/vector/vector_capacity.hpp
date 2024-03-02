/* Copyright [2024] <Casscurs> */

#ifndef VECTOR_CAPACITY_HPP_
#define VECTOR_CAPACITY_HPP_

#include <limits>

#include "./vector_class.hpp"

/* Проверяет пустой ли контейнер */
template <typename T>
bool s21::vector<T>::empty() const noexcept {
  return capacity() == 0;
}

/* Возвращает количество элементов */
template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::size() const noexcept {
  return end_ - begin_;
}

/* Возвращает максимально возможное количество элементов */
template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

/* Выделяет хранилище элементов и копирует текущие элементы во вновь выделенный
 * массив */
template <typename T>
void s21::vector<T>::reserve(size_t size) {
  if (capacity() >= size) return;
  reallocation(size);
}

/* Возвращает количество элементов, которые могут хранится в выделенном на
 * данный момент хранилище */
template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::capacity() const noexcept {
  return AllEnd_ - begin_;
}

/* Освобождение неиспользуемой памяти */
template <typename T>
void s21::vector<T>::shrink_to_fit() {
  if (capacity() == size()) return;
  reallocation(size());
}

#endif  // VECTOR_CAPACITY_HPP_
