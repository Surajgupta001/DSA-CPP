#include<iostream>
#include<string>
using namespace std;

string minMaxLengthWords(string str, string &minWord, string &maxWord){

    int i = 0; // starting pointer
    int j = 0; // ending pointer
  
  
    int minLength = str.size();
    int min_start_index = 0;
    int maxLength = 0;
    int max_start_index = 0;

    // Loop while input string is not empty
    while (j <= str.size()) {
        if (j < str.size() && str[j] != ' ') j++;

        else{
            // end of a word
            // find curr word length
            int current_length = j - i;

            if (current_length < minLength) {
                minLength = current_length;
                min_start_index = i;
            }
            if (current_length > maxLength){
                maxLength = current_length;
                max_start_index = i;
            }
            j++;
            i = j;
        }
    }
    // store minimum and maximum length words
    minWord = str.substr(min_start_index, minLength);
    maxWord = str.substr(max_start_index, maxLength); 
}
int main(){

    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    string minWord, maxWord;
    minMaxLengthWords(str, minWord, maxWord);
    
    cout<<"Minimum length word: "<<minWord<<endl;
    cout<<"Maximum length word: "<<maxWord<<endl;
    
    return 0;
}