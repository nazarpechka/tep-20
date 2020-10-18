#include "array_utils.h"

#include <iostream>

void allocArrayAdd5(int size) {
  if (size < 1) return;
  int* arr = new int[size];
  const int offset = 5;

  for (int i = 0; i < size; ++i) {
    arr[i] = i + offset;
  }

  printArray(&arr, size);

  delete[] arr;
}

bool allocArray2Dim(int*** array, int size_x, int size_y) {
  *array = new int*[size_x];

  if (*array == NULL) return false;

  for (int i = 0; i < size_x; ++i) {
    (*array)[i] = new int[size_y];
    if ((*array)[i] == NULL) return false;
  }

  return true;
}

void printArray(int** array, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << (*array)[i] << " ";
  }
  std::cout << "\n";
}
