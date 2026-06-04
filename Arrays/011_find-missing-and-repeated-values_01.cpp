/**
 * Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.

Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and the missing number is 2.

Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.

Constraints:
2 ≤ n ≤ 106
1 ≤ arr[i] ≤ n

 */

// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
#include "bits/stdc++.h"
using namespace std;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int xMinY = 0;
        int x2MinY2 = 0;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            xMinY += (i+1) - arr[i];
            x2MinY2 += ((i+1)*(i+1)) - (arr[i]*arr[i]);
        }
        int xPlusY = x2MinY2/xMinY;
        int miss  = (xPlusY + xMinY)/2;
        int repeat = (xPlusY - xMinY)/2;
        
        return {repeat, miss};
    }
};