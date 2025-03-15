/*
Maximum Candies Allocated to K Children - [Leetcode - 2226(Medium)]
==================================================================
You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.


Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.

Example 2:

Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.

Constraints:

1 <= candies.length <= 10^5
1 <= candies[i] <= 10^7
1 <= k <= 10^12
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=========== Brute Force ==================
int maxCandies(vector<int>& candies, int k){
    int n = candies.size();
    int maxCandies = 0;
    int total = 0;
    for(int i = 0; i < n; i++){
        total += candies[i];
        maxCandies = max(maxCandies, candies[i]);
    }
    if(total < k) return 0;

    // Brute force try maxC till 1 
    for(int c = maxCandies; c >= 1; c--){
        long long count = 0;
        for(int i = 0; i < n; i++){
            count += candies[i] / c; // How many children can get c candies from this pile
        }
        if(count >= k) return c;
    }
    return 0;
}
*/ 

// ========= Optimised/Improved code
bool canDistribute(vector<int>& candies, int mid, long long k){
    int n = candies.size();
    for(int i=0; i<n; i++){
        k -= candies[i]/mid;
        if(k <= 0){ // all children got mid candies
            return true; // Early return
        }
    }
    return k <= 0; // all children get the mid candies
}

// Binary Search
int maxCandies(vector<int>& candies, int k){
    int n = candies.size();
    int maxCandies = 0;
    long long total = 0;
    int ans = 0;

    for(int i=0; i<n; i++){
        total += candies[i];
        maxCandies = max(maxCandies, candies[i]);
    }
    if(total < k) return 0;

    int low = 1;
    int high = maxCandies;

    while(low <= high){ // Time : n*log(max c)
        int mid = low + (high - low)/2;
        if(canDistribute(candies, mid, k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> candies(n);
    for (int i = 0; i < n; i++){
        cin >> candies[i];
    }
    cout << maxCandies(candies, k) << endl;
}