/*
Given a binary string and an intger k, return the maximum number of consecutive 1's in the string if you can flip at most k 0's.

INPUT: 0001101011 , k = 2
OUTPUT: 7.
*/

#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
#include <string>

int longestOnes(string str, int k){
    int start = 0;
    int end = 0;
    int zero_count = 0;
    int max_length = 0;

    for (; end < str.size(); end++){
        if (str[end] == '0'){
            zero_count++;
        }
        while (zero_count > k){
            if (str[start] == '0')
                zero_count--;
            start++; // contracting our window
        }

        // zero_count <= k
        max_length = max(max_length, end - start + 1);
    }
    return max_length;
}
int main(){

    string str;
    cout << "Enter binary string: ";
    cin>>str;

    int k;
    cout << "Enter max flips: ";
    cin>>k;

    cout<<"Maximum no. of 1's flip is: "<<longestOnes(str, k) << endl;

    return 0;
}
