/*
Given two strings S and T, find the length of the shortest subsequence in S which is not a subsequence in T. If no such subsequence is possible, return -1. A subsequence is a sequence that appears in the same relative order, but is not necessarily contiguous. A string of length n has 2^n different possible subsequences.

String S of length m (1 <= m <= 1000) 
String T of length n (1 <= n <= 1000)

Examples: 


Input : S = “babab” T = “babba”
Output : 3
Explanation: The subsequence “aab” of length 3 is present in S but not in T.


Input :  S = “abb” T = “abab”
Output : -1
Explanation: There is no subsequence that is present in S but not in T.
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool isSubsequence(string str1, string str2) {
    int i = 0, j = 0;
    while (i < str1.length() && j < str2.length()) {
        if (str1[i] == str2[j]) i++;
        j++;
    }
    return i == str1.length();
}

int shortestUncommonSubsequence(string str1, string str2, string current = "", int i = 0){ // index
    int m = str1.size();
    int n = str2.size();

    if (i == m) {
        if (!current.empty() && !isSubsequence(current, str2)) return current.length();
        return INT_MAX;
    }

    int include = shortestUncommonSubsequence(str1, str2, current + str1[i], i + 1);

    int exclude = shortestUncommonSubsequence(str1, str2, current, i + 1);

    return min(include, exclude);
}

int main(){

    string str1, str2;
    cout<<"Enter 1st string: ";
    cin>>str1;

    cout<<"Enter 2nd string: ";
    cin>>str2;

    int ans = shortestUncommonSubsequence(str1, str2, "", 0);
    cout<<"Shortest uncommon subsequence length is: ";;
    cout<<(ans == INT_MAX ? -1 : ans)<<endl;
}