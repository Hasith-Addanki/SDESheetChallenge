/**
 * 
 * Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104

 */

// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include "bits/stdc++.h"
using namespace std;
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int ans = 0;
        int n = arr.size();
        mergeSort(arr, ans, 0, n-1);
        // for(int i=0; i<n; i++)
        //     cout<<arr[i]<<' ';
        return ans;
    }
    
    
    void mergeSort(vector<int> &arr, int &ans, int left, int right) {
        if(right <= left)
            return;
        int mid = left + (right-left)/2;
        mergeSort(arr, ans, left, mid);
        mergeSort(arr, ans, mid+1, right);
        merge(arr, ans, left, mid, right);
    }
    
    void merge(vector<int> &arr, int &ans, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> L(n1), R(n2);
        for(int i=0; i<n1; i++)
            L[i] = arr[i+left];
        
        for(int i=0; i<n2; i++)
            R[i] = arr[mid+1+i];
            
        int i=0, j=0;
        int k = left;
        while(i<n1 && j<n2) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                k++; i++;
            } else {
                ans+= (n1-i);
                arr[k] =  R[j];
                k++;
                j++;
            }
        }
        
        while(i<n1) {
            arr[k] = L[i];
            k++;
            i++;
        }
        
        while(j<n2) {
            arr[k] = R[j];
            k++;
            j++;
        }
    }
};