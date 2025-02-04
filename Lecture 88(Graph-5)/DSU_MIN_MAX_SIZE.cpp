/*
Disjoint Sets Union 2
==========================
Implement disjoint sets union data structure. You have perform queries of two types:

=> Union: u v - unite two sets that contain u and v, respectively
=> get: v - find the sets to which v belongs to, find the minimal and maximal element of the set, and the total number of elements in it.

INPUT:
5 11
union 1 2
get 3
get 2
union 2 3
get 2
union 1 3
get 5
union 4 5
get 5
union 4 1
get 5

OUTPUT:
3 3 1
1 2 2
1 3 3
5 5 1
4 5 1
1 5 5
*/ 


#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int x){
    // Time Complexity : O(log*n)
    // This method return which group/clustor x belongs to
    // It is used to find the root of a tree
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

void Union(vector<int>& parent, vector<int>& size, vector<int>& minimal, vector<int>& maximal, vector<int>& rank, int a, int b){
    // Time Complexity : O(log*n)
    // This method is used to merge two clusters
    if(a == b) return; // both a and b are same set;
    a = find(parent, a);
    b = find(parent, b);

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
        size[a] += size[b];
        minimal[a] = min(minimal[a], minimal[b]);
        maximal[a] = max(maximal[a], maximal[b]);
    }
    else{
        rank[b]++;
        parent[a] = b;
        size[b] += size[a];
        minimal[b] = min(minimal[b], minimal[a]);
        maximal[b] = max(maximal[b], maximal[a]);
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
    vector<int> size(n+1, 1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    for(int i=0;i<=n;i++) parent[i] = minimal[i] = maximal[i] = i;

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
            Union(parent, size, minimal, maximal, rank , x, y);
        }
        else{
            int x;
            cout<<"Enter the element to find: ";
            cin>>x;
            x = find(parent, x);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<size[x]<<" "<<endl;
        }
    }
    return 0;
}