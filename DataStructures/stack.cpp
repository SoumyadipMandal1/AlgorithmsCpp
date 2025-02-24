#include <stdlib.h>
#include <stdexcept>
#include "linkedList.hpp"
#include "stack.hpp"

void initializeStack(Stack *stack)
{
    stack->top = NULL;
}

void push(Stack *stack, int data)
{
    // Creating Node
    Node *newnode =(Node*)malloc(sizeof(Node*));
    newnode->data = data;

    // Adding Node to the Stack
    newnode->next = stack->top;
    stack->top    = newnode;
}

int peek(Stack *stack)
{
    return stack->top->data;
}

int pop(Stack *stack)
{
    if (stack->top == NULL)
        throw std::underflow_error("Empty Stack");

    else
    {
        Node *temp = stack->top;
        int data   = stack->top->data;
        stack->top = stack->top->next;
        free(temp);
        return data;
    }
}
