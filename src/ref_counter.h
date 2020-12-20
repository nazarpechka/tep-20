#ifndef __REF_COUNTER_H__
#define __REF_COUNTER_H__

class RefCounter {
 public:
  RefCounter();

  int inc();
  int dec();
  int get();

 private:
  int m_count;
};

#endif  // __REF_COUNTER_H__