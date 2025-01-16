#include <iostream>
using namespace std;
int main(){
    int x = 10;
    float y = 7.5;
    
    // create a pointer that can store address of x.
    // As x is an integer variable, so we need a pointer,
    // that can store address of integer type.
    
    int *ptr = &x;
    cout<<"Value present at the adress stored in ptr: "<<*ptr<<endl; // dereference
    cout<<"Address stored inside ptr: "<<ptr;

    cout<<endl;
    cout<<endl;

    // create a pointer that can store address of x.
    // As y is an float variable, so we need a pointer,
    // that can store address of float type.

    float *ptr1 = &y;
    cout<<"Value present at the adress stored in ptr: "<<*ptr1<<endl; // dereference
    cout<<"Address stored inside ptr: "<<ptr1;

    return 0;
}