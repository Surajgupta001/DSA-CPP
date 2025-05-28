/*
Maximize the Number of Target Nodes After Connecting Trees I - [LeetCode - 3372(Medium)]
-----------------------------------------------------------------------------------------
There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

Example 1:

Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2

Output: [9,7,9,8,8]

Explanation:

For i = 0, connect node 0 from the first tree to node 0 from the second tree.
For i = 1, connect node 1 from the first tree to node 0 from the second tree.
For i = 2, connect node 2 from the first tree to node 4 from the second tree.
For i = 3, connect node 3 from the first tree to node 4 from the second tree.
For i = 4, connect node 4 from the first tree to node 4 from the second tree.

Example 2:

Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1

Output: [6,3,3,3,3]

Explanation:

For every i, connect node i of the first tree with any node of the second tree.

Constraints:

2 <= n, m <= 1000
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.
0 <= k <= 1000
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// Function to perform BFS and count target nodes within k distance
int BFS(int start, vector<vector<int>>& graph, int k, int n) {
    vector<bool> visited(graph.size(), false); // To keep track of visited nodes 
    vector<int> distance(graph.size(), -1); // To keep track of distance from the start node
    queue<int> qu; // Queue for BFS

    visited[start] = true; // Mark the start node as visited
    distance[start] = 0; // Initialize distance of start node to 0
    qu.push(start); // Push the start node into the queue

    int targetNodeCount = 0;

    while (!qu.empty()) {
        int node = qu.front(); // Get the front node from the queue
        qu.pop(); // Process the node and remove it from the queue

        if (distance[node] <= k) { // If the distance from start node is within k
            targetNodeCount++; // Increment the targetNodeCount of target nodes
        }

        for (int neighbor : graph[node]) { // 
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[node] + 1;
                qu.push(neighbor);
            }
        }
    }

    return targetNodeCount; // Return the count of target nodes
}

// Function to perform DFS and count target nodes within k distance
int DFS(int node, int parent, vector<vector<int>>& graph, int k, int dist) {
    if (dist > k) return 0; // If the distance exceeds k, return 0
    int count = 1; // count itself and initialize count to 1
    for (int neighbor : graph[node]) {
        if (neighbor != parent) {
            count += DFS(neighbor, node, graph, k, dist + 1);
        }
    }
    return count;
}

vector<int> findCount(vector<vector<int>>& edges, int k) {
    int n = edges.size() + 1; // Number of nodes in the tree
    vector<vector<int>> graph(n);
    vector<int> count(n); // To store the count of target nodes for each node

    // Build the graph from edges
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // Perform BFS for each node to count target nodes within k distance
    for (int i = 0; i < n; ++i) {
        count[i] = BFS(i, graph, k, n);
        
        // Alternatively, you can use DFS instead of BFS
        // count[i] = DFS(i, -1, graph, k, 0);
    }

    return count;
}

vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    // How many nodes in tree1
    int n = edges1.size() + 1;

    vector<int> result1 = findCount(edges1, k); // Store targetNode count from each node within tree1 within k distance
    vector<int> result2 = findCount(edges2, k-1); // Store targetNode count from each node within tree2 within k-1 distance

    int maxTargetNodeCount = *max_element(result2.begin(), result2.end());

    for(int i=0; i<result1.size(); i++){
        result1[i] = result1[i] + maxTargetNodeCount; // Add the maximum target node count from tree2 to each node in tree1
    }
    return result1;
}

int main () {
    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;

    vector<int> result = maxTargetNodes(edges1, edges2, k);
    
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}