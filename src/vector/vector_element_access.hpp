#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_ELEMENT_ACCESS_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_ELEMENT_ACCESS_HPP_

#include "./vector_class.hpp"

/* Доступ к элементу с проверкой границ */
template <typename T>
typename s21::vector<T>::reference s21::vector<T>::at(size_type pos) {
  if (pos >= size())
    throw std::out_of_range("incorrect size index");
  else
    return *(begin_ + pos);
}

/* Доступ к указанному элементу */
template <typename T>
typename s21::vector<T>::reference s21::vector<T>::operator[](
    size_type pos) const noexcept {
  return *(begin_ + pos);
}

/* Доступ к первому элементу */
template <typename T>
typename s21::vector<T>::const_reference s21::vector<T>::front()
    const noexcept {
  return *(begin_);
}

/* Доступ к последнему элементу */
template <typename T>
typename s21::vector<T>::const_reference s21::vector<T>::back() const noexcept {
  return *(end_ - 1);
}

/* Прямой доступ к базовому массиву */
template <typename T>
T* s21::vector<T>::data() const noexcept {
  return begin_;
}

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_ELEMENT_ACCESS_HPP_