/*
Count Days Without Meetings - [Leetcode - 3169(Medium)]
========================================================
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.


Example 1:

Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4th and 8th days.

Example 2:

Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5th day.

Example 3:

Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.


Constraints:

1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
    int n = meetings.size();

    sort(begin(meetings), end(meetings)); // Sorting -> starting

    int start = 0;
    int end = 0;
    int ans = 0;

    for(auto &meet : meetings) {
        if(meet[0] > end) {
            ans += meet[0] - end - 1;
        }
        end = max(end, meet[1]);
    }
    if(days > end) {
        ans += days-end;
    }
    return ans;
}

int main(){
    int days = 10;
    vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
    cout << countDays(days, meetings) << endl;
    return 0;
}