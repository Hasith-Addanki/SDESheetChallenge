/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

 

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/

//https://leetcode.com/problems/combination-sum-ii/description/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        set<vector<int>> ans;
        vector<int> temp = {candidates[0]};
        calcSum(ans, candidates, temp, 0, n, candidates[0], target);

        for(int i=1; i<n; i++) {
            if(candidates[i] == candidates[i-1]) continue;
            vector<int> temp2 = {candidates[i]};
            calcSum(ans, candidates, temp2, i, n, candidates[i], target);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void calcSum(set<vector<int>>& ans, vector<int>& candidates,
        vector<int> temp, int i, int n, int sum, int target) {
        if(sum >= target) {
            if(sum == target) 
                ans.insert(temp);
            return;
        }

        // int j = i+1;
        // if (j<n){   
        //     temp.push_back(candidates[j]);
        //     sum += candidates[j];
        //     calcSum(ans, candidates, temp, j, n, sum, target);
        //     if(sum >= target )  return;
        //     sum -= candidates[j];
        //     temp.pop_back();
        // }
        for(int j = i+1; j<n; j++) {
            if(j!= i+1 && candidates[j] == candidates[j-1])
                continue;

            temp.push_back(candidates[j]);
            sum += candidates[j];
            calcSum(ans, candidates, temp, j, n, sum, target);
            if(sum >= target )  return;
            sum -= candidates[j];
            temp.pop_back();
        }
                
    }
};