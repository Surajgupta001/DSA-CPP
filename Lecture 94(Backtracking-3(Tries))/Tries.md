# Tries (Prefix Trees)

## What is a Trie?

A **Trie** (pronounced "try") is a tree-like data structure that is used to store a dynamic set of strings. It's also known as a **Prefix Tree** because it stores strings in a way that allows for efficient prefix-based operations.

### Key Characteristics

- Each node represents a single character
- The root node is empty (represents an empty string)
- Each path from root to a leaf represents a complete word
- All descendants of a node share a common prefix

## Structure of a Trie

Example Trie for words: "cat", "car", "card", "care", "careful"

```plaintext
Example Trie for words: "cat", "car", "card", "care", "careful"

        root
         |
         c
         |
         a
         |
         t(end)
        / \
       r   (end for "cat")
       |
      (end for "car")
      /|\
     d e f
     | | |
   (end) (end) u
   "card" "care" |
                 l
                 |
               (end)
              "careful"
```

## Why Use Tries?

### Advantages

1. **Fast Prefix Search**: O(m) time complexity where m is the length of the prefix
2. **Memory Efficient**: Common prefixes are stored only once
3. **Autocomplete**: Perfect for implementing search suggestions
4. **Dictionary Operations**: Efficient insert, search, and delete operations
5. **Lexicographic Ordering**: Can traverse in alphabetical order

### Time Complexities

- **Insert**: O(m) where m is the length of the word
- **Search**: O(m) where m is the length of the word
- **Delete**: O(m) where m is the length of the word
- **Prefix Search**: O(p) where p is the length of the prefix

## Where to Use Tries?

### 1. **Autocomplete Systems**

- Search engines (Google search suggestions)
- IDE code completion
- Mobile keyboard predictions
- Command line auto-completion

### 2. **Spell Checkers**

- Word processors (MS Word, Google Docs)
- Web browsers
- Text editors
- Mobile keyboards

### 3. **IP Routing Tables**

- Network routers use tries to store routing information
- Longest prefix matching for IP addresses

### 4. **Dictionary Applications**

- Online dictionaries
- Language learning apps
- Crossword puzzle solvers
- Anagram generators

### 5. **Contact Lists**

- Phone contact search
- Email address lookup
- Social media friend search

### 6. **File System Operations**

- Directory path lookups
- File name suggestions
- Path autocompletion in terminals

### 7. **Bioinformatics**

- DNA sequence analysis
- Protein sequence matching
- Genome assembly

### 8. **Game Development**

- Word games (Scrabble, Word Search)
- Text-based adventure games
- Chat filter systems

## Real-World Examples

### 1. **Google Search**

When you type in Google's search box, it uses trie-like structures to provide instant search suggestions based on popular queries.

### 2. **IDE Code Completion**

Modern IDEs like VS Code use tries to store function names, variable names, and keywords for quick autocompletion.

### 3. **Phone Contacts**

Your smartphone's contact app uses tries to quickly find contacts as you type their names.

### 4. **DNS Resolution**

Domain Name System (DNS) servers use trie-like structures to resolve domain names to IP addresses.

## When NOT to Use Tries?

### Disadvantages

1. **Memory Overhead**: Can consume more memory than hash tables for small datasets
2. **Cache Performance**: Poor cache locality due to scattered memory access
3. **Simple Exact Matching**: Hash tables are better for exact string matching
4. **Numerical Data**: Not suitable for numerical key storage

### Better Alternatives

- **Hash Tables**: For exact string matching
- **Suffix Arrays**: For substring search problems
- **B-Trees**: For disk-based storage
- **Bloom Filters**: For membership testing with space constraints

## Implementation Considerations

### Node Structure Options

1. **Array-based**: Fixed size array for each character (fast but memory-intensive)
2. **HashMap-based**: Dynamic mapping (memory-efficient but slightly slower)
3. **Compressed Tries**: Store common suffixes together (memory-optimized)

### Example Use Cases by Industry

- **E-commerce**: Product search and filtering
- **Social Media**: Hashtag suggestions, username search
- **Gaming**: Player name lookup, chat commands
- **Banking**: Account number validation, branch code lookup
- **Healthcare**: Medical term lookup, drug name search

## Standard Trie Template Code

### Basic Trie Implementation (Array-based)

```cpp
class Trie {
private:
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];  // For lowercase a-z
        
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the trie
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }
    
    // Search for a word in the trie
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }
    
    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
    
    // Delete a word from trie
    bool deleteWord(string word) {
        return deleteHelper(root, word, 0);
    }
    
private:
    bool deleteHelper(TrieNode* node, string& word, int index) {
        if (index == word.length()) {
            if (!node->isEndOfWord) return false;
            node->isEndOfWord = false;
            return !hasChildren(node);
        }
        
        int charIndex = word[index] - 'a';
        TrieNode* child = node->children[charIndex];
        if (child == nullptr) return false;
        
        bool shouldDeleteChild = deleteHelper(child, word, index + 1);
        
        if (shouldDeleteChild) {
            delete child;
            node->children[charIndex] = nullptr;
            return !node->isEndOfWord && !hasChildren(node);
        }
        
        return false;
    }
    
    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                return true;
            }
        }
        return false;
    }
};
```

