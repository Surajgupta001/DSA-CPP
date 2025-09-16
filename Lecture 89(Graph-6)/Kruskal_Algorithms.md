# Kruskal Algorithm Overview

The Kruskal algorithm is a popular algorithm in graph theory used to find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.

## How Kruskal Algorithm Works

Here's a step-by-step explanation of the Kruskal algorithm:

1. Sort the Edges: Sort all the edges in non-decreasing order of their weights.
2. Create a Disjoint Set: Create a disjoint set to keep track of the connected components in the graph.
3. Iterate Over the Edges: Iterate over the sorted edges and for each edge:
4. Check for Cycle: Check if including the current edge will create a cycle in the graph. If it does, skip the edge.
5. Add the Edge: If the edge does not create a cycle, add it to the MST and merge the two connected components.

## Kruskal Algorithm Pseudocode

Here's a pseudocode representation of the Kruskal algorithm:

```cpp
    // Sort the edges in non-decreasing order of their weights
    Sort the edges of G in non-decreasing order of their weights

    // Create a disjoint set to keep track of the connected components
    Create a disjoint set S

    // Initialize the MST
    Initialize the MST as an empty graph

    // Iterate over the sorted edges
    For each edge (u, v) in the sorted edges:
        // Check if including the current edge will create a cycle
        If find(u) != find(v):
            // Add the edge to the MST
            Add the edge (u, v) to the MST
            // Merge the two connected components
            Union(u, v)

    // Return the MST
    Return the MST
```

## Kruskal Algorithm Code

```cpp
/*
========== Understanding ==============
Special Subtree ===> tree ----> no cycle 
Subgraph ==> it containsn all the vertices.

MST = > Minimum Spanning Tree
Tree -> graph having no cycle
Spanning -> subgraph having all vertices but min no. of edges available to keep it connected.
*/ 

/*
KRUSKAL's Algorithms
1. One by one keep a picking edge with min weight
2. If choosing an edge forms a cycle avoid it, else it
edge list -> sort by weight
DSU
*/ 

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int> &parent, int a) {
    return parent[a] = ((parent[a] == a) ? a : find(parent, parent[a]));
}

void Union(vector<int> &par, vector<int> &rank, int a, int b) {
    a = find(par, a);
    b = find(par, b);
    if(a == b) return;
    if(rank[a] >= rank[b]) {
        rank[a]++;
        par[b] = a;
    } else {
        rank[b]++;
        par[a] = b;
    }
}

class Edge {
public:
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

ll kruskals(vector<Edge> &input, int n, int e) { // O(V + ElogE)
    sort(input.begin(), input.end(), cmp); // ElogE
    vector<int> parent(n+1);
    vector<int> rank(n+1, 1);
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    int edgeCount = 0; // n-1
    int i = 0;
    ll ans = 0;
    while(edgeCount < n-1 and i < input.size()) { // V-1 -> O(Vlg*V)
        Edge curr = input[i]; // because input is sorted so we will get min wt edge
        int srcPar = find(parent, curr.src);
        int destpar = find(parent, curr.dest);
        if(srcPar != destpar) {
            // include edge as this will not make cycle
            Union(parent, rank, srcPar, destpar);
            ans += curr.wt;
            edgeCount++;
        }

        i++; // doesnt matter u picked the last edge or not, we still need to go to next edge
    }

    return ans;
}

int main(){   
    int n, e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i = 0; i < e; i++) {
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v, n, e)<<endl;

    return 0;
}
```

Here's a pseudocode representation of the Kruskal algorithm:

## Kruskal Algorithm Time Complexity

The time complexity of the Kruskal algorithm is O(E log E) or O(E log V), where E is the number of edges and V is the number of vertices in the graph.

## Space complexity

The space complexity is O(V + E) for the disjoint set data structure and the MST.
