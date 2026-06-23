/*Given an integer array nums that may contain duplicates, return all possible (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]

 

Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/
// https://leetcode.com/problems/subsets-ii/description/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<list<int>> temp;
        temp.insert(list<int>{});
        set<list<int>> ans = powerSet(nums, nums.size()-1, temp);
        // return vector<vector<int>>(ans.begin(), ans.end());
        vector<vector<int>> finalAns;
        for(auto it : ans) {
            finalAns.push_back(vector<int>(it.begin(), it.end()));
        }
        return finalAns;
    }

    set<list<int>> powerSet(vector<int> &nums, int ind, set<list<int>> &temp) {
        if(ind <0)
            return temp;
        set<list<int>> ans(temp.begin(), temp.end());
        for(auto it : temp) {
            it.push_front(nums[ind]);
            ans.insert(it);
            // cout<<nums[ind]<<' '<<ind<<endl;
        }

        return powerSet(nums, ind-1, ans);
    }
};