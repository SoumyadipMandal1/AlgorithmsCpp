#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <string>
#include <vector>

struct AVLTreeNode
{
    int data;
    int height;
    struct AVLTreeNode *left{};
    struct AVLTreeNode *right{};

    AVLTreeNode() = default;

    AVLTreeNode(int n) : data(n),
                         height(1),
                         left(nullptr),
                         right(nullptr) {}
};

typedef struct AVLTreeNode AVLTreeNode;

int height(AVLTreeNode *);

int balanceFactor(AVLTreeNode *);

AVLTreeNode *rightRotation(AVLTreeNode *);

AVLTreeNode *leftRotation(AVLTreeNode *);

AVLTreeNode *insertAVLTree(AVLTreeNode *, int);

AVLTreeNode *AVLTreeFromArray(std::vector<int>);

std::string searchAVLTree(AVLTreeNode *, int);

AVLTreeNode *deleteAVLTree(AVLTreeNode *, int);

#endif
