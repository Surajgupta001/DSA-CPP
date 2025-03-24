/*
Nene invented a new game based on an increasing sequence of integers a1,a2,…,ak.

In this game, initially n players are lined up in a row. In each of the rounds of this game, the following happens:

-> Nene finds the a1-th, a2-th, …, ak-th players in a row. They are kicked out of the game simultaneously. If the i-th player in a row should be kicked out, but there are fewer than i players in a row, they are skipped.

Once no one is kicked out of the game in some round, all the players that are still in the game are declared as winners.

For example, consider the game with a=[3,5] and n=5 players. Let the players be named player A, player B, …, player E in the order they are lined up initially. Then,

-> Before the first round, players are lined up as ABCDE. Nene finds the 3-rd and the 5-th players in a row. These are players C and E. They are kicked out in the first round.
-> Now players are lined up as ABD. Nene finds the 3-rd and the 5-th players in a row. The 3-rd player is player D and there is no 5-th player in a row. Thus, only player D is kicked out in the second round.
-> In the third round, no one is kicked out of the game, so the game ends after this round.
-> Players A and B are declared as the winners.

Nene has not yet decided how many people would join the game initially. Nene gave you q integers n1,n2,…,nq and you should answer the following question for each 1≤i≤q independently:

How many people would be declared as winners if there are ni players in the game initially?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤250). The description of test cases follows.

The first line case contains two integers k and q (1≤k,q≤100) — the length of the sequence a and the number of values ni you should solve this problem for.

The second line contains k integers a1,a2,…,ak (1≤a1<a2<…<ak≤100) — the sequence a.

The third line contains q integers n1,n2,…,nq (1≤ni≤100).

Output
For each test case, output q integers: the i-th (1≤i≤q) of them should be the number of players declared as winners if initially ni players join the game.

Example

Input
6
2 1
3 5
5
5 3
2 4 6 7 9
1 3 5
5 4
3 4 5 6 7
1 2 3 4
2 3
69 96
1 10 100
1 1
100
50
3 3
10 20 30
1 10 100

Output
2 
1 1 1 
1 2 2 2 
1 10 68 
50 
1 9 9 

Note
The first test case was explained in the statement.

In the second test case, when n=1, the only player stays in the game in the first round. After that, the game ends and the only player is declared as a winner.
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// More Efficient 
void solve(){
    int k, q;
    cin>>k>>q;
    vector<int> a(k);
    for(int i = 0; i < k; i++) cin>>a[i];
    while(q--){
        int n;
        cin>>n;
        cout<<min(a[0]-1, n)<<endl;
    }
    cout<<endl;
}

// Less Efficient -> Type of Binary Search
void solve() {
    int k, q;
    cin >> k >> q;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    
    vector<int> b(q);
    for (int i = 0; i < q; i++) cin >> b[i];

    for (int i = 0; i < q; i++) {
        int n = b[i];
        int ans = n;
        while (ans >= a[0]) {
            int x = upper_bound(a.begin(), a.end(), ans) - a.begin();
            ans -= x;
        }
        cout << ans << " ";
    }
    cout << endl;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}