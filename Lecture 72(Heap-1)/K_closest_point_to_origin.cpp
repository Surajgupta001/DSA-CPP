/*
K Closest Point to origin - [Leetcode - 973(Medium)]
===========================================================
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Example 1:

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, pair<int, int>>> pq; // <dist(sq), point>
    for (auto& point : points) {
        int x = point[0], y = point[1];
        int distSq = x*x + y*y; // Calculate squared distance
        pq.push({distSq, {x, y}});
        if (pq.size() > k) pq.pop(); // Maintain only k closest points
    }
    vector<vector<int>> ans;
    while(!pq.empty()) {
        ans.push_back({pq.top().second.first, pq.top().second.second}); // Add point to result
        pq.pop();
    }
    return ans;
}

int main(){

    int n;
    cout<<"Enter the number of points: ";
    cin>>n;

    vector<vector<int>>points(n, vector<int>(2)); // 2D vector for points
    cout<<"Enter the points (x y): ";
    for (int i=0; i<n;i++) {
        cin>>points[i][0]>>points[i][1]; // Input points
    }

    int k;
    cout<<"Enter the number of closest points to return: ";
    cin>>k;

    vector<vector<int>> ans = kClosest(points, k);
    cout<<"The "<<k<< " closest points to the origin are: ";
    for(auto& point : ans) {
        cout<<"["<<point[0]<<", "<<point[1]<< "] ";
    }

    return 0;
}