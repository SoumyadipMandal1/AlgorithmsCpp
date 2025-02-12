#ifndef DATASTRUCTURES_HPP
#define DATASTRUCTURES_HPP

struct singlyLinkedListNode
{
    int data;
    struct singlyLinkedListNode *next;
};

typedef struct singlyLinkedListNode Node;

Node* createNode(int);

Node* createLinkedList(int*, int);

#endif
