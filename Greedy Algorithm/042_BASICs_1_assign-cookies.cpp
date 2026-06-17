/*You are given an array greed[], where greed[i] represents the minimum size of cookie required to satisfy the i-th child, and an array cookie[], where cookie[j] represents the size of the j-th cookie. Each child can receive at most one cookie. A child i will be satisfied if they receive a cookie j such that cookie[j] >= greed[i]. Your task is to determine the maximum number of children that can be satisfied.

Examples:

Input : greed[] = [1, 10, 3], cookie = [1, 2, 3]
Output: 2
Explanation: We can only assign cookie to the first and third child.

Input : greed[] = [10, 100], cookie = [1, 2]
Output: 0
Explanation: We can not assign cookies to any child.

Constraints:
1 ≤ greed.size() ≤  105
1 ≤ cookie.size() ≤  105
1 ≤ greed[i] , cookie[i] ≤ 109*/
// /https://www.geeksforgeeks.org/problems/assign-cookies/1

#include "bits/stdc++.h"
using namespace std;
class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // code here
        sort(greed.begin(), greed.end());
        sort(cookie.begin(), cookie.end());
        int i=0, j=0, n=greed.size(), m=cookie.size();
        int ans = 0;
        while(i<n && j<m) {
            if(greed[i] <= cookie[j]) {
                ans++;
                i++;
                j++;
            } else if (greed[i] > cookie[j])
                j++;
        }
        
        return ans;
        
    }
};