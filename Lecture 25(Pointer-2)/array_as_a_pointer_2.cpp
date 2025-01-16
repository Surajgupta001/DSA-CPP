#include <iostream>
using namespace std;
int main(){
    int arr[3] = {1 ,2 ,3};
    int (*ptr)[3] = &arr;
    cout<<ptr<<" "<<*ptr<<" "<<*arr<<endl;
    return 0;
}