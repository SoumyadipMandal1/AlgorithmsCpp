#include "AVLTree.hpp"
#include "../algorithm.hpp"
#include <string>
#include <vector>

int height(AVLTreeNode *node)
{
    if (node == nullptr)
        return 0;
    else
        return node->height;
}

int balanceFactor(AVLTreeNode *node)
{
    if (node == nullptr)
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

    if (root == nullptr)
    {
        AVLTreeNode *newnode = new AVLTreeNode(data);
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
    else if (balance < -1 && data > root->right->data)
        return leftRotation(root);

    // LR rotation
    else if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RL rotation
    else if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

AVLTreeNode *AVLTreeFromArray(std::vector<int> array)
{
    if (array.empty())
        return nullptr;

    AVLTreeNode *root = new AVLTreeNode(array[0]);

    for (int i = 1; i < array.size(); i++)
        root = insertAVLTree(root, array[i]);

    return root;
}

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

AVLTreeNode *deleteAVLTree(AVLTreeNode *root, int n)
{
    // If node is not present
    if (root == nullptr)
        return root;

    // Traversing the AVL Tree to reach the node
    else if (n < root->data)
        root->left = deleteAVLTree(root->left, n);
    else if (n > root->data)
        root->right = deleteAVLTree(root->right, n);

    else
    {
        // Deleting Node

        // For no child case
        if (root->left == nullptr && root->right == nullptr)
            return nullptr;

        // For one child case
        else if ((root->left == nullptr) != (root->right == nullptr))
        {
            AVLTreeNode *NodeToDelete = root;
            AVLTreeNode *nextNode;
            if (root->left != nullptr)
                nextNode = root->left;
            else
                nextNode = root->right;

            *root = *nextNode;
            free(NodeToDelete);
        }

        // If both children are present
        else
        {
            // Traversing the AVL Tree to the in-order successor
            AVLTreeNode *temp = root->right;
            while (temp->left != nullptr)
                temp = temp->left;

            // Copying the in-order successor's data
            root->data = temp->data;

            // Deleting the in-order successor node
            root->right = deleteAVLTree(root->right, temp->data);
        }
    }

    // Updating the height of current node
    root->height = 1 + maxpair(height(root->left), height(root->right));

    // Balance Factor
    int balance = balanceFactor(root);

    // Balancing the tree
    if (balance > 1)
    {
        // R0 Rotation
        if (balanceFactor(root->left) == 0)
            return rightRotation(root);

        // R1 Rotation
        else if (balanceFactor(root->left) == 1)
            return rightRotation(root);

        // R-1 Rotation
        else if (balanceFactor(root->left) == -1)
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }

    else if (balance < -1)
    {
        // L0 Rotation
        if (balanceFactor(root->right) == 0)
            return leftRotation(root);

        // L1 Rotation
        else if (balanceFactor(root->right) == 1)
            return leftRotation(root);

        // L-1 Rotation
        else if (balanceFactor(root->right) == -1)
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    return root;
}
