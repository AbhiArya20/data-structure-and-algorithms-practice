#include<bits/stdc++.h>
using namespace std;

// LeetCode - 322

class Solution {
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0)
            return 0;
        if(i<0)
            return 1e9;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int ans = 1e9;
        ans = min(ans,f(i-1, amount, coins, dp));
        if(amount>=coins[i])
            ans = min(ans,1+f(i,amount-coins[i],coins, dp));
        return dp[i][amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        int ans = f(n-1,amount,coins,dp);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};


// LeetCode - 518

class Solution {
    int f(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int ans = f(i-1, amount, coins, dp);
        if(amount>=coins[i])
            ans += f(i,amount-coins[i],coins, dp);
        return dp[i][amount] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        int ans = f(n-1,amount,coins,dp);
        return ans;
    }
};



// I can also optimize by using Tabulation or space optimization.
// To minimize prepration time i would write only one either memoization/tabulation for upcoming questions.