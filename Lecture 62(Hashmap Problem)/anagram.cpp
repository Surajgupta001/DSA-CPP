/*
Check whether two string are anagram of each other.Return true if they are else are return false. An anagram of a string is another string that contains the same characters, only the order of character can be different. For exmaple, "abcd" and "dacb" are an anagram of each other.

INPUT: triangle & integral
OUTPUT: TRUE

INPUT: anagram & grams
OUTPUT: False

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkAnagram(string str1, string str2){

    if(str1.size() != str2.size()){
        return false;
    }
    
    unordered_map<char,int>m;
    for(auto c1:str1){
        m[c1]++; // storing character and frequency in str1
    }

    for(auto c2:str2){
        if(m.find(c2) == m.end()){
            return false;
        }
        else{
            m[c2]--;
        }
    }
    for(auto ele:m){
        if(ele.second != 0){
            return false;
        }
    }
    return true;
}
int main(){

    string str1;
    cout<<"Enter a 1st string: ";
    getline(cin,str1);

    string str2;
    cout<<"Enter a 2nd string: ";
    getline(cin,str2);

    if(checkAnagram(str1,str2)){
        cout<<"YES, It is an Anagram.";
    }
    else{
        cout<<"NO, It is not a Anagram.";
    }

    return 0;
}