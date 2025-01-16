/*
Meeting Room-II - [Leetcode - 253(Medium)]
==========================================
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

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
    return ans;
}

int main(){

    vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};

    cout<<minMeetingRooms(intervals)<<endl;

    return 0;
}