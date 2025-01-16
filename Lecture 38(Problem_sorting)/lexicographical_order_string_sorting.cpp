/*
Give an array of names of the fruits, you are supposed to sort it in lexicographical order using the selection sort.

INPUT : ["papya","lime","watermelon","apple","mango","kiwi"].

OUTPUT : ["apple","kiwi","lime","mango","papaya","watermelon"].
*/ 

#include <iostream>
using namespace std;
#include <vector>
#include <string.h>

void selectionSort(char fruit[][60], int n){
    for(int i=0;i<n-1;i++){
        // finding the min element
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(strcmp(fruit[min_index],fruit[j])>0){ // strcmp --> compare two string and return an integer value.
                min_index = j;
            }
        }
        // place the min element at the beginning
        if(i!=min_index){
            swap(fruit[i],fruit[min_index]);
        }
    }
    return;
}

int main(){
    
    char fruit[][60] = {"papya","lime","watermelon","apple","mango","kiwi"};

    int n = sizeof(fruit)/sizeof(fruit[0]);

    selectionSort(fruit,n);

    for(int i=0;i<n;i++){
        cout<<fruit[i]<<" ";
    }
    cout<<endl;
    return 0;
}