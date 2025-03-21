#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stdexcept>
#include <climits>
#include "tree.hpp"

void preOrderTraversal(binaryTreeNode *root, std::vector<int>& treeArray)
{
    if (root != NULL)
    {
        treeArray.push_back(root->data);
        preOrderTraversal(root->left, treeArray);
        preOrderTraversal(root->right, treeArray);
    }
}

void inOrderTraversal(binaryTreeNode *root, std::vector<int>& treeArray)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left, treeArray);
        treeArray.push_back(root->data);
        inOrderTraversal(root->right, treeArray);
    }
}

void postOrderTraversal(binaryTreeNode *root, std::vector<int>& treeArray)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left, treeArray);
        postOrderTraversal(root->right, treeArray);
        treeArray.push_back(root->data);
    }
}

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
        binaryTreeNode *newnode = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
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

binaryTreeNode* randomBinaryTree(int start, int end, double leftChildProbability, double rightChildProbability)
{
    // TODO : For larger values of probability, an error is generated due to large recursion depth

    // Creating node
    binaryTreeNode *root = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
    root->data = start + rand() % (end - start + 1);
    root->left = root->right = NULL;

    // creating left child
    double createLeftChild = rand() / (double) RAND_MAX;
    if (createLeftChild <= leftChildProbability)
        root->left = randomBinaryTree(start, end, leftChildProbability, rightChildProbability);

    // creating right child
    double createRightChild = rand() / (double) RAND_MAX;
    if (createRightChild <= rightChildProbability)
        root->right = randomBinaryTree(start, end, leftChildProbability, rightChildProbability);

    return root;
}

void printBinaryTree(binaryTreeNode *root, int depth, const std::string& direction)
{
    // Printing Binary Tree
    if (root == NULL)   // Base Case
        return;

    for (int i = 0; i < depth; i++)
        std::cout << "|   ";

    if (direction == "L")
        std::cout << "L-- " << root->data << '\n';
    else if (direction == "R")
        std::cout << "R-- " << root->data << '\n';
    else
        std::cout << root->data << '\n';

    // Traversing the tree
    printBinaryTree(root->left, depth + 1, "L");
    printBinaryTree(root->right, depth + 1, "R");
}
