/*
Maximum Frequency of an Element After Performing Operations I - [Leetcode - 3346(Medium)]
------------------------------------------------------------------------------------------
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

Adding 0 to nums[1]. nums becomes [1, 4, 5].
Adding -1 to nums[2]. nums becomes [1, 4, 4].
Example 2:

Input: nums = [5,11,20,20], k = 5, numOperations = 1

Output: 2

Explanation:

We can achieve a maximum frequency of two by:

Adding 0 to nums[1].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
0 <= k <= 105
0 <= numOperations <= nums.length
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int maxEl = *max_element(nums.begin(), nums.end()) + k;
    
    vector<int> freq(maxEl + 1, 0);

    for(auto &num : nums){
        freq[num]++;
    }

    // Calculate prefix sums or cumulative frequencies
    for(int i=1; i<=maxEl; i++){
        freq[i] += freq[i-1];
    }

    int result = 0;

    for(int target = 0; target <= maxEl; target++){
        if(freq[target] == 0) continue; // No elements to convert to 'target'

        int leftNum = max(0, target - k); // l
        int rightNum = min(maxEl, target + k); // r

        int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);

        int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);

        int needToConvert = totalCount - targetCount;

        int maxPossibleFrequency = targetCount + min(needToConvert, numOperations);

        result = max(result, maxPossibleFrequency);
    }
    
    return result;
}

// ============= Difference Array Technique =============
int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int maxVal = *max_element(begin(nums), end(nums)) + k;
    
    vector<int> diff(maxVal+2, 0);
    
    unordered_map<int, int> freq;
    
    for(int i = 0; i < nums.size(); i++) {
        freq[nums[i]]++;
        
        int l = max(nums[i]-k, 0);
        int r = min(nums[i]+k, maxVal);
        
        diff[l]++;
        diff[r+1]--;
    }

    int result = 1;
    
    for(int target = 0; target <= maxVal; target++) {
        
        diff[target] += (target > 0 ? diff[target-1] : 0);
        
        int targetFreq     = freq[target];
        
        int needConversion = diff[target] - targetFreq;
        
        int maxPossibleFreq = min(needConversion, numOperations);
        
        result = max(result, targetFreq + maxPossibleFreq);
    }
    
    return result;
}

int main() {
    vector<int> nums1 = {1, 4, 5};
    int k1 = 1, numOperations1 = 2;
    cout << "Maximum Frequency: " << maxFrequency(nums1, k1, numOperations1) << endl; // Output: 2

    vector<int> nums2 = {5, 11, 20, 20};
    int k2 = 5, numOperations2 = 1;
    cout << "Maximum Frequency: " << maxFrequency(nums2, k2, numOperations2) << endl; // Output: 2

    return 0;
}