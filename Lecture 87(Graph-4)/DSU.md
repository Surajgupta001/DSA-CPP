# Disjoint Set Union (DSU)

Disjoint Set Union (DSU) is a data structure used to manage a set of elements partitioned into a number of non-overlapping (or disjoint) subsets. It is commonly used in graph algorithms to find connected components, detect cycles, and perform union operations.

## Key Operations

Find: Find the representative (or parent) of a set that an element belongs to.

Union: Merge two sets into a single set.

## Implementation

```cpp

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
```

## Explanation

The DSU implementation uses two vectors: parent and rank. The parent vector stores the representative (or parent) of each set, while the rank vector stores the rank of each set.

The find operation uses path compression to optimize the search for the representative of a set. If the vertex is not the representative of its set, it recursively calls find on its parent until it reaches the representative.

The unionSets operation merges two sets by attaching the root of one set to the root of the other set. If the ranks of the two sets are equal, it increments the rank of the new root.

## Time Complexity

The time complexity of the DSU operations is:

find: O(α(n)), where α(n) is the inverse Ackermann function, which grows very slowly.

unionSets: O(α(n))

## Space Complexity

The space complexity of the DSU implementation is O(n), where n is the number of vertices in the graph.
