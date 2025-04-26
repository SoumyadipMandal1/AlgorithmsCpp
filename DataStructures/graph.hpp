#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

typedef std::pair<int, int> Pair;

void addEdgeUndirectedGraph(std::vector<std::vector<Pair>> &graph, int i, int j, int weight = 1);

void addEdgeDirectedGraph(std::vector<std::vector<Pair>> &graph, int source, int destination, int weight = 1);

std::vector<int> breadthFirstSearch(std::vector<std::vector<Pair>> &graph, int root);

#endif
