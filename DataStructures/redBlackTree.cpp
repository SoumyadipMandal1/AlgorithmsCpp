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

redBlackTreeNode *insertRedBlackTree(redBlackTreeNode *root, int data, bool isChild)
{
    if (root == nullptr)
    {
        redBlackTreeNode *newnode;

        if (isChild) // If the node to be inserted will become the child of a node
            newnode = new redBlackTreeNode(data, RED);
        else // If whole tree is NULL
            newnode = new redBlackTreeNode(data, BLACK);

        return newnode;
    }

    // searching for the position of the insertion
    if (data < root->data)
        root->left = insertRedBlackTree(root->left, data, true);
    else
        root->right = insertRedBlackTree(root->right, data, true);

    bool isLeftRed, isRightRed;
    isLeftRed = isRightRed = false;

    if (root->color == BLACK)
    {
        // checks whether the left child and right child of a black tree is red or not
        if (root->left && root->left->color == RED)
            isLeftRed = true;
        if (root->right && root->right->color == RED)
            isRightRed = true;
    }

    // If root is black and both the child are red
    if (isLeftRed && isRightRed)
    {
        if ((root->left->left && root->left->left->color == RED) ||
            (root->left->right && root->left->right->color == RED) ||
            (root->right->left && root->right->left->color == RED) ||
            (root->right->right && root->right->right->color == RED))
        {
            // swapping the color of the root and the child
            root->color = RED;
            root->left->color = root->right->color = BLACK;
            return root;
        }
    }
    else if (isLeftRed)
    {
        bool isLeftRightRed = false;

        if (root->left->right && root->left->right->color == RED)
            isLeftRightRed = true;

        if (isLeftRightRed)
            root->left = leftRotateRedBlackTree(root->left);
        root->color = RED;
        root->left->color = BLACK;
        return rightRotateRedBlackTree(root);
    }
    else if (isRightRed)
    {
        bool isRightLeftRed = false;

        if (root->right->left && root->right->left->color == RED)
            isRightLeftRed = true;

        if (isRightLeftRed)
            root->right = rightRotateRedBlackTree(root->right);
        root->color = RED;
        root->right->color = BLACK;
        return leftRotateRedBlackTree(root);
    }

    return root;
}
