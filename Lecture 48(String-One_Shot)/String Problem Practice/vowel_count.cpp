#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int vowelCount(string str){

    int count = 0;

    for(int i=0;i<int(str.size());i++){
        // checking for lowercase vower
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            count++;
        }
        // checking for uppercase vower
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            count++;
        }
    }
    return count;
}
int main(){

    string str;
    cout<<"Enter a string: ";
    getline(cin,str);

    cout<<"No. of vowels is: "<<vowelCount(str)<<endl;    
    return 0;
}