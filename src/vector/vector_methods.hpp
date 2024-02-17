#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_METHODS_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_METHODS_HPP_

#include "./vector_class.hpp"

template <typename T>
s21::vector<T>::vector() noexcept
    : begin_(nullptr), end_(nullptr), AllEnd_(nullptr) {}

template <typename T>
s21::vector<T>::vector(size_type n)
    : begin_(new value_type[n]()), end_(begin_ + n), AllEnd_(begin_ + n) {}

template <typename T>
s21::vector<T>::vector(std::initializer_list<value_type> const& items)
    : begin_(reinterpret_cast<value_type*>(
          new uint8_t[items.size() * sizeof(value_type)])),
      end_(begin_ + items.size()),
      AllEnd_(begin_ + items.size()) {
  iterator it = begin_;
  auto listIt = items.begin();
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

template <typename T>
s21::vector<T>::vector(const vector& v)
    : begin_(reinterpret_cast<value_type*>(
          new uint8_t[v.size() * sizeof(value_type)])),
      end_(begin_ + v.size()),
      AllEnd_(begin_ + v.size()) {
  iterator it = begin_;
  auto listIt = items.begin();
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

template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::size() const noexcept {
  return end_ - begin_;
}

template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::capacity() const noexcept {
  return AllEnd_ - begin_;
}

// template <typename T>
// void s21::vector<T>::reserve(size_t newcap) {
//   if (capacity >= newcap) return;
//   // подумать про единичку
//   // заменить new char на тип unsigned_char
//   T* newarr_ = reinterpret_cast<T*>(new_char[newcap * sizeof(T)]);
//   size_t i = 0;
//   try {
//     for (; i < size(); ++i) {
//       new (newarr_ + i) T(begin_[i]);
//     }
//   } catch (...) {
//     for (size_t j = 0; j != i; ++j) {
//       (newarr_ + j)->~T;
//     }

//     delete[] reinterpret_cast<char*>(newarr_) throw;
//   }

//   for (T* delit = begin_; delit != end_; ++delit) {
//     delit->~T();
//   }
//   delete[] reinterpret_cast<char*> begin_;
//   // После обновляем end_, buf_end_, begin_
// }

// template <typename T>
// void Vector<T>::push_back(const T& value) {
//   if (end == buff_end_) {
//     reserve(std::max(1, 2 * capcity()));
//   }

//   new (end_) T(value);
//   ++end_;
//   // Если new(end_) T(value); бросает исключение, то нужно возвращать все как
//   // было
//   // обратно!!! Реализовать самому
// }

// void pop_back() {
//   --sz;
//   (arr + sz)->~T();
// }

// T& operator[](size_t i) { return arr[i]; }

// const T& operator[](size_t i) { return arr[i]; }

// T& at(size_t i) {
//   // в отличие от квадратных скобок делает проверку не превзошли ли мы размер
//   if (i >= sz) {
//     throw std::out_of_range("...");
//   } else
//     return arr[i];
// }
// const T& at(size_t i) {
//   // в отличие от квадратных скобок делает проверку не превзошли ли мы размер
//   if (i >= sz) {
//     throw std::out_of_range("...");
//   } else
//     return arr[i];
// }

// // для shrink to fit необходимо выпонить переаллокацию

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_METHODS_HPP_