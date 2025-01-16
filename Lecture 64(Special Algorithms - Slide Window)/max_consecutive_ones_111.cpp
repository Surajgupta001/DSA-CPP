/*
MAX CONSECUTIVE ONES 111 - (LEETCODE - 1004)
==============================================
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

/*
Explanation of the logic step by step:

1. Initialize variables:
   - n: size of the input vector
   - flips: count of 0s flipped to 1s
   - i, j: pointers for the sliding window
   - maxLen: maximum length of consecutive ones
   - len: current length of consecutive ones

2. Iterate through the array using pointer j:
   a. If nums[j] is 1, move j forward
   b. If nums[j] is 0:
      - If flips < k, flip the 0 to 1 and move j forward
      - If flips == k:
        * Calculate current length (j - i)
        * Update maxLen if necessary
        * Move i forward to the next 0 (skipping 1s)
        * Move both i and j forward

3. After the loop, calculate final length and update maxLen

4. Return maxLen as the result

This approach uses a sliding window technique to find the longest subarray of consecutive ones after flipping at most k zeros.
The window expands when we can flip zeros, and contracts when we've used all our flips and encounter another zero.
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxConsecutiveOnes(vector<int> &nums, int k){
    int n = nums.size();
    int flips = 0;
    int i = 0, j = 0;
    int maxLen = 0;
    int len = 0;
    while (j < n){
        if (nums[j] == 1)
            j++;
        else{ // nums[j] == 0;
            if (flips < k){
                flips++;
                j++;
            }
            else{ // flips == k

                // calculate length
                len = j - i;
                maxLen = max(maxLen, len);

                // i ko just uske aage wale 0 se ek index aage le jaoo
                while (nums[i] == 1)
                    i++; // after this 100% nums[i] = 0;
                i++;
                j++;
            }
        }
    }
    // calculate length
    len = j - i;
    maxLen = max(maxLen, len);
    return maxLen;
}

int main(){
    int n;
    cout << "Enter the size of the array: " ;
    cin>>n;

    vector<int> v(n);
    cout << "Enter the elements of the array: " ;
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }
    
    int k;
    cout << "Enter the value of k: " ;
    cin>>k;

    cout << maxConsecutiveOnes(v, k) << endl;
    return 0;
}