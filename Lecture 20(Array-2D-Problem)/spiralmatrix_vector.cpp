#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void spiral_order(vector<vector<int>> &matrix){
    
    int left = 0;
    int right = matrix[0].size()-1;
    int top = 0;
    int bottom = matrix.size()-1;

    int direction = 0;

    while(left<=right && top<=bottom){
        // left --> right
        if(direction == 0){
            for(int column=left;column<=right;column++){
                cout<<matrix[top][column]<<" ";
            }
            top++;
        }
        // top --> bottom
        else if(direction == 1){
            for(int row=top;row<=bottom;row++){
                cout<<matrix[row][right]<<" ";
            }
            right --;
        }
        // right ---> left
        else if(direction == 2){
            for( int column=right;column>=left;column--){
                cout<<matrix[bottom][column]<<" ";
            }
            bottom--;
        }
        // bottom --> top
        else{
            for(int row=bottom;row>=top;row--){
                cout<<matrix[row][left]<<" ";
            }
            left++;
        }
        direction = (direction+1)%4;
        // 0,1,2,3

    }
}

int main(){
    int m;
    cout<<"Enter the number of rows matrix: ";
    cin>>m;

    int n;
    cout<<"Enter the number of rows matrix: ";
    cin>>n;

    cout<<"Enter the all elements of matrix: "<<endl;

    vector<vector<int>> matrix(n,vector<int> (m));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    // print original matrix
    cout<<"Original matrix are: "<<endl;
      for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Spiral mmatrix are : "<<endl;
    spiral_order(matrix);

    return 0;
}