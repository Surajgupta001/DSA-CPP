#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void bucketSort(float arr[], int size){
    vector<vector<float>> bucket(size, vector<float> ());
    // step 1:

    // finding range
    float max_element = arr[0];
    float min_element = arr[0];
    
    for(int i=0;i<size;i++){
        max_element=max(max_element,arr[i]);
        min_element=min(min_element,arr[i]);
    }
    float range = (max_element-min_element)/size;

    // step 2: inserting element into bucket
    for(int i=0;i<size;i++){
        int index = (arr[i]-min_element)/range;
        // boundry element
        float difference = (arr[i]-min_element)/range-index;
        if(difference==0 && arr[i]!=min_element){
            bucket[index-1].push_back(arr[i]);
        }
        else{
            bucket[index].push_back(arr[i]);
        }
    }

    // step3: sorting individual bucket
    for(int i=0;i<size;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    // step4: combining element fron bucket
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }
}

int main(){

    float arr[] = {6.13,8.45,0.12,1.89,4.75,2.63,7.85,10.39};
    
    int size = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr,size);

    cout<<"Bucket sorted array: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}