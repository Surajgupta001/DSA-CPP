#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 0 1 1 1
// 0 0 0 1
// 0 0 1 1

// maxOnes = min_value
// maxOnesRow = -1
// columns = 4
// numberOfOnes = columns - j => 4 - 1 = 3

int leftMostOneRow(vector<vector<int>> &v){
    int left_Most_One = -1;
    int max_One_Row = -1;

    //  finding leftmost ones in 0th row;

    // for(int j=v[0].size()-1;j>=0;j--){
    //     if(v[0][j]==1){
    //         left_Most_One = j;
    //     }
    //     else{
    //         break;
    //     }
    // }

    int j = v[0].size()-1;
    while(j>=0 && v[0][j]==1){
        left_Most_One = j;
        max_One_Row = 0;
        j--;
    }
    // Check in rest of the rows if we can find a one left to the left_most_one.
    for(int i=1;i<v.size();i++){
        while(j>=0 &&  v[i][j]==1){
            left_Most_One = j;
            j--;
            max_One_Row = i;
        }
    }
}

int maximumOnesrows(vector<vector<int>> &v){
    int maxOnes = INT_MIN;
    int maxOnesRow = -1; // index
    int columns = v[0].size();

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
                int numberOfOnes = columns - j;
                if(numberOfOnes > maxOnes){
                    maxOnes = numberOfOnes;
                    maxOnesRow = i;
                }
                break;
            }
        }
    }
    return maxOnesRow;
}

int main(){

    cout<<"Enter the matrix: "<<endl;
    int m;
    cout<<"Enter the size of rows: ";
    cin>>m;
    int n;
    cout<<"Enter the size of column: ";
    cin>>n;

    vector<vector<int>>vec(n,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }

    cout<<"Maximum numbers of 1s is ith rows: ";
    int result = maximumOnesrows(vec);
    cout<<result<<endl;

    return 0;
}