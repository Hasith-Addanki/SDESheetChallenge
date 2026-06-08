/**Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Subarrays with sum = -5 are [-5] and [-5, 8, -14, 2, 4]. The length of the longest subarray with a sum of -5 is 5.

Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].

Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109 */

//https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    // int longestSubarray(vector<int>& arr, int k) {
    //     // code here
    //     int ans = 0;
    //     int n = arr.size();
    //     int i=0, j=0;
    //     int sum = 0;
    //     for(j; j<n; j++) {
    //         sum += arr[j];
    //         while(sum>k && i<j) {
    //             sum -= arr[i++];
    //         }
    //         if(sum == k)
    //             ans = max(ans, (j-i+1));
    //     }
        
    //     return ans;
    // }
    int longestSubarray(vector<int>& arr, int k) {
        int ans = 0;
        int n = arr.size();
        int sum = 0;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            
            if(sum == k)
                ans = max(ans, i+1);
            
            int tar = sum - k;
            if(m.find(tar) != m.end()) {
                // cout<<ans<<' '<<i<<' '<<m[tar]<<endl;
                ans = max(ans, (i - m[tar]));
            }
            
            if(m.find(sum) == m.end())
                m[sum] = i;
        }
        
        return ans;
    }
};