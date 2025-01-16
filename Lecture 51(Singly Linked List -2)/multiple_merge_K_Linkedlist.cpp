#include <iostream>
using namespace std;
#include <vector>

class node{
    public:
    int value;
    node *next;

    node(int data){
        value = data;
        next = nullptr;
    }
};

class LinkedList{
    public:
    node *head;

    LinkedList(){
        head = nullptr;
    }

    void insertAtTail(int value){

        node *new_node = new node(value);
        if(head == NULL){ // linked List is empty
            head = new_node;
        return;
        }

        node *temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next =  new_node;
    }

    void display(){
        node *temp = head;
        while(temp != NULL){
            cout<<temp -> value<<"->";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }
};

node* mergeLinkedLists(node* &head1, node* &head2){
    node *dummyHeadNode = new node(-1);

    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummyHeadNode;

    while(ptr1 && ptr2){
        if(ptr1 -> value < ptr2 -> value){
            ptr3 -> next = ptr1;
            ptr1 = ptr1 -> next;
        }
        else{
            ptr3 -> next = ptr2;
            ptr2 = ptr2 -> next;
        }
        ptr3 = ptr3 -> next;
    }
    if(ptr1){
        ptr3 -> next = ptr1;
    }
    else{
        ptr3 -> next = ptr2;
    }
    return dummyHeadNode -> next;
}

node *mergeKLinkedlist(vector<node*>&lists){

    if(lists.size() == 0){
        return NULL;
    }
    while(lists.size()>1){

        node *mergeHead = mergeLinkedLists(lists[0],lists[1]);
        lists.push_back(mergeHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

// vector -> head1 ,head2, head3 head4;
// 1. head1 and head2 ll will be merged
// vector -> head3 head4 mergedhead1_2;
// 2.head3 and head 4 will be merged
// vector -> mergedhead1_2 mergedhead3_4
// 3.mergedhead1_2 and mergedhead3_4 will be merged
// vector -> mergedhead1_2_3_4

int main(){

    LinkedList ll1;
    ll1.insertAtTail(1);
    ll1.insertAtTail(7);
    ll1.insertAtTail(8);
    ll1.display();

    LinkedList ll2;
    ll2.insertAtTail(2);
    ll2.insertAtTail(4);
    ll2.insertAtTail(5);
    ll2.display();

    LinkedList ll3;
    ll3.insertAtTail(3);
    ll3.insertAtTail(6);
    ll3.display();

    vector<node*> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    lists.push_back(ll3.head);

    LinkedList mergedLL;
    mergedLL.head = mergeKLinkedlist(lists);
    mergedLL.display();

    return 0;

}