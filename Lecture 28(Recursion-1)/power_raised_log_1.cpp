#include <iostream>
using namespace std;
int powerlog(int a, int b){
    if(b==0) return 1; // Base case;
    if(b%2==0){
        // if b is even
        int result = powerlog(a,b/2);
        return result*result;
    }
    else{
        // if b is odd
        int result = powerlog(a,(b-1)/2);
        return a*result*result;
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