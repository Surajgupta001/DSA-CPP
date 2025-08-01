/*
MIXTURES - Mixtures
#dynamic-programming

Harry Potter has n mixtures in front of him, arranged in a row. Each mixture has one of 100 different colors (colors have numbers from 0 to 99).

He wants to mix all these mixtures together. At each step, he is going to take two mixtures that stand next to each other and mix them together, and put the resulting mixture in their place.

When mixing two mixtures of colors a and b, the resulting mixture will have the color (a+b) mod 100.

Also, there will be some smoke in the process. The amount of smoke generated when mixing two mixtures of colors a and b is a*b.

Find out what is the minimum amount of smoke that Harry can get when mixing all the mixtures together.

Input
There will be a number of test cases in the input.

The first line of each test case will contain n, the number of mixtures, 1 <= n <= 100.

The second line will contain n integers between 0 and 99 - the initial colors of the mixtures.

Output
For each test case, output the minimum amount of smoke.

Example
Input:
2
18 19
3
40 60 20

Output:
342
2400
In the second test case, there are two possibilities:

first mix 40 and 60 (smoke: 2400), getting 0, then mix 0 and 20 (smoke: 0); total amount of smoke is 2400
first mix 60 and 20 (smoke: 1200), getting 80, then mix 40 and 80 (smoke: 3200); total amount of smoke is 4400
The first scenario is a much better way to proceed.
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
============== Recursion ==============
int helper(vector<int>& colors, int i, int j){
    int result = 0;
    for(int m=i; m<=j; m++){
        result = (result % 100 + colors[m]) % 100;
    }
    return result;
}

int colorMixture(vector<int>& color, int i, int j){
    if(i == j) return 0;
    int minSmoke = INT_MAX;
    for(int k=i; k<j; k++){
        int smoke = helper(color, i, k) * helper(color, k+1, j);
        minSmoke = min(minSmoke, smoke + colorMixture(color, i, k) + colorMixture(color, k+1, j));
    }
    return minSmoke;
}
*/ 

int helper(vector<int>& colors, int i, int j){
    int result = 0;
    for(int m=i; m<=j; m++){
        result = (result + colors[m]) % 100;
    }
    return result;
}

int colorMixture(vector<int>& color, int i, int j, vector<vector<int>>& dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int minSmoke = INT_MAX;
    for(int k=i; k<j; k++){
        int smoke = helper(color,i,k) * helper(color,k+1,j);
        minSmoke = min(minSmoke, smoke + colorMixture(color,i,k, dp) + colorMixture(color,k+1,j, dp));
    }
    return dp[i][j] = minSmoke;
}

int calculateMinSmoke(vector<int> &colors){
    int n = colors.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return colorMixture(colors,0,colors.size()-1,dp);
}

/*
============ Tabulation ====================
int calculateMinSmoke(vector<int> &colors){
    vector<vector<int>> dp(colors.size(), vector<int>(colors.size(), 0));
    for(int len=2;len<=colors.size();len++){
        for(int i=0;i<=colors.size()-len;i++){
            int j = i+len-1;
            int minSmoke = INT_MAX;
            for(int k=i; k<j; k++){
                int smoke = (helper(colors,i,k) * helper(colors,k+1,j));
                minSmoke = min(minSmoke, dp[i][k] + dp[k+1][j] + smoke);
            }
            dp[i][j] = minSmoke;
        }
    }
    return dp[0][colors.size()-1];
}
*/

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>colors(n);
    cout<<"Enter all the elements: ";
    for(int i=0; i<n; i++) cin>>colors[i];

    cout<<"Minimum amount of smoke will be : "<<calculateMinSmoke(colors)<<endl;

    return 0;
}