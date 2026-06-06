/**Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

    0 <= i < j < nums.length and
    nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

 

Constraints:

    1 <= nums.length <= 5 * 104
    -231 <= nums[i] <= 231 - 1
 */
// https://leetcode.com/problems/reverse-pairs/description/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        mergeSort(nums, ans, 0, n-1);
        return ans;
    }

    void mergeSort(vector<int> &nums, int &ans, int left, int right) {
        if(left>=right)
            return;
        int mid = left + (right - left)/2;
        mergeSort(nums, ans, left, mid);
        mergeSort(nums, ans, mid+1, right);
        merge(nums, ans, left, mid, right);
    }

    void merge(vector<int> &nums, int &ans, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<long> a(n1);
        vector<long> b(n2);
        for(int i=0; i<n1; i++)
            a[i] = nums[left+i];
        for(int i=0; i<n2; i++)
            b[i] = nums[mid+i+1];
        
        int i=0, j=0;
        int k = left;
        while(i<n1 && j<n2) {
           if(a[i] < b[j]) {
                if(b[j] <0) {
                    int temp = j;
                    while(temp<n2 && a[i] > (long long )2L*b[temp] && b[temp]<0)
                        temp++;
                    ans += (temp - j);
                }
                nums[k++] = a[i++];
           }
            else {
                int temp = i;
                while(temp <n1 && a[temp] <= ((long long)2L*b[j]))
                    temp++;
                ans += (n1 - temp);
                nums[k++] = b[j++];
            }
        }

        while(i<n1)
            nums[k++] = a[i++];
        while(j<n2)
            nums[k++] = b[j++];
    }
}; 