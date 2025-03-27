/*
Minimum Index of a Valid Split - [Leetcode - 2780(Meduim)]
An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.

Example 1:

Input: nums = [1,2,2,2]
Output: 2
Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
It can be shown that index 2 is the minimum index of a valid split. 

Example 2:

Input: nums = [2,1,3,1,1,1,7,1,2,1]
Output: 4
Explanation: We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
It can be shown that index 4 is the minimum index of a valid split.

Example 3:

Input: nums = [3,3,3,3,7,2,2]
Output: -1
Explanation: It can be shown that there is no valid split.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
nums has exactly one dominant element.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute FOrce
int minimumIndex(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int, int> mp1; //stores elements of left subarray 
    unordered_map<int, int> mp2; //stores elements of right subarray

    for(int &num : nums) {
        mp2[num]++;
    }

    for(int i = 0; i < n; i++) {
        int num = nums[i];

        mp1[num]++;
        mp2[num]--;

        int n1 = i+1;
        int n2 = n-i-1;

        if(mp1[num]*2 > n1 && mp2[num]*2 > n2) {
            return i;
        }
    }
    return -1;
}

// Using Majority Element Concept -> Boyer-Moore Majority Algorithms
int minimumIndex(vector<int>& nums) {
    int n = nums.size();

    int majority   = -1;
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(count == 0) {
            majority = nums[i];
            count = 1;
        } else if(nums[i] == majority) {
            count++;
        } else {
            count--;
        }
    }

    int majorityCount = 0;
    for(int &num : nums) {
        if(num == majority) {
            majorityCount++;
        }
    }

    count = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == majority) {
            count++;
        }

        int remainingCount = majorityCount - count;
        int n1 = i+1;
        int n2 = n-i-1;

        if(count*2 > n1 && remainingCount*2 > n2) {
            return i;
        }
    }
    return -1;

}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> nums = {1,2,2,2};
    cout << minimumIndex(nums) << endl;
        
    return 0;
}