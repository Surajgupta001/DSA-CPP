/*
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
*/ 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int longestSubArray(vector<int> &nums){
    int n = nums.size();
    int k = 1;
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
    return maxLen-1;
}

int main(){

    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> v(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<"The length of the longest subarray with all 1's after deleting one element: "<<longestSubArray(v)<<endl;
    return 0;
}