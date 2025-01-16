#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int main(){

    string str = "Survive";

    // str.substr(position,length of string).

    cout<<str.substr(0,3)<<endl;
    cout<<str.substr(0)<<endl;

    return 0;
}