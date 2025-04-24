#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <string>
#include <vector>

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left{};
    struct binaryTreeNode *right{};

    binaryTreeNode() = default;

    binaryTreeNode(int n) : data(n),
                            left(nullptr),
                            right(nullptr) {}
};

typedef struct binaryTreeNode binaryTreeNode;

void preOrderTraversal(binaryTreeNode *, std::vector<int> &);

void inOrderTraversal(binaryTreeNode *, std::vector<int> &);

void postOrderTraversal(binaryTreeNode *, std::vector<int> &);

void insertBST(binaryTreeNode *, int);

void deleteBST(binaryTreeNode *, binaryTreeNode *);

binaryTreeNode *binarySearchTreeFromArray(std::vector<int>);

std::string searchBST(binaryTreeNode *, int);

binaryTreeNode *randomBinaryTree(int, int, double leftChildProbability = 0.5, double rightChildProbability = 0.5);

template <typename T>
inline void printTree(T *root, int depth = 0, const std::string &direction = "")
{
    // Base Case
    if (root == nullptr)
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
    printTree(root->left, depth + 1, "L");
    printTree(root->right, depth + 1, "R");
}

binaryTreeNode *binaryTreeFromPreOrderAndInOrder(std::vector<int>, std::vector<int>);

binaryTreeNode *binaryTreeFromPostOrderAndInOrder(std::vector<int>, std::vector<int>);

binaryTreeNode *binaryTreeFromPreOrderAndPostOrder(std::vector<int>, std::vector<int>);

struct huffmanBinaryTree
{
    char data;
    struct huffmanBinaryTree *left{};
    struct huffmanBinaryTree *right{};

    huffmanBinaryTree() = default;

    huffmanBinaryTree(char character) : data(character),
                                        left(nullptr),
                                        right(nullptr) {}
};

typedef struct huffmanBinaryTree huffmanBinaryTree;

std::vector<std::pair<char, int>> frequencyCount(std::string);

huffmanBinaryTree *createHuffmanCodeTree(std::vector<std::pair<char, int>>);

void createHuffmanCodesHelperFunction(huffmanBinaryTree *, std::vector<std::pair<char, std::vector<bool>>> &, std::vector<bool>);

std::vector<std::pair<char, std::vector<bool>>> createHuffmanCodes(huffmanBinaryTree *);

std::pair<std::vector<bool>, huffmanBinaryTree *> huffmanCoding(std::string);

std::string huffmanCode_to_text(std::vector<bool>, huffmanBinaryTree *);

#endif
