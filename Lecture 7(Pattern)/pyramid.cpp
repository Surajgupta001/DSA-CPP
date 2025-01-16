/*
   *
  ***
 *****
*******
*/
#include <iostream>
using namespace std;
int main(){
    int row; // user input
    cin>>row;
    for(int i=1;i<=row;i++){ //i --> row number.
        for(int j=1;j<=row-i;j++){
            cout<<" "; //space printing
        }
        for(int j=1;j<=(2*i-1);j++){
            cout<<"*"; //star printing
        }
        cout<<endl;
    }
    return 0;
}

/*
* * * * * * * * * 
  * * * * * * * 
    * * * * * 
      * * * 
        * 
*/ 
#include <iostream>
using namespace std;
int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    for(int i=rows; i>=1;i--) {
        for(int space=0; space<rows-i;space++)
            cout<<"  ";
        for(int j = i; j <= 2*i-1; ++j)
            cout << "* ";
        for(int j = 0; j < i-1; ++j)
            cout << "* ";
        cout << endl;
    }
    return 0;
}


/*
* * * * * 
  * * * * 
    * * * 
      * * 
        * 
*/ 
#include <iostream>
using namespace std;
int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    for(int i = rows; i >= 1; i--) {
        for(int space = 0; space < rows-i; ++space)
            cout << "  ";
        for(int j = i; j <= 2*i-1; ++j)
            cout << "* ";
            cout<<endl;
    }
    return 0;
}

/*
*
 * *
 * * *
 * * * *
 * * * * *
*/ 
#include <iostream>
using namespace std;
int main(){
    int rows;
    cout<<"Enter the rows: ";
    cin>>rows;
    for(int i=0;i<=rows;i++){
        for(int space=rows;space<=rows-i;space++)
        cout<<" ";
        for(int j=0;j<=i-1;j++)
        cout<<" *";
        cout<<endl;
    }
    return 0;
}