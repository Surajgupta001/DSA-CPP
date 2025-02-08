/*
Count Unreachable Pairs of Nodes in an Undirected Graph - [Leetcode - 2316(Medium)]
====================================================================================

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Example 1:

Input: n = 3, edges = [[0,1],[0,2],[1,2]]
Output: 0
Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

Example 2:

Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
Output: 14
Explanation: There are 14 pairs of nodes that are unreachable from each other:
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
Therefore, we return 14.
*/ 
#include <iostream>
#include <vector>
using namespace std;

// Function to find the parent of a node
int find(int* parent, int x) {
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]); // Path compression
    }
    return parent[x];
}

// Function to unite two nodes
void unite(int* parent, int* size, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY]) {
            std::swap(rootX, rootY);
        }
        parent[rootY] = rootX; // Merge smaller component into larger one
        size[rootX] += size[rootY]; // Update size of the larger component
    }
}

// Function to count the number of unreachable pairs
int countPairs(int n, vector<vector<int>>& edges) {
    int* parent = new int[n];
    int* size = new int[n];

    // Initialize parent and size arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i; // Each node is its own parent initially
        size[i] = 1;
    }

    // Union all edges
    for (auto& edge : edges) {
        unite(parent, size, edge[0], edge[1]);
    }

    // Count the sizes of all connected components
    vector<int> componentSizes;
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        int root = find(parent, i);
        if (!visited[root]) {
            componentSizes.push_back(size[root]);
            visited[root] = true;
        }
    }

    // Calculate the total number of unreachable pairs
    int totalPairs = 0;
    int sum = 0;
    for (int size : componentSizes) {
        totalPairs += sum * size; // Multiply current component size with the sum of previous component sizes
        sum += size; // Add current component size to the sum
    }

    return totalPairs;
}

int main() {
    int n = 7;
    vector<vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
    std::cout << countPairs(n, edges) << std::endl; // Output: 14
    return 0;
}