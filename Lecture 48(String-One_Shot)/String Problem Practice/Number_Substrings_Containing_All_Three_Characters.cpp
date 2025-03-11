/*
Number of Substrings Containing All Three Characters - [Leetcode - 1358(Medium)]
===============================================================================
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/ 

#include <iostream>
#include <vector>
using namespace std;

int numberOfSubstrings(string s){
    int n = s.length();
    vector<int> freq(3, 0);
    int req = 3;
    int formed = 0;
    int ans = 0;
    int left = 0;

    for(int right = 0; right < n; right++){
        freq[s[right] - 'a']++;
        if(freq[s[right] - 'a'] == 1){
            formed++;
        }

        while(formed == req && left <= right){
            ans += n - right;
            freq[s[left] - 'a']--;
            if(freq[s[left] - 'a'] == 0){
                formed--;
            }
            left++;
        }
    }
    return ans;
}

int main(){
    string s = "abcabc";
    cout << numberOfSubstrings(s) << endl;
    return 0;
}