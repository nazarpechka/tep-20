#include <iostream>

#include "tree_dynamic.h"

void TestTree() {
  std::cout << "Example trees:\n";
  /*
            0
        1      2
      11 12  21 22
  */
  TreeDynamic<int> tree;

  tree.GetRoot()->AddChild();
  tree.GetRoot()->AddChild();

  tree.GetRoot()->GetChild(0)->SetValue(1);
  tree.GetRoot()->GetChild(1)->SetValue(2);

  tree.GetRoot()->GetChild(0)->AddChild();
  tree.GetRoot()->GetChild(0)->AddChild();

  tree.GetRoot()->GetChild(0)->GetChild(0)->SetValue(11);
  tree.GetRoot()->GetChild(0)->GetChild(1)->SetValue(12);

  tree.GetRoot()->GetChild(1)->AddChild();
  tree.GetRoot()->GetChild(1)->AddChild();

  tree.GetRoot()->GetChild(1)->GetChild(0)->SetValue(21);
  tree.GetRoot()->GetChild(1)->GetChild(1)->SetValue(22);

  tree.PrintTree();
  std::cout << '\n';

  TreeDynamic<std::string> second_tree;

  second_tree.GetRoot()->AddChild();
  second_tree.GetRoot()->AddChild();

  second_tree.GetRoot()->GetChild(0)->SetValue("Hello");
  second_tree.GetRoot()->GetChild(1)->SetValue("World");

  second_tree.GetRoot()->GetChild(0)->AddChild();
  second_tree.GetRoot()->GetChild(0)->GetChild(0)->SetValue("123");

  second_tree.PrintTree();
  std::cout << '\n';
}

int main(void) { TestTree(); }