### Advanced Trie Implementation (HashMap-based)

```cpp
class AdvancedTrie {
private:
    struct TrieNode {
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;
        int count;  // Number of words passing through this node
        
        TrieNode() : isEndOfWord(false), count(0) {}
    };
    
    TrieNode* root;
    
public:
    AdvancedTrie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->count++;
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
    
    // Count words with given prefix
    int countWordsWithPrefix(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return 0;
            }
            curr = curr->children[c];
        }
        return curr->count;
    }
    
    // Get all words with given prefix
    vector<string> getWordsWithPrefix(string prefix) {
        vector<string> result;
        TrieNode* curr = root;
        
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return result;
            }
            curr = curr->children[c];
        }
        
        dfs(curr, prefix, result);
        return result;
    }
    
private:
    void dfs(TrieNode* node, string currentWord, vector<string>& result) {
        if (node->isEndOfWord) {
            result.push_back(currentWord);
        }
        
        for (auto& pair : node->children) {
            dfs(pair.second, currentWord + pair.first, result);
        }
    }
};
```

### Binary Trie (For XOR Operations)

```cpp
class BinaryTrie {
private:
    struct TrieNode {
        TrieNode* children[2];
        
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    BinaryTrie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->children[bit] == nullptr) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* curr = root;
        int maxXor = 0;
        
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            if (curr->children[oppositeBit] != nullptr) {
                maxXor |= (1 << i);
                curr = curr->children[oppositeBit];
            } else {
                curr = curr->children[bit];
            }
        }
        return maxXor;
    }
    
    bool search(int num) {
        TrieNode* curr = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->children[bit] == nullptr) {
                return false;
            }
            curr = curr->children[bit];
        }
        return true;
    }
};
```

### Usage Examples

```cpp
int main() {
    // Basic Trie Usage
    Trie trie;
    
    // Insert words
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    
    // Search operations
    cout << trie.search("app") << endl;        // true
    cout << trie.search("apple") << endl;      // true
    cout << trie.search("appl") << endl;       // false
    cout << trie.startsWith("app") << endl;    // true
    
    // Advanced Trie Usage
    AdvancedTrie advTrie;
    advTrie.insert("cat");
    advTrie.insert("car");
    advTrie.insert("card");
    
    cout << advTrie.countWordsWithPrefix("ca") << endl;  // 3
    
    vector<string> words = advTrie.getWordsWithPrefix("car");
    for (string word : words) {
        cout << word << " ";  // car card
    }
    
    // Binary Trie Usage (XOR problems)
    BinaryTrie binTrie;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    
    for (int num : nums) {
        binTrie.insert(num);
    }
    
    int maxXor = 0;
    for (int num : nums) {
        maxXor = max(maxXor, binTrie.findMaxXOR(num));
    }
    cout << "Maximum XOR: " << maxXor << endl;
    
    return 0;
}
```

### Template Variations

#### 1. Trie with Frequency Count

```cpp
struct TrieNode {
    bool isEndOfWord;
    int frequency;  // How many times this word appears
    TrieNode* children[26];
    
    TrieNode() : isEndOfWord(false), frequency(0) {
        fill(children, children + 26, nullptr);
    }
};
```

#### 2. Trie for Any Character Set

```cpp
struct TrieNode {
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;  // Supports any character
    
    TrieNode() : isEndOfWord(false) {}
};
```

#### 3. Compressed Trie (Patricia Tree)

```cpp
struct CompressedTrieNode {
    string edgeLabel;  // Store string instead of single character
    bool isEndOfWord;
    vector<CompressedTrieNode*> children;
    
    CompressedTrieNode(string label = "") : edgeLabel(label), isEndOfWord(false) {}
};
```

## Common Question Patterns & Problems

### Pattern 1: Basic Trie Operations

**Common Questions:**

- Implement Trie (Insert, Search, StartsWith)
- Design Add and Search Words Data Structure
- Word Break Problem

**Example Problem:**

```cpp
// LeetCode 208: Implement Trie (Prefix Tree)
class Trie {
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        TrieNode() : isEnd(false) {
            fill(children, children + 26, nullptr);
        }
    };
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
```

### Pattern 2: Word Search & Pattern Matching

**Common Questions:**

- Word Search II (Board + Dictionary)
- Add and Search Words (with '.' wildcard)
- Stream of Characters

**Key Approach:**

- Build trie from dictionary words
- Use DFS/Backtracking on board/input
- Prune search space using trie structure

