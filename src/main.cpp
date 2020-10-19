#include <iostream>

#include "table_utils.h"

int main(void) {
  // Zadanie 1
  AllocTableAdd5(10);

  // Zadanie 2
  const int kSizeX = 2, ksizeY = 3;
  int **table_2dim = NULL;
  if (AllocTable2Dim(table_2dim, kSizeX, ksizeY)) {
    table_2dim[0][0] = 0;
    table_2dim[0][1] = 1;
    table_2dim[0][2] = 2;

    table_2dim[1][0] = 3;
    table_2dim[1][1] = 4;
    table_2dim[1][2] = 5;

    PrintTable2Dim(table_2dim, kSizeX, ksizeY);

    DeallocTable2Dim(table_2dim, kSizeX, ksizeY);
  }

  return 0;
}