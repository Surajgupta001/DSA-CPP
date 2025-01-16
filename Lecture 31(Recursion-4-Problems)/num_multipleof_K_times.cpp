/*
Q. Given a number num and a value k. Print k multiple of num.

Constraint : k > 0
input 1 : num = 12, k = 5
output 1: 12 24 36 48 60

input 2 : num = 3, k = 8
output 2 : 3 6 9 12 15 18 21 24
*/ 

#include <iostream>
using namespace std;

void function (int num, int k){
    if(k==0) return; // Base case
    function (num,k-1); // Assumption
    cout<<(num*k)<<" "; // self work
}
int main(){
    int num;
    cout<<"Enter the num: ";
    cin>>num;

    int k;
    cout<<"Enter the value of ktimes: ";
    cin>>k;

    cout<<"5 multiple of num: ";
    function (num,k);
    return 0;
}