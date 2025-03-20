/*
Minimum Cost Walk in Weighted Graph - [Leetcode - 3108(Hard)]
=============================================================
There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.



Example 1:

Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]

Output: [1,-1]

Explanation:
To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).

In the second query, there is no walk between nodes 3 and 4, so the answer is -1.

Example 2:

Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]

Output: [0]

Explanation:
To achieve the cost of 0 in the first query, we need to move on the following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).

Constraints:

2 <= n <= 105
0 <= edges.length <= 105
edges[i].length == 3
0 <= ui, vi <= n - 1
ui != vi
0 <= wi <= 105
1 <= query.length <= 105
query[i].length == 2
0 <= si, ti <= n - 1
si != ti
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int>parent; // Global

// Function to find the parent of a node in the Union-Find data structure
int find(int x) {
    // If the node is the parent of itself, return it
    if (parent[x] == x) return x;
    // Otherwise, recursively find the parent and update the node's parent
    return parent[x] = find(parent[x]);
}

// Function to union two nodes in the Union-Find data structure
void Union(int a, int b) {
    // Update the parent of node b to be node a
    parent[b] = a;
}

// Function to calculate the minimum cost of walks for each query
vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query) {
    // Initialize the parent array and cost array for the Union-Find data structure
    parent.resize(n);
    vector<int> cost(n); // Store "And operation" cost of each component

    // Initialize each node as its own parent and set the cost to -1
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        cost[i] = -1;
    }

    // Iterate through each edge and update the Union-Find data structure
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        // Find the parents of nodes u and v
        int parent_u = find(u); // parent_u -> parent of u
        int parent_v = find(v); // parent_v -> parent of v

        // If the parents are different, union the nodes and update the cost
        if (parent_u != parent_v) {
            cost[parent_u] &= cost[parent_v];
            Union(parent_u, parent_v);
        }
        // Update the cost of the parent node with the bitwise AND of the edge weight
        cost[parent_u] &= w;
    }

    // Initialize the result vector to store the minimum cost of walks for each query
    vector<int> ans;

    // Iterate through each query and calculate the minimum cost of the walk
    for (auto &q : query) {
        int src = q[0];
        int dest = q[1];

        // Find the parents of the source and destination nodes
        int p1 = find(src);
        int p2 = find(dest);

        // If the source and destination are the same, the cost is 0
        if (src == dest)
            ans.push_back(0);
        // If the parents are different, there is no walk between the nodes
        else if (p1 != p2)
            ans.push_back(-1);
        // Otherwise, the cost is the cost of the parent node
        else
            ans.push_back(cost[p1]);
    }
    return ans;
}

int main() {
    int v = 5;                                                     // Number of vertices
    vector<vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}}; // Edges with weight
    vector<vector<int>> query = {{0, 3}, {3, 4}};                  // Queries

    vector<int> result = minimumCost(v, edges, query);

    cout << "Minimum Cost Walks: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Query-" << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}