#ifndef _SRC_TABLE_H_
#define _SRC_TABLE_H_

#include <string>

class Table {
 private:
  std::string name_;
  int *table_;
  int size_;

 public:
  Table();
  Table(const std::string &name, int size);
  Table(Table &other);
  ~Table();

  void SetName(const std::string &name);
  bool SetNewSize(int size);
  Table *Clone();
};

#endif