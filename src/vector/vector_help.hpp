/* Copyright [2024] <Casscurs> */

#ifndef VECTOR_HELP_HPP_
#define VECTOR_HELP_HPP_

#include <utility>

#include "./vector_class.hpp"

template <typename T>
void s21::vector<T>::initializeFromItems(iterator start, const_iterator end,
                                         const_iterator listIt) {
  auto it = start;
  try {
    for (; it != end; ++it, ++listIt) {
      new (it) T(*listIt);
    }
  } catch (...) {
    for (iterator delit = start; delit != it; ++delit) {
      delit->~T();
    }
    delete[] reinterpret_cast<uint8_t*>(start);
    throw;
  }
  return;
}
template <typename T>
void s21::vector<T>::full_clear() {
  for (iterator del = begin_; del != end_; ++del) {
    del->~T();
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

template <typename T>
void s21::vector<T>::reallocation(size_t size) {
  T* newarr_ = reinterpret_cast<T*>(new uint8_t[size * sizeof(T)]);
  size_type objQuant = this->size();

  initializeFromItems(newarr_, newarr_ + objQuant, begin_);
  this->full_clear();

  begin_ = newarr_;
  end_ = newarr_ + objQuant;
  AllEnd_ = newarr_ + size;
}

#endif  // VECTOR_HELP_HPP_
