/*
Maximize the Minimum Powered City - [Leetcode - 2528(Hard)]
------------------------------------------------------------
You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.

Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.

Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.
The power of a city is the total number of power stations it is being provided power from.

The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.

Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.

Note that you can build the k power stations in multiple cities.

Example 1:

Input: stations = [1,2,4,5,0], r = 1, k = 2
Output: 5
Explanation: 
One of the optimal ways is to install both the power stations at city 1. 
So stations will become [1,4,4,5,0].
- City 0 is provided by 1 + 4 = 5 power stations.
- City 1 is provided by 1 + 4 + 4 = 9 power stations.
- City 2 is provided by 4 + 4 + 5 = 13 power stations.
- City 3 is provided by 5 + 4 = 9 power stations.
- City 4 is provided by 5 + 0 = 5 power stations.
So the minimum power of a city is 5.
Since it is not possible to obtain a larger power, we return 5.

Example 2:

Input: stations = [4,4,4,4], r = 0, k = 3
Output: 4
Explanation: 
It can be proved that we cannot make the minimum power of a city greater than 4.

Constraints:

n == stations.length
1 <= n <= 105
0 <= stations[i] <= 10^5
0 <= r <= n - 1
0 <= k <= 109
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Helper function to check if a given minimum power 'mid' can be achieved
bool check(long long mid, vector<long long>& diff, int r, int k) {
    int n = diff.size();
    vector<long long> tempDiff = diff; // Create a copy of the difference array

    long long cummulativeSum = 0; // To maintain the current power at each city

    for (int i = 0; i < n; i++) {
        cummulativeSum += tempDiff[i]; // Update current power using difference array

        if(cummulativeSum < mid){
            long long needed = mid - cummulativeSum; // Additional power needed
            if(needed > k){
                return false; // Not enough additional power stations
            }
            k -= needed; // Use the needed power stations
            cummulativeSum += needed; // Greedily I had chosen to add stations on the city which can cover more range

            // increase power in the range [i, i + 2*r]
            if(i + 2 * r + 1 < n){
                tempDiff[i + 2 * r + 1] -= needed; // Update the difference array to reflect the added stations' effect
            }
        }
    }
    return true; // If we can achieve the required power
}

long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    
    vector<long long> diff(n, 0); // Difference array to manage range updates
    
    for(int i=0; i<n; i++){
        diff[max(0, i - r)] += stations[i];
        if(i + r + 1 < n){
            diff[i + r + 1] -= stations[i];
        }
    }

    long long low = *min_element(stations.begin(), stations.end()); // Minimum power without additional stations
    long long high = accumulate(stations.begin(), stations.end(), 0LL) + k; // Max possible power

    long long result = 0;

    // Binary search to find the maximum minimum power
    while(low <= high){
        long long mid = low + (high - low) / 2;
    
        if(check(mid, diff, r, k)){ // If mid is achievable
            result = mid; // Update result
            low = mid + 1; // Try for a higher minimum power
        }
        else{
            high = mid - 1; // Try for a lower minimum power
        }
    }
    return result;
}

int main() {
    vector<int> stations = {1, 2, 4, 5, 0};
    int r = 1;
    int k = 2;

    long long result = maxPower(stations, r, k);
    cout << "Maximum possible minimum power of a city: " << result << endl;

    return 0;
}