#include <iostream>
using namespace std;

int factorial (int n){
    if(n==1 || n==0) return 1; // Base Case
    int rec_ans = n*factorial(n-1); // function call
    return rec_ans; // return
}
int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;
    
    cout<<"Factorial of this number is: "<<factorial(n);

    return 0;
}