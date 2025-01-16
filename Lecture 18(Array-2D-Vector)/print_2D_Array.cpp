#include <iostream>
using namespace std;
#include <vector>

int main(){

    int m;
    cout<<"Enter the size of rows: ";
    cin>>m;

    int n;
    cout<<"Enter the size of columns: ";
    cin>>n;

    // decelaration of 2D Array in vector.
    vector<vector<int>>v(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    
    cout<<"2D Array: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}