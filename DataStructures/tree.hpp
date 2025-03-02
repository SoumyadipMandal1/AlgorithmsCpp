#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <string>

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

typedef struct binaryTreeNode binaryTreeNode;

binaryTreeNode* binarySearchTree(std::vector<int>, int);

std::string searchBST(binaryTreeNode*, int);

#endif
