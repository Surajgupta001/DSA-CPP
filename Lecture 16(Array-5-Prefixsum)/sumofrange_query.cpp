/*
Given an array of integer of size n. Answer q quaries where  you need to print the sun of values in a given range if indices from l to r (both included).

NOTE:The value of l and r in quaries follow 1-based indexing.
*/ 

/*
1-based indexing given mean:
l=1 --> it means 1st element;
r=3 --> it means 3rd element;

But in 0-indexing
l=0 --> it means 1st element;
r=3 --> it means 4th element;

index -->      0   1    2    3    4    5    6
vector -->     0   x1   x2

0 based indexing --> 0 ....... n-1.
1 based indexing --> 1 ....... n.
*/ 

// 0 5 1 2 3 4
// 0 5 6 8 11 15 ---prefix sum array
// l=1, r=3
// ans = v[r] - v[l-1] = v[3]-v[0] = 8 - 0 = 8.

// l=2, r=5;
// ans = v[r] - v[l-1] = v[5] - v[1] = 15 - 5 = 10. 

#include <iostream>
using namespace std;
#include <vector>

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    // calculating prefic sum array;
    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
    }

    int query;
    cout<<"Enter the query: ";
    cin>>query;

    while(query--){
        int l,r;
        cin>>l>>r;
        int ans = 0;

        // ans = prefix_sum_array[r] - prefix_sum_array[l-1];
        ans = v[r]-v[l-1];

        cout<<ans<<endl;
    }

    return 0;
}