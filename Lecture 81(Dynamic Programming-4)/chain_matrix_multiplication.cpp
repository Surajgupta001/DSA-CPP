/*
Matrix Chain Multiplication
==================================
Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i-1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum. When two matrices of size m*n and n*p when multiplied, they generate a matrix of size m*p and the number of multiplications performed is m*n*p.

Examples:

Input: arr[] = {2, 1, 3, 4}
Output: 20
Explanation: There are 3 matrices of dimensions 2×1, 1×3, and 3×4, 
Let the input 3 matrices be M1, M2, and M3. There are two ways to multiply ((M1 x M2) x M3) and (M1 x (M2 x M3)), 
Please note that the result of M1 x M2 is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix.
((M1 x M2) x M3)  requires (2 x 1 x 3)  + (0) +  (2 x 3 x 4) = 30 
(M1 x (M2 x M3))  requires (0)  + (1 x 3 x 4) +  (2 x 1 x 4) = 20 
The minimum of these two is 20.


Input: arr[] = {1, 2, 3, 4, 3}
Output: 30
Explanation: There are 4 matrices of dimensions 1×2, 2×3, 3×4, 4×3. Let the input 4 matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1M2)M3)M4. The minimum number is 1*2*3 + 1*3*4 + 1*4*3 = 30


Input: arr[] = {3, 4}
Output: 0
Explanation: As there is only one matrix so, there is no cost of multiplication.
*/ 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// =========== Recursion ==================
int chainMatrixMultiplication(int i, int j, vector<int>& v){
    if(i == j or i+1 == j) return 0;
    int ans = INT_MAX;
    for(int k = i+1;k<j;k++){
        ans = min(ans, chainMatrixMultiplication(i,k,v) + chainMatrixMultiplication(k,j,v) + v[i]*v[k]*v[j]);
    }
    return ans;
} 

int helper(int i, int j, vector<int>& v, vector<vector<int>> dp){
    if(i == j or i+1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i+1;k<j;k++){
        ans = min(ans, helper(i,k,v,dp) + helper(k,j,v,dp) + v[i]*v[k]*v[j]);
    }
    return dp[i][j] = ans;
}

int matrixChainMultiplication(int n, vector<int>& v){
    vector<vector<int>> dp(n, vector<int>(n,-1));
    return helper(0,n-1,v,dp);
}

// =================== Tabulation =====================
int matrixChainMultiplication(int n, vector<int>& v){
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(int len=3;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j = i+len-1;
            dp[i][j] = INT_MAX;
            for(int k = i+1;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i]*v[k]*v[j]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter all the elements of vector: ";
    for(int i = 0;i<n;i++) cin>>v[i];

    cout<<matrixChainMultiplication(n,v)<<endl;
    
    return 0;
}