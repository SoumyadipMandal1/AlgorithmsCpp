#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <vector>

typedef enum
{
    RED,
    BLACK
} Color;

struct redBlackTreeNode
{
    int data;
    struct redBlackTreeNode *left;
    struct redBlackTreeNode *right;
    Color color;

    redBlackTreeNode() = default;

    redBlackTreeNode(int n, Color color) : data(n), left(nullptr), right(nullptr), color(color)
    {
    }
};

typedef struct redBlackTreeNode redBlackTreeNode;

redBlackTreeNode *leftRotateRedBlackTree(redBlackTreeNode *);

redBlackTreeNode *rightRotateRedBlackTree(redBlackTreeNode *);

redBlackTreeNode *insertRedBlackTree(redBlackTreeNode *, int, bool isChild = false);

redBlackTreeNode *createRedBlackTree(std::vector<int> &);

#endif
