/*You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

    The maximum number of jobs that can be completed within their deadlines.
    The total maximum profit earned by completing those jobs.

Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

Constraints:
1 ≤ deadline.size() = profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500*/
//https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
#include "bits/stdc++.h"
using namespace std;
class Solution {
  public:
    vector<int> jobSequencing_Naive(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>> v;
        int n= deadline.size();
        int maxDeadline = -1;
        for(int i=0; i<n; i++) {
            v.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        sort(v.begin(), v.end());
        int jobs = 0, prof = 0;
        vector<bool> ass(maxDeadline+1, false);
        
        for(int i=n-1; i>=0; i--) {
            if(jobs == maxDeadline) break;
            
            int ind = v[i].second;
            while(ass[ind]) 
                ind--;
            if(ind == 0)
                continue;
            jobs++;
            ass[ind] = true;
            prof += v[i].first;
            
           
        }
        
        return {jobs, prof};
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        vector<pair<int,int>> v;
        int n= deadline.size();
        for(int i=0; i<n; i++) {
            v.push_back({deadline[i], profit[i]});
        }
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>, greater<int>> min_q;
        for(int i=0; i<n; i++) {
            if(v[i].first > min_q.size())
                min_q.push(v[i].second);
            else if(v[i].second > min_q.top()) {
                min_q.pop();
                min_q.push(v[i].second);
            }
        }
        
        vector<int> ans(2,0);
        while(min_q.size() >0) {
            ans[0]++;
            ans[1] += min_q.top();
            min_q.pop();
        }
        
        return ans;
    }

};
