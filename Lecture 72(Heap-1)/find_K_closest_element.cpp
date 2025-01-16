#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> findClosestElement(vector<int>& v, int k, int x){
    priority_queue<pair<int, int>>pq; // mapheap (max size is k) <dist,ele>
    for(auto ele:v){
        int distance = abs(x - ele); // calculating absolute distance form x closest element 
        pq.push({distance, ele}); // Push the pair (distance, element) into the priority queue
        if(pq.size() > k) pq.pop();
    }
    vector<int>ans;
    while(pq.size() > 0){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of vector: ";
    for(int i=0;i<n;i++) cin>>v[i];

    int k;
    cout<<"Enter the smallest distance: ";
    cin>>k;

    int x;
    cout<<"Enter the closest element: ";
    cin>>x;

    vector<int>ans = findClosestElement(v, k, x);
    cout<<"The elements closest to "<<x<<" are: ";
    for(auto ele:ans) cout<<ele<<" ";

    return 0;
}