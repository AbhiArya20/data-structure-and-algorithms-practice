#include<bits/stdc++.h>
using namespace std;

// GFG - Count all possible paths from top left to bottom right

class Solution {
    int mod = 1e9+7;
    long long int f(int i, int j, int m, int n,vector<vector<long long int>> &dp){
        if(i>=m || j>=n)
            return 0;
        if(i == m-1 && j == n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j] = (f(i+1,j,m,n,dp)+f(i,j+1,m,n,dp))%mod;
    }
  public:
    long long int numberOfPaths(int m, int n){
        vector<vector<long long int>> dp(m,vector<long long int>(n,-1));
        return f(0,0,m,n,dp);
    }
};