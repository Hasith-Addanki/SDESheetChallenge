/*Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true

 

Constraints:

    1 <= s.length <= 100
    s[i] is '(', ')' or '*'.
*/
//https://leetcode.com/problems/valid-parenthesis-string/description/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool checkValidString_Old(string s) {
        int n = s.length();
        return check(s, 0, 0, n);
    }

    bool check(string &s, int cnt, int i, int n) {
        if(i==n ) return cnt == 0;
        if(cnt <0) return false;
        if(s[i] == '(') {
            return check(s, cnt + 1, i + 1, n);
        } else if (s[i] == ')') {
            if(cnt == 0) return false;
            return check(s, cnt -1, i+1, n);
        }
        return check(s, cnt, i+1, n) || 
            check(s, cnt+1, i+1, n) || 
            check(s, cnt-1, i+1, n);
    }

    bool checkValidString(string s) {
        int mn =0, mx = 0, n=s.length();
        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                mn++;
                mx++;
            }
            else if(s[i] == ')') {
                mn--;
                mx--;
            } else {
                mn--;
                mx++;
            }
            if(mn <0)
                mn=0;
            if(mx <0)
                return false;
        }
        return (mx==0 || mn==0);
    }
};