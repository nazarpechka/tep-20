#include <iostream>

#include "array_utils.h"

int main(void) {
  allocArrayAdd5(5);

  int** dim_array = NULL;
  if (allocArray2Dim(&dim_array, 2, 2)) {
    std::cout << dim_array;

    dim_array[0][0] = 0;
    dim_array[0][1] = 1;
    dim_array[1][0] = 2;
    dim_array[1][1] = 3;

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        std::cout << "\n" << dim_array[i][j] << " ";
      }
      std::cout << "\n";
    }
  }
  return 0;
}