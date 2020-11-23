#include <iostream>

#include "tree_dynamic.h"
#include "tree_static.h"

void TestTree() {
  /*
            0
        1      2
      11 12  21 22
  */
  TreeDynamic tree;

  tree.GetRoot()->AddNewChild();
  tree.GetRoot()->AddNewChild();

  tree.GetRoot()->GetChild(0)->SetValue(1);
  tree.GetRoot()->GetChild(1)->SetValue(2);

  tree.GetRoot()->GetChild(0)->AddNewChild();
  tree.GetRoot()->GetChild(0)->AddNewChild();

  tree.GetRoot()->GetChild(0)->GetChild(0)->SetValue(11);
  tree.GetRoot()->GetChild(0)->GetChild(1)->SetValue(12);

  tree.GetRoot()->GetChild(1)->AddNewChild();
  tree.GetRoot()->GetChild(1)->AddNewChild();

  tree.GetRoot()->GetChild(1)->GetChild(0)->SetValue(21);
  tree.GetRoot()->GetChild(1)->GetChild(1)->SetValue(22);

  // tree.GetRoot()->GetChild(0)->GetChild(1)->PrintUp();

  std::cout << '\n';
  tree.PrintTree();
}

void TestMoving() {
  std::cout << "Before moving: \n";
  TreeDynamic first_tree;

  first_tree.GetRoot()->AddNewChild();
  first_tree.GetRoot()->AddNewChild();
  first_tree.GetRoot()->AddNewChild();

  first_tree.GetRoot()->GetChild(0)->SetValue(1);
  first_tree.GetRoot()->GetChild(1)->SetValue(2);
  first_tree.GetRoot()->GetChild(2)->SetValue(3);

  first_tree.GetRoot()->GetChild(2)->AddNewChild();
  first_tree.GetRoot()->GetChild(2)->GetChild(0)->SetValue(4);

  first_tree.PrintTree();

  TreeDynamic second_tree;

  second_tree.GetRoot()->SetValue(50);

  second_tree.GetRoot()->AddNewChild();
  second_tree.GetRoot()->AddNewChild();

  second_tree.GetRoot()->GetChild(0)->SetValue(54);
  second_tree.GetRoot()->GetChild(1)->SetValue(55);

  second_tree.GetRoot()->GetChild(0)->AddNewChild();
  second_tree.GetRoot()->GetChild(0)->AddNewChild();

  second_tree.GetRoot()->GetChild(0)->GetChild(0)->SetValue(56);
  second_tree.GetRoot()->GetChild(0)->GetChild(1)->SetValue(57);

  second_tree.GetRoot()->GetChild(0)->GetChild(0)->AddNewChild();

  second_tree.GetRoot()->GetChild(0)->GetChild(0)->GetChild(0)->SetValue(58);

  second_tree.PrintTree();

  NodeDynamic* parent = first_tree.GetRoot()->GetChild(2);
  NodeDynamic* child = second_tree.GetRoot()->GetChild(0);

  parent->MoveSubtree(child);

  std::cout << "After moving:\n";
  first_tree.PrintTree();
  second_tree.PrintTree();
}

int main(void) { TestMoving(); }