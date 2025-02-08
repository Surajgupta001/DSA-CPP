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

int dfs(vector<vector<int>>& graph, vector<bool>& visited, int node){
    if(visited[node]) return 0;
    visited[node] = true;
    int componentSize = 1;
    for(int neighbor : graph[node]){
        componentSize += dfs(graph, visited, neighbor);
    }
    return componentSize;
}

int countPairs(int n, vector<vector<int>>& edges){
    // Create an adjacency list to represent the graph
    vector<vector<int>> graph(n);
    for(auto &edge : edges){
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    // Create visited array and total unreachable pairs
    vector<bool> visited(n, false);
    vector<int> componentSizes;

    // DFS to identify connected components
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int componentSize = dfs(graph, visited, i);
            componentSizes.push_back(componentSize);
        }
    }

    // Calculate the total unreachable pairs
    int totalPairs = 0;
    int sum = 0;
    for(int size : componentSizes){
        totalPairs += sum * size; // Multiply current component size with the sum of previous component sizes
        sum += size; // Add current component size to the sum
    }
    return totalPairs;
}

int main(){
    int n = 7;
    vector<vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    cout << countPairs(n, edges) << endl; // Output: 14
    return 0;
}