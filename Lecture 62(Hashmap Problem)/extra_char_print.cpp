/*
FIND ONE EXTRA CHARACTER IN A STRING
Given two strings which are of lengths n and n+1. The second string contains all the characters of the first string, but there is one extra character. Your task is to find the extra character in the second string.

Input : string strA = "abcd";
        string strB = "cbdae";
Output : e
string B contain all the element there is a one extra character which is e
Input : string strA = "kxml";
        string strB = "klxml";
Output : l
string B contain all the element there is a one extra character which is l
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void printExtraChar(string str1, string str2){
    /*
    * Time: O(n);
    * Space: O(1);
    */ 
   if(str1.size() > str2.size()){
        swap(str1,str2);
    }
    unordered_map<char,int> count;

    // Count frequency of each character in str1
    for (int i=0;i<str1.size();i++) {
        count[str1[i]]++;
    }

    // Find the extra character in str2
    for (int i=0;i<str2.size();i++) {
        if (count[str2[i]] == 0) {
            cout<<"Extra character is: "<<str2[i]<<endl;
            return;
        }
        count[str2[i]]--;
    }
}

int main(){

    string str1;
    cout<<"Enter a 1st string: ";
    cin>>str1;

    string str2;
    cout<<"Enter a 2nd string: ";
    cin>>str2;

    printExtraChar(str1,str2);
    
    return 0;
}