#include <iostream>
using namespace std;

int sumOfdigit (int n){
    
    if(n<=9 && n>=0) return n;

    return sumOfdigit(n/10) + (n%10);
}
int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Sum of digit is: "<<sumOfdigit(n);
    
    return 0;
}