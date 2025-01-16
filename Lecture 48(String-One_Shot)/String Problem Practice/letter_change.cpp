#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string letterChange(string str){
    // variable to store ASCII value of character.
    char char_code;

    for(int i=0;i<str.size();i++){
        char_code = int(str[i]); // Get ASCII value of the character.

        // FOR LOWERCASE
        // check if character is 'z', then change it to 'a' 
        if(char_code == 122){
            str[i] = char(97);
        }
        // FOR UPPERCASE
        // // check if character is 'Z', then change it to 'A' 
        else if(char_code == 90){
            str[i] = char (65);
        }
        // check lowercase or uppercase
        else if(char_code >= 65 && char_code <=90 || char_code >= 97 && char_code <= 122){
            str[i] = char(char_code + 1);
        }
    }
    return str;
}
int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    
    cout<<"Changed String are: "<<letterChange(str)<<endl;

    return 0;
} 