#include <iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter no. of rows of 1st matrix: ";
    cin>>m;
    int n;
    cout<<"Enter no. of column of 1st matrix: ";
    cin>>n;
    int arr[m][n];
    cout<<"Enter element of 1st matrix: "<<endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }
    // wave print
    cout<<endl;
    int min_row = 0;
    int max_row = m-1;
    int min_column = 0;
    int max_columnn = n-1;
    int total_element = m*n;
    int count = 0;
    while(count<total_element){
        // print the minimum row;
        for(int j=min_column;j<=max_columnn;j++){
            cout<<arr[min_row][j]<<" ";
            count++;
        }
        min_row++;
        if(count>=total_element)
        break;
        // print the maximun column;
        for(int i=min_row;i<=max_row;i++){
            cout<<arr[i][max_columnn]<<" ";
            count++;
        }
        max_columnn--;
        if(count>=total_element)
        break;
        // print the maximum row;
        for(int j=max_columnn;j>=min_column;j--){
            cout<<arr[max_row][j]<<" ";
            count++;
        }
        max_row--;
        if(count>=total_element)
        break;
        // print the minimum column;
        for(int i=max_row;i>=min_row;i--){
            cout<<arr[i][min_column]<<" ";
            count++;
        }
        min_column++;
        if(count>=total_element)
        break;
    }
    return 0;
}