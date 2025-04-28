#include "binaryTree.hpp"
#include "../algorithm.hpp"
#include "queue.hpp"
#include <climits>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

void preOrderTraversal(binaryTreeNode *root, std::vector<int> &treeArray)
{
    if (root != nullptr)
    {
        treeArray.push_back(root->data);
        preOrderTraversal(root->left, treeArray);
        preOrderTraversal(root->right, treeArray);
    }
}

void inOrderTraversal(binaryTreeNode *root, std::vector<int> &treeArray)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left, treeArray);
        treeArray.push_back(root->data);
        inOrderTraversal(root->right, treeArray);
    }
}

void postOrderTraversal(binaryTreeNode *root, std::vector<int> &treeArray)
{
    if (root != nullptr)
    {
        postOrderTraversal(root->left, treeArray);
        postOrderTraversal(root->right, treeArray);
        treeArray.push_back(root->data);
    }
}

std::vector<int> levelOrderTraversal(binaryTreeNode *root)
{
    if (root == NULL)
        return {};

    binaryTreeNode *temp;
    auto *queue = new Queue<binaryTreeNode *>();
    queue->enqueue(root);
    std::vector<int> treeArray;

    while (!queue->isEmpty())
    {
        temp = queue->dequeue();
        treeArray.push_back(temp->data);

        if (temp->left != NULL)
            queue->enqueue(temp->left);
        if (temp->right != NULL)
            queue->enqueue(temp->right);
    }

    return treeArray;
}

void insertBST(binaryTreeNode *root, int n)
{
    // Creating new node
    binaryTreeNode *newnode = new binaryTreeNode(n);

    binaryTreeNode *temp = root;
    while ((n < temp->data && temp->left != nullptr) || (n > temp->data && temp->right != nullptr))
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
    if (currentBinaryTreeNode->left == nullptr && currentBinaryTreeNode->right == nullptr)
    {
        free(currentBinaryTreeNode);
        previousBinaryTreeNode->left = previousBinaryTreeNode->right = nullptr;
    }

    else if (currentBinaryTreeNode->left != nullptr && currentBinaryTreeNode->right == nullptr)
    {
        previousBinaryTreeNode->left = currentBinaryTreeNode->left;
        free(currentBinaryTreeNode);
    }

    else if (currentBinaryTreeNode->left == nullptr && currentBinaryTreeNode->right != nullptr)
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

            if (previousTemp->left == nullptr)
                currentTemp = previousTemp;
            else
            {
                currentTemp = previousTemp->left;
                while (currentTemp->left != nullptr)
                {
                    previousTemp = currentTemp;
                    currentTemp = currentTemp->left;
                }
                previousTemp->left = nullptr;
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

            if (previousTemp->left == nullptr)
                currentTemp = previousTemp;
            else
            {
                currentTemp = previousTemp->left;
                while (currentTemp->left != nullptr)
                {
                    previousTemp = currentTemp;
                    currentTemp = currentTemp->left;
                }
                previousTemp->left = nullptr;
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
        return nullptr;

    // Initializing the root
    binaryTreeNode *root = new binaryTreeNode(arr[0]);

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
    binaryTreeNode *root = new binaryTreeNode(start + rand() % (end - start + 1));

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

// TODO : Implement a checking mechanism to find whether two arrays represent a binary tree or not

binaryTreeNode *binaryTreeFromPreOrderAndInOrder(std::vector<int> preOrder, std::vector<int> inOrder)
{
    // For empty tree
    if (preOrder.empty() && inOrder.empty()) // Base Case
        return nullptr;

    // Handling errors
    else if (preOrder.empty() || inOrder.empty())
        throw std::logic_error("The two vectors does not represent pre-order and in-order of a same binary tree.");
    // else if (preOrder.back() != inOrder.back())
    // throw std::logic_error("The two vectors does not represent pre-order and in-order of a same binary tree.");

    // Main body of the function
    else
    {
        // Creating new node
        binaryTreeNode *root = new binaryTreeNode(preOrder[0]);

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
        return nullptr;

    // Handling errors
    else if (postOrder.empty() || inOrder.empty())
        throw std::logic_error("The two vectors does not represent post-order and in-order of a same binary tree.");
    // else if (postOrder[0] != inOrder[0])
    // throw std::logic_error("The two vectors does not represent post-order and in-order of a same binary tree.");

    // Main body of the function
    else
    {
        // Creating new node
        binaryTreeNode *root = new binaryTreeNode(postOrder.back());

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
        return nullptr;

    // Handling errors
    else if (preOrder.empty() || postOrder.empty())
        throw std::logic_error("The two vectors does not represent pre-order and post-order of a same binary tree.");
    // else if (preOrder[0] != postOrder.back())
    // throw std::logic_error("The two vectors does not represent pre-order and post-order of a same binary tree.");

    // Main body of the function
    else
    {
        // Creating new node
        binaryTreeNode *root = new binaryTreeNode(preOrder[0]);

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

std::map<char, int> frequencyCount(std::string text)
{
    int found; // Flag for checking if a character is already present in the string or not
    std::map<char, int> frequency;

    // Calculating frequency of each character in a text
    for (char character : text)
    {
        frequency[character]++;
    }

    return frequency;
}

huffmanBinaryTree *createHuffmanCodeTree(std::map<char, int> frequency)
{
    std::vector<std::pair<huffmanBinaryTree *, int>> huffmanCodes;

    // Creating array of nodes of for huffman coding
    for (auto &[character, occurence] : frequency)
    {
        huffmanBinaryTree *root = new huffmanBinaryTree(character);
        huffmanCodes.push_back({root, occurence});
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
                secondmin = firstmin;
                firstmin = huffmanCodes[i].second;
                secondminpos = firstminpos;
                firstminpos = i;
            }
            else if (huffmanCodes[i].second >= firstmin && huffmanCodes[i].second < secondmin)
            {
                secondmin = huffmanCodes[i].second;
                secondminpos = i;
            }
        }

        // Updatind the huffman tree array
        huffmanBinaryTree *root = new huffmanBinaryTree();
        root->left = huffmanCodes[firstminpos].first;
        root->right = huffmanCodes[secondminpos].first;
        huffmanCodes.push_back({root, huffmanCodes[firstminpos].second + huffmanCodes[secondminpos].second});

        if (firstminpos > secondminpos)
        {
            huffmanCodes.erase(huffmanCodes.begin() + firstminpos);
            huffmanCodes.erase(huffmanCodes.begin() + secondminpos);
        }
        else
        {
            huffmanCodes.erase(huffmanCodes.begin() + secondminpos);
            huffmanCodes.erase(huffmanCodes.begin() + firstminpos);
        }
    }

    return huffmanCodes[0].first;
}

void createHuffmanCodesHelperFunction(huffmanBinaryTree *root,
                                      std::vector<std::pair<char, std::vector<bool>>> &huffmanCodes,
                                      std::vector<bool> huffmanCode)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCodes.push_back({root->data, huffmanCode});
        return;
    }

    createHuffmanCodesHelperFunction(root->left, huffmanCodes, array_push(huffmanCode, false));
    createHuffmanCodesHelperFunction(root->right, huffmanCodes, array_push(huffmanCode, true));
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
    std::map<char, int> frequency = frequencyCount(text);
    huffmanBinaryTree *root = createHuffmanCodeTree(frequency);
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
        while (temp->left != nullptr && temp->right != nullptr)
        {
            if (compressedData[pos] == false)
                temp = temp->left;
            else
                temp = temp->right;
            pos++;
        }

        text += temp->data;
        temp = root;
    }

    return text;
}
