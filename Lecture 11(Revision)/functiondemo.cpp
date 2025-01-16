#include <iostream>
using namespace std;

int addition(int x, int y){
    int result = x + y;
    return result;
}

void fun(string name){
    cout<<"Are you having fun "<<name<<" ?"<<endl;
}

int main(){
    
    fun("Suraj");
    int response = addition(9,8);
    cout<<response;
    return 0;
}