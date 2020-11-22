#include "table.h"

#include <iostream>

const std::string Table::kDefaultName = "default_table";
const int Table::kDefaultSize = 5;

std::ostream &operator<<(std::ostream &stream, const Table &other) {
  for (int i = 0; i < other.size_; ++i) {
    stream << other.array_[i] << ' ';
  }
  return stream;
}

std::istream &operator>>(std::istream &stream, const Table &other) {
  for (int i = 0; i < other.size_; ++i) {
    stream >> other.array_[i];
  }
  return stream;
}

Table::Table() {
  name_ = kDefaultName;
  std::cout << "bezp: '" << name_ << "'\n";

  size_ = kDefaultSize;
  array_ = new int[size_];
}

Table::Table(const std::string &name, int size) {
  name_ = name;
  std::cout << "parametr: '" << name_ << "'\n";

  size_ = size > 0 ? size : kDefaultSize;
  array_ = new int[size_];
}

Table::Table(Table &other) {
  name_ = other.name_ + "_copy";
  std::cout << "kopiuj: '" << name_ << "'\n";

  size_ = other.size_;
  array_ = new int[size_];
  memcpy(array_, other.array_, size_ * sizeof(int));
}

Table::~Table() {
  std::cout << "usuwam: '" << name_ << "'\n";
  delete[] array_;
}

Table &Table::operator=(const Table &other) {
  if (&other == this) return *this;
  name_ = other.name_;
  std::cout << "operator=: '" << name_ << "'\n";

  size_ = other.size_;
  delete[] array_;
  array_ = new int[size_];
  memcpy(array_, other.array_, size_ * sizeof(int));

  return *this;
}

Table &Table::operator*=(const int num) {
  MultiplyBy(num);
  return *this;
}

Table Table::operator+(const Table &other) const {
  Table result(name_ + " + " + other.name_, size_ + other.size_);
  memcpy(result.array_, array_, size_ * sizeof(int));
  memcpy(&result.array_[size_], other.array_, other.size_ * sizeof(int));
  return result;
}

Table Table::operator*(const int num) {
  Table result(*this);
  result.MultiplyBy(num);
  return result;
}

bool Table::operator==(const Table &other) const {
  if (size_ != other.size_) return false;
  for (int i = 0; i < size_; ++i) {
    if (array_[i] != other.array_[i]) return false;
  }
  return true;
}

bool Table::operator!=(const Table &other) const {
  if (*this == other) return false;
  return true;
}

int &Table::operator[](int index) const { return array_[index]; }

void Table::SetName(const std::string &name) { name_ = name; }

const std::string &Table::GetName() const { return name_; }

bool Table::SetSize(int new_size) {
  if (new_size <= size_) return false;
  int *new_array = new int[new_size];

  memcpy(new_array, array_, size_ * sizeof(int));

  delete[] array_;

  array_ = new_array;
  size_ = new_size;

  return true;
}

int Table::GetSize() const { return size_; }

void Table::Print() const {
  for (int i = 0; i < size_; ++i) {
    std::cout << array_[i] << " ";
  }
  std::cout << '\n';
}

void Table::MultiplyBy(int num) {
  for (int i = 0; i < size_; ++i) {
    array_[i] = array_[i] * num;
  }
}

void Table::SetValueAt(int index, int val) {
  if (index > -1 && index < size_) {
    array_[index] = val;
  }
}

int Table::GetValueAt(int index) { return operator[](index); }

Table *Table::Clone() {
  Table *clone = new Table(*this);
  clone->SetName(name_);
  return clone;
}
