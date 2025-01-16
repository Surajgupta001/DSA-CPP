/*
Removing Digits - [CSES]
==========================
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?

Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 -> 20 -> 18 -> 10 -> 9 -> 0.
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> get_digit(int n){
    vector<int> result;
    while(n > 0){
        if(n % 10 != 0) result.push_back(n % 10);
        n /= 10;
    }
    return result;
}

/*
================ Recursion ==================
int minimumSteps(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    
    int result = INT_MAX;

    vector<int> digits = get_digit(n);
    for(int i=0;i<digits.size();i++){
        result = min(result, minimumSteps(n - digits[i]));
    }
    return result + 1;
}
*/ 

int helper(vector<int>& dp, int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(dp[n] != -1) return dp[n];
    vector<int> digits = get_digit(n);
    int result = INT_MAX;
    for(int i=0;i<digits.size();i++){
        result = min(result, helper(dp, n - digits[i]));
    }
    return dp[n] = result + 1;
}

int minimumSteps(int n){
    vector<int> dp(n+1, -1);
    return helper(dp, n);
}


/*
=============== Tabulation ================
int minimumSteps(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for(int i=1;i<=9;i++) dp[i] = 1;
    for(int i=10;i<=n;i++){ // i -> state
        vector<int> digits = get_digit(i);
        int result = INT_MAX;
        for(int j=0;j<digits.size();j++){ // j -> digits
            result = min(result, dp[i - digits[j]]);
        }
        dp[i] = 1 + result;
    }
    return dp[n];
}
*/ 

int main(){

    int n;
    cout<<"Enter a number: ";
    cin>>n;

    cout<<"Minimum steps are required to make the number equal to 0 is: "<<minimumSteps(n)<<endl;
    
    return 0;
}