// 1st way;
#include <iostream>
using namespace std;

    bool prime(int num){
        for(int i=2;i<=num-1;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    
    bool primebtr(int num){
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }

int main(){

    int a;
    cout<<"Enter the value of a: ";
    cin>>a;

    int b;
    cout<<"Enter the value of b: ";
    cin>>b;

    for(int i=a;i<b;i++){
        if(prime(i)){
            cout<<i<<endl;
        }
    }

    return 0;
}