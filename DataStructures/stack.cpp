#include "stack.hpp"
#include "linkedList.hpp"
#include <stdexcept>

Stack::Stack()
{
    top = nullptr;
}

bool Stack::isEmpty()
{
    if (top == nullptr)
        return true;
    else
        return false;
}

void Stack::push(int n)
{
    Node *newnode = new Node(n);

    if (top == nullptr)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}

int Stack::peek()
{
    if (top == nullptr)
        throw std::underflow_error("Empty Stack\n");

    return top->data;
}

int Stack::pop()
{
    if (top == nullptr)
        throw std::underflow_error("Empty Stack");

    int data = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;

    return data;
}
