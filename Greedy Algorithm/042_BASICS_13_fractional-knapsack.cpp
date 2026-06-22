/*Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

Input: val[] = [500], wt[] = [30], capacity = 10
Output: 166.670000
Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 of it, yielding value 166.670000.

Constraints:
1 ≤ val.size = wt.size ≤ 105
1 ≤ capacity ≤ 109
1 ≤ val[i], wt[i] ≤ 104
*/
//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include "bits/stdc++.h"
using namespace std;
class Solution {
  public:
  
    static bool compare(pair<int, int> &a, pair<int,int> &b) {
        return ((double)a.first/a.second) > ((double)b.first/b.second);
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int, int>> v;
        int n = val.size();
        for(int i=0; i<n; i++) 
            v.push_back({val[i], wt[i]});
        
        sort(v.begin(), v.end(), compare);

        double ans = 0;
        double cap = (double) capacity;
        for(int i=0; i<n; i++) {
            if(cap >= v[i].second) {
                cap -= v[i].second;
                ans += v[i].first;
            }
            else if(cap==0)
                break;
            else {
                double temp= ((double)v[i].first/v[i].second); 
                ans += (double)temp*cap;
                break;
            }
        }
        
        return ans;
    }
};
