/*
Q. Given a number n. Find the increasing sequence from 1 to n without using any loop.

Constraint : 0<n<=1e6
input 1 : n = 4
output 1: 1 2 3 4

input 2 : n = 2
output 2 : 1 2
*/ 

#include <iostream>
using namespace std;

void increasing (int n){
    if(n==0) return;
    increasing (n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Increasing order is: ";
    increasing(n);
    return 0;
}