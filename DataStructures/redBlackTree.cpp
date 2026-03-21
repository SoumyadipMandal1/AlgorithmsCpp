#include "redBlackTree.hpp"

redBlackTreeNode *leftRotateRedBlackTree(redBlackTreeNode *node)
{
    redBlackTreeNode *rightSubTree = node->right;

    // Left rotation
    node->right = rightSubTree->left;
    rightSubTree->left = node;

    return rightSubTree;
}

redBlackTreeNode *rightRotateRedBlackTree(redBlackTreeNode *node)
{
    redBlackTreeNode *leftSubTree = node->left;

    // Right rotation
    node->left = leftSubTree->right;
    leftSubTree->right = node;

    return leftSubTree;
}
