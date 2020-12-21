#include "table.h"

#include <iostream>

const std::string Table::DEFAULT_NAME = "Default table";
const int Table::DEFAULT_SIZE = 5;

std::ostream &operator<<(std::ostream &stream, const Table &other) {
  for (int i = 0; i < other.m_size; ++i) {
    stream << other.m_array[i] << ' ';
  }
  return stream;
}

Table::Table()
    : m_name(DEFAULT_NAME), m_size(DEFAULT_SIZE), m_array(new int[m_size]) {
  std::cout << "bezp: " << m_name << "\n";
}

Table::Table(const std::string &name, int size)
    : m_name(name),
      m_size(size > 0 ? size : DEFAULT_SIZE),
      m_array(new int[m_size]) {
  std::cout << "parametr: " << m_name << "\n";
}

Table::Table(std::string &&name, int size)
    : m_name(std::move(name)),
      m_size(size > 0 ? size : DEFAULT_SIZE),
      m_array(new int[m_size]) {
  std::cout << "parametr (rvalue string): " << m_name << "\n";
}

Table::Table(const Table &other) {
  std::cout << "kopiuj: " << other.m_name + " (copy)"
            << "\n";
  copy(other);
}

Table::Table(Table &&other) {
  std::cout << "przenoszacy: " << other.m_name + " (moved)"
            << "\n";

  move(std::move(other));
}

Table::~Table() {
  std::cout << "usuwam: " << m_name << "\n";
  delete[] m_array;
}

Table &Table::operator=(const Table &other) {
  std::cout << "operator=: " << other.m_name + " (copy)"
            << "\n";

  if (this != &other) {
    delete[] m_array;
    m_array = nullptr;  // exception safety
    m_size = 0;

    copy(other);
  }

  return *this;
}

Table &Table::operator=(Table &&other) {
  std::cout << "operator= (przenoszacy): " << other.m_name + " (moved)"
            << "\n";

  if (this != &other) {
    move(std::move(other));
  }

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

Table Table::operator*(const int num) const {
  Table result(*this);
  result.multiply(num);
  return result;
}

bool Table::operator==(const Table &other) const {
  if (this != &other) {
    if (m_size != other.m_size) return false;
    for (int i = 0; i < m_size; ++i) {
      if (m_array[i] != other.m_array[i]) return false;
    }
  }
  return true;
}

bool Table::operator!=(const Table &other) const { return !(*this == other); }

int &Table::operator[](int index) const { return m_array[index]; }

void Table::setName(const std::string &name) { m_name = name; }

void Table::setName(std::string &&name) { m_name = std::move(name); }

const std::string &Table::getName() const { return m_name; }

bool Table::setSize(int new_size) {
  if (new_size <= m_size) return false;
  int *new_array = new int[new_size];

  std::copy(m_array, m_array + m_size, new_array);

  delete[] m_array;

  m_array = new_array;
  m_size = new_size;

  return true;
}

int Table::getSize() const { return m_size; }

void Table::print() const {
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

int Table::get(int index) const { return operator[](index); }

void Table::copy(const Table &other) {
  m_name = other.m_name + " (copy)";
  m_size = other.m_size;
  m_array = new int[other.m_size];

  std::copy(other.m_array, other.m_array + other.m_size, m_array);
}

void Table::move(Table &&other) {
  m_name = other.m_name + " (moved)";
  m_size = other.m_size;
  m_array = other.m_array;

  other.m_name = "";
  other.m_size = 0;
  other.m_array = nullptr;
}
