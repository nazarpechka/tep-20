#include "tree_dynamic.h"

#include <algorithm>
#include <iostream>

NodeDynamic::NodeDynamic() {
  val_ = 0;
  parent_ = NULL;
  children_.reserve(3);
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

void NodeDynamic::AddChild() {
  NodeDynamic* child = new NodeDynamic();
  child->SetParent(this);
  children_.push_back(child);
}

NodeDynamic* NodeDynamic::GetChild(unsigned int offset) {
  return (offset < children_.size() ? children_[offset] : NULL);
}

void NodeDynamic::UpdateChildrenPointers() {
  const int size = children_.size();
  for (int i = 0; i < size; ++i) {
    children_[i]->SetParent(this);
  }
}

bool NodeDynamic::MoveSubtree(NodeDynamic* child) {
  if (child == NULL) return false;

  if (child->parent_ != NULL) {
    // Remove the child from previous parent
    std::vector<NodeDynamic*>& parent_vector = child->parent_->children_;
    std::vector<NodeDynamic*>::iterator iter =
        std::find(parent_vector.begin(), parent_vector.end(), child);

    if (iter != parent_vector.end()) parent_vector.erase(iter);
  } else {
    // If child is root in the other tree, create a copy
    NodeDynamic* child_copy = new NodeDynamic(*child);
    child->children_.clear();
    child->val_ = 0;
    child = child_copy;
    child->UpdateChildrenPointers();
  }

  child->SetParent(this);
  children_.push_back(child);

  return true;
}

void NodeDynamic::Print() const { std::cout << " " << val_; }

void NodeDynamic::PrintUp() const {
  Print();
  if (parent_ != NULL)
    parent_->PrintUp();
  else
    std::cout << '\n';
}

void NodeDynamic::PrintDown() const {
  Print();
  for (size_t i = 0; i < children_.size(); ++i) {
    children_[i]->PrintDown();
  }
}

TreeDynamic::TreeDynamic() { root = new NodeDynamic(); }

TreeDynamic::~TreeDynamic() { delete root; }

NodeDynamic* TreeDynamic::GetRoot() { return root; }

void TreeDynamic::PrintTree() {
  root->PrintDown();
  std::cout << '\n';
}
