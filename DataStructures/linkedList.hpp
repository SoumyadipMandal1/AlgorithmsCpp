#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct singlyLinkedListNode
{
    int data;
    struct singlyLinkedListNode *next;
};

typedef struct singlyLinkedListNode Node;

Node* createNode(int);

Node* createLinkedList(int*, int);

int searchLinkedList(Node*, int);

Node* deleteFirst(Node*);

Node* deleteLast(Node*);

Node* deleteLinkedList(Node*, int);

Node* insertFirst(Node*, int);

Node* insertLast(Node*, int);

Node* insertLinkedList(Node*, int, int);

Node* reverseLinkedList(Node*);

#endif
