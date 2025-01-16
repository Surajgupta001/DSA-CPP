#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int k;
    cout<<"Enter the rotation value: ";
    cin>>k;

    k = k%v.size(); // k % n;
    
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    
     
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}