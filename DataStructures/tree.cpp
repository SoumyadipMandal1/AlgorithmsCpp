#include "tree.hpp"
#include "../algorithm.hpp"
#include <climits>
#include <cstddef>
#include <iostream>
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

void insertBST(binaryTreeNode *root, int n)
{
    // Creating new node
    binaryTreeNode *newnode;
    newnode->data = n;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
        return;
    }

    binaryTreeNode *temp = root;
    while ((n < temp->data && temp->left != NULL) || (n > temp->data && temp->right != NULL))
    {
        if (n < temp->data)
            temp = temp->left;
        else if (n > temp->data)
            temp = temp->right;
        else
            return;
    }

    if (n < temp->data)
        temp->left = newnode;
    else
        temp->right = newnode;
    return;
}

void deleteBST(binaryTreeNode *previousBinaryTreeNode, binaryTreeNode *currentBinaryTreeNode)
{
    if (currentBinaryTreeNode->left == NULL && currentBinaryTreeNode->right == NULL)
    {
        free(currentBinaryTreeNode);
        previousBinaryTreeNode->left = previousBinaryTreeNode->right = NULL;
    }

    else if (currentBinaryTreeNode->left != NULL && currentBinaryTreeNode->right == NULL)
    {
        previousBinaryTreeNode->left = currentBinaryTreeNode->left;
        free(currentBinaryTreeNode);
    }

    else if (currentBinaryTreeNode->left == NULL && currentBinaryTreeNode->right != NULL)
    {
        previousBinaryTreeNode->right = currentBinaryTreeNode->right;
        free(currentBinaryTreeNode);
    }

    else
    {
        if (previousBinaryTreeNode->left == currentBinaryTreeNode)
        {
            // Replacing the leftmost child of the right sub-tree as the deleted node
            binaryTreeNode *previousTemp, *currentTemp;
            previousTemp = currentBinaryTreeNode->right;

            if (previousTemp->left == NULL)
                currentTemp = previousTemp;
            else
            {
                currentTemp = previousTemp->left;
                while (currentTemp->left != NULL)
                {
                    previousTemp = currentTemp;
                    currentTemp = currentTemp->left;
                }
                previousTemp->left = NULL;
            }

            previousBinaryTreeNode->left = currentTemp;
            currentTemp->left = currentBinaryTreeNode->left;
            currentTemp->right = currentBinaryTreeNode->right;
        }

        else if (previousBinaryTreeNode->right == currentBinaryTreeNode)
        {
            // Replacing the leftmost child of the right sub-tree as the deleted node
            binaryTreeNode *previousTemp, *currentTemp;
            previousTemp = currentBinaryTreeNode->right;

            if (previousTemp->left == NULL)
                currentTemp = previousTemp;
            else
            {
                currentTemp = previousTemp->left;
                while (currentTemp->left != NULL)
                {
                    previousTemp = currentTemp;
                    currentTemp = currentTemp->left;
                }
                previousTemp->left = NULL;
            }

            previousBinaryTreeNode->right = currentTemp;
            currentTemp->left = currentBinaryTreeNode->left;
            currentTemp->right = currentBinaryTreeNode->right;
        }
    }
}

binaryTreeNode *binarySearchTreeFromArray(std::vector<int> arr)
{
    // Empty array
    if (arr.empty())
        return NULL;

    // Initializing the root
    binaryTreeNode *root = NULL;

    binaryTreeNode *temp;
    for (int i = 0; i < arr.size(); i++)
        insertBST(root, arr[i]);

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
