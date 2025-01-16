#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

void countSort(vector<int> &v, int position){
    int n = v.size();
    // create frequency array
    vector<int>frequency(10,0);
    for(int i=0;i<n;i++){
        frequency[(v[i]/position)%10]++;
    }

    // cumulative frequency
    for(int i=1;i<10;i++){
        frequency[i]+=frequency[i-1];
    }

    // ans array
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--frequency[(v[i]/position)%10]]=v[i];
    }

    // copy back the ans to original array
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }

    return;
}

void radixSort(vector<int> &v){
    int max_element = INT_MIN;
    for(auto x:v){
        max_element = max(x,max_element);
    }

    for(int position = 1;max_element/position>0;position*=10){
        countSort(v,position);
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

    radixSort(v);

    cout<<"Radix Sorted Array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}