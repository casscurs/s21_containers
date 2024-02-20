#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_CAPACITY_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_CAPACITY_HPP_

#include "./vector_class.hpp"

// void reserve(size_type size);
// size_type capacity() const noexcept;
// void shrink_to_fit();

/* Проверяет пустой ли контейнер */
template <typename T>
bool s21::vector<T>::empty() const noexcept {
  return capacity() == 0;
}

/* Возвращает количество элементов */
template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::size() const noexcept {
  return end_ - begin_;
}

/* Возвращает максимально возможное количество элементов */
template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::max_size() const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

/* Выделяет хранилище элементов и копирует текущие элементы во вновь выделенный
 * массив */
template <typename T>
void s21::vector<T>::reserve(size_type size) {
  if (capacity() >= size) return;
  T* newarr_ = reinterpret_cast<T*>(new uint8_t[size * sizeof(T)]);
  size_type objQuant = this->size();

  initializeFromItems(newarr_, newarr_ + objQuant, begin_);
  this->clear();
  std::swap(begin_, newarr_);
  std::swap(end_, newarr_ + objQuant);
  std::swap(AllEnd_, newarr_ + size);
}

/* Возвращает количество элементов, которые могут хранится в выделенном на
 * данный момент хранилище */
template <typename T>
typename s21::vector<T>::size_type s21::vector<T>::capacity() const noexcept {
  return AllEnd_ - begin_;
}

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

// // для shrink to fit необходимо выпонить переаллокацию

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_CAPACITY_HPP_