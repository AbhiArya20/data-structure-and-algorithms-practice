#include<bits/stdc++.h>
using namespace std;

// GFG - Count Palindromic Subsequence

class Solution{
    int mod = 1e9+7;
    long long int f(int s, int e, string &str,vector<vector<long long int>> &dp){
        if(s>e)
            return 0;
        if(s==e)
            return 1;
        if(dp[s][e]!=-1)
            return dp[s][e];
        if(str[s] == str[e])
            return dp[s][e] = (1+f(s+1,e,str,dp)+f(s,e-1,str,dp))%mod;
        return dp[s][e] = ((f(s+1,e,str,dp)+f(s,e-1,str,dp)-f(s+1,e-1,str,dp))%mod + mod )%mod;
    }
    public:
    long long int  countPS(string &str){
        int n = str.size();
        vector<vector<long long int>> dp(n,vector<long long int>(n,-1));
        return f(0,n-1,str,dp)%mod;
    }
};