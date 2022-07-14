#include<bits/stdc++.h>
using namespace std;

// LeetCode - 368

class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& a) {
        sort(a.begin(),a.end());
        int ans = 1;
        int val = 0;
        vector<int> dp(n,1);
        vector<int> parent(n);
        for(int i = 1; i<n; i++){
           parent[i]=i;
           for(int j = 0; j<i; j++){
               if(a[i] % a[j] == 0 && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
               }
           }
           if(ans<dp[i]){
               val = i;
               ans = dp[i];
           }
        }
        vector<int> res;
        res.push_back(a[val]);
        while(parent[val]!=val){
            val = parent[val];
            res.push_back(a[val]);
        }
        return res;
    }
};
