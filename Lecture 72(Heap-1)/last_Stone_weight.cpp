/*
Last Stone Weight - [Leetcode - 1046(Easy)]
=============================================
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x => y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight x - y.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.

Example 2:

Input: stones = [1]
Output: 1
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int lastStoneWeight(vector<int>& v){
    priority_queue<int> pq;
    for(auto ele:v) pq.push(ele);
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if(x != y) pq.push(x-y);
    }
    return pq.size() == 0 ? 0 : pq.top();
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<"Last Stone Weight: "<<lastStoneWeight(v)<<endl;

    return 0;
}