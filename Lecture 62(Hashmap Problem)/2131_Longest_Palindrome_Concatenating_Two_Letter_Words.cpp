/*
Longest Palindrome by Concatenating Two Letter Words - [Leetcode - 2131(Medium)]
---------------------------------------------------------------------------------
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.
*/ 

/*
========== Logic ==========
1. If both letters of a word are different, then find the reverse of that word in the array and use both words to form a palindrome.
2. if both letters of a word are the same, we can use it as a center of palindrome.
3. Use a hash map to count occurrences of each word. Because search time in a hash map is O(1) on average, it will be efficient for large inputs.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> map; // Map to store the count of each word

    int length = 0;

    for(string &word : words){
        string reverseWord = word; // Creating a reverse of the current word
        reverse(reverseWord.begin(), reverseWord.end()); // Reverse the word to find its counterpart

        if(map[reverseWord] > 0) {
            // If the reverse of the word exists, we can form a palindrome
            length += 4; // Each pair contributes 4 to the length
            map[reverseWord]--; // Decrease the count of the reverse word
        }
        else {
            // Otherwise, we store the word in the map
            map[word]++;
        }
    }

    // Check for words with the same letters (like "aa", "bb", etc.)
    for(auto &entry : map){
        string word = entry.first;
        int count = entry.second;

        // If the word has both letters the same, we can use it as a center of palindrome
        if(word[0] == word[1] and count > 0){ // Check if both letters are the same and we have at least one such word
            length += 2; // Each such word contributes 2 to the length
            break; // We can only use one such word as the center
        }
    }

    return length;
}

int main(){
    vector<string> words = {"lc", "cl", "gg"};
    cout << "Length of the longest palindrome: " << longestPalindrome(words) << endl; // Output: 6

    words = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << "Length of the longest palindrome: " << longestPalindrome(words) << endl; // Output: 8

    words = {"cc", "ll", "xx"};
    cout << "Length of the longest palindrome: " << longestPalindrome(words) << endl; // Output: 2

    return 0;
}