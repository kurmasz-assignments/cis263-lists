#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "dsexceptions.h"

template<typename Object>
class Vector {
public:
  explicit Vector(int initSize = 0)
      : theSize{initSize},
        theCapacity{initSize + SPARE_CAPACITY} { objects = new Object[theCapacity]; }

  Vector(const Vector &rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr} {
    objects = new Object[theCapacity];
    for (int k = 0; k < theSize; ++k)
      objects[k] = rhs.objects[k];
  }

  Vector &operator=(const Vector &rhs) {
    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  ~Vector() { delete[] objects; }

  Vector(Vector &&rhs)
      : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects} {
    rhs.objects = nullptr;
    rhs.theSize = 0;
    rhs.theCapacity = 0;
  }

  Vector &operator=(Vector &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);

    return *this;
  }

  bool empty() const { return size() == 0; }

  int size() const { return theSize; }

  int capacity() const { return theCapacity; }

  Object &operator[](int index) {
#ifndef NO_CHECK
    if (index < 0 || index >= size())
      throw ArrayIndexOutOfBoundsException{};
#endif
    return objects[index];
  }

  const Object &operator[](int index) const {
#ifndef NO_CHECK
    if (index < 0 || index >= size())
      throw ArrayIndexOutOfBoundsException{};
#endif
    return objects[index];
  }

  void resize(int newSize) {
    // Change the size of the vector (i.e., teh value returned by the method size).
    // If newSize > capacity, then the new capacity should be newSize * 2.

    // Place your code here.  
  }

  void reserve(int newCapacity) {
    // Increase the capacity of the vector.  Do not change the size.

    // Place your code here.  
  }

  // Stacky stuff
  void push_back(const Object &x) {
    if (theSize == theCapacity)
      reserve(2 * theCapacity + 1);
    objects[theSize++] = x;
  }

  // Stacky stuff
  void push_back(Object &&x) {
    if (theSize == theCapacity)
      reserve(2 * theCapacity + 1);
    objects[theSize++] = std::move(x);
  }

  void pop_back() {
    if (empty())
      throw UnderflowException{};
    --theSize;
  }

  const Object &back() const {
    if (empty())
      throw UnderflowException{};
    return objects[theSize - 1];
  }

  // Iterator stuff: not bounds checked
  typedef Object *iterator;
  typedef const Object *const_iterator;

  iterator begin() { return &objects[0]; }

  const_iterator begin() const { return &objects[0]; }

  iterator end() { return &objects[size()]; }

  const_iterator end() const { return &objects[size()]; }

  iterator insert(iterator iter, const Object &x) {
    // Insert x **before** iter.
    // Make sure your algorithm is O(N).

    // Place your code here.  
    return iter;
  }

  iterator erase(iterator from, iterator to) {
    // Remove all the elements between from and to (including from.  *not* including to).
    // Make sure your algorithm is O(N).

    // Place your code here.  
    return to;
  }

  static const int SPARE_CAPACITY = 2;

private:
  int theSize;
  int theCapacity;
  Object *objects;
};

#endif
