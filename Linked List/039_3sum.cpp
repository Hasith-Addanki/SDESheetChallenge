/**Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

 

Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105
 */
//https://leetcode.com/problems/3sum/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     map<int, bool> m;
    //     int n = nums.size();
    //     for(int i=0; i<n; i++) {
    //         for(int j=i+1; j<n; j++) {
    //             int tar = 0 - nums[i] - nums[j];
    //             if(m.find(tar) != m.end()) {
                    // int small = min(nums[i], min(nums[j], tar));
                    // int large = max(nums[i], max(nums[j], tar));
                    // int mid = nums[i] + nums[j] + tar - small - large;
    //                 ans.push_back({small, mid, large});
    //                 // ans.push_back({tar, nums[i], nums[j]});
    //             }
    //         }
    //         m[nums[i]] = true;
    //     }

    //     sort(ans.begin(), ans.end());
    //     vector<vector<int>> finalAns;
    //     if(ans.size() !=0)
    //         finalAns.push_back(ans[0]);
    //     n = ans.size();
    //     int k = 0;
    //     for(int i=1; i<n; i++) {
    //         if(ans[i][0] == finalAns[k][0] &&
    //             ans[i][1] == finalAns[k][1] &&
    //             ans[i][2] == finalAns[k][2])
    //             continue;
    //         finalAns.push_back(ans[i]);
    //         k++;
    //     }
    //     return finalAns;
    // }

    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     map<int, bool> m;
    //     int n = nums.size();
    //     map<string, bool> m2;
        
    //     for(int i=0; i<n; i++) {
    //         for(int j=i+1; j<n; j++) {
    //             int tar = 0 - nums[i] - nums[j];
    //             if(m.find(tar) != m.end()) {
    //                 int small = min(nums[i], min(nums[j], tar));
    //                 int large = max(nums[i], max(nums[j], tar));
    //                 int mid = nums[i] + nums[j] + tar - small - large;
    //                 string triplet = to_string(small) +
    //                         to_string(mid) + 
    //                         to_string(large);
    //                 // cout<<triplet<<endl;
    //                 if(m2.find(triplet) == m2.end()) {
    //                     ans.push_back({tar, nums[i], nums[j]});
    //                     m2[triplet] = true;
    //                 }
    //             }
    //         }
    //         m[nums[i]] = true;
    //     }
    //     return ans;
    // }

    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, bool> m;
        int n = nums.size();
        // map<string, bool> m2;
        set<vector<int>> s;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int tar = 0 - nums[i] - nums[j];
                if(m.find(tar) != m.end()) {
                    int small = min(nums[i], min(nums[j], tar));
                    int large = max(nums[i], max(nums[j], tar));
                    int mid = nums[i] + nums[j] + tar - small - large;
                    s.insert({small, mid, large});
                }
            }
            m[nums[i]] = true;
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};