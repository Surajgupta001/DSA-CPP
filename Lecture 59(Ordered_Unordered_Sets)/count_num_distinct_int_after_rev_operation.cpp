/*
Count Number of Distinct Integers After Reverse Operations - leetCode [2442(Medium)]
====================================================================================
You are given an array nums consisting of positive integers.

You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.

Return the number of distinct integers in the final array.

Example 1:

Input: nums = [1,13,10,12,31]
Output: 6
Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).

Example 2:

Input: nums = [2,2,2]
Output: 1
Explanation: After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
The number of distinct integers in this array is 1 (The number 2).

*/ 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int reverse(int num){
    /*
    * Time: O(logn)
    */ 
    int reversedNum = 0;
    while(num > 0){
        reversedNum = reversedNum * 10 + num % 10; // Build the reversed number
        num /= 10; // Remove the last digit
    }
    return reversedNum;
}

// int reverse(int num){
        /*
        * Time: O(n)
        */ 
//     string str = to_string(num);
//     reverse(str.begin(),str.end());
//     return stoi(str);
// }


pair<int, unordered_set<int>> countDistinctIntegers(vector<int>& nums){
    unordered_set<int> distinctIntegers; // Store the distinct numbers
    for(int num : nums){
        distinctIntegers.insert(num); // insert the original 
        distinctIntegers.insert(reverse(num));
    }
    return {distinctIntegers.size(), distinctIntegers}; // return the count and the set of distinct integers
}

int main(){
    
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter all the elements of vectors: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    auto result = countDistinctIntegers(v);
    cout<<"Distinct integers: ";
    for(auto num : result.second) {
        cout<<num<<" "; // Print each distinct integer
    }
    cout<<endl<<"Distinct integers after reversing: " <<result.first<<endl; // Print count

    return 0;
}