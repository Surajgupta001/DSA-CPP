#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string isPalindrome(string str){

    /*
    Time: O(N)
    Space: O(N)
    */ 
    
    string p = str;

    reverse(p.begin(),p.end());
    
    if(str == p){
        return "It is Palindrome.";
    }
    else{
        return "It is not palindrome.";
    }
}
int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout<<isPalindrome(str)<<endl;

    return 0;
}