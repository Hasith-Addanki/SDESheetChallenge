/*
Given an array nums of distinct integers, return all the possible . You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

 

Constraints:

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.

*/
//https://leetcode.com/problems/permutations/

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        calcPerm(ans, temp, nums, -1);
        return ans;
    }

    void calcPerm(vector<vector<int>>& ans, vector<int> temp,
        vector<int> nums, int i) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int j=i+1; j<nums.size(); j++) {
            swap(nums[j], nums[i+1]);
            cout<<"i= "<<i<<"; j="<<j<<"; nums[j]="<<nums[j]<<"; nums[i+1]="<<nums[i+1]<<endl;
            temp.push_back(nums[i+1]);
            calcPerm(ans, temp, nums, i+1);
            temp.pop_back();
            swap(nums[j], nums[i+1]);
            cout<<"i= "<<i<<"; j="<<j<<"; nums[j]="<<nums[j]<<"; nums[i+1]="<<nums[i+1]<<endl;
        }
    }
};