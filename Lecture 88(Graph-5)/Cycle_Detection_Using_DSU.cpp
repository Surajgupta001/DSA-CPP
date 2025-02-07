#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int x){
    // Time Complexity : O(log*n)
    // This method return which group/clustor x belongs to
    // It is used to find the root of a tree
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

bool Union(vector<int>& parent, vector<int>& rank, int a, int b){
    // Time Complexity : O(log*n)
    // This method is used to merge two clusters
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return true;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
    return false;
}

int main(){
    
    int n, m;
    cout<<"Enter the no. of elements and queries : ";
    cin>>n>>m;
    // n -> elements; m-> no of queries
    
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for(int i=0;i<=n;i++) parent[i] = i;

    while(m--){
            int x, y;
            cout<<"Enter the first & second element to merge: ";
            cin>>x>>y;
            bool b = Union(parent, rank, x, y);
            if(b == true) cout<<"Elements already in same group OR Cycle Detected"<<endl;
    }
    return 0;
}