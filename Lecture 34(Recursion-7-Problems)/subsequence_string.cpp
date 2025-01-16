/*
Given a string, we have to find out all its subsequence of it. A string is a subsequence of a given string , that is generayed by deleting some character of a given string without changing its order.

INPUT: abc
OUTPUT: a,b,c,ab,bc,ac,abc
*/ 

#include <iostream>
#include <vector>
using namespace std;

void function (string &str, int i, string result, vector<string> &li){
    if(i==str.length()){
        return li.push_back(result);
    }
    function (str,i+1,result+str[i],li);
    function (str,i+1,result,li);
}
int main(){
    vector<string>res;
    string str = "abc";
    cout<<"Subsequence character are: "<<endl;
    function(str,0," ",res);
    for (int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}