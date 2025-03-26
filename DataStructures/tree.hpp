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

binaryTreeNode *binarySearchTree(std::vector<int>, int);

std::string searchBST(binaryTreeNode *, int);

binaryTreeNode *randomBinaryTree(int start, int end, double leftChildProbability = 0.5, double rightChildProbability = 0.5);

void printBinaryTree(binaryTreeNode *root, int depth = 0, const std::string &direction = "");

binaryTreeNode *binaryTreeFromPreOrderAndInOrder(std::vector<int> preOrder, std::vector<int> inOrder);

void deleteBinaryTreeNode(binaryTreeNode *previousBinaryTreeNode, binaryTreeNode *currentBinaryTreeNode);

#endif
