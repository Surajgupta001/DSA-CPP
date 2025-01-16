/*
Smallest Range Covering Elements from K Lists - [Leetcode - 632(Hard)]
========================================================================
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, pair<int, int>> pip;
vector<int> smallestRange(vector<vector<int>> &v){
    priority_queue<pip, vector<pip>, greater<pip>> pq;
    int mx = INT_MIN;

    // Initialize the priority queue with the first element of each list
    for (int i=0; i<v.size(); i++){
        mx = max(mx, v[i][0]);
        pq.push({v[i][0], {i, 0}});
    }
    int mn = pq.top().first; // The minimum element in the current range
    int start = mn;          // Start of the range
    int end = mx;            // End of the range

    // Process the priority queue
    while (true){
        int row = pq.top().second.first; // Get the row index
        int col = pq.top().second.second; // Get the column index
        pq.pop();

        // If we have reached the end of one of the lists, break
        if (col == v[row].size() - 1) break;

        // Push the next element from the same list into the priority queue
        pq.push({v[row][col + 1], {row, col + 1}});
        mx = max(mx, v[row][col + 1]); // Update the maximum

        mn = pq.top().first; // Get the new minimum from the priority queue

        // Update the range if the current range is smaller
        if(mx - mn < end - start) {
            start = mn;
            end = mx;
        }
    }
    return {start, end}; // Return the smallest range
}

int main(){

    vector<vector<int>> v = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> res = smallestRange(v);
    cout << "[" << res[0] << "," << res[1] << "]" << endl;

    return 0;
}