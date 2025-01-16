/*
An encoded string(s) is given, and the task is to decode it. The encoding pattern is that the occurence of the string is guven at the starting and each string is encloded by square brackets.

INPUT 1: 1[b]
OUTPUT: b

INPUT 2: 3[b2[ca]]
OUTPUT: bcacabcacabcaca
*/ 

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string decodedString(string str){

    /*
    Space: O(n);
    Time: O(string.size())
    */ 

    string result = "";

    // traversing the encoded string
    for(int i=0;i<str.size();i++){
        if(str[i] != ']'){
            result.push_back(str[i]);
        }
        else{
            // extract string from result
            string str = " ";
            while(!result.empty() && result.back() != '['){
                str.push_back(result.back());
                result.pop_back();
            }

            // reversing the string
            reverse(str.begin(),str.end());

            // extract last char result which is [
            result.pop_back();

            // extract num from result
            string num = " ";
            while(!result.empty() && (result.back() >= '0' && result.back() <= '9')){
               num.push_back(result.back());
               result.pop_back(); 
            }

            // reversing the  num string
            reverse(num.begin(),num.end());

            // convert string to integer
            int int_num = stoi(num);

            // inserting string in result int_num times
            while(int_num){
                result += str;
                int_num--;
            }

        } 
    }
    return result;
}
int main(){

    string str;
    cout<<"Enter a string: ";
    cin>>str;

    cout<<decodedString(str)<<endl;

    return 0;
}