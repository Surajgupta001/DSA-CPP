/*
Maximize the Number of Partitions After Operations - [Leetcode - 3003(Hard)]
-------------------------------------------------------------------------------
You are given a string s and an integer k.

First, you are allowed to change at most one index in s to another lowercase English letter.

After that, do the following partitioning operation until s is empty:

Choose the longest prefix of s containing at most k distinct characters.
Delete the prefix from s and increase the number of partitions by one. The remaining characters (if any) in s maintain their initial order.
Return an integer denoting the maximum number of resulting partitions after the operations by optimally choosing at most one index to change.

 

Example 1:

Input: s = "accca", k = 2

Output: 3

Explanation:

The optimal way is to change s[2] to something other than a and c, for example, b. then it becomes "acbca".

Then we perform the operations:

The longest prefix containing at most 2 distinct characters is "ac", we remove it and s becomes "bca".
Now The longest prefix containing at most 2 distinct characters is "bc", so we remove it and s becomes "a".
Finally, we remove "a" and s becomes empty, so the procedure ends.
Doing the operations, the string is divided into 3 partitions, so the answer is 3.

Example 2:

Input: s = "aabaab", k = 3

Output: 1

Explanation:

Initially s contains 2 distinct characters, so whichever character we change, it will contain at most 3 distinct characters, so the longest prefix with at most 3 distinct characters would always be all of it, therefore the answer is 1.

Example 3:

Input: s = "xxyz", k = 1

Output: 4

Explanation:

The optimal way is to change s[0] or s[1] to something other than characters in s, for example, to change s[0] to w.

Then s becomes "wxyz", which consists of 4 distinct characters, so as k is 1, it will divide into 4 partitions.

 

Constraints:

1 <= s.length <= 104
s consists only of lowercase English letters.
1 <= k <= 26
*/ 

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

#define ll long long

int helper(ll idx, ll uniqueChars, bool canChanged, string &s, int k, unordered_map<ll, int> &dp) {
    // create a unique key for the current state by combining the index, unique characters bitmask, and canChanged flag into a single long long integer.
    ll key = (idx << 27) | (uniqueChars << 1) | canChanged; 

    // check if the result for the current state is already computed
    if(dp.count(key)) return dp[key];

    // base case: if we have processed the entire string, return 0 as there are no more partitions to be made.
    if(idx >= s.size()) return 0;
    
    // get the index of the current character in the alphabet (0 for 'a', 1 for 'b', ..., 25 for 'z')
    int charIndex = s[idx] - 'a';
    
    // update the unique characters bitmask by setting the bit corresponding to the current character to 1 (using bitwise OR)
    int newUniqueChars = uniqueChars | (1LL << charIndex);

    // count the number of unique characters by counting the number of set bits in the bitmask (using the built-in function __builtin_popcountll)
    int uniqueCharCount = __builtin_popcountll(newUniqueChars);

    int result;

    if(uniqueCharCount > k){
        // if the number of unique characters exceeds k, we need to start a new partition. We increment the partition count by 1 and reset the unique characters bitmask to only include the current character.
        result = 1 + helper(idx+1, (1LL << charIndex), canChanged, s, k, dp);
    } else {
        // if the number of unique characters does not exceed k, we continue with the current partition.
        result = helper(idx+1, newUniqueChars, canChanged, s, k, dp);
    }

    if(canChanged){
        for(int newCharIndex=0; newCharIndex<26; newCharIndex++){
            // create a new bitmask for unique characters by setting the bit corresponding to the new character index to 1 (using bitwise OR)
            int newCharSet = uniqueChars | (1LL << newCharIndex);
            
            // count the number of unique characters in the new bitmask (using the built-in function __builtin_popcountll)
            int newUniqueCharCount = __builtin_popcountll(newCharSet);

            if(newUniqueCharCount > k){
                // if the number of unique characters in the new bitmask exceeds k, we need to start a new partition. We increment the partition count by 1 and reset the unique characters bitmask to only include the new character.
                result = max(result, 1 + helper(idx+1, (1LL << newCharIndex), false, s, k, dp));
            } else {
                // if the number of unique characters in the new bitmask does not exceed k, we continue with the current partition.
                result = max(result, helper(idx+1, newCharSet, false, s, k, dp));
            }
        }
    }

    return dp[key] = result; // store the computed result in the dp map before returning it
}

int maxPartitionsAfterOperations(string s, int k) {
    unordered_map<ll, int> dp;
    // we add 1 to the result to account for the last partition that will be made when the string is fully processed.
    return helper(0, 0, true, s, k, dp) + 1;
}

int main() {
    string s = "accca";
    int k = 2;
    cout << maxPartitionsAfterOperations(s, k) << endl; // Output: 3
    return 0;
}