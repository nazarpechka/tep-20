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
  void AddChild();
  NodeDynamic *GetChild(unsigned int offset);

  void UpdateChildrenPointers();
  bool MoveSubtree(NodeDynamic *child);
  void Print() const;
  void PrintUp() const;
  void PrintDown() const;

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