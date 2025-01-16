#include <iostream>
using namespace std;
int main(){
    int num1,num2,temp;
    cout<<"Before swaping the number : \n";
    cout<<"Enter the value of num1 : ";
    cin>>num1;
    cout<<"Enter the value of num2 : ";
    cin>>num2;
    temp = num1;
    num1 = num2;
    num2 = temp;
    cout<<"After swaping the number \n";
    cout<<"Value of num1 : "<<num1<<endl;
    cout<<"Value of num2 : "<<num2<<endl;
    return 0;
}   


#include <iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Before swaping number: \n";
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout<<"After the swaping number :\n";
    cout<<"Value of a : "<<a<<endl;
    cout<<"value of b : "<<b<<endl;
    return 0;
}
