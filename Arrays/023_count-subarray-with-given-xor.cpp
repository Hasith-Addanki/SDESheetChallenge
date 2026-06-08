/*Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Note: It is guranteed that the total count will fit within a 32-bit integer.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.

Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.

Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
0 ≤ k ≤ 105*/
//https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
#include "bits/stdc++.h"
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long ans=0, n = arr.size();
        int sum = 0;
        map<int, long> m;
        for(int i=0; i<n; i++) {
            sum ^= arr[i];
            if(sum == k)
                ans++;
            
            int tar = sum^k;
            if(m.find(tar) != m.end())
                ans += m[tar];
            
            m[sum]++;
        }
        
        return ans;
    }
};            

