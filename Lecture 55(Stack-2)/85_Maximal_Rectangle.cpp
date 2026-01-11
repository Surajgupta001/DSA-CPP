/*
Maximal Rectangle - [Leetcode - 85(Hard)]
-------------------------------------------
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// NOTE : Firstly solve - Leetcode - [84. Largest Rectangle in Histogram]

vector<int> nextSmallerElement(vector<int> &heights) {
    int n = heights.size();
    vector<int> nextSmaller(n, n); // Default to n if no smaller element found
    stack<int> st;                 // Stack to store indices

    for (int i=n - 1; i>=0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if (!st.empty()){
            nextSmaller[i] = st.top();
        }
        st.push(i);
    }
    return nextSmaller;
}

vector<int> prevSmallerElement(vector<int> &heights) {
    int n = heights.size();
    vector<int> prevSmaller(n, -1); // Default to -1 if no smaller element found
    stack<int> st;                  // Stack to store indices

    for (int i=0; i<n; i++){
        while (!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if (!st.empty()){
            prevSmaller[i] = st.top();
        }
        st.push(i);
    }
    return prevSmaller;
}

int findMaxArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> nextSmaller = nextSmallerElement(heights);
    vector<int> prevSmaller = prevSmallerElement(heights);

    int maxArea = 0;

    for (int i=0; i<n; i++){
        int height = heights[i];
        int width = nextSmaller[i] - prevSmaller[i] - 1;
        
        int area = height * width;
        
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> heights(n); // heights

    // Add the 1st Row in the heights - 1D
    for (int i=0; i<n; i++){
        heights[i] = (matrix[0][i] == '1') ? 1 : 0;
    }

    int maxArea = findMaxArea(heights);

    for (int row=1; row<m; row++){
        for (int col=0; col<n; col++){
            if (matrix[row][col] == '0'){
                heights[col] = 0;
            }
            else{
                heights[col] += 1;
            }
        }
        maxArea = max(maxArea, findMaxArea(heights));
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;

    return 0;
}