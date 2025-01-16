// While loop;
#include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the integer: ";
    cin>>num;
    int sum=0;
    int i=0; // loop variable
    while(i<=num){ //condition
        sum+=i;
        i++; // updating loop variable
    }
    cout<<sum<<endl;
    return 0;
}