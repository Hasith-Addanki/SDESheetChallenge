/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105

*/
// https://leetcode.com/problems/jump-game/description/

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool canJump2(vector<int>& nums) {
        int n = nums.size(), i=0;
        bool ans = false;
        vector<bool> visited(n, false); 
        jump(nums,visited, i, n, ans);
        
        return ans;
    }

    bool jump(vector<int>& nums, vector<bool> &visited, int i, int n, bool &ans) {
        if(i==n-1 || ans==true) {
            ans = true;
            return ans;
        }

        if(nums[i] == 0) 
            return false;
        
        for(int j=1;  i+j<n && j<=nums[i]; j++) {
            if(visited[i+j])
                continue;
            ans = ans | jump(nums,visited, i+j, n, ans);
            visited[i+j] = true;
            if(ans)
                break;
        }

        return ans;
    }


     bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;

        for(int i=0; maxInd<n-1 && i<n-1; i++) {
            maxInd = max(maxInd, (i+nums[i]));
            if(maxInd == i) return false;
        }

        return true;
    }
};