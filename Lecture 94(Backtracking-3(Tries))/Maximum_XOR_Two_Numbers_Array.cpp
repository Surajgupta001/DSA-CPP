/*
Maximum XOR of Two Numbers in an Array - [Leetcode - 420(Medium)]
===========================================================
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.


Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    Node* left;  // Represents 0
    Node* right; // Represents 1

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class Trie {
public:
    // Insert a number into the Trie
    void insert(Node* head, int value) {
        Node* current = head;
        for (int i = 31; i >= 0; i--) {
            int bit = (value >> i) & 1;
            if (bit == 0) {
                if (current->left == nullptr) {
                    current->left = new Node();
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new Node();
                }
                current = current->right;
            }
        }
    }

    // Find the maximum XOR for a given number with the numbers in the Trie
    int maxXorPair(Node* head, int value) {
        Node* current = head;
        int curr_XOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (value >> i) & 1;
            if (bit == 0) {
                // Try to go to the right (1) to maximize XOR
                if (current->right != nullptr) {
                    curr_XOR += (1 << i);
                    current = current->right;
                } else {
                    current = current->left;
                }
            } else {
                // Try to go to the left (0) to maximize XOR
                if (current->left != nullptr) {
                    curr_XOR += (1 << i);
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
        }
        return curr_XOR;
    }

    // Find the maximum XOR of any two numbers in the array
    int findMaximumXOR(vector<int>& nums) {
        Node* head = new Node();
        int ans = INT_MIN;

        // Insert all numbers into the Trie
        for (int num : nums) {
            insert(head, num);
        }

        // Calculate the maximum XOR for each number with the numbers in the Trie
        for (int num : nums) {
            ans = max(ans, maxXorPair(head, num));
        }

        return ans;
    }
};

int main() {
    Trie trie;

    vector<int> nums = {3, 10, 5, 25, 2, 8};

    cout << "Maximum XOR of two numbers in the array is: " << trie.findMaximumXOR(nums) << endl;

    return 0;
}