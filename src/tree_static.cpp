#include "tree_static.h"

#include <iostream>

NodeStatic::NodeStatic() {
  val_ = 0;
  parent_ = NULL;
}

NodeStatic::~NodeStatic() {
  // Remove 'this' from parent vector?
}

void NodeStatic::SetValue(int new_val) { val_ = new_val; }

int NodeStatic::GetChildrenNumber() const { return children_.size(); }

void NodeStatic::SetParent(NodeStatic* parent) { parent_ = parent; }

NodeStatic* NodeStatic::GetParent() const { return parent_; }

void NodeStatic::AddNewChild() {
  NodeStatic child;
  child.SetParent(this);
  children_.push_back(child);
}

NodeStatic* NodeStatic::GetChild(unsigned int offset) {
  return (offset < children_.size() ? &children_[offset] : NULL);
}

void NodeStatic::Print() const { std::cout << " " << val_; }

void NodeStatic::PrintUp() const {
  Print();
  if (parent_ != NULL) parent_->PrintUp();
}

void NodeStatic::PrintBelow() const {
  Print();
  for (size_t i = 0; i < children_.size(); ++i) {
    children_[i].PrintBelow();
  }
}

TreeStatic::TreeStatic() {}

TreeStatic::~TreeStatic() {}

NodeStatic* TreeStatic::GetRoot() { return (&root); }

void TreeStatic::PrintTree() {
  root.PrintBelow();
  std::cout << '\n';
}
