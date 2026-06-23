/*Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.

Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104*/
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include "bits/stdc++.h"
using namespace std;
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        int n = arr.size();
        vector<vector<int>> calcSum(n+1, vector<int>(sum+1, -1));
        sort(arr.begin(), arr.end());
        int m = n;
        
        for(int i=n-1; i>=0; i--) {
            if(arr[i] <= sum)
                break;
            m--;
        }
            
        
        return m>0 ? getCurrSumRev(arr, m, sum, 0, calcSum) : false;
    }

    
    bool getCurrSumRev(vector<int>& arr, int ind, int sum, int currSum, vector<vector<int>> &calcSum) {
        // cout<<"start : "<<ind<<' '<<currSum<<endl;
        
        if(currSum == sum) {
            calcSum[ind][currSum] = 1;
            return true;
        }
        if(ind == 0) {
            calcSum[ind][currSum] = 0;
            return false;
        }
        
        if(calcSum[ind][currSum] != -1) return (calcSum[ind][currSum] ==1);
        
        bool includedSum = (currSum + arr[ind-1] <= sum) ? 
                                getCurrSumRev(arr, ind-1, sum, currSum + arr[ind-1], calcSum)
                                : false;
                                
        bool excludedSum = getCurrSumRev(arr, ind-1, sum, currSum, calcSum);
        calcSum[ind][currSum] = (excludedSum ||  includedSum) ? 1 : 0;
        
        // cout<<"end : "<<ind<<' '<<currSum<<' '<<includedSum<<' '<<excludedSum<<' '<<calcSum[ind][currSum]<<endl;
        return  excludedSum ||  includedSum;
    }
    
   
    // bool checkSum(vector<int>& arr, int ind, int n, int sum, int currSum) {
    //     if(currSum == sum) return true;
    //     if(currSum > sum || ind == n) return false;
    //     return checkSum(arr, ind+1, n, sum, currSum) ||
    //         checkSum(arr, ind+1, n, sum, currSum + arr[ind]);
    // }
   
   
    
    // bool getCurrSum(vector<int>& arr, int ind, int n, int sum, int currSum, vector<vector<int>> &calcSum) {
    //     if(currSum == sum) {
    //         calcSum[ind][currSum] = 1;
    //         return true;
    //     }
    //     if(ind == n) {
    //         calcSum[ind][currSum] = 0;
    //         return false;
    //     }
        
    //     if(calcSum[ind][currSum] != -1) return calcSum[ind][currSum] ==1;
        
    //     bool includedSum = (currSum + arr[ind] <= sum && ind<n) ? 
    //                             getCurrSum(arr, ind+1, n, sum, currSum + arr[ind], calcSum)
    //                             : false;
                                
    //     bool excludedSum = ind<n ? getCurrSum(arr, ind+1, n, sum, currSum, calcSum) : false;
    //     return  excludedSum ||  includedSum;
    // }
};