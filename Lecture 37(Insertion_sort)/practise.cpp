#include <iostream>
using namespace std;
#include <vector>

void insertionSort(vector<int> &v){
    int n = v.size();

    for(int i=0;i<n;i++){
        int current_element = v[i];
        int j = i-1;

        while(j>=0 && v[j]>current_element){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current_element;
    }
    return;
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<"Unsorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    
    cout<<endl;

    insertionSort(v);

    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}