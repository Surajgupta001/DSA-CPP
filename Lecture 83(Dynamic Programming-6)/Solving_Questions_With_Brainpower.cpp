/*
Solving Questions With Brainpower - [Leetcode - 2140(Medium)]
=============================================================
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

Example 1:

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Example 2:

Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
Output: 7
Explanation: The maximum points can be earned by solving questions 1 and 4.
- Skip question 0
- Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
- Unable to solve questions 2 and 3
- Solve question 4: Earn 5 points
Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.
 

Constraints:

1 <= questions.length <= 105
questions[i].length == 2
1 <= pointsi, brainpoweri <= 105
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Using Recursion with Memoization to solve the problem
long long helper(int n, int i, vector<vector<int>>& questions, vector<long long>& dp){
    if(i >= n) return 0; // Base case: no more questions to solve
    if(dp[i] != -1) return dp[i]; // Check if already computed
    
    // Option 1: Solve the current question
    long long solve = questions[i][0] + helper(n, i + questions[i][1] + 1, questions, dp);
    
    // Option 2: Skip the current question
    long long skip = helper(n, i + 1, questions, dp);

    return dp[i] = max(solve, skip); // Store the result in dp[i]
}

long long mostPoints(vector<vector<int>>& questions){
    int n = questions.size();
    vector<long long> dp(n, -1); // Initialize dp array with -1 (not computed)
    return helper(n, 0, questions, dp); // Start from the first question
}

/*
========== Using Tabulation (Bottom-Up DP) to solve the problem ======
long long mostPoints(vector<vector<int>>& questions){
    int n = questions.size();
    vector<long long> dp(n + 1, 0);// dp[i] is the max points we can get from the first i questions
    for(int i = n - 1; i >= 0; i--){
        dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]);
    }
    return dp[0];
}
*/ 
 
int main(){
        
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
    cout << mostPoints(questions) << endl; // Output: 5
        
    return 0;
}