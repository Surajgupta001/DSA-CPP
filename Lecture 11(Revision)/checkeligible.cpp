#include <iostream>
using namespace std;
bool checkeligible(int age , int limit){
    if(age>=limit){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int age;
    cout<<"Enter the age: ";
    cin>>age;

int limit;
    cout<<"Enter the limit: ";
    cin>>limit;

    int response =  checkeligible(age,limit);
    if(response){
        cout<<"Yes, the current person is eligible to vote";
    }
    else{
        cout<<"No, the current person is not eligible to vote";
    }

    return 0;
}