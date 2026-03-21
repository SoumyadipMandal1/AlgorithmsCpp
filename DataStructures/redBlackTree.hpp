#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

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

    redBlackTreeNode(int n) : data(n), left(nullptr), right(nullptr), color(RED)
    {
    }
};

typedef struct redBlackTreeNode redBlackTreeNode;

redBlackTreeNode *leftRotateRedBlackTree(redBlackTreeNode *);

redBlackTreeNode *rightRotateRedBlackTree(redBlackTreeNode *);

#endif
