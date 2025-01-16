#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the value: ";
    cin>>num;
    if((num%2 == 0)&&(num%3 == 0)){
        cout<<num<<endl;
    }
    return 0;
}