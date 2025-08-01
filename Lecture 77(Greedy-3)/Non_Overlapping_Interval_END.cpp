/*
Non-overlapping Intervals - [Leetcode - (435)]
===============================================

Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& i1, vector<int>& i2){
    return i1[1] < i2[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals){
    int ans = 0;
    sort(intervals.begin(), intervals.end(), cmp);
    int lastEndTime = intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0] < lastEndTime) ans++;
        else lastEndTime = intervals[i][1];
    }
    return ans;
}

int main(){

    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    
    cout<<eraseOverlapIntervals(intervals)<<endl;
    
    return 0;
}