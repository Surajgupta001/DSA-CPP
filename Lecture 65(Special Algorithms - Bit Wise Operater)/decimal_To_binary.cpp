#include <iostream>
using namespace std;

string decimalToBinary(int num){
    string result = "";
    while(num > 0){
        if(num % 2 == 0){
            // even
            result = "0" + result;
        }
        else{
            // odd
            result = "1" + result;
        }
        // num = num / 2;
        num = num >> 1;
    }
    return result;
}
int main(){

    int n;
    cout<<"Enter Decimal number: ";
    cin>>n;

    cout<<"Binary number: "<<decimalToBinary(n)<<endl;

    return 0;
}