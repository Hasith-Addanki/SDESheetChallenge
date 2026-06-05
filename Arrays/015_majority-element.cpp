/*
he majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

 

Constraints:

    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109
    The input is generated such that a majority element will exist in the array.

 
Follow-up: Could you solve the problem in linear time and in O(1) space?*/

// https://leetcode.com/problems/majority-element/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], cnt = 1;
        int n = nums.size();
        for(int i=1; i<n; i++) {
            if(cnt == 0) {
                cnt =1;
                ans = nums[i];
            } else {
                if(ans == nums[i])
                    cnt++;
                else
                    cnt--;
            }
        }
        return ans;
    }
};