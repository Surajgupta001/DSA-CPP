/*
Ugly Number - [Leetcode - 363(Easy)]
=====================================
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
*/
#include <iostream>
using namespace std;

// Function to check if a number is ugly
bool isUgly(int n){
    if(n <= 0) return false;

    // Divide n by 2, 3, and 5 until it is no longer divisible by any of these numbers
    while(n % 2 == 0) n /= 2;
    while(n % 3 == 0) n /= 3;
    while(n % 5 == 0) n /= 5;
    
    // If n is reduced to 1, it means all prime factors are limited to 2, 3, and 5
    return (n == 1);
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    
    cout<<boolalpha<<isUgly(n)<<endl;

    return 0;
}