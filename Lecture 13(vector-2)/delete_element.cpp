#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int>v;
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }

    // to delete element
    v.pop_back();
    
    // to insert loop
    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}