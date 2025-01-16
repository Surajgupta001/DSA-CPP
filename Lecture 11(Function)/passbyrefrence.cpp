#include <iostream>
using namespace std;
int main(){
    int p = 5;
    int &q = p; // pass by refence;
    q++;
    cout<<p<<endl;

    cout<<&p<<endl; // printing address;
    cout<<&q<<endl; //  printing address;

    return 0;
}