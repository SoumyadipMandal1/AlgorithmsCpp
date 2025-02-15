#include <stdlib.h>
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

Node* insertFirst(Node *head, int data)
{
    Node *newnode = createNode(data);
    newnode->next = head;
    return newnode;
}

Node* insertLast(Node *head, int data)
{
    Node *newnode = createNode(data);
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    return head;
}

Node* insertLinkedList(Node *head, int data, int index)
{
    // If index is more than length, then data is inserted at the end of the linked list

    if (index == 0)
        return insertFirst(head, data);

    Node *newnode = createNode(data);
    Node *temp = head;
    int counter = 1;
    while (temp->next != NULL)
    {
        if (counter == index)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
        counter++;
    }

    // Inserting at the end of linked list
    temp->next = newnode;
    return head;
}

Node* reverseLinkedList(Node *head)
{
    Node *temp1, *temp2, *temp3;

    if (head == NULL)
        return NULL;

    else if (head->next == NULL)
        return head;

    else if (head->next->next == NULL)
    {
        temp1 = head;
        temp2 = head->next;
        temp2->next = temp1;
        temp1->next = NULL;
        return temp2;
    }
    temp1 = head;
    temp2 = head->next;
    temp3 = head->next->next;
    temp2->next = temp1;
    temp1->next = NULL;

    while (temp3->next != NULL)
    {
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
        temp2->next = temp1;
    }

    temp3->next = temp2;
    return temp3;
}

Node* createCircularLinkedList(int* arr, int n)
{
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

    // Joining the last node to head
    newnode->next = head;

    return head;
}
