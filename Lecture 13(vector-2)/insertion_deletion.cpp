/*
WAP to create a 1-D array of n elements and perform the following menu based operations using function.

a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element.
d. traversal of the array.

Sample Input/Output:
Enter size n : 5
Enter element of array:
Enter Array elements: 10 23 45 37 52
***MENU*** 1.\
1. Insert
2. Delete
3. Linear Search
4. Traverse
5. Exit

Enter option: 1

Element to insert: 61
Enter Position: 2
Element inserted
Enter option: 4

Array Elements: 10 23 61 45 37 52

*/ 

#include <iostream>
#include <vector>
using namespace std;

// Function to insert an element at a specific position
void insertElement(vector<int>& vec, int element, int position){
    vec.insert(vec.begin() + position, element);
}

// Function to delete an element from a specific position
void deleteElement(vector<int>& vec, int position) {
    if (position < vec.size()) {
        vec.erase(vec.begin() + position);
    } else {
        cout<<"Invalid position"<<std::endl;
    }
}

// Function to perform linear search
void linearSearch(vector<int>& vec, int element) {
    for(int i=0; i<vec.size();i++) {
        if (vec[i] == element) {
            cout<<"Element found at position: "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found"<<endl;
}

// Function to traverse the vector
void traverse(vector<int>& vec) {
    cout<<"Array Elements: ";
    for(int element:vec) {
        cout<<element<<" ";
    }
    cout<<endl;
}

int main() {

    int n;
    cout<<"Enter the size of vectors: ";
    cin>>n;

    vector<int> vec(n);
    cout<<"Enter all the elements of vectors: ";
    for(int i=0; i<n; i++) {
        cin>>vec[i];
    }

    while(true){
        cout<<endl<<"***MENU***"<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Linear Search"<<endl;
        cout<<"4. Traverse"<<endl;
        cout<<"5. Exit"<<endl;

        int option;
        cout<<"Enter option: ";
        cin>>option;

        switch(option) {
            case 1:{

                int element, position;
                cout<<"Enter a element u want insert: ";
                cin>>element;
                cout<<"Enter a index u want: ";
                cin>>position;

                insertElement(vec, element, position);

                cout<<"Inserted Element: ";
                for(int i=0;i<vec.size();i++){
                    cout<<vec[i]<<" ";
                }
                break;
            }

            case 2:
            {
                int position;
                cout << "Enter Position: ";
                cin >> position;

                deleteElement(vec, position);

                cout<<"Deleted Element: ";
                for(int i=0;i<vec.size();i++){
                    cout<<vec[i]<<" ";
                }
                break;
            }

            case 3:{

                int element;
                cout<<"Enter a number u want search: ";
                cin>>element;

                linearSearch(vec, element);
                break;
            }

            case 4:
                traverse(vec);
                break;

            case 5:
                return 0;

            default:
                cout<<"Invalid option" << std::endl;
        }
    }

    return 0;
}