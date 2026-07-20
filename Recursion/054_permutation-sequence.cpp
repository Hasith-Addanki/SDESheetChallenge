// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

//     "123"
//     "132"
//     "213"
//     "231"
//     "312"
//     "321"

// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"

// Example 2:

// Input: n = 4, k = 9
// Output: "2314"

// Example 3:

// Input: n = 3, k = 1
// Output: "123"

 

// Constraints:

//     1 <= n <= 9
//     1 <= k <= n!


// https://leetcode.com/problems/permutation-sequence/description/
#include "bits/stdc++.h"
using namespace std;
class Solution {
    vector<int> nFact;
public:
    string getPermutation(int n, int k) {
        nFact = vector<int>(10, 1);
        string ans = "";
        for(int i=1; i<=n; i++) {
            ans += to_string(i);
            nFact[i] = nFact[i-1] * i;
        }
        calcPerm(ans, 1, n, k);
        return ans;
    }

    void calcPerm(string& ans, int i, int n, int k) {
        int j = 1;
        int low = 0, high = 0;

        for(j; j<=n; j++) {
            low = ((j-1) * nFact[n-1]) + 1;
            high = j * nFact[n-1];
            if(low <= k && k<= high)
                break;
        }
        swap(ans[i-1], ans[i+j-2]);
        sort(ans.begin() + i, ans.end());

        if(low == k)
            return;
        if(high == k) {
            reverse(ans.begin() + i, ans.end());
            return;
        }
        k -= ((j-1) * nFact[n-1]);
        calcPerm(ans, i+1, n-1, k);
    }
};