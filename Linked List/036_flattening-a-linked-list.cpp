/*Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom points to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and → represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 10 is pointing to 20 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.

Input:

Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 30 and so on.
So, after flattening the linked list the sorted list will be 
5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.

Constraints:
0 ≤ n ≤ 100
1 ≤ number of nodes in sub-linked list(mi) ≤ 50
1 ≤ node->data ≤ 105*/
//https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include "bits/stdc++.h"
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; 

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        Node* ans = root;
        while(root->next) {
            root = sortLL(root, root->next);
            // break;
        }
        return ans;
    }
    
    Node* sortLL(Node* headA, Node* headB) {
        if(headA == nullptr) return headB;
        if(headB == nullptr) return headA;
        Node* temp = nullptr;
        
        if(headA->data > headB->data) {
            temp = headA;
            headA = headB;
            headB = temp;
        }
        Node* ans = headA;
        headA->next = headB->next;

        
        Node* prev = nullptr;
        while(headA && headB) {
            // cout<<headA->data<<' '<<headB->data<<endl;
            if(headA->data <= headB->data) {
                prev = headA;
                headA = headA->bottom;
            } else {
                temp = new Node(headB->data);
                temp->bottom = headA;
                prev->bottom = temp;
                headB = headB->bottom;
                prev = prev->bottom;
            }
        }
        
        if(headB)
            prev->bottom = headB;
        return ans;
    } 
};