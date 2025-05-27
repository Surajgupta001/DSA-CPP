// ============ Using -> Kahn's Algorithm ========
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
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

/*
=============== Using DFS ================
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
*/ 