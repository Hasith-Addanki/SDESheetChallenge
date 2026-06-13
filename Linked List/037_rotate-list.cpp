// /https://leetcode.com/problems/rotate-list/description/
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
#include "bits/stdc++.h"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k==0) return head;

        ListNode *ans = head, *temp = head;
        int n = 0;
        while(temp) {
            temp = temp->next;
            n++;
        }

        k = k%n;
        if(k==0)
            return head;

        k = n-k;
        cout<<n<<' '<<k<<endl;
        temp = head;

        
        ListNode* prev = nullptr;
        while(temp && k>0) {
            prev = temp;
            temp = temp->next;
            k--;
        }
        prev->next = nullptr;

        ans = temp;
        while(temp && temp->next ) {
            temp = temp->next;
        }

        temp->next = head;
        return ans;
    }
};