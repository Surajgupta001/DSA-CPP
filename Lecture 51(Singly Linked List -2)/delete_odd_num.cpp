/*
Write a Program to delete all odd elements from a Singly Linked List.

INPUT: 1 2 3 4 5 6 7 8 9 10
OUTPUT: 2 4 6 8 10
*/ 

#include <iostream>
using namespace std;
class solution{
    public:
    int data;
    solution* next;
};
void deleteOddElement(solution* &head){
    solution* prev = NULL;
    solution* curr = head;

    while(curr != nullptr){
        if(curr->data % 2 != 0){
            solution* temp = curr;
            curr = curr->next;
            if(prev != nullptr){
                prev->next = curr;
            }
            else{
                head = curr;
            }
            delete temp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}