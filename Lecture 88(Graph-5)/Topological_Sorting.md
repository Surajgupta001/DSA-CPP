# Topological Sorting

Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG).

Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge u -> v, vertex u comes before v in the ordering.

## Why is Topological Sorting Important?

Topological sorting is used in many applications, including:

1. Scheduling: Topological sorting can be used to schedule tasks that have dependencies on each other.
2. Course Prerequisites: Topological sorting can be used to determine the order in which courses should be taken based on their prerequisites.
3. Dependency Resolution: Topological sorting can be used to resolve dependencies between packages or modules in software development.

## How to Perform Topological Sorting

There are several algorithms to perform topological sorting, including:

1. Kahn's Algorithm: This algorithm works by choosing vertices with no incoming edges and removing them from the graph.
2. Depth-First Search (DFS): This algorithm works by performing a DFS on the graph and adding vertices to the ordering as they are finished.

## Topological Sorting in C++

Here is an implementation of topological sorting in C++ using Kahn's algorithm and DFS:

### Kahn's Algorithm

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Function to perform topological sorting using Kahn's algorithm
vector<int> topologicalSortKahn(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    vector<int> result;

    // Calculate the in-degree of each vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            inDegree[graph[i][j]]++;
        }
    }

    // Initialize a queue with vertices that have an in-degree of 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform the topological sort
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);

        // Decrease the in-degree of each neighbor
        for (int i = 0; i < graph[vertex].size(); i++) {
            inDegree[graph[vertex][i]]--;
            if (inDegree[graph[vertex][i]] == 0) {
                q.push(graph[vertex][i]);
            }
        }
    }

    // Check if the graph has a cycle
    if (result.size() != n) {
        throw runtime_error("Graph has a cycle");
    }

    return result;
}

// Example usage
int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    vector<int> result = topologicalSortKahn(graph);
    cout << "Topological order: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
```

### DFS Algorithm

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to perform DFS on the given vertex
void dfs(int vertex, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& result) {
    visited[vertex] = true;

    // Recursively visit each neighbor
    for (int i = 0; i < graph[vertex].size(); i++) {
        if (!visited[graph[vertex][i]]) {
            dfs(graph[vertex][i], graph, visited, result);
        }
    }

    // Add the vertex to the result list
    result.push_back(vertex);
}

// Function to perform topological sorting using DFS
vector<int> topologicalSortDFS(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> result;

    // Perform the DFS on each vertex
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, result);
        }
    }

    // Reverse the result list
    reverse(result.begin(), result.end());

    return result;
}

// Example usage
int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    vector<int> result = topologicalSortDFS(graph);
    cout << "Topological order: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
```

Note that the DFS algorithm has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges, while Kahn's algorithm has a time complexity of O(V + E) in the worst case. However, Kahn's algorithm is generally faster in practice because it avoids the overhead of recursive function calls.
