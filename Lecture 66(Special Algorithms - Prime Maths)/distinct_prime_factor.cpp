/*
Distinct Prime Factors Of Product Of Array - [Leetcode - 2521(Medium)]
========================================================================
Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.

Note that:

A number greater than 1 is called prime if it is divisible by only 1 and itself.
An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.
 

Example 1:

Input: nums = [2,4,3,7,10,6]
Output: 4
Explanation:
The product of all the elements in nums is: 2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7.
There are 4 distinct prime factors so we return 4.
Example 2:

Input: nums = [2,4,8,16]
Output: 1
Explanation:
The product of all the elements in nums is: 2 * 4 * 8 * 16 = 1024 = 210.
There is 1 distinct prime factor so we return 1.
*/ 

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Sieve of Eratosthenes
void fillSieve(vector<bool>& Sieve){
    int n = Sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++){
        for(int j=i*2;j<=n;j+=i){
            Sieve[j] = 0;
        }
    }
}

// Distinct Prime Factors
int distinctPrimeFactor(vector<int>& nums){
    int n = nums.size()-1;
    int mx = -1;
    for(int i=0;i<n;i++){
        mx = max(mx,nums[i]);
    }

    // Sieve of Eratosthenes
    vector<bool> Sieve(mx+1,1); // 1 means prime
    // 0 and 1 are not prime numbers
    if(mx+1 > 0) Sieve[0] = 0;
    if(mx+1 > 1) Sieve[1] = 0;
    fillSieve(Sieve);
    
    // Storing all prime numbers in a vector
    vector<int>primes;
    for(int i=2;i<=mx;i++){
        // If the number is prime, then store it in the vector
        if(Sieve[i] == 1) primes.push_back(i);
    }

    // Distinct Prime Factors
    vector<bool>taken(primes.size(),0); 
    for(int i=0;i<n;i++){
        int ele = nums[i];
        for(int j=0;j<primes.size();j++){
            // If the prime number is greater than the element, then break the loop
            if(primes[j] > ele) break;
            // If the prime number is a factor of the element, then mark it as taken
            if(ele % primes[j] == 0) taken[j] = 1;
        }
    }

    // Counting distinct prime factors
    int count = 0;
    for(int i=0;i<taken.size();i++){
        // If the prime number is taken, then increment the count
        if(taken[i] == 1) count++;
    }
    return count;
}

int main(){
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<"Distinct prime factors: "<<distinctPrimeFactor(v)<<endl;

    return 0;
}