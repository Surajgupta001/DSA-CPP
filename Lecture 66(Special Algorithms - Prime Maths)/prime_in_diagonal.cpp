/*
PRIME IN DIAGONAL - [LEETCODE - 2614(Easy)]
=============================================
You are given a 0-indexed two-dimensional integer array nums.

Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of the diagonals, return 0.

Note that:

An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
An integer val is on one of the diagonals of nums if there exists an integer i for which nums[i][i] = val or an i for which nums[i][nums.length - i - 1] = val.


In the above diagram, one diagonal is [1,5,9] and another diagonal is [3,5,7].


Example 1:

Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
Output: 11
Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers present on at least one of the diagonals. Since 11 is the largest prime, we return 11.

Example 2:

Input: nums = [[1,2,3],[5,17,7],[9,11,10]]
Output: 17
Explanation: The numbers 1, 3, 9, 10, and 17 are all present on at least one of the diagonals. 17 is the largest prime, so we return 17.
*/ 

/*
Logic behind the diagonalPrime function:

1. We iterate through the diagonal elements of the square matrix:
   - Main diagonal: num[i][i]
   - Secondary diagonal: num[i][n-i-1]

2. For each element on the diagonals, we check if it's prime using the isPrime function.

3. If a prime number is found, we update the maximum prime (mx) if the current prime is larger.

4. The isPrime function checks primality by:
   - Returning false for numbers <= 1
   - Checking divisibility up to the square root of the number for efficiency
   - Returning true if no divisors are found

5. Finally, we return the largest prime number found on the diagonals (mx).

This approach is efficient as it only checks the diagonal elements, 
reducing the number of primality tests needed compared to checking all matrix elements.
*/

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n){
    if(n <= 1) return false;
    for (int i=2;i<=sqrt(n);i++){
        if (n % i == 0) return false;
    }
    return true;
}

// Function to find the largest prime number on the diagonals
int diagonalPrime(vector<vector<int>>& num){
    int n = num.size();
    int mx = 0;
    for(int i=0;i<n;i++){
        if(isPrime(num[i][i])){
            mx = max(mx , num[i][i]);
        }
        if(isPrime(num[i][n-i-1])){
            mx = max(mx , num[i][n-i-1]);
        }
    }
    return mx;
}

int main(){
    int n;
    cout<<"Enter the size of the 2D array: ";
    cin>>n;
    
    vector<vector<int>> nums(n, vector<int>(n));
    cout<<"Enter the elements of the 2D array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    
    cout<<"Largest prime on diagonal: "<<diagonalPrime(nums)<<endl;
    
    return 0;
}