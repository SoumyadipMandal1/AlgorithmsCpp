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

redBlackTreeNode *rightRotateRedBlackTree(redBlackTreeNode *node)
{
    redBlackTreeNode *leftSubTree = node->left;

    if (leftSubTree == nullptr)
        throw std::logic_error("Right rotation cannot be performed on a node whose left sub-tree is null");

    // Right rotation
    node->left = leftSubTree->right;
    leftSubTree->right = node;

    return leftSubTree;
}
