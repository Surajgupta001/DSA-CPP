# Kahn's Algorithm

Kahn's algorithm is a popular algorithm for performing topological sorting on a directed acyclic graph (DAG). It was first proposed by Arthur B. Kahn in 1962.

## Overview

Kahn's algorithm works by repeatedly removing nodes with no incoming edges from the graph and adding them to the result. The algorithm terminates when all nodes have been removed from the graph, or when a cycle is detected.

## Step-by-Step Explanation

Here is a step-by-step explanation of Kahn's algorithm:

1. Create a graph: Represent the dependencies as a directed graph, where each node represents a task or a module, and a directed edge from node u to node v indicates that task u depends on task v.
2. Find all nodes with no incoming edges: These nodes have no dependencies and can be resolved first.
3. Remove nodes with no incoming edges: Remove these nodes from the graph and add them to the result.
4. Update the in-degree of neighboring nodes: For each node that was removed, decrement the in-degree of its neighboring nodes.
5. Repeat steps 2-4: Continue removing nodes with no incoming edges until the graph is empty.
6. Check for cycles: If the graph is not empty after removing all nodes with no incoming edges, it means there is a cycle in the graph, and the dependencies cannot be resolved.

## Example Walkthrough

Suppose we have a graph representing dependencies between tasks:

* Task A depends on tasks B and C.
* Task B depends on task D.
* Task C depends on task D.
* Task D has no dependencies.

The graph can be represented as:

1. A -> B
2. A -> C
3. B -> D
4. C -> D

Here is a step-by-step walkthrough of Kahn's algorithm:

1. Find all nodes with no incoming edges: D
2. Remove node D: A -> B, A -> C, B -> D (removed), C -> D (removed)
3. Update the in-degree of neighboring nodes: B and C now have no incoming edges
4. Find all nodes with no incoming edges: B, C
5. Remove nodes B and C: A -> B (removed), A -> C (removed)
6. Update the in-degree of neighboring nodes: A now has no incoming edges
7. Find all nodes with no incoming edges: A
8. Remove node A: (graph is empty)

The resolved dependencies are: D, B, C, A

## Pseudocode

Kahn's algorithm can be implemented using a queue to keep track of nodes with no incoming edges (in-degree of zero). The algorithm iteratively removes these nodes and updates the in-degrees of their neighbors until all nodes are processed or a cycle is detected.
Here is a pseudocode implementation of Kahn's algorithm:

```cpp
function Kahn'sAlgorithm(graph):
    // Create a map to store the in-degree of each node
    inDegree = {}
    for each node in graph:
        inDegree[node] = 0
    for each node in graph:
        for each neighbor in node's neighbors:
            inDegree[neighbor]++

    // Create a queue to store nodes with no incoming edges
    queue = []
    for each node in graph:
        if inDegree[node] == 0:
            queue.push(node)

    // Perform topological sorting
    result = []
    while queue is not empty:
        node = queue.pop()
        result.push(node)
        for each neighbor in node's neighbors:
            inDegree[neighbor]--
            if inDegree[neighbor] == 0:
                queue.push(neighbor)

    // Check for cycles
    if result.size() != graph.size():
        throw "Cycle detected in the graph"

    return result
```

## Khan's Algorithms

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
int v; // no of vertex;
void add_edge(int a, int b, bool biDir = true){
    graph[a].push_back(b);
    if(biDir) graph[b].push_back(a);
}

void topoBFS(){
    // Kahn algorithms
    vector<int> indegree(v, 0);
    for(int i = 0; i < v; i++){
        for(auto neighbour : graph[i]){
            // i -> neighbours
            indegree[neighbour]++;
        }
    }
    // Create a queue and enqueue all vertices with indegree 0
    queue<int>q;
    unordered_set<int> visited;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
            visited.insert(i);
        }
    }
    // Process all vertices in the queue
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // Process this node
        cout<<node<<" ";
        for(auto neighbour : graph[node]){
            if(not visited.count(neighbour)){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}
int main(){
    
    cout<<"Enter the number of vertex: ";
    cin>>v;

    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;

    graph.resize(v, list<int>());
    while(e--){
        int x, y;
        cin>>x>>y;
        add_edge(x, y, false);
    }
    topoBFS();
    return 0;
}
```

## Time Complexity

The time complexity of Kahn's algorithm is O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph. This is because we need to iterate over all nodes and edges to perform the topological sorting.

## Space Complexity

The space complexity of Kahn's algorithm is O(V), where V is the number of vertices (nodes) in the graph. This is because we need to store the in-degree of each node and the result of the topological sorting.
