#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int main(){

    string str = "ABCD";
    char ch = 'E';

    str.push_back(ch);
    cout<<str<<endl;
    
    return 0;
}