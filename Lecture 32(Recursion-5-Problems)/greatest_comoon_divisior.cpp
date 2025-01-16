/*
Given two number x and y . Find the greatest common divisor of x and y using recursion.

Constraints: 0<=x, y<=10^6
Input 1: x = 4, y = 9
Output 1 : 1

intput 2 : x = 12, y = 20
Output 2 : 4

*/ 

/*
EUCLID'S ALGORITHM
If we substract (or division) a smaller number from a larger number, (we can reduce the larger number) but the GCD will not change.

Example: GCD ---> 54,72 - GCD will be 18.

*/ 
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b > a) return gcd(b, a);
    if(b==0) return a; // Base case
    return gcd (b,a%b);
}
int main(){

    int n;
    cout<<"Enter the 1st number: ";
    cin>>n;

    int m;
    cout<<"Enter the 2nd number: ";
    cin>>m;

    cout<<"GCD of these 2 number is : "<<gcd(n,m);

    return 0;
}