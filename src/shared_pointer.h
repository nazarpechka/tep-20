#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

#include "ref_counter.h"

template <typename T>
class SharedPointer {
 public:
  SharedPointer(T* pointer);
  SharedPointer(const SharedPointer& other);
  ~SharedPointer();

  SharedPointer<T>& operator=(const SharedPointer<T>& other);

  T& operator*();
  T* operator->();

 private:
  T* m_pointer;
  RefCounter* m_counter;
};

template <typename T>
SharedPointer<T>::SharedPointer(T* pointer)
    : m_pointer(pointer), m_counter(new RefCounter()) {
  m_counter->inc();
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& other)
    : m_pointer(other.m_pointer), m_counter(other.m_counter) {
  m_counter->inc();
}

template <typename T>
SharedPointer<T>::~SharedPointer() {
  if (m_counter->dec() == 0) {
    delete m_pointer;
    delete m_counter;
  }
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T>& other) {
  if (this != &other) {
    if (m_counter->dec() == 0) {
      delete m_pointer;
      delete m_counter;
    }

    m_pointer = other.m_pointer;
    m_counter = other.m_counter;
    m_counter->inc();
  }

  return *this;
}

template <typename T>
T* SharedPointer<T>::operator->() {
  return m_pointer;
}

template <typename T>
T& SharedPointer<T>::operator*() {
  return *m_pointer;
}

#endif  // __SHARED_POINTER_H__