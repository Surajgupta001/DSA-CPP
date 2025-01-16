/*
Ray and coin Boxes
=====================
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.

Input:
First line contains N - number of coin boxes.
Second line contains M - number of days.
Each of the next M lines consists of two space separated integers L and R.
Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.

Output:
For each query output the result in a new line.

Constraints:
1 ≤ N ≤ 1000000
1 ≤ M ≤ 1000000
1 ≤ L ≤ R ≤ N
1 ≤ Q ≤ 1000000
1 ≤ X ≤ N

Sample Input           Sample Output
7
4
1 3
2 5
1 2
5 6
4                     
1                      6
7                      0
4                      0
2                      4
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cout<<"Enter no. of boxes: ";
    cin>>n;

    // Number of coins in each box
    vector<int>v(n+1,0);
    int m;
    cout<<"Enter how many queries: ";
    cin>>m;

    // Vectors to mark the start and end of ranges where coins are added
    vector<int>l(n+1,0); 
    vector<int>r(n+1,0);

    // Process each day's range [L, R]
    for(int i=0;i<m;i++){
        int L,R;
        cout<<"Enter L and R: ";
        cin>>L>>R;
        l[L]++;  // Mark the start of the range
        r[R]++;  // Mark the end of the range
    }

    // Calculate the number of coins in each box using prefix sums
    v[1] = l[1];
    for(int i=2;i<=n;i++){
        v[i] = v[i-1] + l[i] - r[i-1];
    }

    // Count how many boxes have exactly 'i' coins
    vector<int>coin(n+1,0);
    for(int i=0;i<=n;i++){
        int coins = v[i];
        coin[coins]++; 
    }

    // Apply suffix sum to count how many boxes have at least 'i' coins
    for(int i=coin.size()-2;i>=0;i--){
        coin[i] += coin[i+1];
    }

    // Handle queries
    int q;
    cout<<"Enter no. of queries: "<<endl;
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter number of coins: ";
        cin>>num;
        cout<<" -> "<<coin[num]<<endl; 
    }
    return 0;
}