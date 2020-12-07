#ifndef __TREE_DYNAMIC_H__
#define __TREE_DYNAMIC_H__

#include <vector>

template <typename T>
class NodeDynamic {
 public:
  NodeDynamic();
  NodeDynamic(const T& val);
  ~NodeDynamic();

  void SetValue(const T& new_val);
  int GetChildrenCount() const;
  void SetParent(NodeDynamic<T>* parent);
  NodeDynamic<T>* GetParent() const;
  void AddChild();
  void AddChild(const T& val);
  NodeDynamic<T>* GetChild(unsigned int offset);

  bool MoveSubtree(NodeDynamic<T>* child);
  bool FromTheSameTree(NodeDynamic<T>* other);
  void Print() const;
  void PrintUp() const;
  void PrintDown() const;

 private:
  std::vector<NodeDynamic<T>*> children_;
  NodeDynamic<T>* parent_;
  T val_;
};

template <typename T>
class TreeDynamic {
 public:
  TreeDynamic();
  ~TreeDynamic();

  NodeDynamic<T>* GetRoot();
  void PrintTree();

 private:
  NodeDynamic<T>* root;
};

template <typename T>
NodeDynamic<T>::NodeDynamic() {
  children_.reserve(3);
  parent_ = NULL;
}

template <typename T>
NodeDynamic<T>::NodeDynamic(const T& val) {
  children_.reserve(3);
  parent_ = NULL;
  val_ = val;
}

template <typename T>
NodeDynamic<T>::~NodeDynamic() {
  int size = children_.size();
  for (int i = 0; i < size; ++i) {
    delete children_[i];
  }
}

template <typename T>
void NodeDynamic<T>::SetValue(const T& new_val) {
  val_ = new_val;
}

template <typename T>
int NodeDynamic<T>::GetChildrenCount() const {
  return children_.size();
}

template <typename T>
void NodeDynamic<T>::SetParent(NodeDynamic<T>* parent) {
  parent_ = parent;
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::GetParent() const {
  return parent_;
}

template <typename T>
void NodeDynamic<T>::AddChild() {
  NodeDynamic<T>* child = new NodeDynamic<T>();
  child->SetParent(this);
  children_.push_back(child);
}

template <typename T>
void NodeDynamic<T>::AddChild(const T& val) {
  NodeDynamic<T>* child = new NodeDynamic<T>(val);

  child->SetParent(this);
  children_.push_back(child);
}

template <typename T>
NodeDynamic<T>* NodeDynamic<T>::GetChild(unsigned int offset) {
  return (offset < children_.size() ? children_[offset] : NULL);
}

template <typename T>
bool NodeDynamic<T>::MoveSubtree(NodeDynamic<T>* child) {
  if (child == NULL || child->parent_ == NULL || child == this) return false;

  // Remove the child from previous parent
  typename std::vector<NodeDynamic<T>*>& parent_vector =
      child->parent_->children_;
  typename std::vector<NodeDynamic<T>*>::iterator iter =
      std::find(parent_vector.begin(), parent_vector.end(), child);

  if (iter != parent_vector.end()) parent_vector.erase(iter);

  child->SetParent(this);
  children_.push_back(child);

  return true;
}

template <typename T>
bool NodeDynamic<T>::FromTheSameTree(NodeDynamic<T>* other) {
  if (this == other) return true;

  NodeDynamic<T>* root_first = this;
  NodeDynamic<T>* root_second = other;

  while (root_first->parent_ != NULL) {
    root_first = root_first->parent_;
  }

  while (root_second->parent_ != NULL) {
    root_second = root_second->parent_;
  }

  return root_first == root_second;
}

template <typename T>
void NodeDynamic<T>::Print() const {
  std::cout << " " << val_;
}

template <typename T>
void NodeDynamic<T>::PrintUp() const {
  Print();
  if (parent_ != NULL)
    parent_->PrintUp();
  else
    std::cout << '\n';
}

template <typename T>
void NodeDynamic<T>::PrintDown() const {
  Print();
  for (size_t i = 0; i < children_.size(); ++i) {
    children_[i]->PrintDown();
  }
}

template <typename T>
TreeDynamic<T>::TreeDynamic() {
  root = new NodeDynamic<T>();
}

template <typename T>
TreeDynamic<T>::~TreeDynamic() {
  delete root;
}

template <typename T>
NodeDynamic<T>* TreeDynamic<T>::GetRoot() {
  return root;
}

template <typename T>
void TreeDynamic<T>::PrintTree() {
  root->PrintDown();
  std::cout << '\n';
}

#endif