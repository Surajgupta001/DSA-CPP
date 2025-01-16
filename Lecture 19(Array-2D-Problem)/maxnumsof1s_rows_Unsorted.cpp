#include <iostream>
using namespace std;
int main(){
    
    cout<<"Enter the matrix: ";
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

    int max_count = 0;
    int max_index = -1;

    for(int i=0;i<m;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1)
            count++;
        }
        if(max_count < count){
            max_count = count;
            max_index = i;
        }
        cout<<endl;
    }

    cout<<"Maxcount is: "<<max_count<<endl;
    cout<<"Max_index is: "<<max_index;

    return 0;
}