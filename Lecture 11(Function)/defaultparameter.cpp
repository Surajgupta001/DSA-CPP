#include <iostream>
using namespace std;

int add(int a, int b=1, int c=2){
    int sum = a+b+c;
    return sum;
}

int main(){
    
    cout<<add(2)<<endl; // 5 
    cout<<add(2,2)<<endl; // 6
    cout<<add(2,2,3)<<endl; // 7

    return 0;
}