#ifndef TREE_HPP
#define TREE_HPP

#include <string>
#include <vector>

struct binaryTreeNode
{
    int data;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

typedef struct binaryTreeNode binaryTreeNode;

void preOrderTraversal(binaryTreeNode *, std::vector<int> &);

void inOrderTraversal(binaryTreeNode *, std::vector<int> &);

void postOrderTraversal(binaryTreeNode *, std::vector<int> &);

void insertBST(binaryTreeNode *root, int n);

void deleteBST(binaryTreeNode *previousBinaryTreeNode, binaryTreeNode *currentBinaryTreeNode);

binaryTreeNode *binarySearchTreeFromArray(std::vector<int>);

std::string searchBST(binaryTreeNode *, int);

binaryTreeNode *randomBinaryTree(int start, int end, double leftChildProbability = 0.5, double rightChildProbability = 0.5);

void printBinaryTree(binaryTreeNode *root, int depth = 0, const std::string &direction = "");

binaryTreeNode *binaryTreeFromPreOrderAndInOrder(std::vector<int> preOrder, std::vector<int> inOrder);

binaryTreeNode *binaryTreeFromPostOrderAndInOrder(std::vector<int> preOrder, std::vector<int> inOrder);

binaryTreeNode *binaryTreeFromPreOrderAndPostOrder(std::vector<int> preOrder, std::vector<int> inOrder);

struct huffmanBinaryTree
{
    char data;
    struct huffmanBinaryTree *left;
    struct huffmanBinaryTree *right;
};

typedef struct huffmanBinaryTree huffmanBinaryTree;

std::vector<std::pair<char, int>> frequencyCount(std::string);

huffmanBinaryTree *createHuffmanCodeTree(std::vector<std::pair<char, int>>);

void createHuffmanCodesHelperFunction(huffmanBinaryTree *, std::vector<std::pair<char, std::vector<bool>>> &, std::vector<bool>);

std::vector<std::pair<char, std::vector<bool>>> createHuffmanCodes(huffmanBinaryTree *);

std::pair<std::vector<bool>, huffmanBinaryTree *> huffmanCoding(std::string);

std::string huffmanCode_to_text(std::vector<bool>, huffmanBinaryTree *);

#endif
