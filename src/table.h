#ifndef _SRC_TABLE_H_
#define _SRC_TABLE_H_

#include <string>

class Table {
 private:
  static const std::string kDefaultName;
  static const int kDefaultSize;

  std::string name_;
  int *table_;
  int size_;

 public:
  Table();
  Table(const std::string &name, int size);
  Table(Table &other);
  ~Table();

  void SetName(const std::string &name);
  const std::string &GetName() const;
  bool SetNewSize(int new_size);
  int GetSize() const;
  Table *Clone();
};

#endif
