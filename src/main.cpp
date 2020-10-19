#include <iostream>

#include "table.h"
#include "table_utils.h"

int main(void) {
  // Zadanie 1
  AllocTableAdd5(10);

  // Zadanie 2 i 3
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

  // Zadanie 4
  {
    Table stat_tab("static_table", 10);
    Table *dyn_tab = new Table("dynamic_table", 10);

    ModifyTable(stat_tab, 15);  // Copies the object
    std::cout << stat_tab.GetName() << " size = " << stat_tab.GetSize() << '\n';

    ModifyTable(&stat_tab, 15);  // Works on a pointer
    std::cout << stat_tab.GetName() << " size = " << stat_tab.GetSize() << '\n';

    Table *clone_tab = dyn_tab->Clone();
    assert(clone_tab->GetName() == dyn_tab->GetName());
    assert(clone_tab->GetSize() == dyn_tab->GetSize());

    delete dyn_tab;
  }

  return 0;
}
