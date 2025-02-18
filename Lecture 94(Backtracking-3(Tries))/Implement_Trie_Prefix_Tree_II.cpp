/*
Implement Trie II (Prefix Tree) - [Leetcode - 1804(Medium)]
===========================================================
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

* Trie() Initializes the trie object.
* void insert(String word) Inserts the string word into the trie.
* int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
* int countWordsStartingWith(String prefix) Returns the number of strings in the trie that have the string prefix as a prefix.
* void erase(String word) Erases the string word from the trie.
 

Example 1:

Input
["Trie", "insert", "insert", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsEqualTo", "countWordsStartingWith", "erase", "countWordsStartingWith"]
[[], ["apple"], ["apple"], ["apple"], ["app"], ["apple"], ["apple"], ["app"], ["apple"], ["app"]]
Output
[null, null, null, 2, 2, null, 1, 1, null, 0]

Explanation
Trie trie = new Trie();
trie.insert("apple");               // Inserts "apple".
trie.insert("apple");               // Inserts another "apple".
trie.countWordsEqualTo("apple");    // There are two instances of "apple" so return 2.
trie.countWordsStartingWith("app"); // "app" is a prefix of "apple" so return 2.
trie.erase("apple");                // Erases one "apple".
trie.countWordsEqualTo("apple");    // Now there is only one instance of "apple" so return 1.
trie.countWordsStartingWith("app"); // return 1
trie.erase("apple");                // Erases "apple". Now the trie is empty.
trie.countWordsStartingWith("app"); // return 0
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, countWordsEqualTo, countWordsStartingWith, and erase.
It is guaranteed that for any function call to erase, the string word will exist in the
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
    int countWordsEndingHere;
    int countWordsStarting;

    // constructor
    Node(char data){
        value = data;
        terminal = false;
        countWordsEndingHere = countWordsStarting = 0;
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node('\0');
    }
    void insert(string word){
        Node* current = root;
        for(int i = 0 ; i < word.size(); i++){
            char ch = word[i];
            if(current -> children.count(ch)){
                current = current -> children[ch];
                current -> countWordsStarting++;
            }
            else{
                Node* child= new Node(ch);
                current -> children[ch] = child;
                current = current -> children[ch];
                current -> countWordsStarting++;
            }
        }
        current -> terminal = true;
        current -> countWordsEndingHere++;
    }
    int countWordsEqualTo(string word){
        Node* current = root;
        for(int i = 0 ; i < word.size(); i++){
            char ch = word[i];
            if(current -> children.count(ch)){
                current = current -> children[ch];
            }
            else{
                return 0;
            }
        }
        return current -> countWordsEndingHere;
    }
    int countWordsStartingWith(string prefix){
        Node* current = root;
        for(int i = 0 ; i < prefix.size(); i++){
            char ch = prefix[i];
            if(current -> children.count(ch)){
                current = current -> children[ch];
            }
            else{
                return 0;
            }
        }
        return current -> countWordsStarting;
    }
    void erase(string word) {
        Node *current = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            current = current->children[ch];
            current->countWordsStarting--;
        }
        current->countWordsEndingHere--;
    }
};

int main(){

    Trie trie;

    cout<<"null"<<endl;
    trie.insert("apple");
    cout<<"null"<<endl;
    trie.insert("apple");
    cout<<"null"<<endl;
    cout<<trie.countWordsEqualTo("apple")<<endl;
    cout<<trie.countWordsStartingWith("app")<<endl;
    trie.erase("apple");
    cout<<"null"<<endl;
    cout<<trie.countWordsEqualTo("apple")<<endl;
    cout<<trie.countWordsStartingWith("app")<<endl;
    trie.erase("apple");
    cout<<"null"<<endl;
    cout<<trie.countWordsStartingWith("app")<<endl;

    return 0;
}