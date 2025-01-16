#include <iostream>
using namespace std;
int main(){
    int arr[2] = {4,7};
    int *ptr = &arr[0];

    // 1st way;
    // cout<<ptr<<" "<<*ptr<<endl;
    // cout<<ptr+1<<" "<<*(ptr+1)<<endl;

    // 2nd way;
    cout<<ptr<<" "<<*ptr<<endl;
    cout<<*ptr++<<endl;
    cout<<arr[0]<<" "<<arr[1]<<endl;
    cout<<ptr<<" "<<*ptr<<endl;

    return 0;
}
