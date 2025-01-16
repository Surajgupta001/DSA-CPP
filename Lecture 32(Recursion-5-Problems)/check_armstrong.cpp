/*
Given a number n. Printfif it is an armstrong number or not.

i.e 153 = 1^3 + 5^3 + 3^3 = 3 + 125 + 9 = 153.
*/ 

#include <iostream>
using namespace std;

int power_recursive(int a, int b){
    if(b==0) return 1; // Base case;
    if(b%2==0){
        // if b is even
        int result = power_recursive(a,b/2);
        return result*result;
    }
    else{
        // if b is odd
        int result = power_recursive(a,(b-1)/2);
        return a*result*result;
    }
}

int function(int n, int digit){
    // base case
    if(n==0) return 0;
    return power_recursive(n%10,digit) + function(n/10,digit);
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int no_Of_digit = 0;
    int temp = n;
    while (temp>0){
        temp = temp/10;
        no_Of_digit++;
    }

    int result = function(n, no_Of_digit);
    if(result == n){
        cout<<"Yes it is Armstrong Number.";
    }
    else{
        cout<<"No, it is not Armstrong Number.";
    }
    return 0;
}