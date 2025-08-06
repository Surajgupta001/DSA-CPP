/*
Fruits Into Baskets III - [Leetcode - 3479(Medium)]
----------------------------------------------------
You are given two arrays of integers, fruits and baskets, each of length n, where fruits[node] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.

From left to right, place the fruits according to these rules:

Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
Each basket can hold only one type of fruit.
If a fruit type cannot be placed in any basket, it remains unplaced.
Return the number of fruit types that remain unplaced after all possible allocations are made.



Example 1:

Input: fruits = [4,2,5], baskets = [3,5,4]

Output: 1

Explanation:

fruits[0] = 4 is placed in baskets[1] = 5.
fruits[1] = 2 is placed in baskets[0] = 3.
fruits[2] = 5 cannot be placed in baskets[2] = 4.
Since one fruit type remains unplaced, we return 1.

Example 2:

Input: fruits = [3,6,1], baskets = [6,4,7]

Output: 0

Explanation:

fruits[0] = 3 is placed in baskets[0] = 6.
fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
fruits[2] = 1 is placed in baskets[1] = 4.
Since all fruits are successfully placed, we return 0.



Constraints:

n == fruits.length == baskets.length
1 <= n <= 105
1 <= fruits[i], baskets[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void buildTree(int node, int start, int end, vector<int> &baskets, vector<int> &segmentTree){
    if (start == end){
        segmentTree[node] = baskets[start];
        return;
    }
    int mid = (start + end) / 2;

    buildTree(2 * node + 1, start, mid, baskets, segmentTree);
    buildTree(2 * node + 2, mid + 1, end, baskets, segmentTree);

    segmentTree[node] = max(segmentTree[2 * node + 1], segmentTree[2 * node + 2]);
}

bool querySegmentTree(int node, int start, int end, vector<int> &segmentTree, int value){
    if(segmentTree[node] < value){
        return false; // No basket in this segment
    }

    if(start == end){
        segmentTree[node] = -1; // Mark basket as used
        return true;
    }
    
    int mid = (start + end) / 2;
    bool placed = false;

    if(segmentTree[2 * node + 1] >= value){
        placed = querySegmentTree(2 * node + 1, start, mid, segmentTree, value);
    }
    else{
        placed = querySegmentTree(2 * node + 2, mid + 1, end, segmentTree, value);
    }

    segmentTree[node] = max(segmentTree[2 * node + 1], segmentTree[2 * node + 2]);

    return placed;
}

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets){
    int n = fruits.size();

    vector<int> segmentTree(4 * n, -1);

    buildTree(0, 0, n - 1, baskets, segmentTree);

    int unplaced = 0;
    
    for (int &fruit : fruits){
        if(!querySegmentTree(0, 0, n - 1, segmentTree, fruit)){
            unplaced++;
        }
    }

    return unplaced;
}

int main(){

    vector<int> fruits = {4, 2, 5};
    vector<int> baskets = {3, 5, 4};

    cout << "Number of unplaced fruits: " << numOfUnplacedFruits(fruits, baskets) << endl;

    return 0;
}