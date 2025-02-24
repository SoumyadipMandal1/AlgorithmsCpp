#ifndef STACK_HPP
#define STACK_HPP

#include "linkedList.hpp"
#include "stack.hpp"

struct Stack
{
    Node *top;
};

typedef struct Stack Stack;

void createStack(Stack*);

void push(Stack*, int);

int peek(Stack*);

int pop(Stack*);

#endif
