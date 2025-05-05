/*
Merge Operations for Minimum Travel Time - [Leetcode - 3538(Hard)]
------------------------------------------------------------------
You are given a straight road of length l km, an integer n, an integer k, and two integer arrays, position and time, each of length n.

The array position lists the positions (in km) of signs in strictly increasing order (with position[0] = 0 and position[n - 1] = l).

Each time[i] represents the time (in minutes) required to travel 1 km between position[i] and position[i + 1].

You must perform exactly k merge operations. In one merge, you can choose any two adjacent signs at indices i and i + 1 (with i > 0 and i + 1 < n) and:

Update the sign at index i + 1 so that its time becomes time[i] + time[i + 1].
Remove the sign at index i.
Return the minimum total travel time (in minutes) to travel from 0 to l after exactly k merges.

 

Example 1:

Input: l = 10, n = 4, k = 1, position = [0,3,8,10], time = [5,8,3,6]

Output: 62

Explanation:

Merge the signs at indices 1 and 2. Remove the sign at index 1, and change the time at index 2 to 8 + 3 = 11.

After the merge:
position array: [0, 8, 10]
time array: [5, 11, 6]

Segment	    Distance (km)	    Time per km (min)	  Segment Travel Time (min)
0 → 8	    8	                5	                  8 × 5 = 40
8 → 10	    2	                11	                  2 × 11 = 22

Total Travel Time: 40 + 22 = 62, which is the minimum possible time after exactly 1 merge.

Example 2:

Input: l = 5, n = 5, k = 1, position = [0,1,2,3,5], time = [8,3,9,3,3]

Output: 34

Explanation:

Merge the signs at indices 1 and 2. Remove the sign at index 1, and change the time at index 2 to 3 + 9 = 12.
After the merge:
position array: [0, 2, 3, 5]
time array: [8, 12, 3, 3]
Segment	     Distance (km)	   Time per km (min)	Segment Travel Time (min)
0 → 2	     2	               8	                2 × 8 = 16
2 → 3	     1	               12	                1 × 12 = 12
3 → 5	     2	               3	                2 × 3 = 6
Total Travel Time: 16 + 12 + 6 = 34, which is the minimum possible time after exactly 1 merge.
 

Constraints:

1 <= l <= 105
2 <= n <= min(l + 1, 50)
0 <= k <= min(n - 2, 10)
position.length == n
position[0] = 0 and position[n - 1] = l
position is sorted in strictly increasing order.
time.length == n
1 <= time[i] <= 100​
1 <= sum(time) <= 100​​​​​​
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
================== Recursion =======================
int N;

int helper(int i, int k, int currRate, vector<int>& position, vector<int>& time){
    // Base Case
    if(i == N-1){
        if(k > 0){
            return INT_MAX;
        }
        return 0;
    }

    // Code
    int result = INT_MAX;

    // Skip and no Merging case
    int skipResultTime = helper(i+1, k, time[i+1], position, time);
    if(skipResultTime != INT_MAX){
        int dist = position[i+1] - position[i];
        result = min(result, ((dist*currRate) + skipResultTime));
    }

    // We decided to merging
    if(k > 0){
        int mergeTime = time[i+1];
        int mergeCount = 0;

        for(int j=i+2; j<N and mergeCount<k; j++){
            mergeCount++;
            mergeTime += time[j];

            // Recursion
            // i -------> j
            int mergeResultTime = helper(j, k - mergeCount, mergeTime, position, time);
            if(mergeResultTime != INT_MAX){
                int dist = position[j] - position[i];
                result = min(result, ((dist*currRate) + mergeResultTime));
            }
        }
    }
    return result;
}
*/


int helper(int i, int n, int k, int currRate, vector<int>& position, vector<int>& time,  vector<vector<vector<int>>>& dp){
    // Base Case
    if(i == n-1){
        if(k > 0){
            return INT_MAX;
        }
        return 0;
    }

    if(dp[i][k][currRate] != -1){ 
        return dp[i][k][currRate];
    }

    // Code
    int result = INT_MAX;

    // Skip and no Merging case
    int skipResultTime = helper(i+1, n, k, time[i+1], position, time, dp);
    if(skipResultTime != INT_MAX){
        int dist = position[i+1] - position[i];
        result = min(result, ((dist*currRate) + skipResultTime));
    }

    // We decided to merging
    if(k > 0){
        int mergeTime = time[i+1];
        int mergeCount = 0;

        for(int j = i+2; j < n and mergeCount < k; j++){
            mergeCount++;
            mergeTime += time[j];

            // Recursion
            // i -------> j
            int mergeResultTime = helper(j,n, k - mergeCount, mergeTime, position, time, dp);
            if(mergeResultTime != INT_MAX){
                int dist = position[j] - position[i];
                result = min(result, ((dist*currRate) + mergeResultTime));
            }
        }
    }
    return dp[i][k][currRate] = result;
}

int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {

    int cummulativeTime = 0;
    for(auto &t : time){
        cummulativeTime += t;
    }

    // 3D Vector DP
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(cummulativeTime + 1, -1)));

    return helper(0, n, k, time[0], position, time, dp);
}

int main(){
    int l = 10, n = 4, k = 1;
    vector<int> position = {0, 3, 8, 10};
    vector<int> time = {5, 8, 3, 6};
    
    int result = minTravelTime(l, n, k, position, time);
    cout << "Minimum Travel Time: " << result << endl;
    
    return 0;
}