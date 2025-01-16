#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

vector<int> targetSumPair(vector<int> &v, int k){

    unordered_map<int,int>m;
    vector<int>ans(2,-1);

    for(int i=0;i<v.size();i++){
        if(m.find(k-v[i]) != m.end()){
            ans[0] = m[k-v[i]];
            ans[1] = i;
            return ans;
        }
        else{
            m[v[i]] = i;
        }
    }
    return  ans;
}

int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int target;
    cout<<"Enter target value: ";
    cin>>target;

    vector<int> ans = targetSumPair(v,target);

    cout<<"Indexes are : "<<ans[0]<<" & "<<ans[1];

    return 0;
}