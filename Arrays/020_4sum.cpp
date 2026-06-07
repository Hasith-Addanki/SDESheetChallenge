/**Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

 

Constraints:

    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
 */
//https://leetcode.com/problems/4sum/description/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> s;
        map<long long, bool> m;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    long long tar = (long)target - (long)nums[i] - (long)nums[j] - (long)nums[k];
                    if(m.find(tar) != m.end()) {
                        vector<int> temp = {
                            (int)tar, nums[i], nums[j], nums[k]
                        };
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
            m[nums[i]] = true;
        }

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};