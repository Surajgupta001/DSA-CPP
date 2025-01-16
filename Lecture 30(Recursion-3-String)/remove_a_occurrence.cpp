/*
Remove all the occuerence of 'a' form tring s = "abcax"
*/ 
#include <iostream>
using namespace std;

string function (string &s, int idx, int n){
    // Base case 
    if(idx == n) return "";
    string current = "";
    current += s[idx];
    return ((s[idx] == 'a') ? "" : current) + function(s, idx+1,n); // ternary operator;
}
int main(){
    string s = "abcax";
    int n = 5;
    cout<<function(s,0,n);
    return 0;
}