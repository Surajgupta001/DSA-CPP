/*
Count the number of digit for a given number n;
i.e. 34762 -------> 5 digit in this number.
----> using operator to solve this type of problem.
----> Division operator.
*/ 

#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the digit: ";
    cin>>n;
    int digits=0;
    while(n>0){
        digits++;
        n=n/10;
    }
    cout<<"digit of these number is: "<<digits<<endl;
    return 0;
}