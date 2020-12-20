#ifndef _SRC_TABLE_H_
#define _SRC_TABLE_H_

#include <string>

class Table {
 public:
  Table();
  Table(const std::string &name, int size);
  Table(const Table &other);
  Table(Table &&other);
  ~Table();

  friend std::ostream &operator<<(std::ostream &stream, const Table &other);
  friend std::istream &operator>>(std::istream &stream, const Table &other);

  Table &operator=(const Table &other);
  Table &operator=(Table &&other);
  Table &operator*=(const int num);
  Table operator+(const Table &other) const;
  Table operator*(const int num);
  bool operator==(const Table &other) const;
  bool operator!=(const Table &other) const;
  int &operator[](int index) const;

  void setName(const std::string &name);
  const std::string &getName() const;
  bool setSize(int new_size);
  int getSize() const;
  void set(int index, int val);
  int get(int index);
  void Print() const;
  void multiply(int num);
  Table *Clone();

 private:
  static const std::string DEFAULT_NAME;
  static const int DEFAULT_SIZE;

  std::string m_name;
  int *m_array;
  int m_size;
};

#endif
