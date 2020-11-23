#include "tree_dynamic.h"

#include <algorithm>
#include <iostream>
#include <iterator>

NodeDynamic::NodeDynamic() {
  val_ = 0;
  parent_ = NULL;
}

NodeDynamic::~NodeDynamic() {
  int size = children_.size();
  for (int i = 0; i < size; ++i) {
    delete children_[i];
  }
  // Remove 'this' from parent vector?
}

void NodeDynamic::SetValue(int new_val) { val_ = new_val; }

int NodeDynamic::GetChildrenNumber() const { return children_.size(); }

void NodeDynamic::SetParent(NodeDynamic* parent) { parent_ = parent; }

NodeDynamic* NodeDynamic::GetParent() const { return parent_; }

void NodeDynamic::AddNewChild() {
  NodeDynamic* child = new NodeDynamic();
  child->SetParent(this);
  children_.push_back(child);
}

NodeDynamic* NodeDynamic::GetChild(unsigned int offset) {
  return (offset < children_.size() ? children_[offset] : NULL);
}

bool NodeDynamic::MoveSubtree(NodeDynamic* new_child) {
  std::vector<NodeDynamic*>& parent_vector = new_child->parent_->children_;
  std::vector<NodeDynamic*>::iterator found =
      std::find(parent_vector.begin(), parent_vector.end(), new_child);
  if (found != parent_vector.end()) parent_vector.erase(found);

  children_.push_back(new_child);
}

void NodeDynamic::Print() const { std::cout << " " << val_; }

void NodeDynamic::PrintBelow() const {
  Print();
  for (size_t i = 0; i < children_.size(); ++i) {
    children_[i]->PrintBelow();
  }
}

TreeDynamic::TreeDynamic() { root = new NodeDynamic(); }

TreeDynamic::~TreeDynamic() { delete root; }

NodeDynamic* TreeDynamic::GetRoot() { return root; }

void TreeDynamic::PrintTree() {
  root->PrintBelow();
  std::cout << '\n';
}
