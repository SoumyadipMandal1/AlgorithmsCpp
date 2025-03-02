#include <stdlib.h>
#include <vector>
#include <string>
#include <stdexcept>
#include "tree.hpp"

binaryTreeNode* binarySearchTree(std::vector<int> arr, int n)
{
    // Empty array
    if (!n)
        return NULL;

    else if (n < 0)
        throw std::invalid_argument("Number of elements in the array can not be less than zero");

    // Initializing the root
    binaryTreeNode *root = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
    root->data = arr[0];
    root->left = root->right = NULL;

    // This flag checks if same number is encountered in the binary search tree
    int sameNumber;

    binaryTreeNode *temp;
    for (int i = 1; i < n; i++)
    {
        // Initializing the flag
        sameNumber = 0;

        temp = root;
        while ((arr[i] < temp->data && temp->left != NULL) || (arr[i] > temp->data && temp->right != NULL))
        {
            if (arr[i] < temp->data)
                temp = temp->left;

            else if (arr[i] > temp->data)
                temp = temp->right;

            else
            {
                sameNumber = 1;
                break;
            }
        }

        if (sameNumber)
            continue;

        // Creating new node
        binaryTreeNode *newnode =(binaryTreeNode*)malloc(sizeof(binaryTreeNode));
        newnode->data = arr[i];
        newnode->left = newnode->right = NULL;

        if (arr[i] < temp->data)
            temp->left = newnode;

        else
            temp->right = newnode;
    }

    return root;
}

// BST stands for BinarySearch Tree

std::string searchBST(binaryTreeNode *root, int key)
{
    if (root->data == key)
        return "->Found";

    else if (key < root->data)
    {
        if (root->left)
            return "->left" + searchBST(root->left, key);
        else
            return "Not Found";
    }

    else
    {
        if (root->right)
            return "->right" + searchBST(root->right, key);
        else
            return "->Not Found";
    }
}
