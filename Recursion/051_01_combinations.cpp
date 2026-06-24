/*Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

 

Constraints:

    1 <= n <= 20
    1 <= k <= n

*/
// https://leetcode.com/problems/combinations/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1; i+k-1 <=n; i++) {
            temp = {i};
            getCombinations(i, n, k, temp, ans);
        }
        return ans;
    }

    void getCombinations(int ind, int n, int k, vector<int> temp, vector<vector<int>> &ans) {
        // cout<<"ind: "<<ind<<endl;
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for(int start = ind + 1; start<= n; start++) {
            // cout<<"start: "<<start<<endl;

            temp.push_back(start);
            getCombinations(start, n, k, temp, ans);
            temp.pop_back();
        }
    }


    vector<vector<int>> combine_intial(int n, int k) {
        vector<vector<int>> ans;
        for(int i=1; i<=n; i++) {
            if(i+k-1 > n) break;
            vector<int> temp = {i};
            if(k==1) {
                ans.push_back(temp);
                continue;
            }

            for(int j=i+1; j<=n; j++) {
                if(temp.size() == k) {
                    ans.push_back(temp);
                    temp.pop_back();
                }
                temp.push_back(j);
            }
            if(temp.size()  == k)
                ans.push_back(temp);
        }

        return ans; 
    }

    vector<vector<int>> combine_TLE(int n, int k) {
        // vector<vector<int>> ans;
        set<set<int>> ans;
        set<int> temp;
        for(int i=n-k+1; i<=n; i++)
            temp.insert(i);
        ans.insert(temp);

        for(int i=n-k; i>=1; i--) {
            set<set<int>> tempAns(ans.begin(), ans.end());
            for(auto it : tempAns) {
                vector<int> v(it.begin(), it.end());
                for(int j=0; j<v.size(); j++) {
                    int actual = v[j];
                    v[j] = i;
                    ans.insert(set<int>(v.begin(), v.end()));
                    v[j] = actual;
                }
            }
        }

        vector<vector<int>> finalAns;
        for(auto it: ans) 
            finalAns.push_back(vector<int>(it.begin(), it.end()));
        return finalAns; 
    }
};