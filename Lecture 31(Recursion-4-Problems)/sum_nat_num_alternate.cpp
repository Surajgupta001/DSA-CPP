/*
Given a number n. Find the sum of natural numbers till n but with alternate signs.
That means if n = 5 the ypu have to return 1-2+3-4+5 = 3 as your answer.
Constraints: 0<=n<=10^6.

Input 1: n = 10
Output 1 : = -5

Input 2 : = 5
output 2 : = 3
*/

#include <iostream>
using namespace std;
int function (int n){
    if(n==0) return 0; // Base case
    // Calculate sum of first n-1 natural num with alternate.
    return function(n-1) + ((n%2==0) ? (-n) : (n)); // Assumption
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Alternate sum of number is : "<<function(n)<<endl;
    return 0;
}