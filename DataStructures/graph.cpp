#include "graph.hpp"
#include "queue.hpp"
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

std::vector<int> breadthFirstSearch(std::vector<std::vector<Pair>> &graph, int root)
{
    // Initializing all the necessary variables
    Queue *queue = new Queue();
    std::vector<bool> isVisited(graph.size(), false);
    std::vector<int> bfs;
    int temp;

    // Initializing the first point of Breadth First Search
    queue->enqueue(root);
    isVisited[root] = true;
    bfs.push_back(root);

    while (queue->isEmpty() == false)
    {
        temp = queue->dequeue();
        for (Pair node : graph[temp])
        {
            if (isVisited[node.first] == false)
            {
                queue->enqueue(node.first);
                isVisited[node.first] = true;
                bfs.push_back(node.first);
            }
        }
    }

    return bfs;
}
