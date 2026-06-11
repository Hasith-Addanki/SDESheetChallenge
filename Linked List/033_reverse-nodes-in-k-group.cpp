/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

 

Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000

 

Follow-up: Can you solve the problem in O(1) extra memory space?*/

//https://leetcode.com/problems/reverse-nodes-in-k-group/description/
#include "bits/stdc++.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // return reverseLL(head->next->next->next->next, k);
        if(head==nullptr || head->next == nullptr || k==1)
            return head;
        ListNode* ans = head;
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        while(temp) {
            ListNode* rev = reverseLL(temp, k);
            if(ans==head)
                ans = rev;
            
            if(prevNode) {
                prevNode->next = rev;
            }

            for(int i=0; rev && i<k; i++) {
                prevNode = rev;
                rev = rev->next;
            }
            // temp = rev->next;
            temp = rev;
            
        }

        return ans;
    }

    ListNode* reverseLL(ListNode* head, int k) {
        ListNode *prev = head, *next = head;
        int i=0;
        ListNode* temp = head;
        while(temp) {
            // cout<<temp->val<<' '<<i<<endl;
            temp = temp->next;
            i++;
        }
        cout<<i<<' '<<k<<endl;
        if(i<k){
            // cout<<"returning";
            return head;
        }
        
        i=0;

        while(next && i<k) {
            ListNode* temp = next->next;
            next->next = prev;
            prev =next;
            next = temp;
            i++;
        }

        if(head)
            head->next = next;
        return prev;
    }
};