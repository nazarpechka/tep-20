#ifndef SRC_TABLEUTILS_H_
#define SRC_TABLEUTILS_H_

void AllocTableAdd5(int size);
bool AllocTable2Dim(int**& table, int size_x, int size_y);
bool DeallocTable2Dim(int**& table, int size_x, int size_y);
void PrintTable(int table[], int size);
void PrintTable2Dim(int* table[], int size_x, int size_y);

#endif