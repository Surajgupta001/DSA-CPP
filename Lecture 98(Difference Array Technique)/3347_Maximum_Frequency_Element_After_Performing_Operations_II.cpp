/*
Maximum Frequency of an Element After Performing Operations II - [Leetcode - 3347(Hard)]
-----------------------------------------------------------------------------------------
You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.

Example 1:

Input: nums = [1,4,5], k = 1, numOperations = 2

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1], after which nums becomes [1, 4, 5].
Adding -1 to nums[2], after which nums becomes [1, 4, 4].
Example 2:

Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109
0 <= numOperations <= nums.length
*/ 

// ========= DIFFERENCE ARRAY TECHNIQUE =========
// ======= Contineous part of Leetcode - 3346(Medium) =======

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int maxVal = *max_element(begin(nums), end(nums)) + k;

    map<int, int> diff; // map for difference array
    unordered_map<int, int> freq; // map to store frequency of elements
    
    for(int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
        
        int l = max(nums[i]-k, 0);
        int r = min(nums[i]+k, maxVal);
        
        diff[l]++;
        diff[r+1]--;

        diff[nums[i]] += 0; // ensure nums[i] exists in diff map
    }

    int result = 1;
    int cummSum = 0; // to store cumulative sum of difference array
    for(auto itr = diff.begin(); itr != diff.end(); ++itr){

        int target = itr->first;
        itr->second += cummSum;

        int targetFreq = freq[target];

        int needConversion = itr->second - targetFreq;
        
        int maxPossibleFreq = min(needConversion, numOperations);
        
        result = max(result, targetFreq + maxPossibleFreq);

        cummSum = itr->second;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 4, 5};
    int k = 1;
    int numOperations = 2;
    int result = maxFrequency(nums, k, numOperations);
    cout << "Maximum Frequency: " << result << endl; // Output: 2
    return 0;
}