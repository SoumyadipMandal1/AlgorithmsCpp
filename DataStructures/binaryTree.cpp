#include "binaryTree.hpp"
#include "../algorithm.hpp"
#include <climits>
#include <cstddef>
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

void insertBST(binaryTreeNode *root, int n)
{
    // Creating new node
    binaryTreeNode *newnode = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
    newnode->data = n;
    newnode->left = newnode->right = NULL;

    binaryTreeNode *temp = root;
    while ((n < temp->data && temp->left != NULL) || (n > temp->data && temp->right != NULL))
    {
        if (n < temp->data)
            temp = temp->left;
        else if (n > temp->data)
            temp = temp->right;
    }

    if (n == temp->data)
        return;
    else if (n < temp->data)
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
    binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
    root->data = arr[0];
    root->left = root->right = NULL;

    for (int i = 1; i < arr.size(); i++)
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

// TODO : Implement a checking mechanism to find whether two arrays represent a binary tree or not

binaryTreeNode *binaryTreeFromPreOrderAndInOrder(std::vector<int> preOrder, std::vector<int> inOrder)
{
    // For empty tree
    if (preOrder.empty() && inOrder.empty()) // Base Case
        return NULL;

    // Handling errors
    else if (preOrder.empty() || inOrder.empty())
        throw std::logic_error("The two vectors does not represent pre-order and in-order of a same binary tree.");
    // else if (preOrder.back() != inOrder.back())
    // throw std::logic_error("The two vectors does not represent pre-order and in-order of a same binary tree.");

    // Main body of the function
    else
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
}

binaryTreeNode *binaryTreeFromPostOrderAndInOrder(std::vector<int> postOrder, std::vector<int> inOrder)
{
    // For empty tree
    if (postOrder.empty() && inOrder.empty()) // Base Case
        return NULL;

    // Handling errors
    else if (postOrder.empty() || inOrder.empty())
        throw std::logic_error("The two vectors does not represent post-order and in-order of a same binary tree.");
    // else if (postOrder[0] != inOrder[0])
    // throw std::logic_error("The two vectors does not represent post-order and in-order of a same binary tree.");

    // Main body of the function
    else
    {
        // Creating new node
        binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
        root->data = postOrder.back();
        root->left = root->right = NULL;

        // Searching for the position of root in the in-order array
        int rootPos = linear(inOrder, inOrder.size(), root->data);

        // Creating post-order and in-order arrays of left and right sub-trees
        std::vector<int> postOrderLeft(postOrder.begin(), postOrder.begin() + rootPos);
        std::vector<int> postOrderRight(postOrder.begin() + rootPos, postOrder.begin() + postOrder.size() - 1);
        std::vector<int> inOrderLeft(inOrder.begin(), inOrder.begin() + rootPos);
        std::vector<int> inOrderRight(inOrder.begin() + rootPos + 1, inOrder.begin() + inOrder.size());

        // Traversing the binary tree
        root->left = binaryTreeFromPostOrderAndInOrder(postOrderLeft, inOrderLeft);
        root->right = binaryTreeFromPostOrderAndInOrder(postOrderRight, inOrderRight);

        return root;
    }
}

binaryTreeNode *binaryTreeFromPreOrderAndPostOrder(std::vector<int> preOrder, std::vector<int> postOrder)
{
    // For empty tree
    if (preOrder.empty() && postOrder.empty())
        return NULL;

    // Handling errors
    else if (preOrder.empty() || postOrder.empty())
        throw std::logic_error("The two vectors does not represent pre-order and post-order of a same binary tree.");
    // else if (preOrder[0] != postOrder.back())
    // throw std::logic_error("The two vectors does not represent pre-order and post-order of a same binary tree.");

    // Main body of the function
    else
    {
        // Creating new node
        binaryTreeNode *root = (binaryTreeNode *)malloc(sizeof(binaryTreeNode));
        root->data = preOrder[0];
        root->left = root->right = NULL;

        // If pre-order and post-order arrays contains only single element
        if (preOrder[0] == postOrder[0]) // Base Case
            return root;

        // Searching left child in post-order array
        int leftChildPos = linear(postOrder, postOrder.size(), preOrder[1]);

        // Creating pre-order and post-order arrays of left and right sub-trees
        std::vector<int> preOrderLeft(preOrder.begin() + 1, preOrder.begin() + leftChildPos + 2);
        std::vector<int> postOrderLeft(postOrder.begin(), postOrder.begin() + leftChildPos + 1);
        std::vector<int> preOrderRight(preOrder.begin() + leftChildPos + 2, preOrder.end());
        std::vector<int> postOrderRight(postOrder.begin() + leftChildPos + 1, postOrder.end() - 1);

        // Traversing the binary tree
        root->left = binaryTreeFromPreOrderAndPostOrder(preOrderLeft, postOrderLeft);
        root->right = binaryTreeFromPreOrderAndPostOrder(preOrderRight, postOrderRight);

        return root;
    }
}

// TODO : Generating all binary trees from a given pre-order and post-order

/*************** Implementing Hoffman's Coding ****************************/

std::vector<std::pair<char, int>> frequencyCount(std::string text)
{
    int found; // Flag for checking if a character is already present in the string or not
    std::vector<std::pair<char, int>> frequency;

    // Calculating frequency of each character in a text
    for (char character : text)
    {
        found = 0;
        for (std::pair<char, int> frequencyPair : frequency)
        {
            if (character == frequencyPair.first)
            {
                frequencyPair.second++;
                found = 1;
            }
        }

        if (!found)
            frequency.push_back({character, 1});
    }

    return frequency;
}

huffmanBinaryTree *createHoffmanCodeTree(std::vector<std::pair<char, int>> frequency)
{
    std::vector<std::pair<huffmanBinaryTree *, int>> huffmanCodes;

    // Creating array of nodes of for huffman coding
    for (std::pair<char, int> frequencyPair : frequency)
    {
        huffmanBinaryTree *root = (huffmanBinaryTree *)malloc(sizeof(huffmanBinaryTree));
        root->character = frequencyPair.first;
        root->left = root->right = NULL;
        huffmanCodes.push_back({root, frequencyPair.second});
    }

    int firstmin, secondmin;
    int firstminpos, secondminpos;
    while (huffmanCodes.size() > 1)
    {
        // Find the first and second minimum number and finding its position
        firstmin = secondmin = INT_MAX;
        firstminpos = secondminpos = -1;
        for (int i = 0; i < huffmanCodes.size(); i++)
        {
            if (huffmanCodes[i].second < firstmin)
            {
                firstmin = huffmanCodes[i].second;
                secondmin = firstmin;
                firstminpos = i;
                secondminpos = firstminpos;
            }
            else if (huffmanCodes[i].second >= firstmin && huffmanCodes[i].second < secondmin)
            {
                secondmin = huffmanCodes[i].second;
                secondminpos = i;
            }
        }

        // Updatind the hoffman tree array
        huffmanBinaryTree *root = (huffmanBinaryTree *)malloc(sizeof(huffmanBinaryTree));
        root->left = huffmanCodes[firstminpos].first;
        root->right = huffmanCodes[secondminpos].first;
        huffmanCodes.erase(huffmanCodes.begin() + firstmin);
        huffmanCodes.erase(huffmanCodes.begin() + secondmin);
        huffmanCodes.push_back({root, firstmin + secondmin});
    }

    return huffmanCodes[0].first;
}

void createHuffmanCodesHelperFunction(huffmanBinaryTree *root, std::vector<std::pair<char, std::vector<bool>>> &huffmanCodes, std::vector<bool> huffmanCode)
{
    // Base Case
    if (root->left == NULL && root->right == NULL)
    {
        huffmanCodes.push_back({root->character, huffmanCode});
        return;
    }

    {
        huffmanCode.push_back(false);
        createHuffmanCodesHelperFunction(root->left, huffmanCodes, huffmanCode);
    }

    {
        huffmanCode.push_back(true);
        createHuffmanCodesHelperFunction(root->right, huffmanCodes, huffmanCode);
    }
}

std::vector<std::pair<char, std::vector<bool>>> createHuffmanCodes(huffmanBinaryTree *root)
{
    std::vector<std::pair<char, std::vector<bool>>> huffmanCodes;
    std::vector<bool> huffmanCode;
    createHuffmanCodesHelperFunction(root, huffmanCodes, huffmanCode);
    return huffmanCodes;
}

std::pair<std::vector<bool>, huffmanBinaryTree *> huffmanCoding(std::string text)
{
    std::vector<std::pair<char, int>> frequency = frequencyCount(text);
    huffmanBinaryTree *root = createHoffmanCodeTree(frequency);
    std::vector<std::pair<char, std::vector<bool>>> huffmanCode = createHuffmanCodes(root);

    std::vector<bool> compressedData;
    // This for loop iterates over the text
    for (char character : text)
    {
        // This for loop iterates over all the characters present in the huffmanCode
        for (std::pair<char, std::vector<bool>> characterCodePair : huffmanCode)
        {
            if (character == characterCodePair.first)
            {
                // Appends the huffman code for each character to the main array
                for (int i = 0; i < characterCodePair.second.size(); i++)
                    compressedData.push_back(characterCodePair.second[i]);
            }
        }
    }

    return {compressedData, root};
}

std::string huffmanCode_to_text(std::vector<bool> compressedData, huffmanBinaryTree *root)
{
    huffmanBinaryTree *temp = root;
    int pos = 0;
    std::string text = "";

    while (pos < compressedData.size())
    {
        while (temp->left != NULL && temp->right != NULL)
        {
            if (compressedData[pos] == false)
                temp = temp->left;
            else
                temp = temp->right;
            pos++;
        }

        text += temp->character;
        pos++;
        temp = root;
    }

    return text;
}
