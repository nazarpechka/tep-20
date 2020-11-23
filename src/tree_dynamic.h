#ifndef __TREE_DYNAMIC_H__
#define __TREE_DYNAMIC_H__

#include <vector>

class NodeDynamic {
 public:
  NodeDynamic();
  ~NodeDynamic();

  void SetValue(int new_val);
  int GetChildrenNumber() const;
  void SetParent(NodeDynamic *parent);
  NodeDynamic *GetParent() const;
  void AddNewChild();
  NodeDynamic *GetChild(unsigned int offset);

  bool MoveSubtree(NodeDynamic *new_child);
  void Print() const;
  void PrintBelow() const;

 private:
  std::vector<NodeDynamic *> children_;
  NodeDynamic *parent_;
  int val_;
};

class TreeDynamic {
 public:
  TreeDynamic();
  ~TreeDynamic();

  NodeDynamic *GetRoot();
  void PrintTree();

 private:
  NodeDynamic *root;
};

#endif