/*

MINIMUM PENALTY FOR A SHOP - (LEETCODE - 2483)
===============================================================
You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

if the ith character is 'Y', it means that customers come at the ith hour
whereas 'N' indicates that no customers come at the ith hour.
If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

For every hour when the shop is open and no customers come, the penalty increases by 1.
For every hour when the shop is closed and customers come, the penalty increases by 1.
Return the earliest hour at which the shop must be closed to incur a minimum penalty.

Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.


Example 1:

Input: customers = "YYNY"
Output: 2
Explanation: 
- Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
- Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
- Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
- Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
- Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.

Example 2:

Input: customers = "NNNNN"
Output: 0
Explanation: It is best to close the shop at the 0th hour as no customers arrive.

Example 3:

Input: customers = "YYYY"
Output: 4
Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.
*/ 

#include <iostream>
#include <string>
using namespace std;

int bestClosingTime(string customres){
    int n = customres.length();
    int pre[n+1]; // no. of N before kth hour
    int suf[n+1]; // no. of Y after and including kth hour

    pre[0] = 0;
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1] + ((customres[i-1] == 'N') ? 1 : 0);
    }

    suf[n] = 0;
    for(int i=n-1;i>=0;i--){
        suf[i] = suf[i+1] + ((customres[i] == 'Y') ? 1 : 0);
    }

    int minPenalty = n;
    for(int i=0;i<=n;i++){
        int penalty = pre[i] + suf[i];
        if(penalty < minPenalty) {
            minPenalty = penalty;
        }
    }

    for(int i=0;i<=n;i++){
        int penalty = pre[i] + suf[i];
        if(penalty == minPenalty) return i;
    }
    return n;
}

int main() {
    string str;
    cout<<"Enter a string: ";
    cin>>str;

    int result = bestClosingTime(str);
    cout << "The shop should be closed at hour " << result << endl;
    return 0;
}