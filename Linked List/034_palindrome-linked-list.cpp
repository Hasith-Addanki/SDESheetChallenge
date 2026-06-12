// https://leetcode.com/problems/palindrome-linked-list/description/
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
    bool isPalindrome(ListNode* head) {
        string a = "", revA = "";
        // while(head) {
        //     a += head->val + '0';
        //     head = head->next;
        // }
        // int n = a.length();
        // for(int i=0; i<n/2; i++) {
        //     if(a[i] != a[n-1-i]) return false;
        // }

        runThrough(head, a, revA);
        return a == revA;
    }

    // TLE
    void runThrough(ListNode* head, string &a, string &revA) {
        if(head == nullptr) {
            a = "";
            revA = "";
            return;
        }
        runThrough(head->next, a, revA);
        char temp= head->val + '0';
        a = temp  + a;
        revA = revA + temp;
    }
};