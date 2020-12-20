#include "ref_counter.h"

RefCounter::RefCounter() : m_count(0) {}

int RefCounter::inc() { return ++m_count; }

int RefCounter::dec() { return --m_count; }

int RefCounter::get() { return m_count; }
