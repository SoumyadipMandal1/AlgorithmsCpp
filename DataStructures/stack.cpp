#include <stdlib.h>
#include "linkedList.hpp"
#include "stack.hpp"

void createStack(Stack *stack)
{
    stack->top = NULL;
}

void push(Stack *stack, int data)
{
    Node *newnode =(Node*)malloc(sizeof(Node*));
    newnode->data = data;
    newnode->next = stack->top;
    stack->top    = newnode;
}

int peek(Stack *stack)
{
    return stack->top->data;
}

int pop(Stack *stack)
{
    Node *temp = stack->top;
    int data   = stack->top->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}
