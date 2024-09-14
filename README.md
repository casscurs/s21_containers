# s21_containers Library

### Overview

The `s21_containers` library is a custom C++ implementation of several fundamental container classes such as `list`, `map`, `queue`, `set`, `stack`, and `vector`. The library is designed to closely follow the logic and behaviors of the C++ Standard Template Library (STL), while adhering to memory handling conventions, iterator operations, and appropriate handling of abnormal situations. 

The library is implemented using C++17 standards and the GCC compiler, and includes full support for iterators, container operations, and template-based designs to support various data types. Additionally, unit testing is implemented using the GTest framework to ensure the correctness of all operations.

### Key Features

The `s21_containers` library provides:

- **Standard Constructors**: Includes default, copy, move constructors, and constructors with initialization lists.
- **Element Access Methods**: Supports element access through methods like `operator[]`, and functions to retrieve front, back, and specific elements.
- **Capacity Check Methods**: Allows for checking the container's size, capacity, and whether it is empty.
- **Modifier Methods**: Enables adding, removing, and modifying elements within containers. It also supports clearing the container entirely.
- **Iterator Support**: Iterators are implemented for seamless navigation and manipulation of container elements. These iterators support standard operations like dereferencing, incrementing, and comparing.
- **Templated Container Classes**: Generic template-based implementations allow for various data types to be stored within containers, following the principles of C++ class templates.

The containers are divided into two main types:

- **Sequential Containers**: Including `list`, `vector`, `queue`, and `stack`, where elements are ordered in sequence. 
- **Associative Containers**: Including `map` and `set`, which allow for fast lookups based on key-value pairs or unique elements.

### Containers

#### List
A doubly linked list implementation that allows efficient insertion and deletion of elements at any position. It provides both forward and backward iterators for navigation through the list.

#### Vector
A dynamic array that supports fast access to elements by index. It automatically resizes itself when necessary and provides random access iterators for fast navigation.

#### Queue
A FIFO (First-In, First-Out) structure that supports adding elements to the back and removing elements from the front.

#### Stack
A LIFO (Last-In, First-Out) structure that supports pushing and popping elements from the top.

#### Set
An associative container that stores unique elements in a specific order. Elements are accessed by their values.

#### Map
A key-value associative container where each element is stored as a pair. Keys are unique, and values are retrieved through these keys.

### Iterators

All containers in the `s21_containers` library provide iterators through the `begin()` and `end()` methods. These iterators function similarly to C++ STL iterators, allowing for pointer-like operations and interaction with container elements.

Iterator operations include:

- `*iter`: Accesses the element pointed to by the iterator.
- `++iter`: Advances the iterator to the next element.
- `--iter`: Moves the iterator to the previous element.
- `iter1 == iter2`: Checks if two iterators point to the same element.
- `iter1 != iter2`: Checks if two iterators point to different elements.

### Templated Classes

All containers are implemented as template classes, enabling them to store elements of any type without rewriting the implementation for each specific type. For example, the `list` container can store integers, floating-point numbers, characters, or even user-defined types.

### Bonus Features

The library also includes several bonus features that enhance its functionality:

#### 1. `s21_containersplus` Library

In addition to the primary containers, the library also provides implementations for the `array` and `multiset` classes, found in the `s21_containersplus.h` header file.

- **Array**: A fixed-size sequence container that provides fast element access and manipulation.
- **Multiset**: Similar to `set`, but allows for multiple identical elements to be stored.

#### 2. `insert_many` Method

This method allows bulk insertion of elements into a container at specified positions or appending them to the front or back of the container.

- `iterator insert_many(const_iterator pos, Args&&... args)`: Inserts new elements before `pos` in containers like `list` and `vector`.
- `void insert_many_back(Args&&... args)`: Adds elements to the back of containers like `list`, `vector`, and `queue`.
- `void insert_many_front(Args&&... args)`: Adds elements to the front of containers like `list` and `stack`.
- `vector<std::pair<iterator,bool>> insert_many(Args&&... args)`: Inserts multiple elements into associative containers like `map`, `set`, and `multiset`.

### Unit Testing

To ensure the correctness and robustness of the `s21_containers` library, all methods are thoroughly tested using the GTest framework. The test suite covers edge cases, memory management, and abnormal behaviors to ensure that the containers adhere to STL logic.

### Makefile

A Makefile is provided for building and testing the library. The Makefile includes the following targets:

- `clean`: Cleans up build artifacts.
- `test`: Compiles and runs the unit tests.

### Conclusion

The `s21_containers` library is a comprehensive, custom-built alternative to C++'s Standard Template Library containers. Its focus on correctness, memory safety, and adherence to standard behaviors makes it a solid foundation for learning and developing C++ container classes.

