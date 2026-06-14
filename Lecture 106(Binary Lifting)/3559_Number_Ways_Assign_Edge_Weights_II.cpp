/*
Number of Ways to Assign Edge Weights II - [Leetcode - 3559(Hard)]
---------------------------------------------------------------------
There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.

Return an array answer, where answer[i] is the number of valid assignments for queries[i].

Since the answer may be large, apply modulo 109 + 7 to each answer[i].

Note: For each query, disregard all edges not in the path between node ui and vi.

Example 1:

Input: edges = [[1,2]], queries = [[1,1],[1,2]]

Output: [0,1]

Explanation:

Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

Example 2:

Input: edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]

Output: [2,1,4]

Explanation:

Query [1,4]: The path from Node 1 to Node 4 consists of two edges (1 → 3 and 3 → 4). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
Query [3,4]: The path from Node 3 to Node 4 consists of one edge (3 → 4). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
Query [2,5]: The path from Node 2 to Node 5 consists of three edges (2 → 1, 1 → 3, and 3 → 5). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.
 

Constraints:

2 <= n <= 105
edges.length == n - 1
edges[i] == [ui, vi]
1 <= queries.length <= 10^5
queries[i] == [ui, vi]
1 <= ui, vi <= n
edges represents a valid tree.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int mod = 1e9 + 7;

void dfs(int root,int parent, const vector<vector<int>> &graph, vector<vector<int>> &ancestorTable, vector<int> &depth) {
    // Set the immediate parent of the current node in the ancestor table
    ancestorTable[root][0] = parent;

    for(auto &neighbor : graph[root]){ // Iterate through all neighbors of the current node
        if(neighbor != parent){ // Avoid traversing back to the parent node
            depth[neighbor] = depth[root] + 1; // Set the depth of the neighbor node
            dfs(neighbor, root, graph, ancestorTable, depth); // Recursively call DFS for the neighbor node
        }
    }
}

void buildAncestorTable(int n, int cols, vector<vector<int>> &ancestorTable) {
    for(int j = 1; j < cols; j++){
        for(int node = 0; node < n; node++){
            if(ancestorTable[node][j - 1] != -1){ // Check if the ancestor at level j-1 exists
                // Set the ancestor at level j for the current node by looking up the ancestor of its ancestor at level j-1
                ancestorTable[node][j] = ancestorTable[ancestorTable[node][j - 1]][j - 1];
            }
        }
    }
}

int findLCA(int u, int v, int cols, const vector<vector<int>> &ancestorTable, const vector<int> &depth) {
    // Ensure that u is the deeper node. If not, swap u and v.
    if(depth[u] < depth[v]){
        swap(u, v); // Swap u and v to ensure u is the deeper node
    }

    // Calculate the depth difference between u and v
    int k = depth[u] - depth[v];

    // Lift u up to the same depth as v using the ancestor table
    for(int j = 0; j < cols; j++){
        if(k & (1 << j)){
            u = ancestorTable[u][j]; // Move u up by 2^j levels
        }
    }

    if(u == v){ // If u and v are the same after lifting, return u as the LCA
        return u; // Return the lowest common ancestor (LCA) of u and v
    }

    for(int j = cols - 1; j >= 0; j--){
        if(ancestorTable[u][j] != -1 && ancestorTable[u][j] != ancestorTable[v][j]){ // If the ancestors of u and v at level j are different, move both u and v up to their ancestors at level j
            u = ancestorTable[u][j]; // Move u up to its ancestor at level j
            v = ancestorTable[v][j]; // Move v up to its ancestor at level j
        }
    }

    return ancestorTable[u][0];
}

vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries) {

    int n = edges.size() + 1;

    int cols = log2(n) + 1; // Calculate the number of columns needed for the ancestor table

    vector<vector<int>> graph(n);

    for (auto &edge : edges) {
        int u = edge[0] - 1; // Convert to 0-based index
        int v = edge[1] - 1; // Convert to 0-based index

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> ancestorTable(n, vector<int>(cols, -1));
    vector<int> depth(n, 0);

    dfs(0, -1, graph, ancestorTable, depth);

    buildAncestorTable(n, cols, ancestorTable);

    vector<long long> powerOf2(n + 1);
    powerOf2[0] = 1;

    for(int i = 1; i <= n; i++){
        powerOf2[i] = (powerOf2[i - 1] * 2) % mod;
    }

    vector<int> result;

    for (auto &query : queries) {

        int u = query[0] - 1;
        int v = query[1] - 1;

        int LCA = findLCA(u, v, cols, ancestorTable, depth);

        // Calculate the distance between u and v using their depths and the depth of their lowest common ancestor (LCA)
        int d = depth[u] + depth[v] - 2 * depth[LCA];

        if (d == 0) { // If the distance is 0, it means u and v are the same node, so there are no edges in the path, resulting in 0 valid assignments
            result.push_back(0);
        } else { // If the distance is greater than 0, calculate the number of valid assignments using the precomputed powers of 2
            result.push_back((int)powerOf2[d - 1]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> edges = {{1,2}};
    vector<vector<int>> queries = {{1,1},{1,2}};
    vector<int> result = assignEdgeWeights(edges, queries);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}