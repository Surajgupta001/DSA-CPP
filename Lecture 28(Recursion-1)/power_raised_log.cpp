#include <iostream>
using namespace std;

int powerlog(int a, int b){
    
    if(b==0) return 1; // Base case;

    int x = powerlog(a,b/2);
    if(b%2==0){ // even
        return x*x;
    }
    else{ // odd
        return a*x*x;
    }
}
int main(){
    
    int a;
    cout<<"Enter base: ";
    cin>>a;

    int b;
    cout<<"Enter exponent: ";
    cin>>b;

    cout<<"power is: "<<powerlog(a,b);

    return 0;
}