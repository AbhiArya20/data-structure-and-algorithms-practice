#include<bits/stdc++.h>
using namespace std;

// LeetCode - 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = 100000;
        for(int v: prices){
            ans = max(ans, v-mini);
            mini = min(mini, v);
        }
        return ans;
    }
};

// LeetCode - 122
class Solution {
    int f(int i,int buy, int n, vector<int> &prices,vector<vector<int>> &dp){
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy){
            int unbuy = f(i+1,buy,n,prices,dp);
            int get = - prices[i] + f(i+1,false,n,prices,dp);
            return dp[i][buy] = max(get, unbuy);
        }else{
            int unsell = f(i+1, buy, n, prices,dp);
            int sell = prices[i] + f(i+1,true, n, prices,dp);
            return dp[i][buy] = max(unsell, sell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,true,n,prices,dp);
    }
};



// LeetCode - 123
class Solution {
    int f(int i,int buy, int count, int n, vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(count == 2)
            return 0;
        if(i==n)
            return 0;
        if(dp[i][buy][count]!=-1)
            return dp[i][buy][count];
        if(buy){
            int unbuy = f(i+1,buy,count,n,prices,dp);
            int get = - prices[i] + f(i+1,false,count,n,prices,dp);
            return dp[i][buy][count] = max(get, unbuy);
        }else{
            int unsell = f(i+1, buy, count, n, prices,dp);
            int sell = prices[i] + f(i+1,true,count+1, n, prices,dp);
            return dp[i][buy][count] = max(unsell, sell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int>(2,-1)));
        return f(0,true,0,n,prices,dp);
    }
};


// LeetCode - 188
class Solution {
    int f(int i,int buy, int count, int k, int n, vector<int> &prices,vector<vector<vector<int>>> &dp){
        if(count == k)
            return 0;
        if(i==n)
            return 0;
        if(dp[i][buy][count]!=-1)
            return dp[i][buy][count];
        if(buy){
            int unbuy = f(i+1,buy,count,k,n,prices,dp);
            int get = - prices[i] + f(i+1,false,count,k,n,prices,dp);
            return dp[i][buy][count] = max(get, unbuy);
        }else{
            int unsell = f(i+1, buy, count,k, n, prices,dp);
            int sell = prices[i] + f(i+1,true,count+1,k, n, prices,dp);
            return dp[i][buy][count] = max(unsell, sell);
        }
    }
public:
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2,vector<int>(k,-1)));
        return f(0,true,0,k,n,prices,dp);
    }
};



// LeetCode - 309
class Solution {
    int f(int i,int buy, int n, vector<int> &prices,vector<vector<int>> &dp){
        if(i>=n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy){
            int unbuy = f(i+1,buy,n,prices,dp);
            int get = - prices[i] + f(i+1,false,n,prices,dp);
            return dp[i][buy] = max(get, unbuy);
        }else{
            int unsell = f(i+1, buy, n, prices,dp);
            int sell = prices[i] + f(i+2,true, n, prices,dp);
            return dp[i][buy] = max(unsell, sell);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,true,n,prices,dp);
    }
};


// LeetCode - 714

class Solution {
    int f(int i,int buy,int fee, int n, vector<int> &prices,vector<vector<int>> &dp){
        if(i==n)
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        if(buy){
            int unbuy = f(i+1,buy,fee,n,prices,dp);
            int get = - prices[i] + f(i+1,false,fee,n,prices,dp);
            return dp[i][buy] = max(get, unbuy);
        }else{
            int unsell = f(i+1, buy,fee, n, prices,dp);
            int sell = prices[i] - fee + f(i+1,true,fee, n, prices,dp);
            return dp[i][buy] = max(unsell, sell);
        }
    }
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,true,fee,n,prices,dp);
    }
};