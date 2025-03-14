/*
Range Additions - [Leetcode - 370(Medium)]
=============================================
You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.

Example 1:

Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]

Example 2:

Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
Output: [0,-4,2,2,2,4,4,-4,-4,-4]

Constraints:

1 <= length <= 105
0 <= updates.length <= 104
0 <= startIdxi <= endIdxi < length
-1000 <= inci <= 1000
*/ 

#include <iostream>
#include <vector>
using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates){
    
    // Initialize the differnce array
    vector<int> diff(length, 0);

    // Step 1 : Apply update using the difference array
    for(auto &update : updates){
        int left = update[0];
        int right = update[1];
        int value = update[2];

        diff[left] += value; // Add increment at StartIndex
        if(right + 1 < length){
            diff[right + 1] -= value; // Subtract increment after endIndex
        }
    }
    // Step 2 : Compute the final array form the differnce array
    vector<int> ans(length, 0);
    int prefixSum = 0;
    for(int i = 0; i < length; i++){
        prefixSum += diff[i];
        ans[i] = prefixSum;
    }
    return ans;
}

int main(){
    int length = 5;
    
    vector<vector<int>> updates = {{1,3,2},{2,4,3},{0,2,-2}};
    vector<int> result = getModifiedArray(length, updates);
    
    cout<<"Applying all the updates in array is: ";
    
    for(auto &num : result) cout << num << " ";
    
    return 0;
}