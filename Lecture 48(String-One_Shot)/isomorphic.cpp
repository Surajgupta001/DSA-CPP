#include <iostream>
#include<vector>
#include <string>
using namespace std;

bool isIsomorphic(string str1, string str2){
    /*
    * Time: O(size of string)
    * Space: O(1)
    */
    vector<int>v1(128,-1);
    vector<int>v2(128,-1);
    
    if(str1.size() != str2.size()){ // if string size does not match
        return false;
    }

    for(int i=0;i<str1.size();i++){
        if(v1[str1[i]] != v2[str2[i]]){ // checking if value of chacter at index i match in box vector
            return false;
        }
        v1[str1[i]] = v2[str2[i]] = i; // storing string position in vector for character at index i
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

    if(isIsomorphic(str1,str2)){
        cout<<"String are Isomorphic"<<endl;
    }
    else{
        cout<<"string are not Isomorphic"<<endl;
    }
    return 0;
}