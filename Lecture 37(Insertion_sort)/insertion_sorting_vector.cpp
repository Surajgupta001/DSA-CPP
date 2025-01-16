#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void InsertionSort(vector<int> &v){
    int n = v.size();
    for(int i=1;i<n;i++){
        int current_element = v[i];
        // find the currect position for our current element
        int j = i-1;
        while(j>=0 && v[j]>current_element){
            v[j+1] = v[j];
            j--;
        }
        // insert current element
        v[j+1] = current_element;
    }
}
int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter all the element of array: "<<endl;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Unsorted Array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    InsertionSort(v);

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}