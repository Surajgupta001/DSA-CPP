/*
Sort an array consisting of only 0s and 1s.
*/ 

#include <iostream>
using namespace std;
#include <vector>

void SortZerosAnsOnes(vector<int> &v){

    int left_ptr = 0;
    int right_ptr = v.size()-1;

    while(left_ptr < right_ptr){
        if(v[left_ptr] == 1 && v[right_ptr] == 0){
            v[left_ptr++] = 0;
            v[right_ptr--] = 1;

        }
        if(v[left_ptr] == 0){
            left_ptr++;
        }
        if(v[right_ptr] == 1){
            right_ptr--;
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
    }

    return 0;
}