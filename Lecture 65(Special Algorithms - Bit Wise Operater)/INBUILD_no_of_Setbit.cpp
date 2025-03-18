/*
Find the number of set bit (i.e. no of 1's) for any integer.
*/ 
#include <iostream>
using namespace std;

int countSetBits(int n){
    return __builtin_popcount(n);
}

int main(){

    int n;
    cout<<"Enter decimal number: ";
    cin>>n;


    cout<<"Numbers of 1's: "<<countSetBits(n)<<endl;

    return 0;
}