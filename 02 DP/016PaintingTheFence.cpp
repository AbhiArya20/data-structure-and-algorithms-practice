#include<bits/stdc++.h>
using namespace std;

// GFG - Painting the Fence

class Solution{
    int mod = 1e9+7;
    long long f(int n, int k,vector<long long> &dp){
        if(n==1)
            return k;
        if(n==2)
            return k*k;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = ((k-1)*(f(n-1,k,dp)+f(n-2,k,dp))%mod)%mod;
    }
    public:
    long long countWays(int n, int k){
        vector<long long> dp(n+1,-1);
        return f(n,k,dp);
    }
};