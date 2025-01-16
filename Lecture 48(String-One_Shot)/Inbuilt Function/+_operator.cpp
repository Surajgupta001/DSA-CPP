#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int main(){

    string str1 = "Suraj";
    string str2 = "Gupta";

    cout<<str1+str2<<endl;

    // when str1 me str2 ko append karna hai tab.
    str1+=str2; // s1=s1+s2(copy string created for str1 extra space for creating copy) ---> both are not same.
    cout<<str1<<endl;

    return 0;
}