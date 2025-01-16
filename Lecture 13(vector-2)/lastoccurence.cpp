/*
Find the last occurrences/position of an array element x in given array.
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

    int x;
    cout<<"Enter x: ";
    cin>>x;

    int index = -1;

    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            index = i;
        }
    }

    for(int i=v.size()-1;i<=0;i--){
        if(v[i]==x){
            index = i;
            break;
        }
    }

    cout<<"Last index/occurrences of this 'x' is: "<<index<<endl;

    return 0;
}