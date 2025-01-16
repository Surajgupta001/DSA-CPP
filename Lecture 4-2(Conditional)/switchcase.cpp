#include <iostream>
using namespace std;
int main(){
    char alphabet;
    cout<<"Enter a alphabet: ";
    cin>>alphabet;
    switch(alphabet){
        case 'a':
        cout<<"It ia vowel: "<<endl;
        break;
        case 'e':
        cout<<"It ia vowel: "<<endl;
        break;
        case 'i':
        cout<<"It ia vowel: "<<endl;
        break;
        case 'o':
        cout<<"It ia vowel: "<<endl;
        break;
        case 'u':
        cout<<"It ia vowel: "<<endl;
        break;
        default:
        cout<<"It is a consonant: "<<endl;
    }
    return 0;
}