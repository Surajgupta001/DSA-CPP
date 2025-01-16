#include <iostream>
using namespace std;
int main(){
    int *ptr = NULL;
    {
        int a = 10;
        ptr = &a;
    }
    cout<<ptr;
}