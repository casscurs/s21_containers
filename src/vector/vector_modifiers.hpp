/* Copyright [2024] <Casscurs> */

#ifndef VECTOR_MODIFIERS_HPP_
#define VECTOR_MODIFIERS_HPP_

#include <algorithm>
#include <utility>

#include "./vector_class.hpp"

/* очищает содержимое */
template <typename T>
void s21::vector<T>::clear() noexcept {
  // size после этого ноль
  for (iterator del = begin_; del != end_; ++del) {
    del->~T();
  }
  end_ = begin_;
  return;
}

/* Вставляет элементы на конкретную позицию и возвращает итератор, указывающий
   на новый элемент */
template <typename T>
typename s21::vector<T>::iterator s21::vector<T>::insert(
    iterator pos, const_reference value) {
  if (pos < begin_ || pos > end_)
    throw std::out_of_range("Iterator is out of range");

  if (pos == end_) {
    this->push_back(value);
    pos = end();
    return --pos;
  }

  size_type index = pos - begin_;

  if (end_ == AllEnd_) {
    reserve(std::max<size_t>(1, 2 * capacity()));
  }
  pos = begin_ + index;

  new (end_) T(*(end_ - 1));

  for (iterator it = end_ - 1; it != pos; --it) {
    *it = std::move(*(it - 1));
  }

  try {
    new (pos) T(value);
    ++end_;
  } catch (...) {
    for (iterator it = pos; it != end_; ++it) {
      *it = std::move(*(it + 1));
    }
    end_->~T();
    throw;
  }

  return pos;
}

template <typename T>
void s21::vector<T>::erase(iterator pos) {
  if (pos < begin_ || pos >= end_)
    throw std::out_of_range("Iterator is out of range");

  auto it = pos;
  try {
    for (; it != end_ - 1; ++it) {
      (it)->~T();
      new (it) T(*(it + 1));
    }
    --end_;
  } catch (...) {
    for (iterator delit = pos; delit != it; ++delit) {
      delit->~T();
    }
    throw;
  }
}

template <typename T>
void s21::vector<T>::push_back(const_reference value) {
  if (end_ == AllEnd_) {
    reserve(std::max<size_t>(1, 2 * capacity()));
  }

  try {
    new (end_) T(value);
    ++end_;
  } catch (...) {
    end_->~T();
    throw;
  }
}

template <typename T>
void s21::vector<T>::pop_back() {
  if (end_ != begin_) {
    --end_;
    end_->~T();
  }
}

template <typename T>
void s21::vector<T>::swap(vector& other) {
  std::swap(begin_, other.begin_);
  std::swap(end_, other.end_);
  std::swap(AllEnd_, other.AllEnd_);
}

#endif  // VECTOR_MODIFIERS_HPP_
