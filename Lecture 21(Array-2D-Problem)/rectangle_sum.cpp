/*
Q. Given a matrix 'a' of dimension nXm and 2 coordinate (l1,r1) and (l2,r2).Return the sum of the rectangle from (l1,r1) to  (l2,r2).
*/ 

// Method 1: Brute Force.

#include <iostream>
#include <vector>
using namespace std;

int rectangle_sum(vector<vector<int>> &matrix,int l1, int r1, int l2, int r2){
    int sum = 0;
    for(int i=l1;i<=l2;i++){
        for(int j=r1;j<=r2;j++){
            sum = sum + matrix[i][j];
        }
    }
    return sum;
}
int main(){
    int m;
    cout<<"Enter the size of row: ";
    cin>>m;

    int n;
    cout<<"Enter the size of column: ";
    cin>>n;

    cout<<"Enter the all element of matrix: "<<endl;

    vector<vector<int>>matrix(m,vector<int>(n));
    // input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    int l1;
    cout<<"Enter the l1 coordinate of matrix: ";
    cin>>l1;

    int r1;
    cout<<"Enter the r1 coordinate of matrix: ";
    cin>>r1;

    int l2;
    cout<<"Enter the l2 coordinate of matrix: ";
    cin>>l2;

    int r2;
    cout<<"Enter the r2 coordinate of matrix: ";
    cin>>r2;


    // output
    cout<<"Printing 2D Arrays are: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Coordinate rectangle sum are: ";
    int sum = rectangle_sum(matrix,l1,r1,l2,r2);
    cout<<sum<<endl;
    return 0;
}