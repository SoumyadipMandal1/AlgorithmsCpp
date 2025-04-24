#ifndef BTREE_HPP
#define BTREE_HPP

#include <vector>

class BTreeNode
{
  public:
    int order;
    int currentSize{0};
    BTreeNode *prev;
    std::vector<int> data;
    std::vector<BTreeNode *> children;

    BTreeNode(int order);
};

#endif
