#include <iostream>
using namespace std;
int main(){
    int day;
    cout<<"Enter the day's name: ";
    cin>>day;
    switch(day){
        case 1:
        cout<<"Monday"<<endl;
        break;

        case 2:
        cout<<"Tuesday"<<endl;
        break;

        case 3:
        cout<<"Wednesday"<<endl;
        break;

        case 4:
        cout<<"Thrusday"<<endl;
        break;

        case 5:
        cout<<"Friday"<<endl;
        break;

        case 6:
        cout<<"Satarday"<<endl;
        break;

        case 7:
        cout<<"Sunday"<<endl;
        break;

        default :
        cout<<"Enter valid date"<<endl;
    }
    return 0;
}