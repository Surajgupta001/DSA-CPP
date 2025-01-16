/*
Count the number of element strictly greater than value x;
*/
#include <iostream>
#include <vector>
using namespace std;

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

    int count = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]>x){
            count++;
        }
    }
    cout<<"No. of greater element of the array of given 'x' is: "<<count<<endl;
    return 0;
}