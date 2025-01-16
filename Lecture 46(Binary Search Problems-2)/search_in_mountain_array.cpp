#include <iostream>
using namespace std;
#include <vector>

int PeakInMOuntainArray(vector<int> &v, int low, int high){
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(v[mid] > v[mid-1]){
            // increasing curve
            ans = max(ans,mid);
            low =  mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Peak index is: "<<PeakInMOuntainArray(v,1,v.size()-1)<<endl;

    return 0;
}