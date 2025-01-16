#include <iostream>
using namespace std;
int main(){
    int n1,n2;
    cout<<"Enter 2 integer: \n";
    cin>>n1>>n2;

    cout<<"Enter the operatot(=,-,*,/,%) : ";
    char op;
    cin>>op;

    switch(op){
        case '+':
        cout<<"sum is : "<<n1+n2<<endl;
        break;
        case '-':
        cout<<"difference is : "<<n1-n2<<endl;
        break;
        case '*':
        cout<<"product is : "<<n1*n2<<endl;
        break;
        case '/':
        cout<<"division is : "<<n1/n2<<endl;
        break;
        case '%':
        cout<<"modulus is : "<<n1%n2<<endl;
        break;
        default:
        cout<<"Enter a valid opertaor : "<<endl;
        break;
    }
    return 0;
}