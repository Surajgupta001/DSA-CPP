#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0; i<n; i++){ // Start from 0, not 1
        cin>>v[i];
    }

    // Formatition of prefix sum
    for(int i=1; i<n; i++){ // Start from 1, not 0
        v[i] += v[i-1];
    }

    // check if any x exist
    int index = -1;
    for(int i=1; i<n; i++){
        if(2*(v[i-1]) == v[n-1]){ // Check if the sum of the left part is equal to the sum of the right part
            index = i;
        }
    }
    if(index != -1) cout<<"Yes it can be partitioned at index: "<<index;
    else cout<<"Cannot be partitioned.";

    return 0;
}