#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int main(){

    int num = 432;
    
    string str = to_string(num);
    str += "1";

    cout<<str<<endl;
    return 0;
}