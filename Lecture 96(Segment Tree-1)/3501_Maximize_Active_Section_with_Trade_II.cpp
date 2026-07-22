/*
Maximize Active Section with Trade II - [Leetcode - 3501(Hard)]
----------------------------------------------------------------------
You are given a binary string s of length n, where:

'1' represents an active section.
'0' represents an inactive section.
You can perform at most one trade to maximize the number of active sections in s. In a trade, you:

Convert a contiguous block of '1's that is surrounded by '0's to all '0's.
Afterward, convert a contiguous block of '0's that is surrounded by '1's to all '1's.
Additionally, you are given a 2D array queries, where queries[i] = [li, ri] represents a substring s[li...ri].

For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[li...ri].

Return an array answer, where answer[i] is the result for queries[i].

Note

For each query, treat s[li...ri] as if it is augmented with a '1' at both ends, forming t = '1' + s[li...ri] + '1'. The augmented '1's do not contribute to the final count.
The queries are independent of each other.


Example 1:

Input: s = "01", queries = [[0,1]]

Output: [1]

Explanation:

Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 2:

Input: s = "0100", queries = [[0,3],[0,2],[1,3],[2,3]]

Output: [4,3,1,1]

Explanation:

Query [0, 3] → Substring "0100" → Augmented to "101001"
Choose "0100", convert "0100" → "0000" → "1111".
The final string without augmentation is "1111". The maximum number of active sections is 4.

Query [0, 2] → Substring "010" → Augmented to "10101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "1110". The maximum number of active sections is 3.

Query [1, 3] → Substring "100" → Augmented to "11001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Query [2, 3] → Substring "00" → Augmented to "1001"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 1.

Example 3:

Input: s = "1000100", queries = [[1,5],[0,6],[0,4]]

Output: [6,7,2]

Explanation:

Query [1, 5] → Substring "00010" → Augmented to "1000101"
Choose "00010", convert "00010" → "00000" → "11111".
The final string without augmentation is "1111110". The maximum number of active sections is 6.

Query [0, 6] → Substring "1000100" → Augmented to "110001001"
Choose "000100", convert "000100" → "000000" → "111111".
The final string without augmentation is "1111111". The maximum number of active sections is 7.

Query [0, 4] → Substring "10001" → Augmented to "1100011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.

Example 4:

Input: s = "01010", queries = [[0,3],[1,4],[1,3]]

Output: [4,4,2]

Explanation:

Query [0, 3] → Substring "0101" → Augmented to "101011"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "11110". The maximum number of active sections is 4.

Query [1, 4] → Substring "1010" → Augmented to "110101"
Choose "010", convert "010" → "000" → "111".
The final string without augmentation is "01111". The maximum number of active sections is 4.

Query [1, 3] → Substring "101" → Augmented to "11011"
Because there is no block of '1's surrounded by '0's, no valid trade is possible. The maximum number of active sections is 2.



Constraints:

1 <= n == s.length <= 10^5
1 <= queries.length <= 10^5
s[i] is either '0' or '1'.
queries[i] = [li, ri]
0 <= li <= ri < n
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class SegmentTree {
public:
    // Build Segment Tree
    void build(int idx, int left, int right, vector<int> &arr, vector<int> &segmentTree) {

        if (left == right) {
            segmentTree[idx] = arr[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(2 * idx + 1, left, mid, arr, segmentTree);
        build(2 * idx + 2, mid + 1, right, arr, segmentTree);

        segmentTree[idx] = max(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);
    }

    // Construct Segment Tree
    void construct(vector<int> &arr, vector<int> &segmentTree) {
        int n = arr.size();
        if (n == 0) return;

        segmentTree.resize(4 * n);
        build(0, 0, n - 1, arr, segmentTree);
    }

    // Query Segment Tree
    int query(int queryLeft, int queryRight, int idx, int left, int right, vector<int> &segmentTree) {

        // No Overlap
        if (right < queryLeft || left > queryRight) return INT_MIN;

        // Complete Overlap
        if (queryLeft <= left && right <= queryRight) return segmentTree[idx];

        // Partial Overlap
        int mid = left + (right - left) / 2;

        int leftAnswer = query(queryLeft, queryRight, 2 * idx + 1, left, mid, segmentTree);

        int rightAnswer = query(queryLeft, queryRight, 2 * idx + 2, mid + 1, right, segmentTree);

        return max(leftAnswer, rightAnswer);
    }

    // Range Maximum Query
    int rangeMaximumQuery(int left, int right, int n, vector<int> &segmentTree) {
        if (n == 0 || left > right) return 0;
        return query(left, right, 0, 0, n - 1, segmentTree);
    }
};

vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries) {
    int n = s.size();
    int activeCount = count(s.begin(), s.end(), '1');

    vector<int> blockStart;
    vector<int> blockEnd;

    int i = 0;

    while (i < n) {
        if (s[i] == '0') {
            int start = i;
            while (i < n && s[i] == '0') {
                i++;
            }
            blockStart.push_back(start);
            blockEnd.push_back(i - 1);
        } else {
            i++;
        }
    }

    int m = blockStart.size();

    // Less than two zero blocks
    if (m < 2) {
        return vector<int>(queries.size(), activeCount);
    }

    vector<int> blockSize(m);

    for (int i = 0; i < m; i++) {
        blockSize[i] = blockEnd[i] - blockStart[i] + 1;
    }

    vector<int> pairSum(m - 1);

    for (int i = 0; i < m - 1; i++) {
        pairSum[i] = blockSize[i] + blockSize[i + 1];
    }

    SegmentTree st;
    vector<int> segmentTree;

    st.construct(pairSum, segmentTree);

    vector<int> result;

    for (auto &query : queries) {
        int l = query[0];
        int r = query[1];

        auto low = lower_bound(blockEnd.begin(), blockEnd.end(), l) - blockEnd.begin();
        auto high = upper_bound(blockStart.begin(), blockStart.end(), r) - blockStart.begin() - 1;

        int maxPairSum = 0;

        if (low < high) {
            int firstLen = blockEnd[low] - max(blockStart[low], l) + 1;
            int lastLen = min(blockEnd[high], r) - blockStart[high] + 1;

            if (high - low == 1) {
                maxPairSum = firstLen + lastLen;
            } else {
                int pair1 = firstLen + blockSize[low + 1];
                int pair2 = blockSize[high - 1] + lastLen;

                int mid = 0;

                if (low + 1 <= high - 2) {
                    mid = st.rangeMaximumQuery(low + 1, high - 2, pairSum.size(), segmentTree);
                }
                maxPairSum = max({pair1, pair2, mid});
            }
        }
        result.push_back(activeCount + maxPairSum);
    }
    return result;
}

int main() {
    string s = "0100";
    vector<vector<int>> queries = {{0,3},{0,2},{1,3},{2,3}};
    vector<int> result = maxActiveSectionsAfterTrade(s, queries);
    for(int res : result) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}