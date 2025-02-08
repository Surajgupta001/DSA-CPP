/*
Most Stones Removed with Same Row or Column - [Leetcode - 947(Medium)]
=======================================================================
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
*/ 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function to find the parent of a node
int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);  // Path compression
    }
    return parent[x];
}

// Function to union two nodes
void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int removeStones(vector<vector<int>>& stones){
    /*
    * Time: O(n);
    * Space: O(n);
    */ 
    int n = stones.size();
    vector<int> parent(n);
    vector<int> rank(n, 1);

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Maps to store the first occurrence of a row or column
    unordered_map<int, int> rowMap;
    unordered_map<int, int> colMap;

    for (int i = 0; i < n; i++) {
        int row = stones[i][0];
        int col = stones[i][1];

        // If the row has been seen before, union the current stone with the first stone in this row
        if (rowMap.count(row)) {
            unite(i, rowMap[row], parent, rank);
        }
        else{
            rowMap[row] = i;
        }

        // If the column has been seen before, union the current stone with the first stone in this column
        if(colMap.count(col)) {
            unite(i, colMap[col], parent, rank);
        }
        else{
            colMap[col] = i;
        }
    }

    // Count the number of unique roots (connected components)
    unordered_set<int> uniqueRoots;
    for(int i = 0; i < n; i++) {
        uniqueRoots.insert(find(i, parent));
    }

    return n - uniqueRoots.size();
}

int main() {
    
    vector<std::vector<int>> stones1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    
    cout << removeStones(stones1) << std::endl;  // Output: 5

    return 0;
}