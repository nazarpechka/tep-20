#include <iostream>
#include <string>

#include "shared_pointer.h"
#include "table.h"

int main(void) {
// Przyklad na rozne operacje
#if 0
  std::cout << '\n';
  Table first("first_table", 3), second("second_table", 3), res;
  first.set(0, 1);
  first.set(1, 2);
  first.set(2, 3);

  second.set(0, 4);
  second.set(1, 5);
  second.set(2, 6);

  res = first + second;
  std::cout << res << '\n';

  std::cout << '\n';
  Table test("test", 3);
  test.set(0, 3);
  test.set(1, 4);
  test.set(2, 5);
  test[2] = 50;

  std::cout << test << '\n';
  test *= 2;
  std::cout << test << '\n';

  std::cout << '\n';

  Table test2;
  test2 = test * 2;
  std::cout << test2 << '\n';
#endif

// Przyklad z move semantics w operatorze +
#if 1
  Table tab1("table1", 3);

  tab1.set(0, 1);
  tab1.set(1, 2);
  tab1.set(2, 3);
  std::cout << "Tab1 = " << tab1 << "\n\n";

  Table tab2("table2", 3);
  tab2.set(2, 1);
  tab2.set(1, 2);
  tab2.set(0, 3);
  std::cout << "Tab2 = " << tab2 << "\n\n";

  Table concat(tab1 + tab2);
  std::cout << "\nConcat table = " << concat << "\n\n";

  tab2 = std::move(tab1);
  std::cout << "tab1 after move = " << tab1 << '\n';
  std::cout << "tab2 after move = " << tab2 << '\n';
#endif

// Przyklad z zaalokowaną statycznie pamięcią
#if 0
  {
    std::string str = "Hello";
    SharedPointer<std::string> ptr(&str);
    std::cout << *ptr << '\n';
  } // Pointer being freed was not allocated
#endif

  return 0;
}
