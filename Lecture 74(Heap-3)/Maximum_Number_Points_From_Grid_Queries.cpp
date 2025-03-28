/*
Maximum Number of Points From Grid Queries - [Leetcode - 2503(Hard)]
====================================================================
You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
Otherwise, you do not get any points, and you end this process.
After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

Example 1:


Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
Example 2:


Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
k == queries.length
1 <= k <= 104
1 <= grid[i][j], queries[i] <= 106
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
========================= BFS (TLE) ====================
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs(vector<vector<int>>& grid, int value, int m, int n){
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    visited[0][0] = true;

    int points = 0;
    while(not q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        if(grid[i][j] > value){
            continue;
        }
        points++;

        for(auto &dir : directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni >= 0 and ni < m and nj >= 0 and nj < n and not visited[ni][nj] and grid[ni][nj] < value){
                q.push({ni, nj});
                visited[ni][nj] = true;
            }
        }
    }
    return points;
} 

vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries){
    int m = grid.size();
    int n = grid[0].size();

    int query = queries.size();
    vector<int> ans(query, 0);
    for(int i = 0; i < query; i++){
        ans[i] = bfs(grid, queries[i], m, n);
    }
    return ans;
}
*/ 

/*
===================== DFS (TLE) =========================
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dfs(vector<vector<int>>& grid, int i, int j, int value, vector<vector<bool>>& visited, int m, int n){
    if(i < 0 or i >= m or j < 0 or j >= n or visited[i][j] or grid[i][j] >= value){
        return 0;
    }

    visited[i][j] = true;
    int points = 1;
    for(auto &dir : directions){
        int ni = i + dir[0];
        int nj = j + dir[1];
        points += dfs(grid, ni, nj, value, visited, m, n);
    }
    return points;
}

vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries){
    int m = grid.size();
    int n = grid[0].size();
    
    int query = queries.size();
    vector<int> ans(query, 0);
    for(int i = 0; i < query; i++){
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        ans[i] = dfs(grid, 0, 0, queries[i], visited, m, n);
    }
    return ans;
}
*/ 

// Optimal Approach using sorting and min-heap
vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries){
    int m = grid.size();
    int n = grid[0].size();
    
    int query = queries.size();
    vector<int> ans(query, 0);

    vector<pair<int, int>> sortedQuery;
    for(int i = 0; i < query; i++){
        sortedQuery.push_back({queries[i], i});
    }
    
    sort(sortedQuery.begin(), sortedQuery.end());
    
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int points = 0;
    pq.push({grid[0][0], 0, 0});
    visited[0][0] = true;

    for(int i=0; i<query; i++){
        int queryValue = sortedQuery[i].first;
        int index = sortedQuery[i].second;
        while(!pq.empty() && pq.top()[0] < queryValue){
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            points++;

            for(auto &dir : directions){
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(ni >= 0 and ni < m and nj >= 0 and nj < n and not visited[ni][nj]){
                    pq.push({grid[ni][nj], ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
        ans[index] = points;
    }
    return ans;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<int>> grid = {{1,2,3},{2,5,7},{3,5,1}};
    vector<int> queries = {5,6,2};
    vector<int> result = maxPoints(grid, queries);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
        
    return 0;
}