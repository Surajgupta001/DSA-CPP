#include <iostream>
using namespace std;
#include <string>

int main(){

    string str;
    cout<<"Enter a string: ";
    // cin>>str;
    getline(cin,str);

    cout<<str<<endl;

    return 0;
}