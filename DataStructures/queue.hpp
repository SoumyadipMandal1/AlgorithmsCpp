#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "linkedList.hpp"

class Queue
{
  private:
    Node *front;
    Node *rear;

  public:
    Queue();

    bool isEmpty();

    void enqueue(int n);

    int dequeue();
};

#endif
