#ifndef _SRC_TABLE_H_
#define _SRC_TABLE_H_

#include <string>

class Table {
 public:
  Table();
  Table(const std::string &name, int size);
  Table(Table &other);
  ~Table();

  friend std::ostream &operator<<(std::ostream &stream, const Table &other);
  friend std::istream &operator>>(std::istream &stream, const Table &other);
  Table &operator=(const Table &other);
  Table &operator*=(const int num);
  Table operator+(const Table &other) const;
  Table operator*(const int num);
  bool operator==(const Table &other) const;
  bool operator!=(const Table &other) const;
  int &operator[](int index) const;

  void SetName(const std::string &name);
  const std::string &GetName() const;
  bool SetSize(int new_size);
  int GetSize() const;
  void SetValueAt(int index, int val);
  int GetValueAt(int index);
  void Print() const;
  void MultiplyBy(int num);
  Table *Clone();

 private:
  static const std::string kDefaultName;
  static const int kDefaultSize;

  std::string name_;
  int *array_;
  int size_;
};

#endif
