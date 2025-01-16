#include <iostream>
using namespace std;

int add(int num1,int num2){
    int sum = num1+num2;
    return sum;
}

int add(int num1,int num2,int num3){
    int sum = num1+num2+num3;
    return sum;
}

float add(float num1, float num2){
    float sum = num1 + num2;
    return sum;
}

int main(){
    int a;
    cout<<"Enter the value of a: ";
    cin>>a;

    int b;
    cout<<"Enter the value of b: ";
    cin>>b;

    int c;
    cout<<"Enter the value of c: ";
    cin>>c;

    float d;
    cout<<"Enter the value of d: ";
    cin>>d;

    float e;
    cout<<"Enter the value of e: ";
    cin>>e;

    cout<<add(d,e)<<endl;

    return 0;
}