# Kruskal Algorithm Overview

The Kruskal algorithm is a popular algorithm in graph theory used to find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.

## How Kruskal Algorithm Works

Here's a step-by-step explanation of the Kruskal algorithm:

1. Sort the Edges: Sort all the edges in non-decreasing order of their weights.
2. Create a Disjoint Set: Create a disjoint set to keep track of the connected components in the graph.
3. Iterate Over the Edges: Iterate over the sorted edges and for each edge:
4. Check for Cycle: Check if including the current edge will create a cycle in the graph. If it does, skip the edge.
5. Add the Edge: If the edge does not create a cycle, add it to the MST and merge the two connected components.

##Kruskal Algorithm Pseudocode
Here's a pseudocode representation of the Kruskal algorithm:

**Procedure Kruskal(G)**:

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

## Kruskal Algorithm Time Complexity

The time complexity of the Kruskal algorithm is O(E log E) or O(E log V), where E is the number of edges and V is the number of vertices in the graph.

## Space complexity

The space complexity is O(V + E) for the disjoint set data structure and the MST.