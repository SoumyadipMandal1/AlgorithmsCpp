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

#endif
