/*
Partition Labels - [Leetcode - 763(Medium)]
===========================================
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.


Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> result;
    
    // last occurrence of each character
    // unordered_map<char, int>mp;
    vector<int> mp(26, -1);
    for(int i=0; i<s.size(); i++){
        int idx = s[i] - 'a';
        mp[idx] = i;
    }
    int i = 0;
    while(i < s.size()){
        int end = mp[s[i] - 'a'];
        
        int j = i;
        while(j < end){
            end = max(end, mp[s[j] - 'a']);
            j++;
        }
        result.push_back(end - i + 1);
        i = j + 1;
    }
    return result;
}

vector<int> partitionLabels(string s){
    vector<int> result;

    // last occurrence of each character
    // unordered_map<char, int>mp;
    vector<int> mp(26, -1);
    for(int i=0; i<s.size(); i++){
        int idx = s[i] - 'a';
        mp[idx] = i;
    }
    int i = 0;
    int start = 0;
    int end = 0;
    while(i < s.size()){
        end = max(end, mp[s[i] - 'a']);
        if(i == end){
            result.push_back(end - start + 1);
            start = end + 1;
        }
        i++;
    }
    return result;
}

int main(){
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = partitionLabels(s);
    cout << "[";
    for(int i=0; i<result.size(); i++){
        cout << result[i];
        if(i != result.size()-1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}