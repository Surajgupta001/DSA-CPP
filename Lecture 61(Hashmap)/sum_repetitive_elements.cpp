/*
You are given an integer n, representin the number of elemenys.Then, you will be given n element. You have to return the sim of repetitive elements i.e. element that appear more than onr time.

INPUT: n = 7;
Elements: [1,1,2,1,3,3,3]

OUTPUT: 4
Explanation: The repetitive element are 1,3 and the sum is 4.
*/ 
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size of vector: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    map<int,int>m;
    for(int i=0;i<n;i++){
        // storing frequency of every element in input array
        m[v[i]]++;
    }

    int sum = 0;
    // finding sum of repetitive elements
    // pair - element, frequency
    for(auto pair:m){
        if(pair.second > 1){ // element is repetitive.
            sum+=pair.first;
        }
    }
    
    cout<<"Repetitive Element sum: "<<sum<<endl;

    return 0;
}