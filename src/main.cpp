#include <iostream>
#include <string>

#include "shared_pointer.h"
#include "table.h"

int main(void) {
  // Zadanie 1
  // Table tab0, tab1;
  // tab0.SetSize(6);
  // tab1.SetSize(10);
  // tab0 = tab1;
  // Dwie tablicy mają wskaznik na tą samą pamięć
  // Destruktor pierwszej tablicy zwolni pamięc
  // Destruktor drugiej tablicy spowoduje exception

  // Zadanie 2
  // Wyjątku nie biędzie ale będzie memory leak 2 tablic

  // Zadanie 3
  // std::cout << '\n';
  // Table tab2("tab2", 6), tab3("tab3", 4);
  // tab2.SetValueAt(0, 1);
  // tab2.SetValueAt(1, 2);
  // tab2.SetValueAt(2, 3);
  // tab2.SetValueAt(3, 4);
  // tab2.SetValueAt(4, 5);
  // tab2.SetValueAt(5, 6);

  // tab3.SetValueAt(0, 51);
  // tab3.SetValueAt(1, 52);
  // tab3.SetValueAt(2, 53);
  // tab3.SetValueAt(3, 54);

  // tab2 = tab3;
  // tab3.SetValueAt(2, 123);

  // std::cout << tab2 << '\n';
  // std::cout << tab3 << '\n';

  // Zadanie 4
  // std::cout << '\n';
  // Table first("first_table", 3), second("second_table", 3), res;
  // first.SetValueAt(0, 1);
  // first.SetValueAt(1, 2);
  // first.SetValueAt(2, 3);

  // second.SetValueAt(0, 4);
  // second.SetValueAt(1, 5);
  // second.SetValueAt(2, 6);

  // res = first + second;
  // std::cout << res << '\n';

  // std::cout << '\n';
  // Table test("test", 3);
  // test.SetValueAt(0, 3);
  // test.SetValueAt(1, 4);
  // test.SetValueAt(2, 5);
  // test[2] = 5;

  // std::cout << test << '\n';
  // test *= 2;
  // std::cout << test << '\n';

  // std::cout << '\n';

  // Table test2;
  // test2 = test * 2;
  // std::cout << test2 << '\n';
  std::string str = "Nazar";
  SharedPointer<std::string> strpoint = &str;
  std::cout << *strpoint;

  return 0;
}
