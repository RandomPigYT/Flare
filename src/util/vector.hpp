#ifndef REFLECTION_UTIL_VECTOR_H
#define REFLECTION_UTIL_VECTOR_H

#include <algorithm>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
//#include <string.h>
#include <cstring>

namespace Reflection::util {

#define INITIAL_VECTOR_SIZE 10
#define VECTOR_GROW_FACTOR 2

template <typename T>
class Vector {
  public:
  Vector() {
    //m_buffer = (T *)malloc(INITIAL_VECTOR_SIZE * sizeof(T));
    m_buffer = new T[INITIAL_VECTOR_SIZE];
    if (m_buffer == NULL) {
      fprintf(stderr, "Failed to reallocate memory");
      exit(EXIT_FAILURE);
    }

    m_capacity = 10;
    m_size = 0;
  }

  Vector(class Vector &v) {
    m_buffer = new T[v.m_capacity];
    m_capacity = v.m_capacity;
    m_size = v.m_size;

    std::copy(begin(), end(), m_buffer);
  }

  ~Vector() {
    //free(m_buffer);
    delete[] m_buffer;
  }

  void pushBack(T element);

  T pop();
  T pop(uint64_t index);

  uint64_t length();

  uint64_t length() const;

  T *begin() const;
  T *end() const;

  T &operator[](uint64_t index);
  T &operator[](uint64_t index) const;

  private:
  T *m_buffer;
  uint64_t m_capacity;
  uint64_t m_size;
};

}

namespace Reflection {

template <typename T>
void util::Vector<T>::pushBack(T element) {
  if (m_size >= m_capacity) {
    //T *temp =
    //(T *)realloc(m_buffer, VECTOR_GROW_FACTOR * m_capacity * sizeof(T));

    T *temp = new T[VECTOR_GROW_FACTOR * m_size];

    if (temp == NULL) {
      fprintf(stderr, "Failed to reallocate memory\n");
      exit(EXIT_FAILURE);
    }

    //std::memcpy(temp, m_buffer, m_size * sizeof(T));
    std::copy(begin(), end(), temp);
    delete[] m_buffer;

    m_buffer = temp;
    m_capacity *= VECTOR_GROW_FACTOR;
  }

  m_buffer[m_size] = element;
  m_size++;
}

template <typename T>
T util::Vector<T>::pop() {
  if (m_size == 0) {
    fprintf(stderr, "Attempted to pop an empty vector\n");
    exit(EXIT_FAILURE);
  }

  m_size--;
  return m_buffer[m_size];
}

template <typename T>
T util::Vector<T>::pop(uint64_t index) {
  if (m_size == 0) {
    fprintf(stderr, "Attempted to pop an empty vector\n");
    exit(EXIT_FAILURE);
  }

  if (index >= m_size) {
    fprintf(stderr, "Out-of-bounds memory access\n");
    exit(EXIT_FAILURE);
  }

  if (index == m_size - 1) {
    return pop();
  }

  T temp = m_buffer[index];

  T *src = &(m_buffer[index + 1]);
  T *dest = &(m_buffer[index]);

  //uint64_t N = (m_size - 1) - index;

  //memmove(dest, src, N * sizeof(T));
  std::copy_backward(src, end(), dest);

  m_size--;
  return temp;
}

template <typename T>
uint64_t util::Vector<T>::length() {
  return m_size;
}

template <typename T>
uint64_t util::Vector<T>::length() const {
  return m_size;
}

template <typename T>
T &util::Vector<T>::operator[](uint64_t index) {
  if (index >= m_size) {
    fprintf(stderr, "Out-of-bounds memory access\n");
    exit(EXIT_FAILURE);
  }

  return m_buffer[index];
}

template <typename T>
T &util::Vector<T>::operator[](uint64_t index) const {
  if (index >= m_size) {
    fprintf(stderr, "Out-of-bounds memory access\n");
    exit(EXIT_FAILURE);
  }

  return m_buffer[index];
}

template <typename T>
T *util::Vector<T>::begin() const {
  return &m_buffer[0];
}

template <typename T>
T *util::Vector<T>::end() const {
  return &m_buffer[m_size - 1];
}

}
#endif
