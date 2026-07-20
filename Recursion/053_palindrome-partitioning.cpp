// Given a string s, partition s such that every of the partition is a . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:

// Input: s = "a"
// Output: [["a"]]

 

// Constraints:

//     1 <= s.length <= 16
//     s contains only lowercase English letters.

//https://leetcode.com/problems/palindrome-partitioning/description/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<int> part;
        calcPal(s, ans, part, -1, s.length());
        return ans;   
    }

    void calcPal(string &s, vector<vector<string>>& ans,
        vector<int> part, int i, int n) {
        // if(part.size() != 0) {
        bool allPal = true;
        vector<string> tempPart;
        int prevInd = -1;
        for(int ind : part) {
            string temp = s.substr(prevInd+1, ind-prevInd);
            tempPart.push_back(temp);
            if(!isPal(temp)) {
                allPal = false;
                break;
            }
            prevInd = ind;
        }
        if(allPal) {
            string temp = s.substr(prevInd+1, n-prevInd-1);
            tempPart.push_back(temp);
            if(isPal(temp))
                ans.push_back(tempPart);
        }
        // }
        for(int j=i+1; j<n-1; j++) {
            part.push_back(j);
            calcPal(s, ans, part, j, n);
            part.pop_back();
        }
    }


    bool isPal(string& s) {
        int n = s.length();
        int m = n/2;
        for(int i=0; i<m; i++) {
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
};