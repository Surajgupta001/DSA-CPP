#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int result = 0;
    for(int i=0;i<n;i++){
        result = result ^ v[i];
    }
    cout<<"Unique elements in the array is: "<<result<<endl;
    
    return 0;
}