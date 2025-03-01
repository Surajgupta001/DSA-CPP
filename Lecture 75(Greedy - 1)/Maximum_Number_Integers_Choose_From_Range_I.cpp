/*
Maximum Number of Integers to Choose From a Range I - [Leetcode - 2554(Medium)]
=================================================================================

You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.

Return the maximum number of integers you can choose following the mentioned rules.

Example 1:

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
Example 2:

Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.
Example 3:

Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.

Constraints:

1 <= banned.length <= 104
1 <= banned[i], n <= 104
1 <= maxSum <= 109
*/ 

#include <iostream>
#include <vector>
#include <Unordered_set>
using namespace std;

int maxCount(vector<int>& banned, int n, int maxSum){
    // Create a set of banned integers for efficient lookups i.e. vector
    unordered_set<int> set(banned.begin(), banned.end());

    int sum = 0; 
    int count = 0;
    
    // Iterate over the range [1,n]
    for(int i=1; i<=n; i++){
        // If the current integer is not in the banned set
        if(set.find(i) == set.end()){
            sum += i; // add the current integer
            if(sum > maxSum) break; // if the sum exceed maxSum, then exit the loop
            count++;
        }
    }
    return count; // incerement the count of chosen integer
}

int main(){
    
    int num;
    cout<<"Enter the size of vector: ";
    cin>>num;
    
    vector<int> v(num);
    cout<<"Enter the elements of vector: ";
    for(int i=0; i<num; i++) cin>>v[i];
    
    int maxSum;
    cout<<"Enter the maxSum: ";
    cin>>maxSum;

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"The maximum number of integers that can be chosen is: "<<maxCount(v,n,maxSum);
    
    return 0;
}