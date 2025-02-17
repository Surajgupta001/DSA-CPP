#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void permutations(string &str, int i){
    if(i == str.length() - 1){
        cout<<str<< endl;
        return;
    }
    unordered_set<char>s;
    for(int idx = i; idx < str.length(); idx++){
        if(s.count(str[idx])) continue;
        s.insert(str[idx]);
        
        swap(str[idx], str[i]);
        permutations(str, i + 1);
        swap(str[idx], str[i]); 
    }
}

int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;
    
    permutations(str, 0);
    
    return 0;
}