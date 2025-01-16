/*
Sort an array consisting of only 0s and 1s.
*/

#include <iostream>
using namespace std;
#include <vector>

void SortZerosAnsOnes(vector<int> &v){
    int Zeros_count = 0;
    // counting zeros
    for(int ele:v){
        if(ele==0){
            Zeros_count++;
        }
    }
    for(int i=0;i<v.size();i++){
        if(i<Zeros_count){
            v[i]=0;
        }
        else{
            v[i]=1;
        }
    }
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    vector<int>v;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    cout<<"Sorted 0 and 1 array are: ";

    SortZerosAnsOnes(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
        //cout<<endl;
    }

    return 0;
}