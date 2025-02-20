/*
Range Frequency Queries - [Leetcode - 2080(Medium)]
====================================================
Design a data structure to find the frequency of a given value in a given subarray.

The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

Implement the RangeFreqQuery class:

RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].
A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that contains the elements of nums between indices left and right (inclusive).

Example 1:

Input
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
Output
[null, 1, 2]

Explanation
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the subarray [33, 4]
rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in the whole array.


Constraints:

1 <= arr.length <= 105
1 <= arr[i], value <= 104
0 <= left <= right < arr.length
At most 105 calls will be made to query
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RangeFreqQuery{
public:
    vector<unordered_map<int, int>> segmentTree;
    int n;
    unordered_map<int, int> addMaps(unordered_map<int, int> &maps1,unordered_map<int, int> &maps2){
        unordered_map<int, int> mp; // empty ans map
        for (auto itr : maps1){
            mp.insert(itr);
        }
        for (auto itr : maps2){
            int key = itr.first;
            int freq = itr.second;
            if (mp.find(key) == mp.end()){ // key not found in mp
                mp.insert(itr);
            }
            else{
                mp[key] += freq;
            }
        }
        return mp;
    }
    void buildTree(vector<int> &v, int i, int low, int high){
        if (low == high){
            segmentTree[i][v[low]] =
                1; // 2nd way in map, and it is not a 2D Array
            return;
        }
        int mid = (low + high) / 2;
        buildTree(v, 2 * i + 1, low, mid);
        buildTree(v, 2 * i + 2, mid + 1, high);
        segmentTree[i] = addMaps(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    RangeFreqQuery(vector<int> &v){
        n = v.size();
        segmentTree.resize(4 * n);
        buildTree(v, 0, 0, n - 1);
    }

    int getFreq(int i, int low, int high, int &left, int &right, int &key){
        if (left > high or right < low) return 0;
        if (low >= left and high <= right){
            if (segmentTree[i].find(key) == segmentTree[i].end()) return 0;
            else return segmentTree[i][key];
        }
        int mid = (low + high) / 2;
        int leftFreq = getFreq(2 * i + 1, low, mid, left, right, key);
        int rightFreq = getFreq(2 * i + 2, mid + 1, high, left, right, key);
        return leftFreq + rightFreq;
    }

    int query(int left, int right, int value){
        return getFreq(0, 0, n - 1, left, right, value);
    }
};

int main(){
    vector<int> arr = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};

    RangeFreqQuery rangeFreqQuery(arr);

    int left = 1, right = 2, value = 4;
    int result1 = rangeFreqQuery.query(left, right, value);
    cout << "Frequency of " << value << " in the subarray [" << left << ", " << right << "] is: " << result1 << endl;

    left = 0, right = 11, value = 33;
    int result2 = rangeFreqQuery.query(left, right, value);
    cout << "Frequency of " << value << " in the subarray [" << left << ", " << right << "] is: " << result2 << endl;

    return 0;
}