/*
Given the head of a doubly linked list, find maximum and minimum distance.
*/
#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

class node{
public:
    int value;
    node *prev;
    node *next;

    // construtor
    node(int data){
        value = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
public:
    node *head;
    node *tail;

    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void display(){
        node *temp = head;
        while (temp != nullptr){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtEnd(int value){
        node *new_node = new node(value);
        // check if linked list is empty
        if (head == nullptr){
            head = new_node;
            tail = new_node;
            return;
        }
        // if linked list is not empty
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    bool isCriticalPoint(node *&currNode){
        if (currNode->prev->value < currNode->value && currNode->next->value < currNode->value){ // local maxima
            return true;
        }
        if (currNode->prev->value > currNode->value && currNode->next->value > currNode->value){ // local minima
            return true;
        }
        return false;
    }

    vector<int> distanceBetweenCriticalPoint(node *head, node *tail){
        vector<int> ans(2, INT_MAX);
        int firstCP = -1, lastCP = -1;
        node *currNode = tail->prev;
        if (currNode == nullptr){
            ans[0] = ans[1] = -1;
            return ans;
        }
        int currPos = 0;
        while (currNode->prev != nullptr){
            if (isCriticalPoint(currNode)){
                if (firstCP == -1){
                    firstCP = lastCP = currPos;
                }
                else{
                    ans[0] = min(ans[0], currPos - lastCP); // min distance
                    ans[1] = currPos - firstCP;             // max distance
                    lastCP = currPos;
                }
            }
            currPos++;
            currNode = currNode->prev;
        }
        if (ans[0] == INT_MAX){
            ans[0] = ans[1] = -1;
        }
        return ans;
    }
};

int main(){

    DoublyLinkedList dll;
    cout << "Inserted Linked List: ";
    dll.insertAtEnd(1);
    dll.insertAtEnd(5);
    dll.insertAtEnd(2);
    dll.insertAtEnd(6);
    dll.insertAtEnd(3);
    dll.display();

    vector<int> ans = dll.distanceBetweenCriticalPoint(dll.head, dll.tail);
    cout <<"Minimum Distance: "<<ans[0]<<endl<<"Maximum Distance: "<<ans[1];

    return 0;
}