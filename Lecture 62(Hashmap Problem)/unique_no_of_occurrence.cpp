/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

bool uniqueOccurence(vector<int> &v){
    // Step 1: Count Occurrence of each number
    map<int, int> countMap;
    for(auto itr : v) countMap[itr]++;
    /*
    for (int num : v) {
        countMap[num] = count(v.begin(), v.end(), num);
    }
    */ 
    // Step 2: Check for uniqueness of count
    unordered_set<int> countSet;
    for(auto &pair : countMap)
        if(countSet.find(pair.second) != countSet.end()) return true; // If the count already exist in the set, return fasle.
        else countSet.insert(pair.second); // Otherwise, insert the count into the set
    return false;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    cout<<boolalpha<<uniqueOccurence(v)<<endl;

    return 0;
} 