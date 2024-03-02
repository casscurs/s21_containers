/* Copyright [2024] <Casscurs> */

#ifndef VECTOR_FUNCTIONS_HPP_
#define VECTOR_FUNCTIONS_HPP_

#include "./vector_class.hpp"

/* По умолчанию */
template <typename T>
s21::vector<T>::vector() noexcept
    : begin_(nullptr), end_(nullptr), AllEnd_(nullptr) {}

/* Параметризованный */
template <typename T>
s21::vector<T>::vector(size_type n)
    : begin_(
          reinterpret_cast<value_type*>(new uint8_t[n * sizeof(value_type)])),
      end_(begin_ + n),
      AllEnd_(begin_ + n) {
  iterator it = begin_;
  try {
    for (; it != end_; ++it) {
      new (it) T();
    }
  } catch (...) {
    for (iterator delit = begin_; delit != it; ++delit) {
      delit->~T();
    }
    delete[] reinterpret_cast<uint8_t*>(begin_);
    throw;
  }
}

/* Списка инициализаторов */
template <typename T>
s21::vector<T>::vector(std::initializer_list<value_type> const& items)
    : begin_(reinterpret_cast<value_type*>(
          new uint8_t[items.size() * sizeof(value_type)])),
      end_(begin_ + items.size()),
      AllEnd_(begin_ + items.size()) {
  initializeFromItems(begin_, end_, items.begin());
}

/* Копирования */
template <typename T>
s21::vector<T>::vector(const vector& v)
    : begin_(reinterpret_cast<value_type*>(
          new uint8_t[v.size() * sizeof(value_type)])),
      end_(begin_ + v.size()),
      AllEnd_(begin_ + v.size()) {
  initializeFromItems(begin_, end_, v.begin_);
}

/* Перемещения */
template <typename T>
s21::vector<T>::vector(vector&& v) noexcept
    : begin_(v.begin_), end_(v.end_), AllEnd_(v.AllEnd_) {
  v.begin_ = nullptr;
  v.end_ = nullptr;
  AllEnd_ = nullptr;
}
/* Деструктор */
template <typename T>
s21::vector<T>::vector::~vector() noexcept {
  full_clear();
}

/* Присваивание перемещением */
template <typename T>
s21::vector<T>& s21::vector<T>::operator=(vector&& v) {
  if (this == &v) return *this;
  full_clear();
  begin_ = v.begin_;
  end_ = v.end_;
  AllEnd_ = v.AllEnd_;
  v.begin_ = nullptr;
  v.end_ = nullptr;
  v.AllEnd_ = nullptr;
  return *this;
}

#endif  // VECTOR_FUNCTIONS_HPP_
