#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <set>
#include <vector>

int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    set<int>set;
    for(auto value:v){
        set.insert(value);
    }

    auto itr = set.begin();
    itr++;
    cout<<"Second smallest number: "<<*itr<<endl;

    return 0;
}