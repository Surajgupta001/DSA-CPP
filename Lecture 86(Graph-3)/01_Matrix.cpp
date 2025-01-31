/*
01 Matrix - [Leetcode - 542(Medium)]
====================================
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/ 

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Function to update the distance matrix using multi-source BFS
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    // Enqueue all the cells that contain 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    // Directions for BFS (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Perform BFS
    while (!q.empty()){ // here i,j -> current cell coordination
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        // Update the distance of neighboring cells
        for (auto& dir : directions){ // neighborsRow and neighborCols represent the neighboring cell's coordinates.
            int neighborsRow = i + dir.first;
            int neighborsCols = j + dir.second;

            // Check if the neighboring cell is within the matrix bounds
            if (neighborsRow >= 0 && neighborsRow < m && neighborsCols >= 0 && neighborsCols < n) {
                // Update the distance if the new distance is smaller
                if (dist[neighborsRow][neighborsCols] > dist[i][j] + 1) {
                    dist[neighborsRow][neighborsCols] = dist[i][j] + 1;
                    q.push({neighborsRow, neighborsCols});
                }
            }
        }
    }

    return dist;
}

int main(){

    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> result = updateMatrix(mat);

    // Print the result
    for (auto& row : result) {
        for (int val : row) {
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}