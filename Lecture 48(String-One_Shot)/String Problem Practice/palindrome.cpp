#include <iostream>
using namespace std;
#include <string>

string isPalindrome(string str){
    
    /*
    Time: O(N)
    Space: O(1)
    */ 

    // iterate over the range [0,n/2]
    for(int i=0;i<str.size()/2;i++){ 

        // str[i] is not equal to the str[n-i-1]
        if(str[i] != str[str.size()-i-1]){
            return "It is not a palindrome.";
        }
    }
    return "It is a palindrome.";
}
int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout<<isPalindrome(str)<<endl;

    return 0;
}