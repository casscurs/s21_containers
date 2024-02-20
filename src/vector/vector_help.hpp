#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_HELP_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_HELP_HPP_

#include "./vector_class.hpp"

template <typename T>
void s21::vector<T>::initializeFromItems(iterator start, const_iterator end,
                                         const_iterator listIt) {
  auto it = start;
  try {
    for (; it != end; ++it, ++listIt) {
      new (it) value_type(*listIt);
    }
  } catch (...) {
    for (iterator delit = start; delit != it; ++delit) {
      delit->~value_type();
    }
    delete[] reinterpret_cast<uint8_t*>(start);
    throw;
  }
  return;
}
template <typename T>
void s21::vector<T>::clear() {
  for (iterator del = begin_; del != end_; ++del) {
    del->~value_type();
  }

  delete[] reinterpret_cast<uint8_t*>(begin_);
  begin_ = nullptr;
  end_ = nullptr;
  AllEnd_ = nullptr;
  return;
}

template <typename T>
void s21::vector<T>::swap(vector&& v) {
  std::swap(begin_, v.begin_);
  std::swap(end_, v.end_);
  std::swap(AllEnd_, v.AllEnd_);
  return;
}

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_HELP_HPP_