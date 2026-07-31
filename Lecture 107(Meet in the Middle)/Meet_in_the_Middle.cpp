/*
You are given an array of n numbers. In how many ways can you choose a subset of the numbers with sum x?

Input
The first input line has two numbers n and x: the array size and the required sum.
The second line has n integers t_1,t_2,\dots,t_n: the numbers in the array.

Output
Print the number of ways you can create the sum x.

Constraints

1 <= n <= 40
1 <= x <= 10^9
1 <= t_i <= 10^9

Example
Input:
4 5
1 2 3 2

Output:
3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
    
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        
        
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int n1 = n / 2;
    int n2 = n - n1;

    vector<ll> sumsA(1 << n1); // size of 2^n1
    for(int mask = 0; mask < (1 << n1); mask++){
        ll sum = 0;
        for(int i=0; i<n1; i++){
            if(mask & (1 << i)){
                sum += v[i];
            }
        }
        sumsA[mask] = sum;
    }

    vector<ll> sumsB(1 << n2); // size of 2^n2
    for(int mask = 0; mask < (1 << n2); mask++){
        ll sum = 0;
        for(int i=0; i<n2; i++){
            if(mask & (1 << i)){
                sum += v[n1 + i];
            }
        }
        sumsB[mask] = sum;
    }

    sort(sumsB.begin(), sumsB.end());

    ll count = 0;
    for(auto sum : sumsA){
        ll needed = x - sum; // remaining sum needed from sumsB
        auto low = lower_bound(sumsB.begin(), sumsB.end(), needed);
        auto high = upper_bound(sumsB.begin(), sumsB.end(), needed);

        count += (high - low);
    }

    cout << count << "\n";
    
    return 0;
}