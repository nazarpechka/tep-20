#include "array_utils.h"

#include <iostream>

void AllocArrayAdd5(int size) {
  if (size < 1) return;
  int* arr = new int[size];
  const int offset = 5;

  for (int i = 0; i < size; ++i) {
    arr[i] = i + offset;
  }

  PrintArray(&arr, size);

  delete[] arr;
}

// bool AllocArray2Dim(int ???piTable, int iSizeX, int iSizeY) {

// }

void PrintArray(int** arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << (*arr)[i] << " ";
  }
  std::cout << "\n";
}
