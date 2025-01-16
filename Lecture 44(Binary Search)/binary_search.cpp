#include <iostream>
using namespace std;
#include <vector>

int binarySearch(vector<int> &v, int target){
    // define search space
    int low = 0; // start of search space
    int high = v.size()-1; // end of the search space

    while(low<=high){
        // calculate mid point for the search space
        // int mid = (low + high)/2;
        int mid = low + (high-low)/2; // modified mid to tackle overflow

        if(v[mid] == target) return mid;

        else if(v[mid] < target){
            // discard the left of mid
            low = mid + 1;
        }
        else{
            // discard the right of mid
            high = mid - 1;
        }
    }
    return -1;
}

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int target;
    cout<<"Enter the target value: ";
    cin>>target;

    cout<<"Target value is present at index : "<<binarySearch(v,target);

    return 0;
}