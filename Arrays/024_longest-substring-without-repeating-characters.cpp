/**Given a string s, find the length of the longest without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

 

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
 */
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        map<char, int> m;
        int left = 0, n=s.length();
        for(int i=0; i<n; i++) {
            char c = s[i];
            if((m.find(c) == m.end()) || (m[c] == 0)) {
                // cout<<i<<' '<<left<<endl;
                ans = max(ans, i-left+1);
            } 
            if(m[c] == 1) {
                while(m[c] == 1 && left<i)
                    m[s[left++]]--;
            }
            m[c] = 1;
        }

        return ans;
    }
};