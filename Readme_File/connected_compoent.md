# Connected Component

A connected component is a subgraph of a graph in which any two vertices are connected to each other by paths. In other words, it is a maximal subgraph that is connected.

## Types of Connected Components

There are two types of connected components:

1. Strongly Connected Component: A strongly connected component is a subgraph in which there is a path from every vertex to every other vertex.
2. Weakly Connected Component: A weakly connected component is a subgraph in which there is a path from every vertex to every other vertex, but the path may not be directed.

## Algorithms for Finding Connected Components

There are several algorithms for finding connected components in a graph. Here are a few:

1. Depth-First Search (DFS): DFS is a popular algorithm for finding connected components. It works by traversing the graph depth-first, starting from an arbitrary vertex.
2. Breadth-First Search (BFS): BFS is another popular algorithm for finding connected components. It works by traversing the graph breadth-first, starting from an arbitrary vertex.
3. Union-Find Algorithm: The union-find algorithm is a disjoint-set data structure that can be used to find connected components.

## Weakly Connected Graph

A weakly connected graph is a graph in which there is a path from every vertex to every other vertex, but the path may not be directed. In other words, it is possible to reach any vertex from any other vertex by traversing the edges of the graph, but we may need to traverse some edges in the opposite direction.

## Properties:

1. Every vertex is reachable from every other vertex, but the path may not be directed.
2. The graph may have "dead ends" or vertices that are only reachable in one direction.
3. The graph may have edges that are only traversable in one direction.

## Characteristics:

1. A weakly connected graph may have multiple connected components.
2. A weakly connected graph is not necessarily strongly connected.
3. A weakly connected graph may have edges that are only traversable in one direction.

## Types of Weakly Connected Graphs:

1. Directed Weakly Connected Graph: A directed graph in which there is a path from every vertex to every other vertex, but the path may not be directed.
2. Undirected Weakly Connected Graph: An undirected graph in which there is a path from every vertex to every other vertex, but the path may not be directed.

Algorithms for Checking Weak Connectivity:

1. Depth-First Search (DFS): DFS can be used to check if a graph is weakly connected by traversing the graph from a given vertex and checking if all vertices are visited.
2. Breadth-First Search (BFS): BFS can also be used to check if a graph is weakly connected by traversing the graph from a given vertex and checking if all vertices are visited.

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

// vector<list<int>>undirected_unweighted_graph;
vector<vector<int>>graph;

int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void dfs(int node, unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbor : graph[node]){
        if(not visited.count(neighbor)){
            dfs(neighbor, visited);
        }
    }
}

int connected_component(){
    unordered_set<int>visited;
    int count = 0;
    for(int i=0;i<v;i++){
        // go to every vertex
        // if from a vertex we can initialse a dfs, we got one more cc
        if(visited.count(i) == 0){
            count++;
            dfs(i, visited);
        }
    }
    return count; // return the count of connected components
}

int main(){

    cout << "Enter the number of vertices: ";
    cin >> v;
    // graph.resize(v, list<int> ());
    graph.resize(v);
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    while(e--){
        int src, dest;
        cout << "Enter source and destination: ";
        cin >> src >> dest;
        // add_edge(src, dest); // unwaighted graph
        add_edge(src, dest, false); // waighted graph

    }
    int connected_components = connected_component(); // call the function and store the result
    cout<<"Connected Component : "<<connected_components<<endl;

    return 0;
}
```

## Time Complexity

The time complexity of finding weakly connected components in a directed graph is O(V + E), where:

V is the number of vertices (nodes) in the graph.
E is the number of edges in the graph.
This is because we can use a graph traversal algorithm, such as Depth-First Search (DFS) or Breadth-First Search (BFS), to visit all vertices and edges in the graph.

## Space Complexity

The space complexity of finding weakly connected components in a directed graph is O(V), where:

V is the number of vertices (nodes) in the graph.
This is because we need to store the visited vertices and the components they belong to.


## Strongly Connected Component (SCC)

## Overview

A Strongly Connected Component (SCC) is a subgraph of a directed graph where there is a path from every vertex to every other vertex in the subgraph.

## Key Properties of SCC

* A path exists from every vertex to every other vertex in the SCC.
* The SCC is a maximal subgraph, meaning that no additional vertices can be added to the SCC without violating the property of strong connectivity.

## Kosaraju's Algorithm for Finding SCC

Kosaraju's algorithm is a linear-time algorithm for finding SCCs in a directed graph. The algorithm consists of the following steps:

* Step 1: Perform DFS on the original Graph

    - Perform a depth-first search (DFS) on the original graph to fill a stack with vertices in the order they finish.
    - This step is implemented in the fillStack function.

* Step 2: Create the Transpose Graph

    - Create the transpose graph by reversing the direction of all edges in the original graph.
    - This step is implemented in the findStronglyConnectedComponents function.

* Step 3: Perform DFS on the Transpose Graph

    - Perform a DFS on the transpose graph to find SCCs.
    - Start the DFS from the top vertex in the stack and explore all reachable vertices.
    - This step is implemented in the findSCC function.

* Step 4: Output the SCCs

## Algorithms
```cpp
/*
Strongly Connected Component (SCC)
==================================
Kosaraju's Algorithm
*/ 

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <stack>
using namespace std;

vector<vector<int>> graph; // global
int v; // no. of vertices
vector<vector<int>> transposeGraph; // global

// Function to add edge to the graph
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

// Function to perform DFS and fill the stack with vertices in the order they finish
void fillStack(int vertex, vector<bool>& visited, stack<int>& st) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            fillStack(neighbor, visited, st);
        }
    }
    st.push(vertex);
}

// Function to perform DFS on the transpose graph and find SCC
void findSCC(int vertex, vector<bool>& visited, vector<int>& scc) {
    visited[vertex] = true;
    scc.push_back(vertex);
    for (int neighbor : transposeGraph[vertex]) {
        if (!visited[neighbor]) {
            findSCC(neighbor, visited, scc);
        }
    }
}

// Function to find Strongly Connected Components
void findStronglyConnectedComponents() {
    stack<int> s;
    vector<bool> visited(v, false);
    int sccCount = 0; // Initialize SCC count

    // Fill the stack with vertices in the order they finish
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            fillStack(i, visited, s);
        }
    }

    // Create the transpose graph
    transposeGraph.resize(v);
    for (int i = 0; i < v; i++) {
        for (int neighbor : graph[i]) {
            transposeGraph[neighbor].push_back(i);
        }
    }

    // Reset the visited array
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }

    // Find SCC
    while (!s.empty()) {
        int vertex = s.top();
        s.pop();
        if (!visited[vertex]) {
            vector<int> scc;
            findSCC(vertex, visited, scc);
            cout << "Strongly Connected Component: ";
            for (int i : scc) {
                cout << i << " ";
            }
            cout << endl;
            sccCount++; // Increment SCC count
        }
    }

    cout << "Number of Strongly Connected Components: " << sccCount << endl;
}

int main(){
    
    cout<<"Enter the number of vertices: ";
    cin>>v;
    
    graph.resize(v);
    
    int e;
    cout<<"Enter the number of edges: ";
    cin>>e;
    
    while(e--){
        int src, dest;
        cout<<"Enter source and destination: ";
        cin>>src>>dest;
        add_edge(src, dest, false); // Changed to false to create a directed graph
    }
    
    findStronglyConnectedComponents();
    
    return 0;
}
```

## Time Complexity
The time complexity of Kosaraju's algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph.

## Space Complexity
The space complexity of Kosaraju's algorithm is O(V + E), where V is the number of vertices and E is the number of edges in the graph.