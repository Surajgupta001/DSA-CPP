#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

void countSort(vector<int> &v){

    int n=v.size();
    
    // finding the maximum element
    int max_element = INT_MIN;
    for(int i=0;i<n;i++){
        max_element = max(v[i],max_element);
    }

    // create the frequency array
    vector<int> frequency(max_element+1,0);
    for(int i=0;i<n;i++){
        frequency[v[i]]++;
    }

    // calculate cumulative frequency
    for(int i=1;i<=max_element;i++){
        frequency[i]+=frequency[i-1];
    }

    // calculate the sorted array
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--frequency[v[i]]]=v[i];
    }

    // copy back the ans to original array
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Unsorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    countSort(v);

    cout<<"Count Sorted Array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}