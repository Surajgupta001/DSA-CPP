# Kadane's Algorithm

Kadane's Algorithm is used to find the **maximum sum of a contiguous subarray** in an array of numbers. It's one of the most efficient algorithms for solving the maximum subarray problem with O(n) time complexity.

## 📌 Problem Statement

Given an array of integers (which may contain positive and negative numbers), find the contiguous subarray with the largest sum.

**Example:**
Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: [4, -1, 2, 1] has the largest sum = 6

## 🎯 Algorithm Concept

The algorithm maintains two variables:

- **currSubArraySum**: Current sum ending at the current position (local maximum)
- **maxSubArraySum**: Maximum sum found so far (global maximum)

### Key Insight

At each position, we decide:

1. Should we **extend** the existing subarray by adding the current element?
2. Or should we **start a new subarray** from the current element?

We choose: `currSubArraySum = max(nums[i], currSubArraySum + nums[i])`

## 📝 Pseudocode

```plain
Algorithm: Kadane's Algorithm (Maximum Subarray Sum)
Input: Array nums[] of size n
Output: Maximum sum of contiguous subarray

Initialize:
    currSubArraySum = nums[0]
    maxSubArraySum = nums[0]

For i = 1 to n-1:
    currSubArraySum = max(nums[i], currSubArraySum + nums[i])
    maxSubArraySum = max(maxSubArraySum, currSubArraySum)

Return maxSubArraySum
```

### For Maximum Absolute Sum (Two Pass Approach)

```plain
Algorithm: Maximum Absolute Subarray Sum
Input: Array nums[] of size n
Output: Maximum absolute sum

// First Pass: Find Maximum Subarray Sum
currSubArraySum = nums[0]
maxSubArraySum = nums[0]

For i = 1 to n-1:
    currSubArraySum = max(nums[i], currSubArraySum + nums[i])
    maxSubArraySum = max(maxSubArraySum, currSubArraySum)

// Second Pass: Find Minimum Subarray Sum
currSubArraySum = nums[0]
minSubArraySum = nums[0]

For i = 1 to n-1:
    currSubArraySum = min(nums[i], currSubArraySum + nums[i])
    minSubArraySum = min(minSubArraySum, currSubArraySum)

Return max(abs(maxSubArraySum), abs(minSubArraySum))
```

## 💻 C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Approach-1 (2 Pass - Kadane's Algorithm for maxSubArrySum and minsubArraySum)
// T.C : O(2*n) ~= O(n)
// S.C : O(1)
int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();

    int currSubArraySum = nums[0];
    int maxSubArraySum = nums[0];
    
    // 1st Pass : Kadane's Algorithm to finding max subarray Sum
    for(int i=1; i<n; i++){
        currSubArraySum = max(nums[i], currSubArraySum + nums[i]);
        maxSubArraySum = max(maxSubArraySum, currSubArraySum);
    }

    // 2nd Pass : Kadane's Algorithm to finding min subarray Sum
    int minSubArraySum = nums[0];
    currSubArraySum = nums[0];

    for(int i=1; i<n; i++){
        currSubArraySum = min(nums[i], currSubArraySum + nums[i]);
        minSubArraySum = min(minSubArraySum, currSubArraySum);
    }

    return max(abs(maxSubArraySum), abs(minSubArraySum));
}
```

## 🔍 Example Walkthrough

### Example 1: Basic Kadane's Algorithm

For array: `[5, -3, 5]`

| Step | Index | Element | currSubArraySum (before) | Calculation    | currSubArraySum (after) | maxSubArraySum |
| ---- | ----- | ------- | ------------------------ | -------------- | ----------------------- | -------------- |
| 1    | 0     | 5       | -                        | Initial        | 5                       | 5              |
| 2    | 1     | -3      | 5                        | max(-3, 5-3=2) | 2                       | 5              |
| 3    | 2     | 5       | 2                        | max(5, 2+5=7)  | 7                       | 7              |

**Result**: Maximum sum = 7 (entire array: [5, -3, 5])

### Example 2: Maximum Absolute Sum

For array: `[2, -5, 1, -4, 3, -2]`

**First Pass (Maximum Subarray Sum):**

| Step | Index | Element | currSubArraySum | maxSubArraySum |
| ---- | ----- | ------- | --------------- | -------------- |
| 1    | 0     | 2       | 2               | 2              |
| 2    | 1     | -5      | -3              | 2              |
| 3    | 2     | 1       | 1               | 2              |
| 4    | 3     | -4      | -3              | 2              |
| 5    | 4     | 3       | 3               | 3              |
| 6    | 5     | -2      | 1               | 3              |

**Second Pass (Minimum Subarray Sum):**

| Step | Index | Element | currSubArraySum | minSubArraySum |
| ---- | ----- | ------- | --------------- | -------------- |
| 1    | 0     | 2       | 2               | 2              |
| 2    | 1     | -5      | -5              | -5             |
| 3    | 2     | 1       | -4              | -5             |
| 4    | 3     | -4      | -8              | -8             |
| 5    | 4     | 3       | -5              | -8             |
| 6    | 5     | -2      | -7              | -8             |

**Result**: max(abs(3), abs(-8)) = **8**

## ⚡ Complexity Analysis

- **Time Complexity**: O(n) - Single pass through the array
- **Space Complexity**: O(1) - Only using constant extra space

## 🎓 Why Does It Work?

The algorithm works based on the principle that:

- If the sum of elements up to the current position is negative, it's better to start fresh from the next element rather than carry forward a negative sum
- We keep track of the maximum sum seen so far to handle cases where the best subarray appears earlier in the array

## 🔄 Variations

### 1. **Standard Kadane's Algorithm (Maximum Subarray Sum)**

```cpp
int maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    int currSubArraySum = nums[0];
    int maxSubArraySum = nums[0];
    
    for(int i = 1; i < n; i++) {
        currSubArraySum = max(nums[i], currSubArraySum + nums[i]);
        maxSubArraySum = max(maxSubArraySum, currSubArraySum);
    }
    
    return maxSubArraySum;
}
```

### 2. **Maximum Absolute Sum (Two Pass - as shown in main code)**

This variation finds the maximum absolute value among all subarray sums. It requires:

- **First pass**: Find maximum subarray sum using Kadane's
- **Second pass**: Find minimum subarray sum using modified Kadane's
- Return the maximum absolute value of both

**Use Case**: When you need the subarray with the largest magnitude (positive or negative)

### 3. **Minimum Subarray Sum**

```cpp
int minSubarraySum(vector<int>& nums) {
    int n = nums.size();
    int currSubArraySum = nums[0];
    int minSubArraySum = nums[0];
    
    for(int i = 1; i < n; i++) {
        currSubArraySum = min(nums[i], currSubArraySum + nums[i]);
        minSubArraySum = min(minSubArraySum, currSubArraySum);
    }
    
    return minSubArraySum;
}
```

### 4. **With Subarray Indices**

```cpp
class Result {
    int maxSum;
    int startIdx;
    int endIdx;
};

