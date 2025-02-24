#ifndef STACK_HPP
#define STACK_HPP

#include "linkedList.hpp"

struct Stack
{
    Node *top;
};

typedef struct Stack Stack;

void initializeStack(Stack*);

void push(Stack*, int);

int peek(Stack*);

int pop(Stack*);

#endif
