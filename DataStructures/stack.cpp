#include "linkedList.hpp"
#include "stack.hpp"

Stack::Stack(int data)
{
    this->top = new Node();
    this->top->data = data;
    this->top->next = nullptr;
}

int Stack::pop()
{
    int data = this->top->data;
    Node *temp = this->top;
    top = top->next;
    delete temp;
    return data;
}

int Stack::peek()
{
    return this->top->data;
}

void Stack::push(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = top;
    top = temp;
}
