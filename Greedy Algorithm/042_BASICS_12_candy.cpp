/*There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

 

Constraints:

    n == ratings.length
    1 <= n <= 2 * 104
    0 <= ratings[i] <= 2 * 104

*/
//https://leetcode.com/problems/candy/description/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        // code here
        int n = ratings.size();
        vector<int> candies(n, 1);
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) 
            v.push_back({ratings[i], i});
        sort(v.begin(), v.end());
        
        if(n==1)
            return 1;
            
        // int ans = 1;
        
        for(int i=0; i<n; i++) {
            int j = v[i].second;
            if(j==0 && ratings[j] > ratings[j+1]) {
                candies[j] = 1+candies[j+1];
            } else if(j==n-1 && ratings[j] > ratings[j-1]) {
                candies[j] = 1+candies[j-1];
            } else if(j>0 && j<n-1) {
                if(ratings[j]>ratings[j-1] && ratings[j]>ratings[j+1])
                    candies[j] = 1 + max(candies[j-1], candies[j+1]);
                else if(ratings[j] > ratings[j-1])
                    candies[j] = 1 + candies[j-1];
                else if(ratings[j] > ratings[j+1])
                    candies[j] = 1 + candies[j+1];
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += candies[i];
            // cout<<candies[i]<<' '<<arr[i]<<endl;
        }
        
        return ans;
    }
};