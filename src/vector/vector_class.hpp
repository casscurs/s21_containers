#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_CLASS_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_CLASS_HPP_

#include <iostream>

namespace s21 {
template <typename T>
class vector {
 private:
  T* begin_;
  T* end_;
  T* AllEnd_;

 public:
  // Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;
  // Constructors
  vector() noexcept;
  vector(size_type n);
  vector(std::initializer_list<value_type> const& items);
  vector(const vector& v);
  // vector(vector&& v);
  // ~vector();
  // vector(size_t count, const T& value = T());
  // Operators

  //  Methods
  size_type size() const noexcept;
  size_type capacity() const noexcept;
  // size_t size() const noexcept;
  // size_t capacity() const noexcept;
  // void reserve(size_type size);
  // void push_back(const T& value);
  // void push_back(const_reference value);
  value_type& operator[](size_t i) { return *(begin_ + i); }
  // Help Functions
  void initializeFromItems(const T* listIt) const;
};
}  // namespace s21

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_CLASS_HPP_