#ifndef STACK_HPP
#define STACK_HPP

#include "linkedList.hpp"

class Stack
{
    private:
        Node *top;

    public:
        Stack(int data);

        int pop();

        int peek();

        void push(int);
};

#endif
