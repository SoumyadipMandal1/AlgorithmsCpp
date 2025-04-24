#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct Node
{
    int data;
    Node *next{};

    Node() = default;

    Node(int n)
        : data(n),
          next(nullptr) {}
};

Node *createLinkedList(int *, int);

int searchLinkedList(Node *, int);

Node *deleteFirst(Node *);

Node *deleteLast(Node *);

Node *deleteLinkedList(Node *, int);

Node *insertFirst(Node *, int);

Node *insertLast(Node *, int);

Node *insertLinkedList(Node *, int, int);

Node *reverseLinkedList(Node *);

Node *createCirculatLinkedList(int *, int);

struct doublyLinkedListNode
{
    int data;
    struct doublyLinkedListNode *next;
    struct doublyLinkedListNode *prev;

    doublyLinkedListNode() = default;

    doublyLinkedListNode(int n) : data(n),
                                  next(nullptr),
                                  prev(nullptr) {}
};

typedef struct doublyLinkedListNode doubleNode;

doubleNode *createDoubleNode(int);

doubleNode *createDoublyLinkedList(int *, int);

#endif
