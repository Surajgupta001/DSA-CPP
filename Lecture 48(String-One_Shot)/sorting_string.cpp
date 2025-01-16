/*
sorting string means: Lexicographical Order.
---> using count sorting
*/ 

#include <iostream>
using namespace std;
#include <vector>
#include <string>

string countSort(string str){
    /*
    * Time: O(size of string).
    * Space: O(26) ==> constant.
    */ 
    vector<int>freq(26,0);
    // Storing frequency of every character in string
    for(int i=0;i<str.size();i++){
        int index = str[i]-'a';
        freq[index]++;
    }

    // Creating our sorted string
    int j=0;
    for(int i=0;i<26;i++){
        while(freq[i]--){
            str[j++] = i + 'a';
        }
    }
    return str;

}
int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout<<"Sorted String or Lexicographical Order: "<<countSort(str)<<endl;
    return 0;
}
