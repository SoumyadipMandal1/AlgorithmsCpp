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

#endif
