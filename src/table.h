#ifndef _SRC_TABLE_H_
#define _SRC_TABLE_H_

#include <string>

class Table {
 public:
  Table();
  Table(const std::string &name, int size);
  void operator=(const Table &other);
  Table(Table &other);
  ~Table();

  void SetName(const std::string &name);
  const std::string &GetName() const;
  bool SetSize(int new_size);
  int GetSize() const;
  void SetValueAt(int index, int val);
  void Print() const;
  Table *Clone();

 private:
  static const std::string kDefaultName;
  static const int kDefaultSize;

  std::string name_;
  int *table_;
  int size_;
};

#endif
