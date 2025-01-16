/*
Construct String With Repeat Limit - [Leetcode - 2182(Medium)]
================================================================

You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.

Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
*/ 

#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

string repeatLimitedString(string str, int repeatLimit){
    unordered_map<char,int>m;
    for(int i=0;i<str.size();i++) m[str[i]]++;
    priority_queue<pair<char,int>>pq;
    for(auto itr:m) pq.push(itr);
    string result = "";
    while(!pq.empty()){
        auto largest = pq.top();
        pq.pop();
        int length = min(repeatLimit,largest.second);
        for(int i=0;i<length;i++) result +=largest.first;
        pair<char,int> secondLargest;
        if(largest.second - length > 0){
            if(!pq.empty()){
                secondLargest = pq.top();
                pq.pop();
                result += secondLargest.first;
            }
            else{
              return result;
            }
            if(secondLargest.second - 1 > 0) pq.push({secondLargest.first, secondLargest.second - 1});
            pq.push({largest.first, largest.second - length});
        }
    }
    return result;
}

int main(){
    
    string str = "cczazcc";
    int repeatLimit = 3;
    cout << "Input: s = " << str << ", repeatLimit = " << repeatLimit << endl;
    cout << "Output: " << repeatLimitedString(str, repeatLimit) << endl;
    
    str = "aababab";
    repeatLimit = 2;
    cout << "Input: s = " << str << ", repeatLimit = " << repeatLimit << endl;
    cout << "Output: " << repeatLimitedString(str, repeatLimit) << endl;
    
    return 0;
}