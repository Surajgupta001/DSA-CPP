/*
Count Prime - [Leetcode - 204(Hard)]
====> Sieve of Eratosthenes
=============================================
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:

Input: n = 0
Output: 0

Example 3:

Input: n = 1
Output: 0
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
        // If the number is prime, then mark all its multiples as not prime
        for(int j=i*2;j<=n;j+=i){
            Sieve[j] = 0;
        }
    }
}
// Count Prime
int countPrime(int n){
    if(n<=2) return 0;
    n = n-1;
    int count = 0;
    vector<bool> Sieve(n+1,1); // 1 means prime & 0 means not prime
    // 0 and 1 are not prime numbers
    fillSieve(Sieve);
    Sieve[0] = 0;
    Sieve[1] = 0;
    // Counting the number of prime numbers
    for(int i=2;i<=n;i++){
        if(Sieve[i]) count++;
    }
    return count;
}
int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Number of primes less than "<<n<<" is: "<<countPrime(n)<<endl;

    return 0;
}