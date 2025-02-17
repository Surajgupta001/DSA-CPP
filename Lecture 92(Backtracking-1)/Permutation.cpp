/*
You are given a string consisting of small alphabets. Consider no repetitation in the character. Print all possible permutations of given strings.
*/ 
#include <iostream>
#include <string>
using namespace std;

void permutations(string input, string output){
    if(input.length() == 0){
        cout<<output<<endl;
        return;
    }
    for(int i=0; i<input.size(); i++){
        char ch = input[i];
        string left = input.substr(0, i);
        string right = input.substr(i+1);
        string ros = left + right; // ros --> rest of string
        permutations(ros, output + ch);
    }
}

int main(){
    
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    
    permutations(input, "");

    return 0;
}