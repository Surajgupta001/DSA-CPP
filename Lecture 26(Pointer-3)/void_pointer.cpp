#include <iostream>
using namespace std;
int main(){
    float f = 10.2;
    int x = 10;
    void *ptr = &f;
    ptr = &x;

    int *integer_pointer = (int *)ptr;
    cout<<*integer_pointer<<endl;
    return 0;
}