Result maxSubarraySumWithIndices(vector<int>& nums) {
    int n = nums.size();
    int currSum = nums[0];
    int maxSum = nums[0];
    int start = 0, end = 0, tempStart = 0;
    
    for(int i = 1; i < n; i++) {
        if(nums[i] > currSum + nums[i]) {
            currSum = nums[i];
            tempStart = i;
        } else {
            currSum += nums[i];
        }
        
        if(currSum > maxSum) {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }
    
    return {maxSum, start, end};
}
```

### 5. **Maximum Circular Subarray Sum**

```cpp
int maxCircularSubarraySum(vector<int>& nums) {
    int n = nums.size();
    
    // Case 1: Maximum subarray is non-circular
    int maxNormal = maxSubarraySum(nums);
    
    // Case 2: Maximum subarray is circular
    int totalSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum += nums[i];
        nums[i] = -nums[i];
    }
    
    int minSubArray = maxSubarraySum(nums); // This gives max of negated = min of original
    int maxCircular = totalSum + minSubArray;
    
    // Handle all negative case
    if(maxCircular == 0) return maxNormal;
    
    return max(maxNormal, maxCircular);
}
```

### 6. **Maximum Product Subarray**

```cpp
int maxProductSubarray(vector<int>& nums) {
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int result = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < 0) {
            swap(maxProduct, minProduct);
        }
        
        maxProduct = max(nums[i], maxProduct * nums[i]);
        minProduct = min(nums[i], minProduct * nums[i]);
        result = max(result, maxProduct);
    }
    
    return result;
}
```

## 📚 Practice Problems

1. **Maximum Subarray** (LeetCode #53) - Standard Kadane's
2. **Maximum Absolute Sum of Any Subarray** (LeetCode #1749) - Two Pass Kadane's (shown in code)
3. **Maximum Sum Circular Subarray** (LeetCode #918)
4. **Maximum Product Subarray** (LeetCode #152)
5. **Best Time to Buy and Sell Stock** (LeetCode #121)
6. **Maximum Subarray Sum After One Operation** (LeetCode #1746)
7. **K-Concatenation Maximum Sum** (LeetCode #1191)

## 💡 Key Takeaways

1. Kadane's Algorithm is a **dynamic programming** approach
2. It's **greedy** in nature - makes locally optimal choices
3. Works in **linear time** - very efficient
4. Can be modified to solve various subarray problems
5. The core idea: "Should I extend or start fresh?"

### Happy Coding! 🚀
