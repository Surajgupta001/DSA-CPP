/*
Find the sum of digit in a given number.
i.e. 34762 ------> sum : 22
----> Here modulus operator is used to solve these type of problem;
*/ 
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    while(n>0){
        int lastdigit=n%10;
        sum = sum+lastdigit;
        n=n/10;
    }
    cout<<sum<<endl;
    return 0;
}