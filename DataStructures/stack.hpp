#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

template <typename T>
class Stack
{
  private:
    struct Node
    {
        T data;
        Node *next;

        Node() = default;

        Node(T n)
            : data(n),
              next(nullptr) {}
    };

    Node *top;

  public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    bool isEmpty()
    {
        return (top == nullptr);
    }

    void push(T n)
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

    T peek()
    {
        if (top == nullptr)
            throw std::underflow_error("Empty Stack\n");

        return top->data;
    }

    T pop()
    {
        if (top == nullptr)
            throw std::underflow_error("Empty Stack");

        T data = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;

        return data;
    }
};

#endif
