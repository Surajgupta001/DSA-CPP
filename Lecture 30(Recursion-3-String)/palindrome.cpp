#include <iostream>
using namespace std;

bool function(int num, int *temp){
    if(num >= 0 and num <=9){
        int last_digitOfTemp = (*temp)%10;
        (*temp) /= 10;
        return (num == last_digitOfTemp);
    }
    bool result = (function(num/10,temp) && (num%10)==((*temp)%10));
    (*temp) /= 10;
}
int main(){
    int num = 131;
    int anothernum = num;
    int *temp = &anothernum;
    cout<<function(num,temp);
    return 0; 
}