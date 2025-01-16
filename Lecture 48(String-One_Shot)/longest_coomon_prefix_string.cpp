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

string LongestCommonPrefix(vector<string> &str){

    /*
    Time: O(n*m)
    Space: O(1) 
    */ 

    // Keeping first string as constant and comparing it with all other string
    string str1 = str[0];
    int ans_size = str1.size();

    for(int i=1;i<str.size();i++){

        int j=0;
        while(j < str1.size() && j < str[i].size() && str1[j] == str[i][j]) // finding the common prefix string size
        j++;

        ans_size = min(ans_size,j); // updating size of ans string
    }
    string ans = str1.substr(0,ans_size);
    return ans;
}
int main(){

    int n;
    cout<<"Enter no. of strings: ";
    cin>>n;

    cout<<"Enter strings: "<<endl;
    vector<string>str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }

    cout<<"Longest common prefix: "<<LongestCommonPrefix(str)<<endl;
    return 0;
}