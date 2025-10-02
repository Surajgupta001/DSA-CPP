/*
Find Center of Star Graph - [leetcode - 1791(Easy)]
=====================================================
There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

Example 1:


Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
Example 2:

Input: edges = [[1,2],[5,1],[1,3],[1,4]]
Output: 1
*/ 

#include <iostream>
#include <vector>
using namespace std;

// Approach-1: Using HashMap
int findCenter(vector<vector<int>>& edges) {
    int n = edges.size() + 1; // Number of nodes
    vector<int> degree(n + 1, 0); // Degree array to count edges for each node

    // Count the degree of each node
    for (auto& edge : edges) {
        degree[edge[0]]++;
        degree[edge[1]]++;
    }

    // The center node will have a degree of n - 1
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == n - 1) {
            return i;
        }
    }

    return -1; // This line should never be reached for a valid star graph
}

// Approach-2: Using the property of star graph
int findCenter(vector<vector<int>>& edges){
    // The center node must be present in the first two edges
    int a = edges[0][0]; // First node of the first edge
    int b = edges[0][1]; // Second node of the first edge

    // Check which node from the first edge is present in the second edge
    int c = edges[1][0]; // First node of the second edge
    int d = edges[1][1]; // Second node of the second edge

    // Return the common node
    return (c == a || c == b) ? c : d;
}

int main(){
    
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    
    cout<<"Center of the star graph is: "<<findCenter(edges)<<endl;
    
    return 0;
}