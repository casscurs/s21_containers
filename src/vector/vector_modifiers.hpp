/* Copyright [2024] <Casscurs> */

#ifndef VECTOR_MODIFIERS_HPP_
#define VECTOR_MODIFIERS_HPP_

#include <algorithm>
#include <utility>

#include "./vector_class.hpp"

/* Очищает содержимое */
template <typename T>
void s21::vector<T>::clear() noexcept {
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
  } catch (...) {
    for (iterator it = pos; it != end_; ++it) {
      *it = std::move(*(it + 1));
    }
    end_->~T();
    throw;
  }
  ++end_;
  return pos;
}
/* Cтирает элемент в позиции */
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

/* Добавляет элемент в конец */
template <typename T>
void s21::vector<T>::push_back(const_reference value) {
  if (end_ == AllEnd_) {
    reserve(std::max<size_t>(1, 2 * capacity()));
  }

  try {
    new (end_) T(value);
  } catch (...) {
    end_->~T();
    throw;
  }
  ++end_;
}

/* Удаляет последний элемент */
template <typename T>
void s21::vector<T>::pop_back() {
  if (end_ != begin_) {
    --end_;
    end_->~T();
  }
}

/* Меняет содержимое */
template <typename T>
void s21::vector<T>::swap(vector& other) {
  std::swap(begin_, other.begin_);
  std::swap(end_, other.end_);
  std::swap(AllEnd_, other.AllEnd_);
}

/* Вставка новых элементов в контейнер непосредственно перед pos */
template <typename T>
template <typename... Args>
typename s21::vector<T>::iterator s21::vector<T>::insert_many(
    const_iterator pos, Args&&... args) {
  if (pos < begin_ || pos > end_)
    throw std::out_of_range("Iterator is out of range");

  size_type index = pos - begin_;

  size_t args_count = sizeof...(Args);

  if (begin_ == nullptr || end_ + args_count >= AllEnd_) {
    reserve(std::max<size_t>(args_count, 2 * (size() + args_count)));
    pos = begin_ + index;
  }

  iterator insert_pos = begin_ + index;

  iterator it = end_ + args_count - 1;
  auto count = end_ - pos;
  try {
    for (iterator k = end_; count != 0; --it, --count) {
      new (it) T(*(--k));
    }
  } catch (...) {
    for (iterator delit = end_ + args_count - 1; delit != it; --delit) {
      delit->~T();
    }
  }

  size_t index_in_args = 0;
  try {
    ((new (insert_pos + index_in_args++) T(std::forward<Args>(args))), ...);
  } catch (...) {
    iterator k = insert_pos + index_in_args;
    for (iterator delit = insert_pos; delit != k; ++delit) {
      delit->~T();
    }
  }

  end_ += args_count;
  return insert_pos;
}

/* Добавляет новые элементы в конец контейнера */
template <typename T>
template <typename... Args>
void s21::vector<T>::insert_many_back(Args&&... args) {
  insert_many(end(), std::forward<Args>(args)...);
}

#endif  // VECTOR_MODIFIERS_HPP_
