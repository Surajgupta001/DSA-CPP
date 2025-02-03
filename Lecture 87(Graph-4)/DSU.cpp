#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int x){
    // This method return which group/clustor x belongs to
    // It is used to find the root of a tree
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& rank, int a, int b){
    // This method is used to merge two clusters
    a = find(parent, a);
    b = find(parent, b);

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
}

int main(){
    
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int m;
    cout<<"Enter the number of queries: ";
    cin>>m;
    
    // n -> elements; m-> no of queries

    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for(int i=0;i<=n;i++) parent[i] = i;

    while(m--){
        string str;
        cin >> str;
        if(str == "Union"){
            int x;
            cout<<"Enter the first element to merge: ";
            cin>>x;
            int y;
            cout<<"Enter the second element to merge: ";
            cin>>y;
            Union(parent, rank, x, y);
        }
        else{
            int x;
            cout<<"Enter the element to find: ";
            cin>>x;
            cout<<"Cluster ID of "<<x<<": "<<find(parent, x)<<endl;
        }
    }
    return 0;
}