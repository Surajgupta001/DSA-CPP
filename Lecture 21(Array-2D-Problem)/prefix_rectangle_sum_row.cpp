/*
Q. Given a matrix 'a' of dimension nXm and 2 coordinate (l1,r1) and (l2,r2).Return the sum of the rectangle from (l1,r1) to  (l2,r2).
*/ 

// Method 1: Brute Force.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rectangle_sum(vector<vector<int>> &matrix,int l1, int r1, int l2, int r2){

    int sum = 0;
    // input prefix sum array row-wise
    for(int i=0;i<matrix.size();i++){
        for(int j=1;j<matrix[0].size();j++){
            matrix[i][j] += matrix[i][j-1];  
        }
    }

    // printing prefix sum array row wise
    cout<<"Printed prefix sum of 2D Array are: "<<endl;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=l1;i<=l2;i++){
        if(r1!=0){
        sum += matrix[i][r2]-matrix[i][r1-1];
        }
        else{
            // matrix[i][r1-1] = 0
            sum = sum + matrix[i][r2];
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
    // user input
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


    // Display output
    cout<<"Printing 2D Arrays are: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int sum = rectangle_sum(matrix,l1,r1,l2,r2);
    cout<<"sum of prefix 2D Array are: "<<sum;
    return 0;
}