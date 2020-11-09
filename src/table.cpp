#include "table.h"

#include <iostream>

const std::string Table::kDefaultName = "default_table";
const int Table::kDefaultSize = 5;

Table::Table() {
  name_ = kDefaultName;
  std::cout << "bezp: '" << name_ << "'\n";

  size_ = kDefaultSize;
  table_ = new int[size_];
}

Table::Table(const std::string &name, int size) {
  name_ = name;
  std::cout << "parametr: '" << name_ << "'\n";

  size_ = size;
  table_ = new int[size_];
}

Table::Table(Table &other) {
  name_ = other.name_ + "_copy";
  std::cout << "kopiuj: '" << name_ << "'\n";

  size_ = other.size_;
  table_ = new int[size_];
  memcpy(table_, other.table_, size_ * sizeof(int));
}

void Table::operator=(const Table &other) {
  name_ = other.name_;
  std::cout << "operator=: '" << name_ << "'\n";

  size_ = other.size_;
  delete[] table_;
  table_ = new int[size_];
  memcpy(table_, other.table_, size_ * sizeof(int));
}

Table::~Table() {
  std::cout << "usuwam: '" << name_ << "'\n";
  delete[] table_;
}

void Table::SetName(const std::string &name) { name_ = name; }

const std::string &Table::GetName() const { return name_; }

bool Table::SetSize(int new_size) {
  if (new_size <= size_) return false;
  int *new_table = new int[new_size];

  memcpy(new_table, table_, size_ * sizeof(int));

  delete[] table_;

  table_ = new_table;
  size_ = new_size;

  return true;
}

int Table::GetSize() const { return size_; }

void Table::Print() const {
  for (int i = 0; i < size_; ++i) {
    std::cout << table_[i] << " ";
  }
  std::cout << '\n';
}

void Table::SetValueAt(int index, int val) {
  if (index > -1 && index < size_) {
    table_[index] = val;
  }
}

Table *Table::Clone() {
  Table *clone = new Table(*this);
  clone->SetName(name_);
  return clone;
}
