/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

 

Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
*/
//https://leetcode.com/problems/trapping-rain-water/description/
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int trap3(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for(int i=1; i<n; i++) {
            left[i] = max(left[i-1], height[i-1]);
            right[n-i-1] = max(right[n-i], height[n-i]);
       }

       for(int i=0; i<n; i++) {
            int temp = min(left[i], right[i]) - height[i];
            ans += (temp>0) ? temp : 0;
       }

       return ans;
    }

    int trap2(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        // vector<int> left(n, 0);
        vector<int> right(n, 0);

        for(int i=1; i<n; i++) {
            // left[i] = max(left[i-1], height[i-1]);
            right[n-i-1] = max(right[n-i], height[n-i]);
       }

        int leftMax = 0;
       for(int i=0; i<n; i++) {
            int temp = min(leftMax, right[i]) - height[i];
            ans += (temp>0) ? temp : 0;
            leftMax = max(leftMax, height[i]);
       }

       return ans;
    }

    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        stack<int> s;
        s.push(n-1);
        for(int i=n-2; i>=0; i--) {
            if(height[i] > height[s.top()])
                s.push(i);
       }

        int leftMax = 0;    
        for(int i=0; i<n-1; i++) {
            if(i==s.top())
                s.pop();

            int temp = min(leftMax, height[s.top()]) - height[i];
            ans += (temp>0) ? temp : 0;
            leftMax = max(leftMax, height[i]);
        }

       return ans;
    }
};