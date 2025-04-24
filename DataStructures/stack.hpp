#ifndef STACK_HPP
#define STACK_HPP

#include "linkedList.hpp"

class Stack
{
  private:
    Node *top;

  public:
    Stack();

    bool isEmpty();

    void push(int n);

    int peek();

    int pop();
};

#endif
