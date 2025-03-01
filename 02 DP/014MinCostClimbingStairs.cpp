#include<bits/stdc++.h>
using namespace std;

// LeetCode - 746

class Solution {
    int f(int i, vector<int> &cost, vector<int> &dp){
        if(i>=cost.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = cost[i] + min(f(i+1,cost, dp), f(i+2, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        int ans0 = f(0, cost, dp);
        dp.clear();
        dp.resize(n, -1);
        int ans1 = f(1, cost, dp);
        return min(ans0, ans1);
    }
};