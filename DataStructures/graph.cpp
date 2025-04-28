#include "graph.hpp"
#include "binaryTree.hpp"
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
    auto *queue = new Queue<int>();
    std::vector<bool> isVisited(graph.size(), false);
    std::vector<int> bfs;
    int temp;

    // Initializing the first point of Breadth First Search
    queue->enqueue(startpos);
    isVisited[startpos] = true;

    while (!queue->isEmpty())
    {
        // Dequeueing a node from the queue
        temp = queue->dequeue();
        bfs.push_back(temp);

        // Enqueueing rest of the nodes into the queue
        for (Pair node : graph[temp])
        {
            if (!isVisited[node.first])
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
    auto *stack = new Stack<int>();
    std::vector<bool> isVisited(graph.size(), false);
    std::vector<int> dfs;
    int temp;

    // Initializing the first point of Breadth First Search
    stack->push(startpos);
    isVisited[startpos] = true;

    while (!stack->isEmpty())
    {
        // Taking out a node from the stack
        temp = stack->pop();
        dfs.push_back(temp);

        // Pushing rest of the nodes into the stack
        for (Pair node : graph[temp])
        {
            if (!isVisited[node.first])
            {
                stack->push(node.first);
                isVisited[node.first] = true;
            }
        }
    }
    return dfs;
}

binaryTreeNode *bfsSpanningTree(std::vector<std::vector<Pair>> &graph, int startpos)
{
    // Initializing all the necessary variables
    std::vector<bool> isVisited(graph.size(), false);
    auto *queue = new Queue<std::pair<binaryTreeNode *, int>>();
    binaryTreeNode *root, *temp;
    std::pair<binaryTreeNode *, int> bfsPair;

    // Initializing the first point of Depth First Search
    isVisited[startpos] = true;
    queue->enqueue({NULL, startpos});

    while (!queue->isEmpty())
    {
        // Taking out a node from the queue
        bfsPair = queue->dequeue();
        if (bfsPair.first == nullptr)
        {
            root = new binaryTreeNode(bfsPair.second);
            temp = root;
        }
        else
        {
            if (bfsPair.first->left == nullptr)
            {
                bfsPair.first->left = new binaryTreeNode(bfsPair.second);
                temp = bfsPair.first->left;
            }
            else
            {
                bfsPair.first->right = new binaryTreeNode(bfsPair.second);
                temp = bfsPair.first->right;
            }
        }

        // Enqueueing rest of the nodes into the queue
        for (Pair node : graph[bfsPair.second])
        {
            if (!isVisited[node.first])
            {
                queue->enqueue({temp, node.first});
                isVisited[node.first] = true;
            }
        }
    }

    return root;
}

binaryTreeNode *dfsSpanningTree(std::vector<std::vector<Pair>> &graph, int startpos)
{
    // Initializing all the necessary variables
    std::vector<int> isVisited(graph.size(), false);
    auto *stack = new Stack<std::pair<binaryTreeNode *, int>>();
    binaryTreeNode *root, *temp;
    std::pair<binaryTreeNode *, int> dfsPair;

    // Initializing the first point of Depth First Search
    isVisited[startpos] = true;
    stack->push({NULL, startpos});

    while (!stack->isEmpty())
    {
        // Taking out a node from the stack
        dfsPair = stack->pop();
        if (dfsPair.first == nullptr)
        {
            root = new binaryTreeNode(dfsPair.second);
            temp = root;
        }
        else
        {
            if (dfsPair.first->left == nullptr)
            {
                dfsPair.first->left = new binaryTreeNode(dfsPair.second);
                temp = dfsPair.first->left;
            }
            else
            {
                dfsPair.first->right = new binaryTreeNode(dfsPair.second);
                temp = dfsPair.first->right;
            }
        }

        // Pushing rest of the nodes into the stack
        for (Pair node : graph[dfsPair.second])
        {
            if (!isVisited[node.first])
            {
                stack->push({temp, node.first});
                isVisited[node.first] = true;
            }
        }
    }

    return root;
}
