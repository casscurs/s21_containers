#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_HELP_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_HELP_HPP_

#include "./vector_class.hpp"

template <typename T>
void s21::vector<T>::initializeFromItems(const T* listIt) const {
  iterator it = begin_;
  try {
    for (; it != end_; ++it, ++listIt) {
      new (it) value_type(*listIt);
    }
  } catch (...) {
    for (iterator delit = begin_; delit != it; ++delit) {
      delit->~value_type();
    }
    delete[] reinterpret_cast<uint8_t*>(begin_);
    throw;
  }
}

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_HELP_HPP_