#include<bits/stdc++.h>
using namespace std;

// LeetCode - 1434

class Solution {
    int mod = 1e9+7;
    int f(int i, int mask, vector<vector<int>> &hatList, vector<vector<int>> &dp){
        if(mask == 0)
            return 1;
        if(i>40)
            return 0;
        if(dp[mask][i]!=-1)
            return dp[mask][i];
        long long ans = f(i+1, mask, hatList,dp);
        for(int j = 0;j<hatList[i].size(); j++){
            if(mask & (1<<hatList[i][j])){
                ans += f(i+1,mask^(1<<hatList[i][j]),hatList,dp);
                ans %= mod;
            }
        }
        return dp[mask][i] = ans;
    }
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> hatList(41);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<hats[i].size(); j++){
                hatList[hats[i][j]].push_back(i);
            }
        }
        int mask = (1<<n)-1;
        vector<vector<int>> dp(mask+1, vector<int>(41,-1));
        return f(0, mask, hatList, dp);
    }
};