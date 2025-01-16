/*
Check whether given square matrix is symmetric or not.
*/ 

// 2 3 6
// 3 4 5
// 6 5 9
// yes it symmetric matrix.

#include <iostream>
using namespace std;
int main(){
    
    int r;
    cout<<"Enter the size of rows: ";
    cin>>r;

    int c;
    cout<<"Enter the size of columns: ";
    cin>>c;

    // 2D array input
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    // 2D array printing
    printf("Printing 2D Array: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    // Transpose matrix input
    printf("Transpose matrix: \n");
    int brr[c][r];
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            brr[j][i]=arr[j][i];
        }
    }

    // transpose matrix printing
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<brr[j][i]<<" ";
        }
        cout<<endl;
    }

    // check symmetric or not unsymmetric i.e. check original matrix = transpose matrix.
    int count = 0;
    for(int i=0;i<r;i++){
        for(int j=0;i<c;j++){
            if(arr[i][j]!=brr[i][j]){
                count++;
                break;
            }
        }
    }
    if(count==0){
        printf("The given matrix is Symmetric.");
    }
    else{
        printf("The given matrix is Unsymmetric.");
    }
    return 0;
}