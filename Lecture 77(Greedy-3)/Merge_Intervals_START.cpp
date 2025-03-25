/*
Merge Interval - [Leetcode-56(Medium)]
==========================================

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

vector<vector<int>>merge(vector<vector<int>>& interval){
    sort(interval.begin(), interval.end(), cmp);
    vector<vector<int>> ans;
    int n = interval.size();
    ans.push_back(interval[0]); // left->right
    for(int i=1;i<n;i++){
        vector<int>currInterval = interval[i];
        if(currInterval[0] <= ans[ans.size()-1][1]){
            // curr.end >= last.start -> overlapping
            ans[ans.size()-1][0] = min(ans[ans.size()-1][0],currInterval[0]);
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1],currInterval[1]);
        }
        else{
            ans.push_back(interval[i]);
        }
    }
    return ans;
}

/*
// Define the lambda function as a standalone function bool
bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

// Alternatively, you can define the lambda function as a static function
// static bool cmp(vector<int>& a, vector<int>& b){
//     return a[0] < b[0];
// }

// Or, you can define the lambda function inside the merge function
vector<vector<int>> merge(vector<vector<int>>& interval) {
    auto cmp = [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; };
    sort(interval.begin(), interval.end(), cmp);
    vector<vector<int>> ans;
    int n = interval.size();
    ans.push_back(interval[0]); // Start with the first interval
    for (int i = 1; i < n; i++) {
        vector<int> currInterval = interval[i];
        if (currInterval[0] <= ans[ans.size() - 1][1]) {
            // curr.start <= last.end -> overlapping
            ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], currInterval[1]);
        }
        else {
            ans.push_back(interval[i]);
        }
    }
    return ans;
}
*/ 

/*
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(begin(intervals), end(intervals)); //on the basis of start point
    
    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for(int i = 1; i<intervals.size(); i++) {

        int curr_start = intervals[i][0];
        int curr_end = intervals[i][1];

        //if no overlap
        if(curr_start > result.back()[1]) {
            result.push_back(intervals[i]);
        } else {
            //there is an overlap
            result.back()[1] = max(result.back()[1], curr_end);
        }

    }
    return result;
}
*/ 

int main(){

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = merge(intervals);

    for(int i=0;i<result.size();i++){
        cout<<"{"<<result[i][0]<<","<<result[i][1]<< "}";
    }

    return 0;
}