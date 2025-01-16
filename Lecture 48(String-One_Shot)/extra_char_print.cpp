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
using namespace std;

void printExtraChar(string str1, string str2){
    /*
    * Time : O(n^2);
    * space : O(1);
    */
    if(str1.size() > str2.size()){
        swap(str1,str2);
    }
    for(int i=0;i<str2.size();i++){
        bool found = false;
        for(int j=0;j<str1.size();j++){
            if(str2[i] == str1[j]){
                found = true;
                break;
            }
        }
        if(!found){
            cout << "Extra character is: " << str2[i] << endl;
            return;
        }
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