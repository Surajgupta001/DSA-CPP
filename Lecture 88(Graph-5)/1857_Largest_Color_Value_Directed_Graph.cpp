/*
Largest Color Value in a Directed Graph - [Leetcode - 1857(Hard)]
------------------------------------------------------------------
There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.

You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.

A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.

Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

Example 1:

Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).

Example 2:

Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.


Constraints:

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors consists of lowercase English letters.
0 <= aj, bj < n

This is the classic Kahn's algorithm approach for topological sorting in a directed graph.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    // Build graph and in-degree array
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }

    // Color count for each node: colorCount[node][color]
    vector<vector<int>> colorCount(n, vector<int>(26, 0));
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            colorCount[i][colors[i] - 'a'] = 1;
        }
    }

    int result = 0;
    int countNodes = 0;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        countNodes++;
        for (int colorIdx = 0; colorIdx < 26; ++colorIdx){
            result = max(result, colorCount[currNode][colorIdx]);
        }
        for (int node : graph[currNode]) {
            for (int colorIdx = 0; colorIdx < 26; ++colorIdx) {
                int add = (colors[node] - 'a' == colorIdx) ? 1 : 0;
                colorCount[node][colorIdx] = max(colorCount[node][colorIdx], colorCount[currNode][colorIdx] + add);
            }
            if (--inDegree[node] == 0) {
                q.push(node);
            }
        }
    }
    // If there are still nodes with non-zero in-degree, it means there's a cycle
    if (countNodes < n) return -1;
    return result;
}

int main() {
    string colors = "abaca";
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};
    cout << "Largest Color Value: " << largestPathValue(colors, edges) << endl; // Output: 3

    colors = "a";
    edges = {{0, 0}};
    cout << "Largest Color Value: " << largestPathValue(colors, edges) << endl; // Output: -1

    return 0;
}