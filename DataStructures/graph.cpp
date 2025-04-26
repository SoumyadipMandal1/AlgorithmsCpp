#include "graph.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include <vector>

void addEdgeUndirectedGraph(std::vector<std::vector<Pair>> &graph, int i, int j, int weight)
{
    // Adds an edge between vertex i and j
    graph[i].push_back({j, weight});
    graph[j].push_back({i, weight});
}

void addEdgeDirectedGraph(std::vector<std::vector<Pair>> &graph, int source, int destination, int weight)
{
    // Adds an edge between i and j
    graph[source].push_back({destination, weight});
}

std::vector<int> breadthFirstSearch(std::vector<std::vector<Pair>> &graph, int startpos)
{
    // Initializing all the necessary variables
    Queue *queue = new Queue();
    std::vector<bool> isVisited(graph.size(), false);
    std::vector<int> bfs;
    int temp;

    // Initializing the first point of Breadth First Search
    queue->enqueue(startpos);
    isVisited[startpos] = true;

    while (queue->isEmpty() == false)
    {
        // Dequeueing a node from the queue
        temp = queue->dequeue();
        bfs.push_back(temp);

        // Enqueueing rest of the nodes into the queue
        for (Pair node : graph[temp])
        {
            if (isVisited[node.first] == false)
            {
                queue->enqueue(node.first);
                isVisited[node.first] = true;
            }
        }
    }
    return bfs;
}

std::vector<int> depthFirstSearch(std::vector<std::vector<Pair>> &graph, int startpos)
{
    // Initializing all the necessary variables
    Stack *stack = new Stack();
    std::vector<bool> isVisited(graph.size(), false);
    std::vector<int> dfs;
    int temp;

    // Initializing the first point of Breadth First Search
    stack->push(startpos);
    isVisited[startpos] = true;

    while (stack->isEmpty() == false)
    {
        // Taking out a node from the stack
        temp = stack->pop();
        dfs.push_back(temp);

        // Pushing rest of the nodes into the stack
        for (Pair node : graph[temp])
        {
            if (isVisited[node.first] == false)
            {
                stack->push(node.first);
                isVisited[node.first] = true;
            }
        }
    }
    return dfs;
}
