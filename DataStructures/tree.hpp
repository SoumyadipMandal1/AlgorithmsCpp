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

void preOrderTraversal(binaryTreeNode*, std::vector<int>&);

void inOrderTraversal(binaryTreeNode*, std::vector<int>&);

void postOrderTraversal(binaryTreeNode*, std::vector<int>&);

binaryTreeNode* binarySearchTree(std::vector<int>, int);

std::string searchBST(binaryTreeNode*, int);

#endif
