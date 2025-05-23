/*
Find the Maximum Sum of Node Values - [Leetcode - 3068(Hard)]
--------------------------------------------------------------
There exists an undirected tree with n nodes numbered 0 to n - 1. You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the tree. You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
nums[u] = nums[u] XOR k
nums[v] = nums[v] XOR k
Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.

Example 1:

Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
Output: 6
Explanation: Alice can achieve the maximum sum of 6 using a single operation:
- Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, and the array nums becomes: [1,2,1] -> [2,2,2].
The total sum of values is 2 + 2 + 2 = 6.
It can be shown that 6 is the maximum achievable sum of values.

Example 2:

Input: nums = [2,3], k = 7, edges = [[0,1]]
Output: 9
Explanation: Alice can achieve the maximum sum of 9 using a single operation:
- Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and nums[1] become: 3 XOR 7 = 4, and the array nums becomes: [2,3] -> [5,4].
The total sum of values is 5 + 4 = 9.
It can be shown that 9 is the maximum achievable sum of values.

Example 3:

Input: nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
Output: 42
Explanation: The maximum achievable sum is 42 which can be achieved by Alice performing no operations.
 

Constraints:

2 <= n == nums.length <= 2 * 104
1 <= k <= 109
0 <= nums[i] <= 109
edges.length == n - 1
edges[i].length == 2
0 <= edges[i][0], edges[i][1] <= n - 1
The input is generated such that edges represent a valid tree.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//Approach-1 (Greedily picking Nodes to XOR with k):
long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    long long sum = 0;
    int count = 0;
    int minNuksaan = INT_MAX;
    
    for(int i=0; i<nums.size(); i++){
        // Greedily pick nodes to XOR with k
        if((nums[i]^k) > nums[i]){ // If XORing with k gives a larger value
            count++; // Count the number of nodes that can be XORed with k
            sum += (nums[i]^k); // Add the new value to the sum
        }
        else{
            // If XORing with k gives a smaller value, add the original value
            sum += nums[i];
        }
        // Calculate the minimum loss if we XOR with k
        minNuksaan = min((long long)minNuksaan, (long long)abs(nums[i] - (nums[i]^k)));
    }
    if(count % 2 == 0){ // If even number of nodes can be XORed with k
        return sum;
    }
    else{
        // If odd number of nodes can be XORed with k, we need to subtract the minimum loss
        return sum - minNuksaan;
    }
}

// Approach-2 (Greedy  + Sorting)
long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

    vector<int> fayda;
    long long idealSum = 0;

    // Calculate the fayda (benefit) of XORing with k for each node
    for(int i=0; i<nums.size(); i++){
        fayda.push_back((nums[i]^k) - nums[i]); // Calculate the fayda (benefit) of XORing with k
        idealSum += 1LL * nums[i]; // Add the original value to the ideal sum
    }

    // Sort the fayda array in descending order
    sort(fayda.begin(), fayda.end(), greater<int>());

    // Calculate the maximum possible sum of values
    for(int i=0; i<nums.size()-1; i+=2){
        // For every two nodes, check if the fayda is positive
        long long pairSum = fayda[i] + fayda[i+1];
        // If the fayda is positive, add it to the ideal sum
        if(pairSum > 0){
            // Add the fayda to the ideal sum
            idealSum += pairSum;
        }
    }
    return idealSum;
}

int main() {
    vector<int> nums = {1, 2, 1};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    
    long long result = maximumValueSum(nums, k, edges);
    cout << "Maximum possible sum of values: " << result << endl;
    
    return 0;
}