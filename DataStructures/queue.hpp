#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "linkedList.hpp"

struct Queue
{
    Node *front;
    Node *rear;
};

void initializeQueue(Queue*);

void enqueue(Queue*, int);

int dequeue(Queue*);

#endif
