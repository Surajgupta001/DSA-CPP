/*
Meeting Room - [Leetcode - 252(Medium)]
==========================================
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals){
    if(intervals.size() == 0) return true;
    vector<int>start, ending;
    for(auto ele:intervals){
        start.push_back(ele[0]);
        ending.push_back(ele[1]);
    }
    
    sort(start.begin(), start.end());
    sort(ending.begin(), ending.end());

    int ans = 0;
    int rooms = 0;
    int i = 0;
    int j = 0;

    while(i < start.size() and j < ending.size()){
        if(start[i] < ending[j]){
            // a meeting is starting
            rooms++;
            ans = max(ans,rooms);
            i++;
        }
        else if(start[i] > ending[j]){
            // a meeting is ending
            rooms--;
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    return ans == 1;
}

int main(){
    
    vector<vector<int>> intervals = {{7,10},{2,4}};
    cout << minMeetingRooms(intervals) << endl;

    return 0;
}