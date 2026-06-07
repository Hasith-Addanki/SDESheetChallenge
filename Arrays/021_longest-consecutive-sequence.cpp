/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/

//https://leetcode.com/problems/longest-consecutive-sequence/description/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> m;
        int n = nums.size();
        for(int i=0; i<n; i++)
            m[nums[i]] = true;

        int ans = 0;
        int currAns = 0;
        int currElem;
        for(auto it=m.begin(); it != m.end(); it++) {
            // cout<<it->first<<endl;
            if(currAns == 0 ||(currElem+1) == it->first) {
                currAns++;
            } else {
                currAns=1;
            }

            currElem = it->first;
            ans = max(ans, currAns);
        }

        return ans;
    }
};