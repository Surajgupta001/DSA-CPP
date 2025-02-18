/*
Implement Trie (Prefix Tree) - [Leetcode - 208(Medium)]
===========================================================
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

* Trie() Initializes the trie object.
* void insert(String word) Inserts the string word into the trie.
* boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
* boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/ 

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
    

class Node{
    public:
    char value;
    bool terminal;
    unordered_map<char, Node*> children;
    // Constructor
    Node(char data){
        value = data;
        terminal = false;
    }
    void makeTerminal(){
        terminal = true;
    }
    bool isTerminal(){
        return terminal == true;
    }
};

class Trie {
public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }
    void insert(string word){
        Node* current = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i]; // current char to be checked
            if(current -> children.count(ch)){
                current = current -> children[ch];
            }
            else{
                Node* child = new Node(ch);
                current -> children[ch] = child;
                current = child;
            }
        }
        current -> makeTerminal();
    }
    bool search(string word){
        Node* current = root;
        for(int i = 0; i < word.length(); i++){
            char ch = word[i]; // current char to be checked
            if(current -> children.count(ch)){
                current = current -> children[ch];
            }
            else{
                // we don't have a character
                return false;
            }
        }
        return current -> isTerminal();
    }
    bool startsWith(string prefix){
        Node* current = root;
        for(int i = 0; i < prefix.size(); i++){
            char ch = prefix[i]; // current char to be checked
            if(current -> children.count(ch)){
                current = current -> children[ch];
            }
            else{
                // we don't have a character
                return false;
            }
        }
        return true;
    }
};

int main(){
    
    Trie trie;
    cout<<"Trie: null"<<endl;
    trie.insert("apple");
    cout<<"Insert 'apple': null"<<endl;
    cout<<"Search 'apple': "<<(trie.search("apple") ? "true" : "false")<<endl;
    cout<<"Search 'app': "<<(trie.search("app") ? "true" : "false")<<endl;
    cout<<"StartsWith 'app': "<<(trie.startsWith("app") ? "true" : "false")<<endl;
    trie.insert("app");
    cout<<"Insert 'app': null"<<endl;
    cout<<"Search 'app': "<<(trie.search("app") ? "true" : "false")<<endl;

    return 0;
}