#ifndef S21_CONTAINERS_SRC_VECTOR_VECTOR_CLASS_HPP_
#define S21_CONTAINERS_SRC_VECTOR_VECTOR_CLASS_HPP_

namespace s21 {
template <typename T>
class vector {
 private:
  T* begin_;
  T* end_;
  T* AllEnd_;

 public:
  /* Member type */
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  /* Functions */
  vector() noexcept;
  vector(size_type n);
  vector(std::initializer_list<value_type> const& items);
  vector(const vector& v);
  vector(vector&& v) noexcept;
  ~vector() noexcept;
  reference operator=(vector&& v);

  /* Element access */
  reference at(size_type pos);
  reference operator[](size_type pos) const noexcept;
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  T* data() const noexcept;

  /* Iterators */
  iterator begin() const noexcept;
  iterator end() const noexcept;

  /* Capacity */
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type size);
  size_type capacity() const noexcept;
  // void shrink_to_fit();

  // Help Functions
  void initializeFromItems(iterator start, const_iterator end,
                           const_iterator listIt);
  void clear();
  void swap(vector&& v);
};
}  // namespace s21

#endif  // S21_CONTAINERS_SRC_VECTOR_VECTOR_CLASS_HPP_