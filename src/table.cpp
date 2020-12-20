#include "table.h"

#include <iostream>

const std::string Table::DEFAULT_NAME = "default_table";
const int Table::DEFAULT_SIZE = 5;

std::ostream &operator<<(std::ostream &stream, const Table &other) {
  for (int i = 0; i < other.m_size; ++i) {
    stream << other.m_array[i] << ' ';
  }
  return stream;
}

std::istream &operator>>(std::istream &stream, const Table &other) {
  for (int i = 0; i < other.m_size; ++i) {
    stream >> other.m_array[i];
  }
  return stream;
}

Table::Table() {
  m_name = DEFAULT_NAME;
  std::cout << "bezp: '" << m_name << "'\n";

  m_size = DEFAULT_SIZE;
  m_array = new int[m_size];
}

Table::Table(const std::string &name, int size) {
  m_name = name;
  std::cout << "parametr: '" << m_name << "'\n";

  m_size = size > 0 ? size : DEFAULT_SIZE;
  m_array = new int[m_size];
}

Table::Table(Table &other) {
  m_name = other.m_name + "_copy";
  std::cout << "kopiuj: '" << m_name << "'\n";

  m_size = other.m_size;
  m_array = new int[m_size];
  memcpy(m_array, other.m_array, m_size * sizeof(int));
}

Table::~Table() {
  std::cout << "usuwam: '" << m_name << "'\n";
  delete[] m_array;
}

Table &Table::operator=(const Table &other) {
  if (&other == this) return *this;
  m_name = other.m_name;
  std::cout << "operator=: '" << m_name << "'\n";

  m_size = other.m_size;
  delete[] m_array;
  m_array = new int[m_size];
  memcpy(m_array, other.m_array, m_size * sizeof(int));

  return *this;
}

Table &Table::operator*=(const int num) {
  multiply(num);
  return *this;
}

Table Table::operator+(const Table &other) const {
  Table result(m_name + " + " + other.m_name, m_size + other.m_size);
  memcpy(result.m_array, m_array, m_size * sizeof(int));
  memcpy(&result.m_array[m_size], other.m_array, other.m_size * sizeof(int));
  return result;
}

Table Table::operator*(const int num) {
  Table result(*this);
  result.multiply(num);
  return result;
}

bool Table::operator==(const Table &other) const {
  if (m_size != other.m_size) return false;
  for (int i = 0; i < m_size; ++i) {
    if (m_array[i] != other.m_array[i]) return false;
  }
  return true;
}

bool Table::operator!=(const Table &other) const {
  if (*this == other) return false;
  return true;
}

int &Table::operator[](int index) const { return m_array[index]; }

void Table::setName(const std::string &name) { m_name = name; }

const std::string &Table::getName() const { return m_name; }

bool Table::setSize(int new_size) {
  if (new_size <= m_size) return false;
  int *new_array = new int[new_size];

  memcpy(new_array, m_array, m_size * sizeof(int));

  delete[] m_array;

  m_array = new_array;
  m_size = new_size;

  return true;
}

int Table::getSize() const { return m_size; }

void Table::Print() const {
  for (int i = 0; i < m_size; ++i) {
    std::cout << m_array[i] << " ";
  }
  std::cout << '\n';
}

void Table::multiply(int num) {
  for (int i = 0; i < m_size; ++i) {
    m_array[i] = m_array[i] * num;
  }
}

void Table::set(int index, int val) {
  if (index > -1 && index < m_size) {
    m_array[index] = val;
  }
}

int Table::get(int index) { return operator[](index); }

Table *Table::Clone() {
  Table *clone = new Table(*this);
  clone->setName(m_name);
  return clone;
}
