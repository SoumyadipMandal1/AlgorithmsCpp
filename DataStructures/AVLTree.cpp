#include "AVLTree.hpp"
#include "../algorithm.hpp"
#include <stdlib.h>
#include <string>
#include <vector>

int height(AVLTreeNode *node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int balanceFactor(AVLTreeNode *node)
{
    if (node == NULL)
        return 0;
    else
        return height(node->left) - height(node->right);
}

AVLTreeNode *rightRotation(AVLTreeNode *node)
{
    AVLTreeNode *leftSubTreeNode = node->left;
    AVLTreeNode *rightChild_of_leftSubTree = node->left->right;

    // Left Rotation
    leftSubTreeNode->right = node;
    node->left = rightChild_of_leftSubTree;

    // Changing tree height
    node->height = 1 + maxpair(height(node->left), height(node->right));
    leftSubTreeNode->height = 1 + maxpair(height(leftSubTreeNode->left), height(leftSubTreeNode->right));

    return leftSubTreeNode;
}

AVLTreeNode *leftRotation(AVLTreeNode *node)
{
    AVLTreeNode *rightSubTreeNode = node->right;
    AVLTreeNode *leftChild_of_rightSubTree = node->right->left;

    // Right Rotation
    rightSubTreeNode->left = node;
    node->right = leftChild_of_rightSubTree;

    // Changing tree height
    node->height = 1 + maxpair(height(node->left), height(node->right));
    rightSubTreeNode->height = 1 + maxpair(height(rightSubTreeNode->left), height(rightSubTreeNode->right));

    return rightSubTreeNode;
}

AVLTreeNode *insertAVLTree(AVLTreeNode *root, int data)
{
    static int isInserted = 1;

    if (root == NULL)
    {
        AVLTreeNode *newnode = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
        newnode->data = data;
        newnode->height = 1;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    // Searching for the position of insertion
    if (data < root->data)
        root->left = insertAVLTree(root->left, data);
    else if (data > root->data)
        root->right = insertAVLTree(root->right, data);
    else
    {
        isInserted = 0;
        return root;
    }

    // Changing height of each node and getting their balance
    if (isInserted)
        root->height = 1 + maxpair(height(root->left), height(root->right));
    int balance = balanceFactor(root);

    // Balancing the tree

    // LL rotation
    if (balance > 1 && data < root->left->data)
        return rightRotation(root);

    // RR rotation
    if (balance < -1 && data > root->right->data)
        return leftRotation(root);

    // LR rotation
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RL rotation
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

AVLTreeNode *AVLTreeFromArray(std::vector<int> array)
{
    if (array.empty())
        return NULL;

    AVLTreeNode *root = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
    root->data = array[0];
    root->height = 1;
    root->left = root->right = NULL;

    for (int i = 1; i < array.size(); i++)
    {
        root = insertAVLTree(root, array[i]);
    }

    return root;
}

// TODO : Generating all possible AVL Trees

std::string searchAVLTree(AVLTreeNode *root, int key)
{
    if (root->data == key)
        return "->Found";
    else if (key < root->data)
    {
        if (root->left)
            return "->left" + searchAVLTree(root->left, key);
        else
            return "Not Found";
    }

    else
    {
        if (root->right)
            return "->right" + searchAVLTree(root->right, key);
        else
            return "->Not Found";
    }
}
