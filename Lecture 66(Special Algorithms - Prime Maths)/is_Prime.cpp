#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    for (int i=2;i<=n-1;i++){
        if (n % i == 0) return false;
    }
    return true;
}

bool isPrime1(int n){
    if(n <= 1) return false;
    for (int i=2;i<=sqrt(n);i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<isPrime(n)<<endl;
    cout<<isPrime1(n);

    return 0;
}