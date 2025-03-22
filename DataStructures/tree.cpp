#include "tree.hpp"
#include "../algorithm.hpp"
#include <climits>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string>
#include <vector>

void preOrderTraversal(binaryTreeNode *root, std::vector<int> &treeArray)
{
    if (root != NULL)
    {
        treeArray.push_back(root->data);
        preOrderTraversal(root->left, treeArray);
        preOrderTraversal(root->right, treeArray);
    }
}

void inOrderTraversal(binaryTreeNode *root, std::vector<int> &treeArray)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left, treeArray);
        treeArray.push_back(root->data);
        inOrderTraversal(root->right, treeArray);
    }
}

void postOrderTraversal(binaryTreeNode *root, std::vector<int> &treeArray)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left, treeArray);
        postOrderTraversal(root->right, treeArray);
        treeArray.push_back(root->data);
    }
}

binaryTreeNode *binarySearchTree(std::vector<int> arr, int n)
{
    // Empty array
    if (!n)
        return NULL;

    else if (n < 0)
        throw std::invalid_argument("Number of elements in the array can not be less than zero");

    // Initializing the root
    binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
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
        binaryTreeNode *newnode = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
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

binaryTreeNode *randomBinaryTree(int start, int end, double leftChildProbability, double rightChildProbability)
{
    // TODO : For larger values of probability, an error is generated due to large recursion depth

    // Creating node
    binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
    root->data = start + rand() % (end - start + 1);
    root->left = root->right = NULL;

    // creating left child
    double createLeftChild = rand() / (double)RAND_MAX;
    if (createLeftChild <= leftChildProbability)
        root->left = randomBinaryTree(start, end, leftChildProbability, rightChildProbability);

    // creating right child
    double createRightChild = rand() / (double)RAND_MAX;
    if (createRightChild <= rightChildProbability)
        root->right = randomBinaryTree(start, end, leftChildProbability, rightChildProbability);

    return root;
}

void printBinaryTree(binaryTreeNode *root, int depth, const std::string &direction)
{
    // Base Case
    if (root == NULL)
        return;

    // Printing Binary Tree
    for (int i = 0; i < depth; i++)
        std::cout << "|   "; // Print the tab spaces

    // Prints the direction and number in the binary tree
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

binaryTreeNode *binaryTreeFromPreOrderAndInOrder(std::vector<int> preOrder, std::vector<int> inOrder)
{
    if (preOrder.empty() == 0)
    {
        // Creating new node
        binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode *));
        root->data = preOrder[0];
        root->left = root->right = NULL;

        // Searching for the position of root in the in-order array
        int rootPos = linear(inOrder, inOrder.size(), root->data);

        // Creating pre-order and in-order arrays of left and right sub-trees
        std::vector<int> preOrderLeft(preOrder.begin() + 1, preOrder.begin() + rootPos + 1);
        std::vector<int> preOrderRight(preOrder.begin() + rootPos + 1, preOrder.begin() + preOrder.size());
        std::vector<int> inOrderLeft(inOrder.begin(), inOrder.begin() + rootPos);
        std::vector<int> inOrderRight(inOrder.begin() + rootPos + 1, inOrder.begin() + inOrder.size());

        // traversing the binary tree
        root->left = binaryTreeFromPreOrderAndInOrder(preOrderLeft, inOrderLeft);
        root->right = binaryTreeFromPreOrderAndInOrder(preOrderRight, inOrderRight);

        return root;
    }
    else
        return NULL;
}

binaryTreeNode *binaryTreeFromPostOrderAndInOrder(std::vector<int> postOrder, std::vector<int> inOrder)
{
    if (postOrder.empty() == 0)
    {
        // Creating new node
        binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode *));
        root->data = postOrder.back();
        root->left = root->right = NULL;

        // Searching for the position of root in the in-order array
        int rootPos = linear(inOrder, inOrder.size(), root->data);

        // Creating post-order and in-order arrays of left and right sub-trees
        std::vector<int> postOrderLeft(postOrder.begin(), postOrder.begin() + rootPos);
        std::vector<int> postOrderRight(postOrder.begin() + rootPos, postOrder.begin() + postOrder.size() - 1);
        std::vector<int> inOrderLeft(inOrder.begin(), inOrder.begin() + rootPos);
        std::vector<int> inOrderRight(inOrder.begin() + rootPos + 1, inOrder.begin() + inOrder.size());

        // traversing the binary tree
        root->left = binaryTreeFromPostOrderAndInOrder(postOrderLeft, inOrderLeft);
        root->right = binaryTreeFromPostOrderAndInOrder(postOrderRight, inOrderRight);

        return root;
    }
    else
        return NULL;
}
