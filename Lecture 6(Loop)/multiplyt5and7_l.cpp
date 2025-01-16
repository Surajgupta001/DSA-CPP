#include <iostream>
using namespace std;
int main(){
    int i=5;
    for(int i=5;;i+=5){
        if(i%7==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}