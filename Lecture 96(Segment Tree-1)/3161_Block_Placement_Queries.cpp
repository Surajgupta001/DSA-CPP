/*
Block Placement Queries - [Leetcode - 3161(Hard)]
----------------------------------------------------
There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

You are given a 2D array queries, which contains two types of queries:

For a query of type 1, queries[node] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
For a query of type 2, queries[node] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
Return a boolean array results, where results[node] is true if you can place the block specified in the ith query of type 2, and false otherwise.

Example 1:

Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

Output: [false,true,true]

Explanation:

For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.

Example 2:

Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

Output: [true,true,false]

Explanation:

Place an obstacle at x = 7 for query 0. A block of size at most 7 can be placed before x = 7.
Place an obstacle at x = 2 for query 2. Now, a block of size at most 5 can be placed before x = 7, and a block of size at most 2 before x = 2.
 
Constraints:

1 <= queries.length <= 15 * 10^4
2 <= queries[node].length <= 3
1 <= queries[node][0] <= 2
1 <= x, sz <= min(5 * 10^4, 3 * queries.length)
The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
The input is generated such that there is at least one query of type 2.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

// Approach : Brute Force
vector<bool> getResults(vector<vector<int>>& queries) {
    vector<bool> result;
    set<int> obstacles;

    for(auto &query : queries){
        // Type 1 query
        if(query[0] == 1){
            obstacles.insert(query[1]);
        } else {
            // Type 2 query
            int x = query[1];
            int size = query[2];

            int prevObstacle = 0;
            bool found = false;

            for(auto &currObstacle : obstacles){
                if(currObstacle > x) break;

                if(currObstacle - prevObstacle >= size){
                    found = true;
                    break;
                }
                prevObstacle = currObstacle;
            }

            if (!found && x - prevObstacle >= size){
                found = true;
            }
            result.push_back(found);
        }
    }
    return result;
}

// Approach : Segment Tree
void updateSegTree(vector<int>& segmentTree, int idx, int value, int node, int l, int r) {
    if (l == r) {
        segmentTree[node] = value;
        return;
    }

    int mid = l + (r - l) / 2;

    // Update the appropriate child node based on the index
    if (idx <= mid) {
        updateSegTree(segmentTree, idx, value, 2 * node + 1, l, mid);
    } else {
        updateSegTree(segmentTree, idx, value, 2 * node + 2, mid + 1, r);
    }

    // Update the current node with the maximum value of its children
    segmentTree[node] = max(segmentTree[2 * node + 1], segmentTree[2 * node + 2]);
}

int querySegTree(vector<int>& segmentTree, int start, int end, int node, int l, int r) {
    if (l > end || r < start) {
        return 0;
    }

    // If the current segment is fully within the query range, return the value of the node
    if (start <= l && r <= end){
        return segmentTree[node];
    }

    int mid = l + (r - l) / 2;

    // Query the left and right child nodes and return the maximum value
    int leftMax = querySegTree(segmentTree, start, end, 2 * node + 1, l, mid);
    int rightMax = querySegTree(segmentTree, start, end, 2 * node + 2, mid + 1, r);

    // Return the maximum of the left and right child nodes
    return max(leftMax, rightMax);
}

vector<bool> getResults(vector<vector<int>>& queries) {
    int n = 5e4; // maximum value of x and sz

    vector<int> segmentTree(4 * n, 0); // segment tree to store maximum gap between obstacles
    
    set<int> obstacles; // to store the positions of obstacles
    obstacles.insert(0); // to handle the case when there are no obstacles before x
    
    vector<bool> result; // to store results of type 2 queries
    
    for (auto& query : queries) {

        // Type 1 query
        if (query[0] == 1) {
            // Place an obstacle at x = query[1]
            int x = query[1];
            auto itr = obstacles.upper_bound(x); // Find the first obstacle greater than x

            // Get the next and previous obstacles
            int nextObstacle = (itr == obstacles.end()) ? -1 : *itr;
            int prevObstacle = *prev(itr);

            // Update the segment tree with the new gaps created by placing the obstacle at x
            updateSegTree(segmentTree, x, x - prevObstacle, 0, 0, n - 1);

            // If there is a next obstacle, update the gap between x and the next obstacle
            if (nextObstacle != -1) {
                updateSegTree(segmentTree, nextObstacle, nextObstacle - x, 0, 0, n - 1);
            }

            // Insert the new obstacle into the set
            obstacles.insert(x);
        }
        else {

            // Type 2 query
            int x = query[1];
            int size = query[2];

            // Find the largest gap between obstacles in the range [0, x]
            auto itr = obstacles.upper_bound(x);

            // Get the previous obstacle
            int prevObstacle = *prev(itr);

            // Query the segment tree for the maximum gap in the range [0, prevObstacle]
            int Value = querySegTree(segmentTree, 0, prevObstacle, 0, 0, n - 1);

            // Calculate the gap between x and the previous obstacle
            int bestGapValue = max(Value, x - prevObstacle);

            // Check if the best gap is greater than or equal to the size of the block
            result.push_back(bestGapValue >= size);
        }
    }
    return result;
}

int main () {
    vector<vector<int>> queries1 = {{1,2},{2,3,3},{2,3,1},{2,2,2}};
    vector<bool> result1 = getResults(queries1);
    for(bool res : result1) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    vector<vector<int>> queries2 = {{1,7},{2,7,6},{1,2},{2,7,5},{2,7,6}};
    vector<bool> result2 = getResults(queries2);
    for(bool res : result2) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}