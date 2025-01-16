#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the value: ";
    cin>>num;
    if((num%3 == 0) || (num%5 == 0)){
        cout<<"It is divisible by 3 & 5: "<<num<<endl;
    }
    else{
        cout<<"It is not divisible by 3 & 5.";
    }
    return 0;
}
