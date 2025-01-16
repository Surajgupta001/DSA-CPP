#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void findFactors(int n){
    /*
    * Time : O(n);
    */ 
    for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<" ";
    }
}

void findFactors1(int n){
    /*
    * Time : O(sqrt(n));
    */ 
    for(int i=1;i<=sqrt(n);i++){
        // if n is not a square root
        if(n%i==0) cout<<i<<" ";
            // if n is square root.
            if(i != sqrt(n)) cout<<n/i<<" ";
    }
}

// sorted order
void findFactors2(int n){
    for(int i=1;i<sqrt(n);i++){
        if(n%i == 0) cout<<i<<" ";
    }
    for(int i=sqrt(n);i>=1;i--){
        if(n%i == 0) cout<<n/i<<" ";
    }
}

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Factors of given numbers are: ";
    findFactors(n);
    cout<<endl;

    cout<<"Factors of given numbers are in pairs: ";
    findFactors1(n);
    cout<<endl;

    cout<<"Factors of given numbers are in sorted order: ";
    findFactors2(n);

    return 0;
}