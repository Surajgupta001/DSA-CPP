#include <iostream>
using namespace std;
#include <set>
#include <string>
#include <algorithm>

bool checkAllAlphabet(string str){
    if(str.size()<26){
        return false;
    }
    transform(str.begin(),str.end(),str.begin(),::tolower);
    
    set<char>alphabets;
    for(auto ch:str){
        alphabets.insert(ch);
    }

    return (alphabets.size() == 26);

}
int main(){

    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    if(checkAllAlphabet(str)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}