/*
Count the number of occurrences of a particular element x; 
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }

    int element;
    cout<<"Enter element to check occurrences: ";
    cin>>element;

    int occurences = 0;
    
    for(int ele:v){
        if(ele==element){
            occurences++;
        }
    }
    cout<<"Occurrences of particular element is: "<<occurences<<endl;
    return 0;
}