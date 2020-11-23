#include "tree_static.h"

#include <algorithm>
#include <iostream>
#include <vector>

NodeStatic::NodeStatic() {
  val_ = 0;
  parent_ = NULL;
  children_.reserve(3);
}

NodeStatic::~NodeStatic() {
  // Remove 'this' from parent vector?
}

void NodeStatic::SetValue(int new_val) { val_ = new_val; }

int NodeStatic::GetChildrenNumber() const { return children_.size(); }

void NodeStatic::SetParent(NodeStatic* parent) { parent_ = parent; }

NodeStatic* NodeStatic::GetParent() const { return parent_; }

void NodeStatic::AddChild() {
  NodeStatic child;
  child.SetParent(this);
  children_.push_back(child);
}

NodeStatic* NodeStatic::GetChild(unsigned int offset) {
  return (offset < children_.size() ? &children_[offset] : NULL);
}

bool NodeStatic::operator==(const NodeStatic& other) { return this == &other; }

void NodeStatic::UpdateChildrenPointers() {
  const int size = children_.size();
  for (int i = 0; i < size; ++i) {
    children_[i].SetParent(this);
  }
}

bool NodeStatic::MoveSubtree(NodeStatic* child) {
  if (child == NULL) return false;

  // Push a copy to children vector
  children_.push_back(*child);
  children_.back().SetParent(this);
  children_.back().UpdateChildrenPointers();

  if (child->parent_ != NULL) {
    // Remove the child from previous parent
    std::vector<NodeStatic>& children = child->parent_->children_;
    std::vector<NodeStatic>::iterator iter =
        std::find(children.begin(), children.end(), *child);

    if (iter != children.end()) children.erase(iter);
  } else {
    // If child is root in the other tree, clear it
    child->children_.clear();
    child->val_ = 0;
    child->parent_ = NULL;
  }

  return true;
}

void NodeStatic::Print() const { std::cout << " " << val_; }

void NodeStatic::PrintUp() const {
  Print();
  if (parent_ != NULL)
    parent_->PrintUp();
  else
    std::cout << '\n';
}

void NodeStatic::PrintDown() const {
  Print();
  for (size_t i = 0; i < children_.size(); ++i) {
    children_[i].PrintDown();
  }
}

TreeStatic::TreeStatic() {}

TreeStatic::~TreeStatic() {}

NodeStatic* TreeStatic::GetRoot() { return (&root); }

void TreeStatic::PrintTree() {
  root.PrintDown();
  std::cout << '\n';
}
