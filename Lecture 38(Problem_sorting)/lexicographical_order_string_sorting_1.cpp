#include <iostream>
using namespace std;
#include <string.h>
int main(){

    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter the words: "<<endl;
    
    string str[n];
    for(int i=0;i<n;i++){
        getline(cin,str[i]);
        // getline --> Allow accepting and reading single multiple line string from the input stream.
    }
    
    cout<<endl;
    // selection sort
    for(int i=0;i<n-1;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if((str[j]<str[min_index])){
                min_index = j;
            }
        }
        // place the min element at the beginning.
        if(1!=min_index){
            string temp = str[min_index];
            str[min_index] = str[i];
            str[i] = temp;
        }
    }
    
    cout<<"Sorted lexicographical order: "<<endl;
    for(int i=0;i<n;i++){
        cout<<str[i]<<" ";
    }
    return 0;
}