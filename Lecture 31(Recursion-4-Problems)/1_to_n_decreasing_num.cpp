/*
Q. Given a number n. Find the decreasing sequence from n to 1 without using any loop.

Constraint : 0<n<=1e6
input 1 : n = 4
output 1: 4 3 2 1

input 2 : n = 2
output 2 : 2 1
*/ 

#include <iostream>
using namespace std;

void decreasing (int n){
    if(n==0) return;
    cout<<n<<" ";
    decreasing (n-1);
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Decreasing order is: ";
    decreasing(n);
    return 0;
}