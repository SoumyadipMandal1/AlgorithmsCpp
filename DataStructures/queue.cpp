#include "queue.hpp"
#include "linkedList.hpp"
#include <stdexcept>

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

bool Queue::isEmpty()
{
    if (front == nullptr)
        return true;
    else
        return false;
}

void Queue::enqueue(int data)
{
    // Creating Node
    Node *newnode = new Node(data);

    // Adding Node
    if (front == nullptr && rear == nullptr)
        front = rear = newnode;

    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int Queue::dequeue()
{
    if (front == nullptr)
        throw std::underflow_error("Empty Queue");

    else if (front == rear)
    {
        int data = front->data;
        front = rear = nullptr;
        return data;
    }

    else
    {
        Node *temp = front;
        int data = front->data;
        front = front->next;
        delete temp;
        return data;
    }
}
