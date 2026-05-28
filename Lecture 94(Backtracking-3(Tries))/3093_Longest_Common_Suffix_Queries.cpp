/*
Longest Common Suffix Queries - [Leetcode - 3093(Hard)]
-------------------------------------------------------------
You are given two arrays of strings wordsContainer and wordsQuery.

For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].

Example 1:

Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

Output: [1,1,1]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.

Example 2:

Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

Output: [2,0,2]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "gh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
For wordsQuery[1] = "acbfgh", only the string at index 0 shares the longest common suffix "fgh". Hence it is the answer, even though the string at index 2 is shorter.
For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
 

Constraints:

1 <= wordsContainer.length, wordsQuery.length <= 10^4
1 <= wordsContainer[i].length <= 5 * 10^3
1 <= wordsQuery[i].length <= 5 * 103
wordsContainer[i] consists only of lowercase English letters.
wordsQuery[i] consists only of lowercase English letters.
Sum of wordsContainer[i].length is at most 5 * 10^5.
Sum of wordsQuery[i].length is at most 5 * 10^5.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class trieNode {
public:

    int index;
    trieNode* children[26];
    ~trieNode() {
        for (int i = 0; i < 26; i++) {
            delete children[i];
        }
    }
};

trieNode* getNode(int i) {
    trieNode* temp = new trieNode();
    temp->index = i;
    
    for(int i = 0; i<26; i++) {
        temp->children[i] = NULL;
    }
    
    return temp;
}

void insertTrie(trieNode* pCrawl, int i, vector<string>& wordsContainer) {
    string word = wordsContainer[i];
    int n = word.size();
    
    for(int j = n-1; j >= 0; j--) {
        int ch_idx = word[j] - 'a';
        
        if(pCrawl->children[ch_idx] == NULL) {
            pCrawl->children[ch_idx] = getNode(i);
        }
        
        pCrawl = pCrawl->children[ch_idx];
        
        if(wordsContainer[pCrawl->index].size() > n) {
            pCrawl->index = i;
        }
    }
}
int search(trieNode* pCrawl, string &word) {
    int result_idx = pCrawl->index;
    int n = word.size();
    
    for(int i = n-1; i >= 0; i--) {
        int ch_idx = word[i]-'a';
        
        pCrawl = pCrawl->children[ch_idx];
        
        if(pCrawl == NULL) {
            return result_idx;
        }
        
        result_idx = pCrawl->index;
    }
    
    return result_idx;
}

vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    int m = wordsContainer.size();
    int n = wordsQuery.size();
    
    vector<int> result(n);
    trieNode* root = getNode(0);
    
    for(int i = 0 ; i < m; i++) {
        if(wordsContainer[root->index].size() > wordsContainer[i].size()) {
            root->index = i;
        }
        insertTrie(root, i, wordsContainer);
    }
    
    for(int i = 0; i < n; i++) {
        result[i] = search(root, wordsQuery[i]);
    }
    
    delete root;   // invokes destructor
    
    return result;
}

int main() {
    vector<string> wordsContainer = {"abcd","bcd","xbcd"};
    vector<string> wordsQuery = {"cd","bcd","xyz"};
    vector<int> result = stringIndices(wordsContainer, wordsQuery);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}