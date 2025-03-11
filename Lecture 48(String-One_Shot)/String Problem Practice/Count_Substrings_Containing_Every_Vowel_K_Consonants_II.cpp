/*
Count of Substrings Containing Every Vowel and K Consonants II - [Leetcode - 3306(Medium)]
===========================================================================================
You are given a string word and a non-negative integer k.

Return the total number of substrings(A substring is a contiguous non-empty sequence of characters within a string.) of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5
*/ 


#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long long countOfSubstrings(string word, int k) {
    int n = word.size();
    
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> vowelCount; // Count of each vowel in the current substring.
    
    int consonants = 0; // count of consonants in the current substring
    int left = 0; // slide window
    int count = 0; 
    
    long long substr = 0;
    
    /*
    Lambda Function minus
    This lambda function is used to decrement the count of a character in the vowelCount map or decrement the consonant count cons. If the count of a vowel becomes zero, it is removed from the map.
    */ 
    auto minus = [&](char c) {
        if (vowels.count(c)) {
            if (--vowelCount[c] == 0) {
                vowelCount.erase(c);
            }
        } else {
            consonants--;
        }
    };

    // Main loop
    for (char c : word) {
        if (vowels.count(c)) { // If the character is a vowel, its count is incremented in the vowelCount map.
            vowelCount[c]++; 
        } else { // If the character is a consonant, the consonant count cons is incremented, and the count variable is reset to zero.
            consonants++;
            count = 0;
        }

        // Sliding window
        while (consonants > k) { // If the consonant count cons exceeds k, the window is shrunk from the left by calling the minus function until cons is less than or equal to k.
            minus(word[left]);
            left++;
        }
        while (consonants == k and vowelCount.size() == 5) { // If the consonant count cons is equal to k and all vowels are present in the vowelCount map, the window is shrunk from the left, and the count variable is incremented.
            count++;
            minus(word[left]);
            left++;
        }
        substr += count;
    }
    return substr;
}

int main(){
    string word;
    cout<<"Enter a word string: ";
    cin>>word;
    int k;
    cout<<"Enter a value for k: ";
    cin>>k;
    cout<<"Number of substrings with k consonants and 5 vowels: "<<countOfSubstrings(word, k);
}