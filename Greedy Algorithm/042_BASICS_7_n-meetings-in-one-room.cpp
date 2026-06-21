/*Activity Selection
Difficulty: MediumAccuracy: 36.21%Submissions: 582K+Points: 4Average Time: 20m

Given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.

Note: Start time and finish time cannot overlap, i.e., if a person finishes an activity at time x, then they cannot start another activity at time x.

Examples:

Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}

Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]
Output: 1
Explanation: A person can perform at most one activity.

Input: start[] = [1, 3, 2, 5], finish[] = [2, 4, 3, 6]
Output: 3
Explanation: A person can perform activities 0, 1 and 3.

Constraints:
1 ≤ start.size() = finish.size() ≤ 2*105
0 ≤ start[i] ≤ finish[i] ≤ 109*/
//https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
#include "bits/stdc++.h"
using namespace std;
class Solution {
    
  struct Meeting {
      int end;
      int pos;
      int start;
      void print() {
          cout<<start<<' '<<pos<<' '<<end<<endl;
      }
  };
  
  static bool compareMeeting(const Meeting& a, const Meeting& b) {
      if(a.end < b.end) return true;
      else if(a.end > b.end) return false;
      else if(a.pos < b.pos) return true;
      return false;
  }
  
  public:
    int activitySelection2(vector<int> &start, vector<int> &finish) {
        // code here
        vector<Meeting> v;
        int n = start.size();
        for(int i=0; i<n; i++)
            v.push_back({finish[i], i, start[i]});
            
        sort(v.begin(), v.end(),compareMeeting);
        // for(int i=0; i<n; i++) {
        //     v[i].print();
        // }
        int ans = 1;
        int currEnd = v[0].end;
        
        for(int i=1; i<n; i++) {
            if(currEnd < v[i].start) {
                ans++;
                currEnd = v[i].end;
            }
        }
        
        return ans;
    }
    
    int activitySelection(vector<int> &start, vector<int> &finish) {
        
        int n = start.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++)
            v.push_back({finish[i], start[i]});
        
        sort(v.begin(), v.end());
        int ans = 1, currEnd = v[0].first;
        for(int i=1; i<n; i++) {
            if(v[i].second > currEnd) {
                ans++;
                currEnd = v[i].first;
            }
        }
        
        return ans;
    }
    
}; 