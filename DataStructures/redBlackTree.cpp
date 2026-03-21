#include "redBlackTree.hpp"
#include <stdexcept>

redBlackTreeNode *leftRotateRedBlackTree(redBlackTreeNode *node)
{
    redBlackTreeNode *rightSubTree = node->right;

    if (rightSubTree == nullptr)
        throw std::logic_error("Left rotation cannot be performed on a node having whose right sub-tree is null");

    // Left rotation
    node->right = rightSubTree->left;
    rightSubTree->left = node;

    return rightSubTree;
}
