#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string str1, string str2){

    /*
    Time: O(size of string).
    Space: O(1)
    */ 
    
    // create frequency array
    vector<int>freq(26,0);

    // if size are different for str1, str2 then return false
    if(str1.size()!=str2.size()){
        return false;
    }

    // store frequency of chacter in str1 and str2
    for(int i=0;i<str1.size();i++){
        freq[str1[i]-'a']++; // for str1, we are incrementing freq of char.
        freq[str2[i]-'a']--; // for str2, we are decrementing freq of char.
    }

    // checking of freq of every character is 0
    for(int i=0;i<26;i++){
        if(freq[i]!=0){ // not anagram
            return false;
        }
    }
    return true;
}
int main(){

    string str1;
    cout<<"Enter a 1st string: ";
    cin>>str1;

    string str2;
    cout<<"Enter a 2nd string: ";
    cin>>str2;

    if(isAnagram(str1,str2)){
        cout<<"String are anagrams"<<endl;
    }
    else{
        cout<<"string are not anagram"<<endl;
    }
    return 0;
}