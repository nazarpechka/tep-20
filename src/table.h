#ifndef _SRC_TABLE_H_
#define _SRC_TABLE_H_

#include <string>

class Table {
 public:
  Table();

  Table(const std::string &name, int size);
  Table(std::string &&name, int size);

  Table(const Table &other);
  Table(Table &&other);

  ~Table();

  Table &operator=(const Table &other);
  Table &operator=(Table &&other);
  Table &operator*=(const int num);

  Table operator+(const Table &other) const;
  Table operator*(const int num) const;
  bool operator==(const Table &other) const;
  bool operator!=(const Table &other) const;
  int &operator[](int index) const;

  void setName(const std::string &name);
  void setName(std::string &&name);
  const std::string &getName() const;
  bool setSize(int new_size);
  int getSize() const;
  void set(int index, int val);
  int get(int index) const;
  void print() const;
  void multiply(int num);

  friend std::ostream &operator<<(std::ostream &stream, const Table &other);

 private:
  static const std::string DEFAULT_NAME;
  static const int DEFAULT_SIZE;

  std::string m_name;
  int m_size;
  int *m_array;

  void copy(const Table &other);
  void move(Table &&other);
};

#endif
