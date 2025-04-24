#include "BTree.hpp"
#include <vector>

BTreeNode::BTreeNode(int m) : order(m)
{
    data.resize(order - 1);
    children.resize(order, nullptr);
}

BTreeNode *insertBTree(BTreeNode *root, int n)
{
    // Traversing the B Tree to reach the child node
    int pos;
    BTreeNode *temp = root;
    while (root->children[0] != nullptr)
    {
        if (n < temp->data[0])
        {
            temp = temp->children[0];
            continue;
        }

        for (pos = 0; pos < temp->currentSize - 1; pos++)
        {
            if (temp->data[pos] < n && n < temp->data[pos + 1])
            {
                temp = temp->children[pos + 1];
                break;
            }
        }

        if (n > temp->data[pos + 1])
            temp = temp->children[pos + 2];
    }

    // Inserting element in non-full child node
    if (temp->currentSize < temp->order - 1)
    {
        if (n < temp->data[0])
            temp->data.insert(temp->data.begin(), n);

        else
        {
            for (pos = 0; pos < temp->currentSize - 1; pos++)
            {
                if (temp->data[pos] < n && n < temp->data[pos + 1])
                {
                    temp->data.insert(temp->data.begin() + pos + 1, n);
                    break;
                }
            }

            if (n > temp->data[pos + 1])
                temp->data.insert(temp->data.begin() + pos + 2, n);
        }

        temp->currentSize++;
    }

    // For a full child node
}
