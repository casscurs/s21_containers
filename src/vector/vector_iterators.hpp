#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_ITERATORS_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_ITERATORS_HPP_
#include "./vector_class.hpp"

/* Итератор начала */
template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::begin() const noexcept {
  return begin_;
}

/* Итератор конца */
template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::end() const noexcept {
  return end_;
}

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_ITERATORS_HPP_