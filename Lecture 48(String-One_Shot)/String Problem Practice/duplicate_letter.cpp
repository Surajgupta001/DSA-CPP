#include <iostream>
using namespace std;
#include <string>

string duplicateLetter(string str, string &str1, string &str2){

    int count_1 = 0;
    int count_2 = 0;
    
    for(int i=0;i<str.size();i++){
        if(str[i] == str1[0]) count_1++;
        if(str[i] == str2[0]) count_2++;
    }
    if(count_1 == count_2){
        return "True";
    }
    else{
        return "False";
    }
}
int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;

    string str1;
    cout<<"Enter a 1st character: ";
    cin>>str1;

    string str2;
    cout<<"Enter a 2nd character: ";
    cin>>str2;

    cout<<duplicateLetter(str,str1,str2)<<endl;

    return 0;
}