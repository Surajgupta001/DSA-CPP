# Prim's Algorithm Overview

Prim's algorithm is another popular algorithm in graph theory used to find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.

## How Prim's Algorithm Works

Here's a step-by-step explanation of Prim's algorithm:

1. Initialize a priority queue to store edges with their weights.
2. Start from a source node and push it into the priority queue with weight 0.
3. Maintain a set of visited nodes to avoid cycles.
4. While the priority queue is not empty and the number of edges in the MST is less than (n-1):
   - Extract the edge with the smallest weight.
   - If the destination node of this edge is already visited, skip it.
   - Otherwise, add the edge to the MST, mark the node as visited, and update the total weight.
   - Push all adjacent edges of the current node into the priority queue if they lead to unvisited nodes and have smaller weights.
5. Return the total weight of the MST.

## Prim's Algorithm Pseudocode

Here's a pseudocode representation of Prim's algorithm:

```cpp
function prims(graph, src, n):
    priority_queue = MinHeap()
    visited = Set()
    parent = Array(n+1)
    weights = Map()
    for i from 1 to n:
        weights[i] = Infinity
    priority_queue.push((0, src))
    weights[src] = 0

    totalCount = 0
    totalWeight = 0

    while totalCount < n and not priority_queue.isEmpty():
        (currentWeight, currentNode) = priority_queue.pop()
        if currentNode in visited:
            continue
        visited.add(currentNode)
        totalCount += 1
        totalWeight += currentWeight

        for (neighbor, weight) in graph[currentNode]:
            if neighbor not in visited and weights[neighbor] > weight:
                priority_queue.push((weight, neighbor))
                parent[neighbor] = currentNode
                weights[neighbor] = weight

    return totalWeight
```

## Prim's Algorithm Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <climits>
#define ll long long int
// #define pp pair<int, int>
using namespace std;

vector<list<pair<int,int>>>graph; // <int,int> ---> <vertex, weight> -- weighted graph
void add_edge(int u, int v, int wt, bool bi_dir = true){
    graph[u].push_back({v, wt});
    if(bi_dir) graph[v].push_back({u, wt});
}

ll prims(int src, int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // {wt, node}
    unordered_set<int>visited;
    vector<int>parent(n+1);
    unordered_map<int,int>mp;
    for(int i=1;i<=n;i++) mp[i] = INT_MAX;
    q.push({0, src});
    mp[src] = 0;

    int totalCount = 0; // 0 ---> n-1 edges
    int ans = 0; // sum of wts
    while(totalCount < n and not q.empty()){
        pair<int,int> curr = q.top();
        if(visited.count(curr.second)){
            q.pop();
            continue;
        }
        visited.insert(curr.second);
        totalCount++;
        ans += curr.first;
        q.pop();
        for(auto neighbour : graph[curr.second]){
            if(not visited.count(neighbour.first) and mp[neighbour.first] > neighbour.second){
                q.push({neighbour.second, neighbour.first});
                parent[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    graph.resize(n+1, list<pair<int,int>>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u, v, wt);
    }
    int src;
    cin>>src;
    cout<<prims(src, n)<<endl;
    return 0;
}
```

## Prim's Algorithm Time Complexity

The time complexity of Prim's algorithm is O(E log V), where E is the number of edges and V is the number of vertices in the graph. This is due to the use of a priority queue.

## Space Complexity

The space complexity is O(V + E) for storing the graph and the priority queue.
