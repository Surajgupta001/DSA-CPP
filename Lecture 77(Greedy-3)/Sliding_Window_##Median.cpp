/*
Sliding Window Median - [Leetcode - 480(Hard)]
=====================================================

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6

Example 2:

Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
*/ 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

double getMediun(priority_queue<int>& left, priority_queue<int,vector<int>,greater<int>>& right, int x, int y){
    int totalSize = x + y;
    if(totalSize % 2 != 0){
        // odd 
        return right.top();
    }
    else{
        // even
        return (left.top() + right.top()) / 2.0;
    }
}

bool isBalanced(int x, int y){
    return (x == y) or (x + 1 == y);
}

vector<double>slidingMethod(vector<int>& v, int n, int k){
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>>right;
    int x = 0;
    int y = 0;
    right.push(v[0]); // indexes
    y++;
    for(int i = 1; i < n; i++){
        int curr = v[i];
        double med = getMediun(left,right,x,y);
        if(curr < med){
            // push to left
            left.push(curr);
            x++;
            if(!isBalanced(x,y)){
                int toBeRemoved = left.top();
                left.pop();
                right.push(toBeRemoved);
                x--; y++;
            }
        }
        else{
            // push to right
            right.push(curr);
            y++;
            if(!isBalanced(x,y)){
                int toBeRemoved = right.top();
                right.pop();
                left.push(toBeRemoved);
                y--; x++;
            }
        }
    }
    double m = getMediun(left,right,x,y); // answer of first window

    vector<double>result;
    result.push_back(m);
    unordered_map<int,int>mp;

    for(int i=k;i<n;i++){
        int newElementIndex = i;
        int oldElementToBeDeleted = i-k;
        double med = getMediun(left,right,x,y);
        if(v[newElementIndex] > med){
            // go right
            right.push(v[newElementIndex]);
            y++;
            if(!isBalanced(x,y)){
                int toBeRemoved = right.top();
                left.pop();
                right.push(toBeRemoved);
                y--; x++;
            }
        }
        else{
            // go left
            left.push(v[newElementIndex]);
            x++;
            if(!isBalanced(x,y)){
                int toBeRemoved = left.top();
                right.pop();
                left.push(toBeRemoved);
                x--; y++;
            }
        }
        mp[v[oldElementToBeDeleted]] = oldElementToBeDeleted;
        while(!left.empty() and mp.count(left.top())){
            mp.erase(left.top());
            left.pop();
            x--;
            if(!isBalanced(x,y)){
                int toBeRemoved = right.top();
                right.pop();
                left.push(toBeRemoved);
                y--; x++;
            }
        }
        while(!right.empty() and mp.count(left.top())){
            mp.erase(right.top());
                right.pop();
                y--;
                if(!isBalanced(x,y)){
                    int toBeRemoved = left.top();
                    left.pop();
                    right.push(toBeRemoved);
                    x--; y++;
                }
            }
            result.push_back(getMediun(left,right,x,y));
    }
    return result;
}

int main(){

    // fast io
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);
    // fast io
    int t = 1;
    // cin >> t

    int n;
    int k;

    cin >> n >> k;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    vector<double>ans = slidingMethod(v,n,k);

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

    return 0;
 
}