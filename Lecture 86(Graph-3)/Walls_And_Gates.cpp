/*
Walls and Gates - [Leetcode - 285(medium)]
===========================================
You are given an m x n grid rooms initialized with these three possible values.

* -1 A wall or an obstacle.
* 0 A gate.
* INF Infinity means an empty room. 

We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example 1:

Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Example 2:

Input: rooms = [[-1]]
Output: [[-1]]
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2147483647;
const vector<int> dx = {-1, 1, 0, 0};
const vector<int> dy = {0, 0, -1, 1};

// Using multi source BFS
void wallsAndGates(vector<vector<int>>& rooms){
    if (rooms.empty() or rooms[0].empty()) return;

    int m = rooms.size();
    int n = rooms[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Add all gates to the queue
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (rooms[i][j] == 0){
                q.push({i, j});
            }
        }
    }
    // BFS
    while (!q.empty()){ // i,j -> current room's coordinate
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        // Check all four directions
        for (int k = 0; k < 4; ++k){
            int neighboursRow = i + dx[k];
            int neighboursCol = j + dy[k];

            // Check if the new position is within the grid and is an empty room
            if (neighboursRow >= 0 and neighboursRow < m and neighboursCol >= 0 and neighboursCol < n and rooms[neighboursRow][neighboursCol] == INF){
                rooms[neighboursRow][neighboursCol] = rooms[i][j] + 1;
                q.push({neighboursRow, neighboursCol});
            }
        }
    }
}

int main(){
    
    vector<vector<int>> rooms = {
        {INF, -1, 0, INF},
        {INF, INF, INF, -1},
        {INF, -1, INF, -1},
        {0, -1, INF, INF}
    };

    wallsAndGates(rooms);

    for (const auto& row : rooms) {
        for (int val : row) cout<<val<<" ";
        cout << endl;
    }

    return 0;
}