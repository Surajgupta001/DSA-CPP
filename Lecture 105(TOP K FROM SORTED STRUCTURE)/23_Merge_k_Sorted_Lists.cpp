/*
Merge k Sorted Lists - [Leetcode - 23(Medium)]
------------------------------------------------
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.
*/

// PATTERN: TOP K FROM SORTED STRUCTURE

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ListNode {
public:
    int value;
    ListNode* next;

    // Constructor
    ListNode(int data){
        value = data;
        next = nullptr;
    }
};

// Make custom comparator for the priority queue to compare ListNode pointers based on their values
static bool customComparator(ListNode* node1, ListNode* node2) {
    return node1->value > node2->value; // Min-heap based on node values
}

ListNode* mergeKLists(vector<ListNode*>& lists) {

    // Priority queue to store the nodes based on their values - MIN-HEAP => (value, node)
    priority_queue<ListNode*, vector<ListNode*>, decltype(&customComparator)> minHeap(&customComparator);


    // Step-1: Put first node of all list in min-heap
    // Step-2: Make head of resultant = min-heap top & push its next element in min-heap
    // Step-3: Maintain a tail pointer to keep track of the last node in the merged list and update it as you add new nodes from the min-heap.
    // Step-4: Repeat until min-heap is empty

    for(ListNode* node : lists){
        if(node != nullptr){
            minHeap.push(node);
        }
    }

    if(minHeap.empty()){
        return nullptr; // No lists to merge
    }

    // Initialize the new linked list with the smallest node
    ListNode* head = minHeap.top();
    minHeap.pop();

    if(head->next != nullptr){
        minHeap.push(head->next);
    }

    ListNode* tail = head; // Tail pointer to keep track of the last node in the merged list

    // Continue merging until the min-heap is empty
    while(!minHeap.empty()){
        ListNode* currentNode = minHeap.top();
        minHeap.pop();

        tail->next = currentNode; // Link the current node to the merged list
        tail = tail->next; // Move the tail pointer to the current node

        if(currentNode->next != nullptr){
            minHeap.push(currentNode->next); // Push the next node of the current node into the min-heap
        }
    }
    return head; // Return the head of the merged list
}

int main() {
    // Example usage:
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    ListNode* mergedList = mergeKLists(lists);

    // Print the merged linked list
    while (mergedList != nullptr) {
        cout << mergedList->value << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    return 0;
}