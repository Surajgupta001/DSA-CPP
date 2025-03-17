/*
Minimum Time to Repair Cars - [ Letcode - 2594(Medium)]
=======================================================
You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

Example 1:

Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation:
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

Example 2:

Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation:
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

Constraints:

1 <= ranks.length <= 105
1 <= ranks[i] <= 100
1 <= cars <= 106
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long int

bool isPossible(vector<int> &ranks, ll mid, int cars){
    ll carsFixed = 0;

    for (int i = 0; i < ranks.size(); i++){
        carsFixed += sqrt(mid / ranks[i]); // ignoring this
    }
    return carsFixed >= cars;
}

long long repairCars(vector<int> &ranks, int cars){
    
    int n = ranks.size();
    int maxRank = *max_element(begin(ranks), end(ranks));
    
    ll low = 1;
    ll high = 1LL * maxRank * cars * cars; // Casting int -> long long
    
    ll ans = -1;
    
    // T.C: O(n * log(maxRank*cars*cars));
    
    while (low <= high){ // log(maxRank * cars * cars)
        ll mid = low + (high - low) / 2;
        if (isPossible(ranks, mid, cars)){ // O(n)
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n, cars;
    cin >> n >> cars;
    vector<int> ranks(n);
    for (int i = 0; i < n; i++){
        cin >> ranks[i];
    }
    cout << repairCars(ranks, cars) << endl;
}