#include "table.h"

#include <iostream>

Table::Table() {
  const int default_size = 5;
  name_ = "default_table";
  std::cout << "bezp: '" << name_ << "'\n";
  table_ = new int[default_size];
  size_ = default_size;
}

Table::Table(const std::string &name, int size) {
  name_ = name;
  std::cout << "parametr: '" << name_ << "'\n";
  table_ = new int[size];
  size_ = size;
}

Table::Table(Table &other) {
  name_ = other.name_ + "_copy";
  std::cout << "kopiuj: '" << name_ << "'\n";
  table_ = new int[other.size_];
  size_ = other.size_;
  for (int i = 0; i < size_; ++i) {
    table_[i] = other.table_[i];
  }
}

Table::~Table() {
  std::cout << "usuwam: '" << name_ << "'\n";
  delete[] table_;
}

void Table::SetName(const std::string &name) { name_ = name; }

bool Table::SetNewSize(int size) {
  if (size <= size_) return false;
  int *new_table = new int[size];

  for (int i = 0; i < size_; ++i) {
    new_table[i] = table_[i];
  }

  delete[] table_;

  table_ = new_table;
  size_ = size;

  return true;
}

Table *Table::Clone() {
  Table *clone = new Table(*this);
  return clone;
}
