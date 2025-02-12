#include <stdlib.h>
#include <tuple>
#include "dataStructures.hpp"

Node* createNode(int data)
{
    // This function creates a node having data stored in it
    Node* node;
    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* createLinkedList(int* arr, int n)
{
    // Creates a linked list from array
    Node *head, *newnode;

    if (n == 0)
        return NULL;

    head = createNode(arr[0]);
    newnode = head;

    for (int i = 1; i < n; i++)
    {
        newnode->next = createNode(arr[i]);
        newnode = newnode->next;
    }

    return head;
}
