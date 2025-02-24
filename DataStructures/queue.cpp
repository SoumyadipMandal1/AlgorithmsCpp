#include <stdlib.h>
#include <stdexcept>
#include "linkedList.hpp"
#include "queue.hpp"

void initializeQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear  = NULL;
}

void enqueue(Queue *queue, int data)
{
    // Creating Node
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;

    // Adding Node
    if (queue->front == NULL && queue->rear == NULL)
        queue->front = queue->rear = newnode;

    else
    {
        queue->rear->next = newnode;
        queue->rear = newnode;
    }
}

int dequeue(Queue *queue)
{
    if (queue->front == NULL)
        throw std::underflow_error("Empty Queue");

    else if (queue->front == queue->rear)
    {
        int data = queue->front->data;
        queue->front = queue->rear = NULL;
        return data;
    }

    else
    {
        Node *temp   = queue->front;
        int data     = queue->front->data;
        queue->front = queue->front->next;
        free(temp);
        return data;
    }
}
