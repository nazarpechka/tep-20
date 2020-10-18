#ifndef _SRC_TABLE_H_
#define _SRC_TABLE_H_

#include <string>

class Table {
 private:
  std::string m_name;

 public:
  Table();
  Table(const std::string &name, int length);
  Table(Table &other);
  ~Table();

  void setName(const std::string &name);
  bool setNewSize(int length);
  Table *clone();
};

#endif