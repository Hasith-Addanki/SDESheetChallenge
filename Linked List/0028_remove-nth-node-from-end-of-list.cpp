/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

 

Follow up: Could you do this in one pass?*/
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = head;
        int sz=0;
        {
            ListNode* temp=head;
            while(temp) {
                sz++;
                temp = temp->next;
            }
        }   

        if(sz-n==0)  return head->next;
        ListNode* prev = nullptr;
        int i = 0;
        while(i<(sz-n)) {
            i++;
            prev = head;
            head = head->next;
        }
        prev->next = head->next;
        return ans;
    }   
};