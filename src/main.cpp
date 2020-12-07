#include <iostream>

#include "tree_dynamic.h"

void TestTree() {
  std::cout << "Example trees:\n";
  /*
            5
        1      2
      11 12  21 22
  */
  TreeDynamic<int> tree;

  tree.GetRoot()->SetValue(5);

  tree.GetRoot()->AddChild(1);
  tree.GetRoot()->AddChild(2);

  tree.GetRoot()->GetChild(0)->AddChild(11);
  tree.GetRoot()->GetChild(0)->AddChild(12);

  tree.GetRoot()->GetChild(1)->AddChild(21);
  tree.GetRoot()->GetChild(1)->AddChild(22);

  tree.PrintTree();
  std::cout << '\n';

  TreeDynamic<std::string> second_tree;

  second_tree.GetRoot()->AddChild("Hello");
  second_tree.GetRoot()->AddChild("World");

  second_tree.GetRoot()->GetChild(0)->AddChild("123");

  second_tree.PrintTree();

  std::cout << '\n';
}

int main(void) { TestTree(); }