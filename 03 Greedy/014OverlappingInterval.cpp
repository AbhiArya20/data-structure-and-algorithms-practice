#include<bits/stdc++.h>
using namespace std;

// GFG - Overlapping Intervals
// LeetCode - 56

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end(),[](auto a,auto b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
         });
         int n = intervals.size(); 
         vector<vector<int>> ans;
         ans.push_back(intervals[0]);
         for(int i=1;i<n;i++){
             if(ans[ans.size()-1][1]>=intervals[i][0]){
                 ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
             }else{
                 ans.push_back(intervals[i]);
             }
         }
         return ans;
    }
};