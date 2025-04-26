#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

template <typename T>
class Queue
{
  private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *front;
    Node *rear;

  public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        while (!isEmpty())
            dequeue();
    }

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(T data)
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

    T dequeue()
    {
        if (front == nullptr)
            throw std::underflow_error("Empty Queue");

        else if (front == rear)
        {
            T data = front->data;
            front = rear = nullptr;
            return data;
        }

        else
        {
            Node *temp = front;
            T data = front->data;
            front = front->next;
            delete temp;
            return data;
        }
    }
};

#endif
