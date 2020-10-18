#ifndef SRC_ARRAYUTILS_H_
#define SRC_ARRAYUTILS_H_

void allocTableAdd5(int size);
bool allocTable2Dim(int*** table, int size_x, int size_y);
bool deallocTable2Dim(int*** table, int size_x, int size_y);
void printTable(int** table, int size);

#endif