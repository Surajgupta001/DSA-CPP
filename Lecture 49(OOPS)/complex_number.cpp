/*
Write a menu driven program to create a structure to represent complex number and perform the following operation using function:

1. addition of two complex number (call by value)
2. multiplication of two complex number (call by address)

Sample Input/Output:
Enter complex number 1: 3 4
Enter complex number 2: 4 5

MENU
1. addition
2. multiplication

Enter your choice: 1
Sum = 7 + 9i

Enter your choice: 2
Sum = -8 + 31i
*/
#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Function to add two complex numbers
    Complex add(Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Function to multiply two complex numbers
    Complex multiply(Complex c) {
        Complex temp;
        temp.real = real * c.real - imag * c.imag;
        temp.imag = real * c.imag + imag * c.real;
        return temp;
    }

    // Function to display complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main(){

    int Main;
    int real1, imag1, real2, imag2;

    cout<<"Enter 1st complex number: ";
    cin>>real1>>imag1;

    cout<<"Enter 2nd complex number: ";
    cin>>real2>>imag2;

    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    while (true) {
        cout<<endl<<"MENU"<<endl;
        cout<<"1. Addition"<<endl;
        cout<<"2. Multiplication"<<endl;
        cout<<"3. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>Main;

        switch (Main) {
            case 1: {
                Complex sum = c1.add(c2);
                cout << "Sum = ";
                sum.display();
                break;
            }
            case 2: {
                Complex product = c1.multiply(c2);
                cout << "Product = ";
                product.display();
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}