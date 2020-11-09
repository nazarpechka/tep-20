#include <iostream>

#include "table.h"
#include "table_utils.h"

int main(void) {
  // Zadanie 1
  // Table tab0, tab1;
  // tab0.SetNewSize(6);
  // tab1.SetNewSize(4);
  // tab0 = tab1;
  // Dwie tablicy mają wskaznik na tą samą pamięć
  // Destruktor pierwszej tablicy zwolni pamięc
  // Destruktor drugiej tablicy spowoduje exception

  // Zadanie 2
  // Wyjątku nie biędzie ale będzie memory leak 2 tablic

  // Zadanie 3
  Table tab2("tab2", 6), tab3("tab3", 4);
  tab2.SetValueAt(0, 1);
  tab2.SetValueAt(1, 2);
  tab2.SetValueAt(2, 3);
  tab2.SetValueAt(3, 4);
  tab2.SetValueAt(4, 5);
  tab2.SetValueAt(5, 6);

  tab3.SetValueAt(0, 51);
  tab3.SetValueAt(1, 52);
  tab3.SetValueAt(2, 53);
  tab3.SetValueAt(3, 54);

  tab2 = tab3;
  tab3.SetValueAt(2, 123);

  tab2.Print();
  tab3.Print();

  return 0;
}
