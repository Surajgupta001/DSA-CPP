/*
Smallest Value After Replacing With Sum Of Prime Factors - [Leetcode - 2507-(medium)]
===========================================================

You are given a positive integer n.

Continuously replace n with the sum of its prime factors.

Note that if a prime factor divides n multiple times, it should be included in the sum as many times as it divides n.
Return the smallest value n will take on.

 

Example 1:

Input: n = 15
Output: 5
Explanation: Initially, n = 15.
15 = 3 * 5, so replace n with 3 + 5 = 8.
8 = 2 * 2 * 2, so replace n with 2 + 2 + 2 = 6.
6 = 2 * 3, so replace n with 2 + 3 = 5.
5 is the smallest value n will take on.
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
// Smallest Value After Replacing With Sum Of Prime Factors
int smallestValue(int n){

    if(isPrime(n)) return n;

    // prime factors
    int sumOfFactors = 0;
    for(int i=1;i<sqrt(n);i++){
        // If the number is a prime factor, then add it to the sum
        if(n%i == 0 && isPrime(i)){
            int m = n;
            while(m%i == 0){
                sumOfFactors += i;
                m /= i;
            }
        }
    }
    // If the number is a prime factor, then add it to the sum
    for(int i=sqrt(n);i>1;i--){
        if(n%i == 0 && isPrime(n/i)){
            int m = n;
            while(m%(n/i) == 0){
                sumOfFactors += (n/i);
                m /= (n/i);
            }
        }
    }
    if(sumOfFactors == n) return n; // n = 4 special case
    return smallestValue(sumOfFactors);
}

/*
* Time: O(sqrt(n)) or even O(log n)
*/ 

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"The smallest value of n is: "<<smallestValue(n)<<endl;
    
    return 0;
}