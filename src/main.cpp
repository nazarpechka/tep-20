#include <iostream>

#include "tree_dynamic.h"
#include "tree_static.h"

#define CURR_TREE TreeDynamic

void TestTree() {
  std::cout << "Example tree:\n";
  /*
            0
        1      2
      11 12  21 22
  */
  CURR_TREE tree;

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
}

void TestMoving() {
  std::cout << "Before moving: \n";
  CURR_TREE first_tree;

  first_tree.GetRoot()->AddChild();
  first_tree.GetRoot()->AddChild();
  first_tree.GetRoot()->AddChild();

  first_tree.GetRoot()->GetChild(0)->SetValue(1);
  first_tree.GetRoot()->GetChild(1)->SetValue(2);
  first_tree.GetRoot()->GetChild(2)->SetValue(3);

  first_tree.GetRoot()->GetChild(2)->AddChild();
  first_tree.GetRoot()->GetChild(2)->GetChild(0)->SetValue(4);

  first_tree.PrintTree();

  CURR_TREE second_tree;

  second_tree.GetRoot()->SetValue(50);

  second_tree.GetRoot()->AddChild();
  second_tree.GetRoot()->AddChild();

  second_tree.GetRoot()->GetChild(0)->SetValue(54);
  second_tree.GetRoot()->GetChild(1)->SetValue(55);

  second_tree.GetRoot()->GetChild(0)->AddChild();
  second_tree.GetRoot()->GetChild(0)->AddChild();

  second_tree.GetRoot()->GetChild(0)->GetChild(0)->SetValue(56);
  second_tree.GetRoot()->GetChild(0)->GetChild(1)->SetValue(57);

  second_tree.GetRoot()->GetChild(0)->GetChild(0)->AddChild();

  second_tree.GetRoot()->GetChild(0)->GetChild(0)->GetChild(0)->SetValue(58);

  second_tree.PrintTree();

  first_tree.GetRoot()->GetChild(2)->MoveSubtree(second_tree.GetRoot());

  std::cout << "After moving:\n";
  first_tree.PrintTree();
  second_tree.PrintTree();

  std::cout << "From bottom to top:\n";
  first_tree.GetRoot()->GetChild(2)->GetChild(1)->GetChild(1)->PrintUp();
  second_tree.GetRoot()->PrintUp();
}

int main(void) {
  TestTree();
  TestMoving();
}