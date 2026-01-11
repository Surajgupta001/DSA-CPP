/*
Largest Rectangle in Histogram - [Leetcode - 84(Hard)]
---------------------------------------------------------
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4


Constraints:

1 <= heights.length <= 10^5
0 <= heights[i] <= 10^4
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// NOTE: Standard problem, Right Smallest Element and Left Smallest Element approach => Monotonic Stack based

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> leftSmaller(n);
    vector<int> rightSmaller(n);
    stack<int> st;

    // FIND PREVIOUS SMALLER ELEMENT (LEFT)
    // We want the index of the first element to the left that is smaller than current
    // If no such element exists, the boundary is -1
    for (int i = 0; i < n; i++){
        while (!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        leftSmaller[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear stack for reuse
    while (!st.empty()){
        st.pop();
    }

    // FIND NEXT SMALLER ELEMENT (RIGHT)
    // We want the index of the first element to the right that is smaller than current
    // If no such element exists, the boundary is n
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        rightSmaller[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++){
        // Width is distance between right boundary and left boundary
        // Boundaries are exclusive, so width = right - left - 1
        int width = rightSmaller[i] - leftSmaller[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main(){
    // Edge Case 1: Standard case
    vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    cout << "Test Case 1 [2,1,5,6,2,3] Expected: 10, Actual: " << largestRectangleArea(heights1) << endl;

    // Edge Case 2: Array with 2 elements
    vector<int> heights2 = {2, 4};
    cout << "Test Case 2 [2,4] Expected: 4, Actual: " << largestRectangleArea(heights2) << endl;

    // Edge Case 3: All elements same
    vector<int> heights3 = {2, 2, 2, 2};
    cout << "Test Case 3 [2,2,2,2] Expected: 8, Actual: " << largestRectangleArea(heights3) << endl;

    // Edge Case 4: Increasing order
    vector<int> heights4 = {1, 2, 3, 4, 5};
    cout << "Test Case 4 [1,2,3,4,5] Expected: 9, Actual: " << largestRectangleArea(heights4) << endl;

    // Edge Case 5: Single element
    vector<int> heights5 = {9};
    cout << "Test Case 5 [9] Expected: 9, Actual: " << largestRectangleArea(heights5) << endl;

    return 0;
}