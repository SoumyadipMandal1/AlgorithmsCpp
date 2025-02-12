#include <stdlib.h>
#include <tuple>
#include "linkedList.hpp"

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

int searchLinkedList(Node *head, int key)
{
    int counter = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
            return counter;
        temp = temp->next;
        counter++;
    }
    return -1;
}

Node* deleteFirst(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteLast(Node *head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteLinkedList(Node *head, int index)
{
    if (index == 0)
        return deleteFirst(head);

    Node *currentNode = head;
    Node *previousNode;
    int counter = 0;

    while (currentNode->next != NULL)
    {
        // Updating the nodes and counter
        previousNode = currentNode;
        currentNode = currentNode->next;
        counter++;

        if (counter == index)
        {
            previousNode->next = currentNode->next;
            free(currentNode);
            return head;
        }

    }

    if (counter + 1 == index)
    {
        previousNode->next = NULL;
        free(currentNode);
        return head;
    }
}
