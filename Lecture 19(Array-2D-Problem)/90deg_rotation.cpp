#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of row/column: ";
    cin>>n; // r*c total element
    cout<<"Enter the all the element: "<<endl;
    int arr[n][n];
    // input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // transpose
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    cout<<endl;
    cout<<"Transpose of matrix: "<<endl;
    // transpose output
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // rotate
    for(int i=0;i<n;i++){
        int j=0;
        int k=n-1;
        while(j<k){
            // swap arr[i][j] and arr[i][k]
            int temp = arr[i][j];
            arr[i][j] = arr[i][k];
            arr[i][k] = temp;
            j++;
            k--;
        }
    }
    cout<<endl;
    // output of rotated matrix
    cout<<"90 degree rotated matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}