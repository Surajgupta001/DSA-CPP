/*
Check whether two string are isomorphic of each other.Return if they are else return false.
*/ 
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool checkNoOneToManyMapping(string str1, string str2){

    unordered_map<char,int> m;

    for(int i=0;i<str1.size();i++){
        if(m.find(str1[i]) != m.end()){
            if(m[str1[i]] != str2[i]){
                return false;
            }
        }
        else{
            m[str1[i]] = str2[i];
        }
    }
}

bool isIsomorphic(string str1, string str2){
    
    if(str1.size() != str2.size()){
        return false;
    }

    // checking one-to-many mapping from str1 to str2
    bool str1TOstr2 = checkNoOneToManyMapping(str1,str2);
    
    // checking one-to-many mapping from str2 to str1
    bool str2TOstr1 = checkNoOneToManyMapping(str2,str1);

    return str1TOstr2 && str2TOstr1;

}
int main(){

    string str1;
    cout<<"Enter a 1st string: ";
    getline(cin,str1);

    string str2;
    cout<<"Enter the 2nd string: ";
    getline(cin,str2);

    if(isIsomorphic(str1,str2)){
        cout<<"String are Isomorphic"<<endl;
    }
    else{
        cout<<"string are not Isomorphic"<<endl;
    }

    return 0;
}
