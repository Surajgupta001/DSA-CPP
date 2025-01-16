#include <iostream>
using namespace std;

int fibo (int n){
    if(n==0 || n==1) return n; // base case
    
    return fibo(n-1) + fibo(n-2); // function call
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Fibonacci number: "<<fibo(n);
    
    return 0;
}