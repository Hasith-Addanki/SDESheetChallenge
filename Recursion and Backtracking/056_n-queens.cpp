/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]

 

Constraints:

    1 <= n <= 9

*/
// https://leetcode.com/problems/n-queens/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        set<int> posDiag;
        set<int> negDiag;

        string s = "";
        for(int i=0; i<n; i++)  
            s += ".";
        for(int i=0; i<n; i++)
            temp.push_back(s);
        fillQ(ans, temp, posDiag, negDiag, n, 0);
        return ans;
    }

    void fillQ(vector<vector<string>>& ans, vector<string> temp,
        set<int> posDiag, set<int> negDiag, int n, int i) {
        if(i==n) {
            ans.push_back(temp);
            return;
        }

        bool assigned = false;
        for(int j=0; j<n; j++) {
            if(canQ(temp, posDiag, negDiag, i, j)) {
                // bool pos = posDiag

                temp[j][i] = 'Q';
                // assigned = true;
                negDiag.insert(i-j);
                posDiag.insert(i+j);
                fillQ(ans, temp, posDiag, negDiag, n, i+1);
                temp[j][i] = '.';
                negDiag.erase(i-j);
                posDiag.erase(i+j);
            }   
            // if(!assigned)
        }
    }

    bool canQ(vector<string>& temp, set<int>& posDiag, set<int>& negDiag, int i, int j) {
        if(temp[j][i] =='Q') return false;
        for(int k=0; k<i; k++) {
            if(temp[j][k] == 'Q') return false;
        }
        if(posDiag.find(i+j) != posDiag.end()) return false;
        if(negDiag.find(i-j) != negDiag.end()) return false;
        return true;
    }
};
