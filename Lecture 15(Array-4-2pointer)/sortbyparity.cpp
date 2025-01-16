/*
Given an array of integer 'a', move all the the even integer at the beginning of the array followed by all the odd integer.The relative order of odd or even integer does not matter.Return any array that satisfies the condition.  
*/ 
#include <iostream>
using namespace std;
#include <vector>

void SortByParity(vector<int> &v){

    int left_ptr = 0;
    int right_ptr = v.size()-1;

    while(left_ptr < right_ptr){
        if(v[left_ptr] %2 == 1 && v[right_ptr] %2 == 0){
            swap(v[left_ptr],v[right_ptr]);
        }
        if(v[left_ptr] %2 == 0){
            left_ptr++;
        }
        if(v[right_ptr] %2 == 1){
            right_ptr--;
        }
    }
    return ;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    SortByParity(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}