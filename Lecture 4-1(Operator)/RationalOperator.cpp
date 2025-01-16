// Rational Operator ----> == , ! , > , < , => , =< .
#include <iostream>
using namespace std;
int main(){
    int num1,num2;
    cout<<"Enter the value of num1: ";
    cin>>num1;
    cout<<"Enter the value of num2: ";
    cin>>num2;
    cout<<(num1 == num2)<<endl;
    cout<<(num1 > num2)<<endl;
    cout<<(num1 < num2)<<endl;
    cout<<(num1 != num2)<<endl;
    cout<<(num1 >= num2)<<endl;
    cout<<(num1 <= num2)<<endl;
    return 0;
}