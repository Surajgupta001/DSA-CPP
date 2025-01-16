/*
Given an array of string. Write a program to find the longest common prefix string amongest an aary of string.

INPUT 1 : ["flower", "flight", "flask"]

OUTPUT 1 : "fl"

INPUT 2 : ["ant", "anti", "antthem"]

OUTPUT 2 : "ant"

*/ 

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>

string LongestCommonPrefix(vector<string>&str){
    /*
    Time: O(nlogn*n)
    Space:O(1)
    */ 

    // sorting the array of string
    sort(str.begin(),str.end());

    int i=0;
    int j=0;

    string str1 = str[0]; // first string
    string str2 = str[str.size()-1]; // last string

    string ans=" ";
    while(i<str1.size() && j<str2.size()){
        if(str1[i] == str2[j]){
            ans += str1[i];
            i++;
            j++;
        }
        else{
            break;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter no. of strings: ";
    cin>>n;

    cout<<"Enter all the strings: ";
    vector<string>strs;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        strs.push_back(str);
    }

    cout<<"Longest common prefix: "<<LongestCommonPrefix(strs)<<endl;
    return 0;
}