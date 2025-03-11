# Dependency Resolution in Graph

## Problem Statement

Given a directed acyclic graph (DAG) representing dependencies between nodes, resolve the dependencies by ordering the nodes in a way that for every edge (u, v), node u comes before node v in the ordering.

## Approach

We can use the topological sorting algorithm to resolve dependencies in a graph. Topological sorting is a linear ordering of vertices in a DAG such that for every directed edge u -> v, vertex u comes before v in the ordering.

## Algorithm

1. Create a graph: Represent the dependencies as a directed graph, where each node represents a task or a module, and a directed edge from node u to node v indicates that task u depends on task v.<br>
1. Find all nodes with no incoming edges: These nodes have no dependencies and can be resolved first.<br>
3. Remove nodes with no incoming edges: Remove these nodes from the graph and add them to the result.<br>
4. Repeat steps 2-3: Continue removing nodes with no incoming edges until the graph is empty.<br>
5. Check for cycles: If the graph is not empty after removing all nodes with no incoming edges, it means there is a cycle in the graph, and the dependencies cannot be resolved.

## Example Use Case

Suppose we have a graph representing dependencies between tasks:

* Task A depends on tasks B and C.
* Task B depends on task D.
* Task C depends on task D.
* Task D has no dependencies.<br>
The topological sorting of this graph would be: D, B, C, A.<br>
The graph can be represented as:<br>
A -> B <br>
A -> C <br>
B -> D <br>
C -> D <br>
<br>

Using the topological sorting algorithm, we can resolve the dependencies as follows:<br>

1. Find all nodes with no incoming edges: D
2. Remove node D: A -> B, A -> C, B -> D (removed), C -> D (removed)<br>
3. Find all nodes with no incoming edges: B, C
Remove nodes B and C: A -> B (removed), A -> C (removed)<br>
4. Find all nodes with no incoming edges: A<br>
6. Remove node A: (graph is empty)<br>
The resolved dependencies are: D, B, C, A<br>

## Code Implementation<br>
Here is a sample implementation of the topological sorting algorithm in C++:

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Function to perform topological sorting
vector<string> topologicalSort(unordered_map<string, vector<string>>& graph) {
    // Create a map to store the in-degree of each node
    unordered_map<string, int> inDegree;
    for (auto& node : graph) {
        inDegree[node.first] = 0;
    }
    for (auto& node : graph) {
        for (auto& neighbor : node.second) {
            inDegree[neighbor]++;
        }
    }

    // Create a queue to store nodes with no incoming edges
    queue<string> q;
    for (auto& node : inDegree) {
        if (node.second == 0) {
            q.push(node.first);
        }
    }

    // Perform topological sorting
    vector<string> result;
    while (!q.empty()) {
        string node = q.front();
        q.pop();
        result.push_back(node);
        for (auto& neighbor : graph[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for cycles
    if (result.size() != graph.size()) {
        throw runtime_error("Cycle detected in the graph");
    }

    return result;
}

int main() {
    // Create a graph representing dependencies between tasks
    unordered_map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D"}},
        {"C", {"D"}},
        {"D", {}}
    };

    // Perform topological sorting
    vector<string> result = topologicalSort(graph);

    // Print the resolved dependencies
    cout << "Resolved dependencies: ";
    for (auto& node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
```

This implementation uses an unordered map to represent the graph, where each key is a node, and its corresponding value is a vector of its neighbors. The topologicalSort function performs the topological sorting algorithm and returns a vector of nodes in the resolved order. The main function demonstrates how to use the topologicalSort function to resolve dependencies in a sample graph.