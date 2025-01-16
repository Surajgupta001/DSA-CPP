/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
*/ 

/*
Logic behind the solution:

1. We use a sliding window approach with two pointers: i (left) and j (right).
2. We initialize a product variable to 1 and a count variable to 0.
3. We iterate through the array using the right pointer j:
   a. Multiply the current element nums[j] to the product.
   b. While the product is greater than or equal to k and i <= j:
      - Divide the product by nums[i] to remove it from the window.
      - Move the left pointer i to the right.
   c. Add the number of valid subarrays ending at j to the count.
      The number of valid subarrays is (j - i + 1).
4. Return the total count of valid subarrays.

This approach works because:
- We expand the window by including elements from the right (j).
- When the product becomes too large, we shrink the window from the left (i).
- At each step, we count all subarrays that end at the current element j.
- The sliding window ensures we don't count the same subarray twice.

Time Complexity: O(n), where n is the length of the input array.
Space Complexity: O(1), as we only use a constant amount of extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    if (k <= 1) return 0;
    int i = 0;
    int count = 0;
    int product = 1;
    for (int j = 0; j < n; j++) {
        product *= nums[j];
        while (product >= k && i <= j) {
            product /= nums[i];
            i++;
        }
        count += j - i + 1;
    }
    return count;
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

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"Elements in the subarray is strictly less than k: "<<numSubarrayProductLessThanK(v,k)<<endl;

    return 0;
}

