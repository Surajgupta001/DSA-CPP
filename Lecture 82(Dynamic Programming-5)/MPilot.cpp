/*
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.

Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).

Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries.

Sample
input 
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
 
output 
19000 
input 
6 
10000 7000 
9000 3000 
6000 4000 
5000 1000 
9000 3000 
8000 6000 
 
output 
32000
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long int
using namespace std;

vector<ll> cap(10005, 0);
vector<ll> as(10005, 0);
ll dp[10005][5005];
int n;
// x = assistant - captain
ll calc(int i, int x) {
	if(dp[i][x] != -1) return dp[i][x];
	if(i == n) {
		return 0;
	}
	if(x == 0) {
		return dp[i][x] = calc(i+1, x+1) + as[i];
	} else if(x == n-i) {
		return dp[i][x] = calc(i+1, x-1) + cap[i];
	} else {
		return dp[i][x] = min(calc(i+1, x+1) + as[i], calc(i+1, x-1)+cap[i]);
	}
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cap[i] >> as[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0] = as[0] + calc(1,1);
    cout << dp[0][0] << endl;
}