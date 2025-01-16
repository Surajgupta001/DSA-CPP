#include <iostream>
using namespace std;
int main(){
    
    cout<<"1st matrix order: "<<endl;
    int m;
    cout<<"Enter the rows of 1st matrix: ";
    cin>>m;
    int n;
    cout<<"Enter the column of 1st matrix: ";
    cin>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // printing original array
    cout<<"Original matrix are: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int brr[n][m];
    // printing input;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            brr[i][j] = arr[j][i];
        }
    }
    // printing output/brr
    cout<<"Transpose matrix are: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}