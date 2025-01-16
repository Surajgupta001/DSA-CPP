/*
Perfect Number - [LEETCODE - 507(Easy)]
=======================================

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.

Example 2:

Input: num = 7
Output: false
*/ 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool checkPerfectNumber(int n){
    int sumOfFactors = 0;
    for(int i=1;i<sqrt(n);i++){
        if(n%i == 0) sumOfFactors += i;
    }
    for(int i=sqrt(n);i>1;i--){
        // If the number is a prime factor, then add it to the sum
        if(n%i == 0) sumOfFactors += n/i;
    }
    return (sumOfFactors == n);
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    
    if(checkPerfectNumber(n)) cout<<"Yes, It's Perfect Number.";
    else cout<<"It is Not a Perfect Number.";

    
    return 0;
}