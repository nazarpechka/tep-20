#ifndef __TREE_STATIC_H__
#define __TREE_STATIC_H__

#include <vector>

class NodeStatic {
 public:
  NodeStatic();
  ~NodeStatic();

  void SetValue(int new_val);
  int GetChildrenNumber() const;
  void SetParent(NodeStatic *parent);
  NodeStatic *GetParent() const;
  void AddChild();
  NodeStatic *GetChild(unsigned int offset);

  bool operator==(const NodeStatic &other);

  void UpdateChildrenPointers();
  bool MoveSubtree(NodeStatic *child);
  void Print() const;
  void PrintUp() const;
  void PrintDown() const;

 private:
  std::vector<NodeStatic> children_;
  NodeStatic *parent_;
  int val_;
};

class TreeStatic {
 public:
  TreeStatic();
  ~TreeStatic();

  NodeStatic *GetRoot();
  void PrintTree();

 private:
  NodeStatic root;
};

#endif  // __TREE_STATIC_H__