**Example Problem Pattern:**

```cpp
// Word Search II approach
class Solution {
    struct TrieNode {
        string word;
        TrieNode* children[26];
        TrieNode() : word("") {
            fill(children, children + 26, nullptr);
        }
    };
    
    void buildTrie(vector<string>& words, TrieNode* root) {
        for (string& word : words) {
            TrieNode* curr = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->word = word;
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, 
             TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // Avoid duplicates
        }
        
        board[i][j] = '#'; // Mark visited
        // Check all 4 directions
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < board.size() && 
                nj >= 0 && nj < board[0].size()) {
                dfs(board, ni, nj, node, result);
            }
        }
        board[i][j] = c; // Restore
    }
};
```

### Pattern 3: Prefix Sum & Counting

**Common Questions:**

- Count Words with Given Prefix
- Sum of Prefix Scores of Strings
- Maximum XOR of Two Numbers

**Key Approach:**

- Store additional information in trie nodes (count, sum, etc.)
- Use trie for efficient prefix operations

### Pattern 4: Autocomplete & Suggestions

**Common Questions:**

- Search Suggestions System
- Auto-complete System
- Top K Frequent Words with Prefix

**Example Implementation:**

```cpp
class AutocompleteSystem {
    struct TrieNode {
        map<char, TrieNode*> children;
        map<string, int> sentences; // sentence -> frequency
    };
    
    TrieNode* root;
    string currentInput;
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        currentInput = "";
        
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    void insert(string& sentence, int freq) {
        TrieNode* curr = root;
        for (char c : sentence) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->sentences[sentence] += freq;
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(currentInput, 1);
            currentInput = "";
            return {};
        }
        
        currentInput += c;
        TrieNode* curr = root;
        
        for (char ch : currentInput) {
            if (curr->children.find(ch) == curr->children.end()) {
                return {};
            }
            curr = curr->children[ch];
        }
        
        // Get top 3 suggestions
        vector<pair<int, string>> candidates;
        for (auto& p : curr->sentences) {
            candidates.push_back({p.second, p.first});
        }
        
        sort(candidates.rbegin(), candidates.rend());
        
        vector<string> result;
        for (int i = 0; i < min(3, (int)candidates.size()); i++) {
            result.push_back(candidates[i].second);
        }
        return result;
    }
};
```

### Pattern 5: Bit Manipulation with Tries

**Common Questions:**

- Maximum XOR of Two Numbers in Array
- Maximum XOR Subarray
- Queries on XOR

**Key Approach:**

- Build trie with binary representation
- For each number, try to find maximum XOR by going opposite direction

**Example:**

```cpp
class Solution {
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = children[1] = nullptr;
        }
    };
    
    TrieNode* root;
    
    void insert(int num) {
        TrieNode* curr = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }
    
    int findMaxXOR(int num) {
        TrieNode* curr = root;
        int maxXor = 0;
        
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            if (curr->children[oppositeBit]) {
                maxXor |= (1 << i);
                curr = curr->children[oppositeBit];
            } else {
                curr = curr->children[bit];
            }
        }
        return maxXor;
    }
};
```

### Pattern 6: String Matching & Replacement

**Common Questions:**

- Replace Words (Root Dictionary)
- Concatenated Words
- Word Squares

### Practice Problems by Difficulty

**Easy:**

1. Implement Trie (LeetCode 208)
2. Longest Word in Dictionary (LeetCode 720)

**Medium:**

1. Add and Search Word (LeetCode 211)
2. Word Search II (LeetCode 212)
3. Replace Words (LeetCode 648)
4. Top K Frequent Words (LeetCode 692)
5. Search Suggestions System (LeetCode 1268)

**Hard:**

1. Word Squares (LeetCode 425)
2. Stream of Characters (LeetCode 1032)
3. Concatenated Words (LeetCode 472)
4. Maximum XOR of Two Numbers (LeetCode 421)

### Key Problem-Solving Tips

1. **Identify Trie Usage:**
   - Multiple string operations with common prefixes
   - Need for prefix-based searching
   - Autocomplete/suggestion features
   - Bit manipulation with binary representation

2. **Common Optimizations:**
   - Store word directly in end nodes to avoid reconstruction
   - Use arrays vs maps based on character set size
   - Implement iterative vs recursive approaches
   - Consider memory cleanup for dynamic tries

3. **Edge Cases to Consider:**
   - Empty strings
   - Single character strings
   - Duplicate words
   - Case sensitivity
   - Non-alphabetic characters

## Conclusion

Tries are powerful data structures that excel in scenarios involving:

- Prefix-based operations
- String storage and retrieval
- Autocomplete functionality
- Dictionary-like operations

Choose tries when you need efficient prefix matching and can afford the memory overhead. For simple exact matching, consider hash tables instead.
