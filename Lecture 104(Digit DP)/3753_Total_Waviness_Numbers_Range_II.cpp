/*
Total Waviness of Numbers in Range II - [Leetcode - 3753(Hard)]
----------------------------------------------------------------------

You are given two integers num1 and num2 representing an inclusive range [num1, num2].

The waviness of a number is defined as the total count of its peaks and valleys:

A digit is a peak if it is strictly greater than both of its immediate neighbors.
A digit is a valley if it is strictly less than both of its immediate neighbors.
The first and last digits of a number cannot be peaks or valleys.
Any number with fewer than 3 digits has a waviness of 0.
Return the total sum of waviness for all numbers in the range [num1, num2].
 

Example 1:

Input: num1 = 120, num2 = 130

Output: 3

Explanation:

In the range [120, 130]:

120: middle digit 2 is a peak, waviness = 1.
121: middle digit 2 is a peak, waviness = 1.
130: middle digit 3 is a peak, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 2:

Input: num1 = 198, num2 = 202

Output: 3

Explanation:

In the range [198, 202]:

198: middle digit 9 is a peak, waviness = 1.
201: middle digit 0 is a valley, waviness = 1.
202: middle digit 0 is a valley, waviness = 1.
All other numbers in the range have a waviness of 0.
Thus, total waviness is 1 + 1 + 1 = 3.

Example 3:

Input: num1 = 4848, num2 = 4848

Output: 2

Explanation:

Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

 

Constraints:

1 <= num1 <= num2 <= 10^15​​​​​​​
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long

pair<ll, ll> helper(int curr, int prevPrev, int prev, bool isLimitedWithActualNumber, bool isLeadingZero, string& s, vector<vector<vector<ll>>>& dpTotalNumbers, vector<vector<vector<ll>>>& dpTotalWaviness) {

    if (curr == (int)s.size()) return make_pair(1LL, 0LL); // totalNumbers = 1, totalWaveScore = 0

    if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {

        if (dpTotalNumbers[curr][prevPrev][prev] != -1 && dpTotalWaviness[curr][prevPrev][prev] != -1) {

            return make_pair(
                dpTotalNumbers[curr][prevPrev][prev],
                dpTotalWaviness[curr][prevPrev][prev]
            );
        }
    }

    ll totalNumbers = 0;
    ll totalWaveScore = 0;

    int limitDigit = isLimitedWithActualNumber ? s[curr] - '0' : 9;

    for (int digit = 0; digit <= limitDigit; digit++) {

        bool newIsLeadingZero = isLeadingZero && digit == 0;

        int newPrevPrev = prev;
        int newPrev = newIsLeadingZero ? -1 : digit;

        pair<ll, ll> result = helper(curr + 1, newPrevPrev, newPrev, isLimitedWithActualNumber && digit == limitDigit, newIsLeadingZero, s, dpTotalNumbers, dpTotalWaviness);

        ll remainTotalNumbers = result.first;
        ll remainTotalWaveScore = result.second;

        if (!newIsLeadingZero && prev >= 0 && prevPrev >= 0) {

            bool peak = (prevPrev < prev && prev > digit);
            bool valley = (prevPrev > prev && prev < digit);

            if (peak || valley) {
                remainTotalWaveScore += remainTotalNumbers;
            }
        }

        totalNumbers += remainTotalNumbers;
        totalWaveScore += remainTotalWaveScore;
    }

    if (!isLimitedWithActualNumber && !isLeadingZero && prevPrev >= 0 && prev >= 0) {

        dpTotalNumbers[curr][prevPrev][prev] = totalNumbers;
        dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
    }

    return make_pair(totalNumbers, totalWaveScore);
}

ll func(long long num) {
    if (num < 100) return 0; // Any number with fewer than 3 digits has a waviness of 0.

    string s = to_string(num);

    vector<vector<vector<ll>>> dpTotalNumbers(20, vector<vector<ll>>(10, vector<ll>(10, -1)));

    vector<vector<vector<ll>>> dpTotalWaviness(20, vector<vector<ll>>(10, vector<ll>(10, -1)));

    pair<ll, ll> result = helper(0, -1, -1, true, true, s, dpTotalNumbers, dpTotalWaviness);

    ll totalNumbers = result.first;
    ll totalWaveScore = result.second;

    return totalWaveScore;
}

long long totalWaviness(long long num1, long long num2) {
    return func(num2) - func(num1 - 1);
}

int main() {
    long long num1 = 120, num2 = 130;
    cout << totalWaviness(num1, num2) << endl;

    num1 = 198, num2 = 202;
    cout << totalWaviness(num1, num2) << endl;

    num1 = 4848, num2 = 4848;
    cout << totalWaviness(num1, num2) << endl;

    return 0;
}