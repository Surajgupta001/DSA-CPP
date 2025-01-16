#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int main(){
    
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    reverse(str.begin(), str.end());

    cout<<"Reversed string: "<<str<<endl;

    return 0;
}