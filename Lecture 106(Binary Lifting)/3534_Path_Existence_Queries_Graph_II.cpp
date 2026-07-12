/*
Path Existence Queries in a Graph II - [Leetcode - 3534(Hard)]
--------------------------------------------------------------------
You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

You are also given an integer array nums of length n and an integer maxDiff.

An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

You are also given a 2D integer array queries. For each queries[i] = [ui, vi], find the minimum distance between nodes ui and vi. If no path exists between the two nodes, return -1 for that query.

Return an array answer, where answer[i] is the result of the ith query.

Note: The edges between the nodes are unweighted.

Example 1:

Input: n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]

Output: [1,1]

Explanation:

The resulting graph is:

Query	Shortest Path	Minimum Distance
[0, 3]	0 → 3	1
[2, 4]	2 → 4	1
Thus, the output is [1, 1].

Example 2:

Input: n = 5, nums = [5,3,1,9,10], maxDiff = 2, queries = [[0,1],[0,2],[2,3],[4,3]]

Output: [1,2,-1,1]

Explanation:

The resulting graph is:

Query	Shortest Path	Minimum Distance
[0, 1]	0 → 1	1
[0, 2]	0 → 1 → 2	2
[2, 3]	None	-1
[4, 3]	3 → 4	1
Thus, the output is [1, 2, -1, 1].

Example 3:

Input: n = 3, nums = [3,6,1], maxDiff = 1, queries = [[0,0],[0,1],[1,2]]

Output: [0,-1,-1]

Explanation:

There are no edges between any two nodes because:

Nodes 0 and 1: |nums[0] - nums[1]| = |3 - 6| = 3 > 1
Nodes 0 and 2: |nums[0] - nums[2]| = |3 - 1| = 2 > 1
Nodes 1 and 2: |nums[1] - nums[2]| = |6 - 1| = 5 > 1
Thus, no node can reach any other node, and the output is [0, -1, -1].

Constraints:

1 <= n == nums.length <= 105
0 <= nums[i] <= 105
0 <= maxDiff <= 105
1 <= queries.length <= 105
queries[i] == [ui, vi]
0 <= ui, vi < n
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int customUpperBound(vector<pair<int, int>>& arr, int target) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    int result = 0;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid].first <= target){
            result = mid; // Update result to the current mid
            low = mid + 1; // Move to the right half
        } else {
            high = mid - 1; // Move to the left half
        }
    }
    return result;
}

vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    // Array of pair
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; i++){
        arr[i] = {nums[i], i}; // Store the value and its index
    }

    // Sort the array based on the values
    sort(arr.begin(), arr.end());

    vector<int> nodeToIdx(n);
    for(int i=0; i<n; i++){
        int node = arr[i].second;
        nodeToIdx[node] = i;
    }

    int rows = n;
    int cols = log2(n) + 1;
    vector<vector<int>> ancestorTable(rows, vector<int>(cols, 0));

    // Fill the column first
    for(int node=0; node<n; node++){
        int farthestIdxOneHop = customUpperBound(arr, arr[node].first + maxDiff); // Find the farthest node reachable in one hop
        ancestorTable[node][0] = farthestIdxOneHop;
    }

    // Fill the rest of the ancestor table
    for(int j=1; j<cols; j++){
        for(int node=0; node<n; node++){
            ancestorTable[node][j] = ancestorTable[ancestorTable[node][j-1]][j-1];
        }
    }

    vector<int> results;
    for(auto& query : queries){
        int u = query[0];
        int v = query[1];

        int a = nodeToIdx[u];
        int b = nodeToIdx[v];
        
        if(a == b){
            results.push_back(0); // Same node, distance is 0
            continue;
        }

        if(a > b) swap(a, b); // Ensure a is less than or equal to b


        int curr = a;
        int jumps = 0;

        for(int j=cols-1; j>=0; j--){
            if(ancestorTable[curr][j] < b){
                curr = ancestorTable[curr][j];
                jumps += (1 << j);
            }
        }
        if(ancestorTable[curr][0] >= b){
            jumps++;
            results.push_back(jumps);
        } else {
            results.push_back(-1); // No path exists
        }
    }

    return results;
}

int main() {
    int n = 5;
    vector<int> nums = {1, 8, 3, 4, 2};
    int maxDiff = 3;
    vector<vector<int>> queries = {{0, 3}, {2, 4}};

    vector<int> results = pathExistenceQueries(n, nums, maxDiff, queries);

    for(int res : results) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}