/*
Check if Grid can be Cut into Sections - [Leetcode - 3394(Medium)]
==================================================================
You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.

Example 1:

Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]

Output: true

Explanation:

The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.

Example 2:

Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]

Output: true

Explanation:

We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

Example 3:

Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]

Output: false

Explanation:

We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.

 
Constraints:

3 <= n <= 109
3 <= rectangles.length <= 105
0 <= rectangles[i][0] < rectangles[i][2] <= n
0 <= rectangles[i][1] < rectangles[i][3] <= n
No two rectangles overlap.
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();

    sort(begin(intervals), end(intervals));

    vector<vector<int>> result;

    result.push_back(intervals[0]);
    //{1, 5}, {5, 7}
    //{1, 7}
    for(int i = 1; i < n; i++) {
        if(intervals[i][0] < result.back()[1]) { //overlapping
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    //x-axis
    vector<vector<int>> hor;
    
    //y-aixs
    vector<vector<int>> vert;

    for(auto &coord : rectangles) {
        int x1 = coord[0];
        int y1 = coord[1];
        int x2 = coord[2];
        int y2 = coord[3];

        hor.push_back({x1, x2});
        vert.push_back({y1, y2});
    }

    vector<vector<int>> result1 = merge(hor);
    if(result1.size() >= 3)
        return true;

    vector<vector<int>> result2 = merge(vert);

    return result2.size() >= 3;
}

    
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example 1
    int n1 = 5;
    vector<vector<int>> rectangles1 = {{1, 0, 5, 2}, {0, 2, 2, 4}, {3, 2, 5, 3}, {0, 4, 4, 5}};
    bool result1 = checkValidCuts(n1, rectangles1);
    cout << "Example 1: " << (result1 ? "true" : "false") << endl;

    // Example 2
    int n2 = 4;
    vector<vector<int>> rectangles2 = {{0, 0, 1, 1}, {2, 0, 3, 4}, {0, 2, 2, 3}, {3, 0, 4, 3}};
    bool result2 = checkValidCuts(n2, rectangles2);
    cout << "Example 2: " << (result2 ? "true" : "false") << endl;

    // Example 3
    int n3 = 4;
    vector<vector<int>> rectangles3 = {{0, 2, 2, 4}, {1, 0, 3, 2}, {2, 2, 3, 4}, {3, 0, 4, 2}, {3, 2, 4, 4}};
    bool result3 = checkValidCuts(n3, rectangles3);
    cout << "Example 3: " << (result3 ? "true" : "false") << endl;

    return 0;
}