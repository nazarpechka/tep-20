#include "table_utils.h"

#include <iostream>

void AllocTableAdd5(int size) {
  if (size < 1) return;

  const int kAddValue = 5;
  int *table = new int[size];

  for (int i = 0; i < size; ++i) {
    table[i] = i + kAddValue;
  }

  PrintTable(table, size);

  delete[] table;
}

// We can also only with pointers - int ***table, then dereference to use
bool AllocTable2Dim(int **&table, int size_x, int size_y) {
  table = new int *[size_x];

  if (table == NULL) return false;

  for (int i = 0; i < size_x; ++i) {
    table[i] = new int[size_y];
    if (table[i] == NULL) return false;
  }

  return true;
}

// We don't need size_y for deallocation process
bool DeallocTable2Dim(int **&table, int size_x, int size_y) {
  if (table == NULL) return false;

  for (int i = 0; i < size_x; ++i) {
    if (table[i] == NULL) return false;
    delete[] table[i];
    table[i] = NULL;
  }

  delete[] table;
  table = NULL;
  return true;
}

void PrintTable(int table[], int size) {
  std::cout << '\n';
  for (int i = 0; i < size; ++i) {
    std::cout << table[i] << ' ';
  }
  std::cout << '\n';
}

void PrintTable2Dim(int *table[], int size_x, int size_y) {
  std::cout << '\n';
  for (int i = 0; i < size_x; ++i) {
    for (int j = 0; j < size_y; ++j) {
      std::cout << table[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void ModifyTable(Table *table, int new_size) { table->SetNewSize(new_size); }

void ModifyTable(Table table, int new_size) { table.SetNewSize(new_size); }
