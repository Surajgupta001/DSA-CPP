#include <iostream>
using namespace std;
#include <string>

int countWord(string str){
    
    int count = 0;
    
    for(int i=0;i<str.size();i++){
        if(str[i] == ' ') // checking for space to count word
        count++;
    }
    return count + 1;
}
int main(){
    
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    cout<<"No. of words: "<<countWord(str)<<endl;

    return 0;
}