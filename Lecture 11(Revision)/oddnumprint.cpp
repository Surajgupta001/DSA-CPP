#include <iostream>
using namespace std;

bool odd(int num){
    if(num%2==0){
        return false;
    }
    else{
        return true;
    }
}

int main(){

    int a;
    cout<<"Enter the value of a: ";
    cin>>a;

    int b;
    cout<<"Enter the value of b: ";
    cin>>b;

    for(int i = a;i<=b;i++){
        if(odd(i)){
            cout<<i<<endl;
        }
    }

    return 0;
}