/*
Q. Given Q quaries, check if the given number is present number in the array or not.
Note: Value of all the element in the array is less than 10 to power 5.
*/ 

#include <iostream>
using namespace std;
#include <vector>

int main(){
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    const int N = 1e5 + 10;
    
    vector<int>frequency(N,0);
    for(int i=0;i<n;i++){
        frequency[v[i]]++;
    }

    int query;
    cout<<"Enter queries: ";
    cin>>query;

    while(query--){
        int query_element;
        cin>>query_element;
        cout<<frequency[query_element]<<endl;
    }
}