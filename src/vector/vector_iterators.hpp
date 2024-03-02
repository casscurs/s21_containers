/* Copyright [2024] <Casscurs> */

#ifndef VECTOR_ITERATORS_HPP_
#define VECTOR_ITERATORS_HPP_
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

#endif  // VECTOR_ITERATORS_HPP_
