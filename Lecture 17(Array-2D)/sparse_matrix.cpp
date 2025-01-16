#include <iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter the size of rows: ";
    cin>>m;

    int n;
    cout<<"Enter the size of columns: ";
    cin>>n;

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Printing 2D Array : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int Zero_count = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0){
                Zero_count++;
            }
        }
    }

    int Non_ZeroCount = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] != 0){
                Non_ZeroCount++;
            }
        }
    }
    if(Zero_count>((m*n)/2)){
        cout<<"The given matrix is sparse matrix."<<endl;
    }
    else{
        cout<<"The given matrix is not sparse matrix."<<endl;
        cout<<"There are number of zeros: "<<Zero_count<<endl;
    }

    cout<<"There are number of Non Zero Count: "<<Non_ZeroCount<<endl;

    return 0;
}