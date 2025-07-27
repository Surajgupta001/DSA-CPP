/*
Maximize Subarrays After Removing One Conflicting Pair - [LeetCode - Hard(3480)]
---------------------------------------------------------------------------------
You are given an integer n which represents an array nums containing the numbers from 1 to n in order. Additionally, you are given a 2D array conflictingPairs, where conflictingPairs[i] = [a, b] indicates that a and b form a conflicting pair.

Remove exactly one element from conflictingPairs. Afterward, count the number of non-empty subarrays of nums which do not contain both a and b for any remaining conflicting pair [a, b].

Return the maximum number of subarrays possible after removing exactly one conflicting pair.

 

Example 1:

Input: n = 4, conflictingPairs = [[2,3],[1,4]]

Output: 9

Explanation:

Remove [2, 3] from conflictingPairs. Now, conflictingPairs = [[1, 4]].
There are 9 subarrays in nums where [1, 4] do not appear together. They are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3] and [2, 3, 4].
The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 9.
Example 2:

Input: n = 5, conflictingPairs = [[1,2],[2,5],[3,5]]

Output: 12

Explanation:

Remove [1, 2] from conflictingPairs. Now, conflictingPairs = [[2, 5], [3, 5]].
There are 12 subarrays in nums where [2, 5] and [3, 5] do not appear together.
The maximum number of subarrays we can achieve after removing one element from conflictingPairs is 12.
 

Constraints:

2 <= n <= 105
1 <= conflictingPairs.length <= 2 * n
conflictingPairs[i].length == 2
1 <= conflictingPairs[i][j] <= n
conflictingPairs[i][0] != conflictingPairs[i][1]
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// // Approach: 1 - Brute Force
// long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs){
//     long long valid = 0;

//     vector<vector<int>> conflictingPoints(n + 1);
//     // conflictingPairs[i] = {points with conflict with i}

//     for(auto &pair : conflictingPairs){
//         // (a, b) is a conflicting pair
//         int a = min(pair[0], pair[1]);
//         int b = max(pair[0], pair[1]);

//         conflictingPoints[b].push_back(a); // b conflicts with a
//     }

//     int maxConflict = 0;
//     int secondMaxConflict = 0;

//     vector<long long> extra(n + 1, 0);
//     // extra[i] = number of extra subarrays by removing conflicting point i
//     for(int end = 1; end <= n; end++){ // visiting each point and treating theme as subarray ending at this point
//         // Total subarrays ending at this point 'end'
//         for(auto &conflictPoint : conflictingPoints[end]){ // check all conflicting points with 'end'
//             // If conflictPoint is greater than maxConflict, it means we can remove it
//             if(conflictPoint >= maxConflict){
//                 secondMaxConflict = maxConflict; // Update second max conflict
//                 maxConflict = conflictPoint; // Update max conflict
//             }
//             else if(conflictPoint > secondMaxConflict){ // If conflictPoint is less than maxConflict but greater than secondMaxConflict
//                 secondMaxConflict = conflictPoint; // Update second max conflict
//             }
//         }

//         // Calculate the number of valid subarrays ending at 'end'
//         valid += end - maxConflict; // All subarrays ending at 'end' minus those that conflict with maxConflict
//         extra[maxConflict] += maxConflict - secondMaxConflict; // Count extra subarrays that can be formed by removing maxConflict
//     }

//     return valid + *max_element(extra.begin(), extra.end()); // Return the total valid subarrays plus the maximum extra subarrays that can be formed by removing one conflicting point
// }

// Approach: 2 - Segment Tree
class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return max(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }
    
public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }
    
    void update(int idx, int val) {
        update(1, 1, n, idx, val);
    }
    
    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 1, n, l, r);
    }
};

long long maxSubarraysSegTree(int n, vector<vector<int>>& conflictingPairs) {
    // Build adjacency list for conflicts
    vector<vector<int>> conflicts(n + 1);
    for (auto& pair : conflictingPairs) {
        int a = min(pair[0], pair[1]);
        int b = max(pair[0], pair[1]);
        conflicts[b].push_back(a);
    }
    
    // Segment tree to maintain maximum conflicting point in ranges
    SegmentTree segTree(n);
    
    long long totalValid = 0;
    vector<long long> benefit(n + 1, 0);
    
    for (int end = 1; end <= n; end++) {
        // Update segment tree with new conflicts ending at 'end'
        for (int conflictPoint : conflicts[end]) {
            segTree.update(conflictPoint, conflictPoint);
        }
        
        // Query the maximum conflicting point in range [1, end]
        int maxConflict = segTree.query(1, end);
        
        // Calculate valid subarrays ending at 'end'
        long long validEndingHere = end - maxConflict;
        totalValid += validEndingHere;
        
        // For each conflicting point, calculate benefit of removing it
        for (int conflictPoint : conflicts[end]) {
            // If we remove this conflict, what would be the new max conflict?
            int newMaxConflict = 0;
            
            // Check conflicts before this point
            if (conflictPoint > 1) {
                newMaxConflict = max(newMaxConflict, segTree.query(1, conflictPoint - 1));
            }
            // Check conflicts after this point
            if (conflictPoint < end) {
                newMaxConflict = max(newMaxConflict, segTree.query(conflictPoint + 1, end));
            }
            
            // Calculate additional subarrays we get by removing this conflict
            long long additionalSubarrays = conflictPoint - newMaxConflict;
            benefit[conflictPoint] += additionalSubarrays;
        }
    }
    
    // Find maximum benefit from removing any conflicting pair
    long long maxBenefit = 0;
    for (auto& pair : conflictingPairs) {
        // Calculate benefit of removing this entire pair
        long long pairBenefit = 0;
        
        // Recalculate without this pair
        SegmentTree tempSegTree(n);
        long long tempValid = 0;
        
        for (int end = 1; end <= n; end++) {
            for (int conflictPoint : conflicts[end]) {
                // Skip the pair we're considering removing
                bool skipThis = false;
                if ((pair[0] == conflictPoint && pair[1] == end) ||
                    (pair[1] == conflictPoint && pair[0] == end)) {
                    skipThis = true;
                }
                
                if (!skipThis) {
                    tempSegTree.update(conflictPoint, conflictPoint);
                }
            }
            
            int maxConflict = tempSegTree.query(1, end);
            tempValid += end - maxConflict;
        }
        
        pairBenefit = tempValid - totalValid;
        maxBenefit = max(maxBenefit, pairBenefit);
    }
    
    return totalValid + maxBenefit;
}

// Alternative more efficient approach using segment tree for range maximum queries
long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    vector<vector<int>> conflicts(n + 1);
    for (auto& pair : conflictingPairs) {
        int a = min(pair[0], pair[1]);
        int b = max(pair[0], pair[1]);
        conflicts[b].push_back(a);
    }
    
    long long totalValid = 0;
    vector<long long> removalBenefit(conflictingPairs.size(), 0);
    
    // For each possible removal, calculate the benefit
    for (int removeIdx = 0; removeIdx < conflictingPairs.size(); removeIdx++) {
        SegmentTree segTree(n);
        long long validCount = 0;
        
        for (int end = 1; end <= n; end++) {
            for (int conflictPoint : conflicts[end]) {
                // Skip the pair we're removing
                bool skip = false;
                auto& removePair = conflictingPairs[removeIdx];
                if ((min(removePair[0], removePair[1]) == conflictPoint && 
                     max(removePair[0], removePair[1]) == end)) {
                    skip = true;
                }
                
                if (!skip) {
                    segTree.update(conflictPoint, conflictPoint);
                }
            }
            
            int maxConflict = segTree.query(1, end);
            validCount += end - maxConflict;
        }
        
        removalBenefit[removeIdx] = validCount;
    }
    
    return *max_element(removalBenefit.begin(), removalBenefit.end());
}

int main() {
    int n = 4;
    vector<vector<int>> conflictingPairs = {{2, 3}, {1, 4}};
    
    long long result = maxSubarrays(n, conflictingPairs);
    cout << "Maximum number of subarrays after removing one conflicting pair: " << result << endl;
    
    // Test with second example
    n = 5;
    conflictingPairs = {{1, 2}, {2, 5}, {3, 5}};
    result = maxSubarrays(n, conflictingPairs);
    cout << "Maximum number of subarrays for second example: " << result << endl;
    
    return 0;
}