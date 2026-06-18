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
    int jump(vector<int>& nums) {
        int l=0, r=0, n = nums.size();
        int jumps = 0;
        while(l<=r && r<n) {
            if(r==n-1)
                break;
            int temp = r+1;

            for(int i=l; i<=r && temp<n; i++) {
                temp = max(temp, i+nums[i]);
            }
            l = r+1;
            r = temp;
            jumps++;
        }

        return jumps;
    }
};