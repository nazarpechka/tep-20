#include "table.h"

#include <iostream>

Table::Table() {
  const int kDefaultSize = 5;
  const std::string kDefaultName = "default_table";

  name_ = kDefaultName;
  std::cout << "bezp: '" << name_ << "'\n";

  size_ = kDefaultSize;
  table_ = new int[size_];
}

Table::Table(const std::string &name, int size) {
  name_ = name;
  std::cout << "parametr: '" << name_ << "'\n";

  size_ = size;
  table_ = new int[size];
}

Table::Table(Table &other) {
  name_ = other.name_ + "_copy";
  std::cout << "kopiuj: '" << name_ << "'\n";

  size_ = other.size_;
  table_ = new int[size_];
  for (int i = 0; i < size_; ++i) {
    table_[i] = other.table_[i];
  }
}

Table::~Table() {
  std::cout << "usuwam: '" << name_ << "'\n";
  delete[] table_;
}

void Table::SetName(const std::string &name) { name_ = name; }

std::string Table::GetName() { return name_; }

bool Table::SetNewSize(int new_size) {
  if (new_size <= size_) return false;
  int *new_table = new int[new_size];

  for (int i = 0; i < size_; ++i) {
    new_table[i] = table_[i];
  }

  delete[] table_;

  table_ = new_table;
  size_ = new_size;

  return true;
}

int Table::GetSize() { return size_; }

Table *Table::Clone() {
  Table *clone = new Table(*this);
  clone->SetName(name_);
  return clone;
}
