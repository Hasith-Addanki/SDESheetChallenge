/**Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

Input: candidates = [2], target = 1
Output: []

 

Constraints:

    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40
 */
//https://leetcode.com/problems/combination-sum/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> temp;
        calcSum(candidates, target, ans, temp, 0);
        // vector<vector<int>> finalAns;
        // for(auto it : ans) 
        //     finalAns.push_back(vector<int>(it.begin(), it.end()));
        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void calcSum(vector<int>& candidates, int target, set<vector<int>>& ans, vector<int> temp, int currSum) {
        if(currSum >= target) {
            if(currSum == target) {
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            return;
        }
        for(int i=0; i<candidates.size(); i++) {
            currSum += candidates[i];
            temp.push_back(candidates[i]);
            calcSum(candidates, target, ans, temp, currSum);
            currSum -= candidates[i];
            temp.pop_back();
        }
    }
};