#include "graph.hpp"
#include "queue.hpp"
#include <stdlib.h>
#include <vector>

typedef std::pair<int, int> P;

void addEdgeUndirectedGraph(std::vector<std::vector<P>> &graph, int i, int j, int weight)
{
    // Adds an edge between vertex i and j
    graph[i].push_back({j, weight});
    graph[j].push_back({i, weight});
}

void addEdgeDirectedGraph(std::vector<std::vector<P>> &graph, int source, int destination, int weight)
{
    // Adds an edge between i and j
    graph[source].push_back({destination, weight});
}

std::vector<int> bfs(std::vector<std::vector<P>> &graph, int root)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    std::vector<bool> isVisited(graph.size(), false);

    enqueue(queue, root);
    isVisited[root] = true;

    while (queue->next != nullptr)
}
