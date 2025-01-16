/*
Keys Keyboard - [leetcode -650(medium)]
==========================================
There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Example 2:

Input: n = 1
Output: 0
*/ 

#include <iostream>
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

// Function to find the greatest divisor of a number
int greatestDivisor(int n){
    for(int i=2;i<=sqrt(n);i++){
        // If i is a divisor of n, then n/i is the greatest divisor
        if(n%i==0) return n/i;
    }
    return 1;
}

// Function to find the minimum number of steps to reach n 'A's on the screen
int minSteps(int n){
    int count = 0;
    while(n > 1){
        // If n is a prime number, we can directly add it to the count
        if(isPrime(n)){
            count += n;
            break;
        }
        // Find the greatest divisor of n
        int highestFactor = greatestDivisor(n);
        // Add the number of steps to reach the greatest divisor
        count += (n/highestFactor);
        // Update n to the greatest divisor
        n = highestFactor;
    }
    return count;
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Minimum number of steps to reach 1: "<<minSteps(n)<<endl;
    
    return 0;
}