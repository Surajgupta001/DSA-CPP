/*
Minimum Operations to Make a Uni-Value Grid - [Leetcode - 2033(Medium)]
=========================================================================
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

Example 1:


Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following: 
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.

Example 2:

Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.

Example 3:

Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 105
1 <= m * n <= 105
1 <= x, grid[i][j] <= 104
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> v; //O(m*n)
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            v.push_back(grid[i][j]);
        }
    }

    //sort(begin(v), end(v)); //O(v.size()log.v.size())
    nth_element(begin(v), begin(v) + v.size()/2, end(v)); //O(v.size()) -> for cpp users
    //{4, 2, 8, 6}
    //{4, 2, 6, 8} - nth_element
    //{2, 4, 6, 8} - complete sorting

    int target = v[v.size()/2];
    int ans = 0;
    
    for(int &itr : v) { //O(m*n)
        if((itr % x) != (target % x)) {
            return -1;
        }
        ans += abs(target-itr)/x;
        
        // ans += ((itr % x) != (target % x)) ? -1 : abs(target-itr)/x;
    }

    return ans;
}

int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x = 2;
    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    cout << minOperations(grid, x) << endl;
    
    return 0;
}