/*
Check if we can partition the array into two subarray with equal sum.More formally,check that the prefix
sum of a part of  the array is equal to the suffix sum of rest of the array.
*/ 

/*
ALOGRITHM TO SOLVE THIS TYPE OF PROBLEM
// prefix_sum i = sum(a0.....ai);
// suffix_sum i+1 = sum(ai+1......an-1);
// suffix_sum i+1 = total_sum - prefix_sum i; 
*/ 

#include <iostream>
using namespace std;
#include <vector>

bool Checkprefix_sumSuffix_sum(vector<int> &v){
    int total_sum = 0;
    for(int i=0;i<v.size();i++){
        total_sum += v[i];
    }
    int prefix_sum = 0;
    for(int i=0;i<v.size();i++){
        prefix_sum += v[i];

        int suffix_sum;
        suffix_sum = total_sum - prefix_sum;

        if(suffix_sum == prefix_sum){
            return true; // true means return 1.
        }
    }
    return false; //  false means return 0.
}


int main(){

    int n;
    cout<<"Enter the sise of array: ";
    cin>>n;

    vector<int>v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    
    cout<<Checkprefix_sumSuffix_sum(v)<<endl;

    return 0;
}