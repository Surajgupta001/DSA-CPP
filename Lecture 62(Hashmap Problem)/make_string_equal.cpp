/*
Can you make the string equal?
Given an array of string. You can move any number of character from one string to any other string any number of times. You just have to make all of them equal.
Print "YES" if you can make every string in the array eual by using any number of operations otherwise print "NO".

INPUT: ["collegeee","coll",collegge]
OUTPUT: YES
EXPLANATION: string at 1 index can take two 'e' form 0 index string and one 'g' from 2 index string.

INPUT: ["wall","ah","wallahah"]
OUTPUT: NO
EXPLANATION: Here we dont't have enough number of characters to make all string equal.
*/ 
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool canMakeEqual(vector<string>& v){

    unordered_map<char,int> m;

    for(auto str:v){
        for(char c:str){
            m[c]++;
        }
    }
    for(auto ele:m){
        if(ele.second % v.size() == 0){
            return true;
        }
    }
    return false;
}

int main(){
    
    int n;
    cout << "Enter the size of vector: ";
    cin>>n;

    vector<string>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    cout<<(canMakeEqual(v));

    return 0;
}