/*
Given an integer n, find the maximum power of 2 that is smaller than n.
*/ 

#include <iostream>
using namespace std;
int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int temp;
    while(n != 0){
        temp = n;
        n = n & (n-1);
    }
    cout<<"The maximum power of 2 smaller than is: "<<temp<<endl; 

    return 0;
}