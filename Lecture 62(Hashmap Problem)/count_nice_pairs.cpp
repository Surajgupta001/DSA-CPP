/*
Count Nice Pairs in an Array - [Leetcode - 1814(Medium)]
=========================================================
You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

* 0 <= i < j < nums.length
* nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) or nums[i]-rev(nums[i]) = nums[j]-rev(nums[j])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.

Example 2:

Input: nums = [13,10,35,24,76]
Output: 4
*/ 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int reverse(int num){
    int revNum = 0;
    while(num > 0){
        revNum = revNum * 10 + num % 10; 
        num /= 10;
    }
    return revNum;
}

// Function to count the number of nice pairs in the given vector
int countNicePair(vector<int>& v){
    int n = v.size();
    int count = 0;
    unordered_map<int,int>m;

    // Subtracting the reversed value from each element
    for(int i=0;i<n;i++) v[i] = v[i] - reverse(v[i]);

    // count nice pair
    for(int i=0;i<n;i++){
        // Check if the modified value already exists in the map
        if(m.find(v[i]) != m.end()){
            count = count % 1000000007;
            count += m[v[i]]; // Occurrences of v[i] to count
            m[v[i]]++;
        }
        else m[v[i]]++; // If v[i] is not in the map
    }
    return count % 1000000007;
}

int main(){
    
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<"Number of nice pairs: "<<countNicePair(v)<<endl;

    return 0;
}