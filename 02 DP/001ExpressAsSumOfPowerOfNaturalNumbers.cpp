#include<bits/stdc++.h>
using namespace std;

// GFG - Express as sum of power of natural numbers

class Solution{
    int mod = 1e9+7;
    
    int ways(int i,int x, int sum, vector<vector<int>>&dp){
        int a =sum - (int)pow(i, x);
        if(a < 0)
            return 0;
        if(a == 0)
            return 1;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int take = ways(i+1,x, a, dp)%mod;
        int untake = ways(i+1, x, sum, dp)%mod;
        return dp[i][sum] = (take+untake)%mod;
    }
    
    
    public:
    int numOfWays(int n, int x)
    {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return ways(1,x,n, dp);
    }
};