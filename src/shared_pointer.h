#ifndef __SHARED_POINTER_H__
#define __SHARED_POINTER_H__

#include "ref_counter.h"

template <typename T>
class SharedPointer {
 public:
  SharedPointer(T* pointer);
  SharedPointer(const SharedPointer& other);
  SharedPointer(SharedPointer<T>&& other);
  ~SharedPointer();

  SharedPointer<T>& operator=(const SharedPointer<T>& other);

  T& operator*();
  T* operator->();

  void setCounter(RefCounter* counter);

  template <typename E>
  SharedPointer<E> dynamicCast();

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
SharedPointer<T>::SharedPointer(SharedPointer&& other)
    : m_pointer(other.m_pointer), m_counter(other.m_counter) {
  other.m_pointer = nullptr;
  other.m_counter = new RefCounter();
}

template <typename T>
SharedPointer<T>::~SharedPointer() {
  if (m_counter->dec() < 1) {
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

template <typename T>
void SharedPointer<T>::setCounter(RefCounter* counter) {
  delete m_counter;
  m_counter = counter;
}

template <typename T>
template <typename E>
SharedPointer<E> SharedPointer<T>::dynamicCast() {
  SharedPointer<E> cast_ptr(dynamic_cast<E*>(m_pointer));
  cast_ptr.setCounter(m_counter);
  m_counter->inc();
  return cast_ptr;
}

#endif  // __SHARED_POINTER_H__