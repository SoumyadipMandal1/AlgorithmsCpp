#include "linkedList.hpp"
#include <stdlib.h>

Node *createLinkedList(int *arr, int n)
{
    // Creates a linked list from array
    Node *head, *newnode;

    if (n == 0)
        return nullptr;

    head = new Node(arr[0]);
    newnode = head;

    for (int i = 1; i < n; i++)
    {
        newnode->next = new Node(arr[i]);
        newnode = newnode->next;
    }

    return head;
}

int searchLinkedList(Node *head, int key)
{
    int counter = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == key)
            return counter;
        temp = temp->next;
        counter++;
    }
    return -1;
}

Node *deleteFirst(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteLast(Node *head)
{
    Node *temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node *deleteLinkedList(Node *head, int index)
{
    if (index == 0)
        return deleteFirst(head);

    Node *currentNode = head;
    Node *previousNode;
    int counter = 0;

    while (currentNode->next != nullptr)
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
        previousNode->next = nullptr;
        free(currentNode);
        return head;
    }
}

Node *insertFirst(Node *head, int data)
{
    Node *newnode = new Node(data);
    newnode->next = head;
    return newnode;
}

Node *insertLast(Node *head, int data)
{
    Node *newnode = new Node(data);
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newnode;
    return head;
}

Node *insertLinkedList(Node *head, int data, int index)
{
    // If index is more than length, then data is inserted at the end of the linked list

    if (index == 0)
        return insertFirst(head, data);

    Node *newnode = new Node(data);
    Node *temp = head;
    int counter = 1;
    while (temp->next != nullptr)
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

Node *reverseLinkedList(Node *head)
{
    Node *temp1, *temp2, *temp3;

    if (head == nullptr)
        return nullptr;

    else if (head->next == nullptr)
        return head;

    else if (head->next->next == nullptr)
    {
        temp1 = head;
        temp2 = head->next;
        temp2->next = temp1;
        temp1->next = nullptr;
        return temp2;
    }
    temp1 = head;
    temp2 = head->next;
    temp3 = head->next->next;
    temp2->next = temp1;
    temp1->next = nullptr;

    while (temp3->next != nullptr)
    {
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
        temp2->next = temp1;
    }

    temp3->next = temp2;
    return temp3;
}

Node *createCircularLinkedList(int *arr, int n)
{
    Node *head, *newnode;

    if (n == 0)
        return nullptr;

    head = new Node(arr[0]);
    newnode = head;

    for (int i = 1; i < n; i++)
    {
        newnode->next = new Node(arr[i]);
        newnode = newnode->next;
    }

    // Joining the last node to head
    newnode->next = head;

    return head;
}

doubleNode *createDoublyLinkedList(int *arr, int n)
{
    doubleNode *head, *newnode;

    if (n == 0)
        return nullptr;

    head = new doubleNode(arr[0]);
    newnode = head;

    for (int i = 1; i < n; i++)
    {
        newnode->next = new doubleNode(arr[i]);
        newnode = newnode->next;
        newnode->next->prev = newnode;
    }

    // Making the Doubly Linked List circular
    newnode->next = head;
    head->prev = newnode;

    return head;
}
