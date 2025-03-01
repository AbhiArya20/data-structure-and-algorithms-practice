#include<bits/stdc++.h>
using namespace std;

// GFG - Travelling Salesman or Hamiltonian Cycle with shortest path
// BruteForce - find all possible Hamiltonian Cycle or Permutation then minimize the cost



class Solution { // DP Approach
    int dfs(int src, int mask, vector<vector<int>>&cost,vector<vector<int>>&dp){
        if(!mask){
            return cost[src][0];
        }
        if(dp[src][mask]!=0)
            return dp[src][mask];
        int n = cost.size();
        int ans = INT_MAX;
        for(int child = 0; child<n; child++){
            if((mask&(1<<child)) && child!=src && child!=0){
                ans = min(ans, dfs(child, (mask^(1<<child)),cost,dp)+cost[src][child]);
            }
        }
        return dp[src][mask] = ans;
    }
public:
    int total_cost(vector<vector<int>>cost){
        int n = cost.size();
        int mask = (1<<n)-1;
        int ans = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(mask+1));
        ans = min(ans, dfs(0,mask^1,cost,dp));
        return ans;
    }
};
